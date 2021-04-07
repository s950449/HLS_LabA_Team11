#include "ap_int.h"
#include "hls_stream.h"

#define WIDTH 8

typedef ap_uint<4> uint4;

class control_mult {

  hls::stream<uint4> data_int;
    
  #pragma hls_design
  void BLOCK0 (hls::stream<uint4> &din,
               hls::stream<uint4> &dout,
               ap_uint<WIDTH> &ctrl) {
    WRITE:for (ap_uint<8> i=0; i<255; i++) {
      if(i==ctrl)
        break;
      dout.write(din.read()*13);
    }
  }

  #pragma hls_design
  void BLOCK1 (hls::stream<uint4> &din,
               hls::stream<uint4> &dout,
               ap_uint<WIDTH> &ctrl) {
    READ:for (ap_uint<WIDTH> i=0; i<255; i++) {
      if(i==ctrl)
        break;
      dout.write(din.read());
    }
  }
    
  public:
    
  control_mult () {}
    
  #pragma hls_design interface
  void top (hls::stream<uint4> &din,
            hls::stream<uint4> &dout,
            ap_uint<WIDTH> &ctrl) {
    BLOCK0(din,data_int,ctrl);
    BLOCK1(data_int,dout,ctrl);
  }
};
