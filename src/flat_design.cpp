#include "ap_int.h"
void BLOCK0 (ap_uint<4> din[3],ap_uint<4> dout[3]){
WRITE:for(ap_uint<3> i=0; i <3; i++) {
dout[i] = din[i]+1;
}
}
void BLOCK1 (ap_uint<4> din[3],ap_uint<4> dout[3]) {
WRITE:for(ap_int<3> i=2; i >= 0; i--) {dout[i] = din[i]-1;
}
}
#pragma hls_design top
void top (ap_uint<4> din[3],ap_uint<4> dout[3]) {
ap_uint<4> tmp[3];
BLOCK0(din,tmp);
BLOCK1(tmp,dout);
}
