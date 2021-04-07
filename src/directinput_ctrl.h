#include "ac_int.h"
#include "ac_channel.h"

#define WIDTH 8

typedef ac_int<4,false> uint4;

class control_mult {

  ac_channel<uint4> data_int;
    
  #pragma hls_design
  void BLOCK0 (ac_channel<uint4> &din,
               ac_channel<uint4> &dout,
               ac_int<WIDTH,false> &ctrl) {
    WRITE:for (ac_int<8,false> i=0; i<255; i++) {
      if(i==ctrl)
        break;
      dout.write(din.read()*13);
    }
  }

  #pragma hls_design
  void BLOCK1 (ac_channel<uint4> &din,
               ac_channel<uint4> &dout,
               ac_int<WIDTH,false> &ctrl) {
    READ:for (ac_int<WIDTH,false> i=0; i<255; i++) {
      if(i==ctrl)
        break;
      dout.write(din.read());
    }
  }
    
  public:
    
  control_mult () {}
    
  #pragma hls_design interface
  void top (ac_channel<uint4> &din,
            ac_channel<uint4> &dout,
            ac_int<WIDTH,false> &ctrl) {
    BLOCK0(din,data_int,ctrl);
    BLOCK1(data_int,dout,ctrl);
  }
};
