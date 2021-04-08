#include "ap_int.h"
#include "hls_stream.h"

#define WIDTH 8

typedef ap_uint<4> uint4;

void BLOCK0(hls::stream<uint4>& din, hls::stream<uint4>& dout, ap_uint<WIDTH>& ctrl);

void BLOCK1(hls::stream<uint4>& din, hls::stream<uint4>& dout, ap_uint<WIDTH>& ctrl);

void top(hls::stream<uint4>& din, hls::stream<uint4>& dout, ap_uint<WIDTH>& ctrl);
