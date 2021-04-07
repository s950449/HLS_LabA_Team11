#include "ac_int.h"
#include "ac_channel.h"

#define CTR_WIDTH 8
#define DAT_WIDTH 4

typedef ac_int<CTR_WIDTH,false> ctr_type;
typedef ac_int<DAT_WIDTH,false> dat_type;

class control_mult {

  ac_channel<ctr_type> ctrl0;
  ac_channel<ctr_type> ctrl1;
    
  #pragma hls_design
  void CONTROL (ac_channel<ctr_type> &ctrl,
                ac_channel<ctr_type> &ctrl0,
                ac_channel<ctr_type> &ctrl1) {
    ctr_type ctrl_int = ctrl.read(); // one read
    ctrl0.write(ctrl_int);
    ctrl1.write(ctrl_int);
  }
    
  #pragma hls_design
  void BLOCK0 (ac_channel<dat_type> &din,
               ac_channel<dat_type> &dout,
               ac_channel<ctr_type> &ctrl) {
    ctr_type ctrl_int = ctrl.read();
    WRITE:for(ctr_type i=0; i<255; i++) {
      if(i==ctrl_int)
        break;
      dout.write(din.read()*13);
    }
  }

  #pragma hls_design
  void BLOCK1 (ac_channel<dat_type> &din,
               ac_channel<dat_type> &dout,
               ac_channel<ctr_type> &ctrl) {
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
  void top (ac_channel<dat_type> &din0,
            ac_channel<dat_type> &din1,
            ac_channel<dat_type> &dout0,
            ac_channel<dat_type> &dout1,
            ac_channel<ctr_type> &ctrl) {
    CONTROL(ctrl,ctrl0,ctrl1);
    BLOCK0(din0,dout0,ctrl0);
    BLOCK1(din1,dout1,ctrl1);
  }
};
