#include "channel_ctrl.h"

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

void BLOCK1 (hls::stream<uint4> &din,
		     hls::stream<uint4> &dout,
		     hls::stream<ctrl_type> &ctrl) {
#pragma HLS PIPELINE II=1
    ctrl_type temp_int = ctrl.read(); // one read
    READ:for (ctrl_type i=0; i != temp_int; i++) {
      dout.write(din.read());
    }
}

void top (hls::stream<uint4> &din,
          hls::stream<uint4> &dout,
          hls::stream<ctrl_type> &ctrl) {
#pragma HLS dataflow
	hls::stream<uint4> data_int;
	hls::stream<ctrl_type> ctrl_int;

    BLOCK0(din, data_int, ctrl, ctrl_int);
    BLOCK1(data_int, dout, ctrl_int);
 }
