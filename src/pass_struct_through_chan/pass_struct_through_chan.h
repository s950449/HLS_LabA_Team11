#include "hls_stream.h"
#include "ap_int.h"

typedef ap_uint<4> uint4;

struct chanStruct {
    uint4 data[3];
};

class simple_chanstruct {
    hls::stream<chanStruct> tmp;

    void BLOCK0(hls::stream<uint4>& din, hls::stream<chanStruct>& dout) {
#pragma HLS PIPELINE II = 1

        chanStruct reg;

        WRITE:for (ap_uint<3> i = 0; i < 3; i++) {
#pragma HLS ARRAY_MAP variable = data horizontal
            reg.data[i] = din.read();
        }
        dout.write(reg);
    }

    void BLOCK1(hls::stream<chanStruct>& din, hls::stream<uint4>& dout) {
#pragma HLS PIPELINE II = 1
        chanStruct reg;
        reg = din.read();
        READ:for (ap_int<4> i = 2; i >= 0; i--) {
            dout.write(reg.data[i]);
        }
    }

   public:
    simple_chanstruct() {}

    void run(hls::stream<uint4>& din, hls::stream<uint4>& dout) {
#pragma HLS STREAM variable = tmp depth = 3
        BLOCK0(din, tmp);
        BLOCK1(tmp, dout);
    }
};

void top(hls::stream<uint4>& din, hls::stream<uint4>& dout);
