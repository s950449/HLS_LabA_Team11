#include "ap_int.h"
#include "hls_stream.h"

#define CTR_WIDTH 8
#define DAT_WIDTH 4

typedef ap_uint<CTR_WIDTH> ctr_type;
typedef ap_uint<DAT_WIDTH> dat_type;

class control_mult {

  hls::stream<ctr_type> ctrl0;
  hls::stream<ctr_type> ctrl1;
    
  #pragma hls_design
  void CONTROL (hls::stream<ctr_type> &ctrl,
                hls::stream<ctr_type> &ctrl0,
                hls::stream<ctr_type> &ctrl1) {
    ctr_type ctrl_int = ctrl.read(); // one read
    ctrl0.write(ctrl_int);
    ctrl1.write(ctrl_int);
  }
    
  #pragma hls_design
  void BLOCK0 (hls::stream<dat_type> &din,
               hls::stream<dat_type> &dout,
               hls::stream<ctr_type> &ctrl) {
    ctr_type ctrl_int = ctrl.read();
    WRITE:for(ctr_type i=0; i<255; i++) {
      if(i==ctrl_int)
        break;
      dout.write(din.read()*13);
    }
  }

  #pragma hls_design
  void BLOCK1 (hls::stream<dat_type> &din,
               hls::stream<dat_type> &dout,
               hls::stream<ctr_type> &ctrl) {
    ctr_type ctrl_int = ctrl.read();
    WRITE:for(ctr_type i=0; i<255; i++) {
      if(i==ctrl_int)
        break;
      dout.write(din.read()*111);
    }
  }
    
  public:
    
  control_mult () {}

  #pragma hls_design interface
  void top (hls::stream<dat_type> &din0,
            hls::stream<dat_type> &din1,
            hls::stream<dat_type> &dout0,
            hls::stream<dat_type> &dout1,
            hls::stream<ctr_type> &ctrl) {
    CONTROL(ctrl,ctrl0,ctrl1);
    BLOCK0(din0,dout0,ctrl0);
    BLOCK1(din1,dout1,ctrl1);
  }
};
