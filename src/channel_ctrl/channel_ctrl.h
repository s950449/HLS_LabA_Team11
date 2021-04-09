#include "ap_int.h"
#include "hls_stream.h"

#define WIDTH 4
typedef ap_uint<4> uint4;
typedef ap_uint<WIDTH> ctrl_type;

void BLOCK0(hls::stream<uint4>& din,
            hls::stream<uint4>& dout,
            hls::stream<ctrl_type>& ctrl_in,
            hls::stream<ctrl_type>& ctrl_out);

void BLOCK1(hls::stream<uint4>& din, hls::stream<uint4>& dout, hls::stream<ctrl_type>& ctrl);

void top(hls::stream<uint4>& din, hls::stream<uint4>& dout, hls::stream<ctrl_type>& ctrl);
