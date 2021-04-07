#include "ap_int.h"
#include "hls_stream.h"

typedef ap_uint<4> uint4;

class recon_multadd_diff {

    
  hls::stream<uint4> b1_in;
  hls::stream<uint4> b2_in;
  hls::stream<uint4> b3_in_0;
  hls::stream<uint4> b3_in_1;

  #pragma hls_design
  void BLOCK0 (hls::stream<uint4> &din0,
               hls::stream<uint4> &din1,
               hls::stream<uint4> &dout0,
               hls::stream<uint4> &dout1) {
#pragma HLS PIPELINE II=1 enable_flush
    uint4 tmp0, tmp1;
    tmp0 = din0.read();
    tmp1 = din1.read();
    dout0.write(tmp0 + tmp1);
    dout1.write(tmp0 - tmp1);
  }

  #pragma hls_design
  void BLOCK1 (hls::stream<uint4> &din,
               h
#pragma HLS PIPELINE II=1
ls::stream<uint4> &dout) {
    uint4 tmp;
    tmp = din.read() * 13;
    dout.write(tmp);
  }
    
  #pragma hls_design
  void BLOCK2 (hls::stream<uin
#pragma HLS PIPELINE II=1 enable_flush
t4> &din1,
               hls::stream<uint4> &dout) {
    uint4 tmp;
    tmp = din1.read() + 111;
    dout.write(tmp);
  }
    
  #pragma hls_design
  void BLOCK3 (hls::stream<uint4> &din0,
               hls::stream<uin
#pragma HLS PIPELINE II=1 enable_flush
t4> &din1,
               hls::stream<uint4> &dout) {
    uint4 tmp;
    tmp = din0.read() - din1.read();
    dout.write(tmp);
  }
    
  public:

  recon_multadd_diff () {}
    
  #pragma hls_design interface
  void run (hls::stream<uint4> &din0,
            hls::stream<uint4> &din1,
            hls::stream<uint4> &dout) {
    BLOCK0(din0,din1,b1_in,b2_in);
    BLOCK1(b1_in,b3_in_0);
    BLOCK2(b2_in,b3_in_1);
    BLOCK3(b3_in_0,b3_in_1,dout);
  }
};
