#include "ap_int.h"
#include "hls_stream.h"

#define WIDTH 4
typedef ap_uint<4> uint4;
typedef ap_uint<WIDTH> ctrl_type;

class control_mult {
    
  hls::stream<uint4> data_int;
  hls::stream<ctrl_type> ctrl_int;
    
  #pragma hls_design
  void BLOCK0 (hls::stream<uint4> &din,
               hls::stream<uint4> &dout,
               hls::stream<ctrl_type> &ctrl_in,
               hls::stream<ctrl_type> &ctrl_out) {
#pragma HLS PIPELINE II=1
    ctrl_type temp_int = ctrl_in.read();
    ctrl_out.write(temp_int); // one write
    WRITE:for (ctrl_type i = 0; i != temp_int; i++) {
      dout.write(din.read() * 13);
    }
  }
    
  #pragma hls_design
  void BLOCK1 (hls::stream<uint4> &din,
               hls::stream<uint4> &dout,
               hls::
#pragma HLS PIPELINE II=1
stream<ctrl_type> &ctrl) {
    ctrl_type temp_int = ctrl.read(); // one read
    READ:for (ctrl_type i=0; i != temp_int; i++) {
      dout.write(din.read());
    }
  }
    
  public:
    
  control_mult () {}
    
  #pragma hls_degisn interface
  void top (hls::stream<uint4> &din,
            hls::stream<uint4> &dout,
            hls::stream<ctrl_type> &ctrl) {
    BLOCK0(din,data_int,ctrl,ctrl_int);
    BLOCK1(data_int,dout,ctrl_int);
  }
};
