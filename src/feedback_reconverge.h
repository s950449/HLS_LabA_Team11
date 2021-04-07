#include "ac_int.h"
#include "ac_channel.h"

typedef ac_int<4,false> uint4;

class recon_multadd_diff {

    
  ac_channel<uint4> b1_in;
  ac_channel<uint4> b2_in;
  ac_channel<uint4> b3_in_0;
  ac_channel<uint4> b3_in_1;

  #pragma hls_design
  void BLOCK0 (ac_channel<uint4> &din0,
               ac_channel<uint4> &din1,
               ac_channel<uint4> &dout0,
               ac_channel<uint4> &dout1) {
    uint4 tmp0, tmp1;
    tmp0 = din0.read();
    tmp1 = din1.read();
    dout0.write(tmp0 + tmp1);
    dout1.write(tmp0 - tmp1);
  }

  #pragma hls_design
  void BLOCK1 (ac_channel<uint4> &din,
               ac_channel<uint4> &dout) {
    uint4 tmp;
    tmp = din.read() * 13;
    dout.write(tmp);
  }
    
  #pragma hls_design
  void BLOCK2 (ac_channel<uint4> &din1,
               ac_channel<uint4> &dout) {
    uint4 tmp;
    tmp = din1.read() + 111;
    dout.write(tmp);
  }
    
  #pragma hls_design
  void BLOCK3 (ac_channel<uint4> &din0,
               ac_channel<uint4> &din1,
               ac_channel<uint4> &dout) {
    uint4 tmp;
    tmp = din0.read() - din1.read();
    dout.write(tmp);
  }
    
  public:

  recon_multadd_diff () {}
    
  #pragma hls_design interface
  void run (ac_channel<uint4> &din0,
            ac_channel<uint4> &din1,
            ac_channel<uint4> &dout) {
    BLOCK0(din0,din1,b1_in,b2_in);
    BLOCK1(b1_in,b3_in_0);
    BLOCK2(b2_in,b3_in_1);
    BLOCK3(b3_in_0,b3_in_1,dout);
  }
};
