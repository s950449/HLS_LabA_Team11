#include "directinput_ctrl.h"
#include "hls_stream.h"

void BLOCK0 (hls::stream<uint4> &din,
             hls::stream<uint4> &dout,
             ap_uint<WIDTH> &ctrl) {
  WRITE:for (ap_uint<8> i = 0; i < 255; i++) {
    if (i == ctrl)
        break;
    dout.write(din.read() * 13);
  }
}

void BLOCK1 (hls::stream<uint4> &din,
             hls::stream<uint4> &dout,
             ap_uint<WIDTH> &ctrl) {
  READ:for (ap_uint<WIDTH> i = 0; i < 255; i++) {
    if(i == ctrl)
        break;
    dout.write(din.read());
  }
}

void top (hls::stream<uint4> &din,
          hls::stream<uint4> &dout,
          ap_uint<WIDTH> &ctrl) {
#pragma HLS STREAM variable=data_int depth=1
  hls::stream<uint4> data_int;
  BLOCK0(din, data_int, ctrl);
  BLOCK1(data_int, dout, ctrl);
}
