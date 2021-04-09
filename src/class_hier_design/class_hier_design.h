#include "ap_int.h"
#include "hls_stream.h"
typedef ap_uint<4> uint4; // avoids hls::stream mixups between << and < <
typedef ap_uint<5> uint5;
class top_chan {
    hls::stream<uint5> tmp; // hls::stream to connect BLOCK0 and BLOCK1
#pragma hls_design
    void BLOCK0(hls::stream<uint4>& a, hls::stream<uint5>& b) {
#pragma HLS PIPELINE II = 1
        uint5 temp[4];
#pragma HLS ARRAY_MAP variable = temp horizontal
        if (!a.empty()) {
            READ:for (ap_uint<3> i = 0; i < 4; i++) {
                temp[i] = a.read();
            }
            WRITE:for (ap_uint<4> i = 0; i < 4; i++) {
                if (i % 2 == 0) b.write(temp[i] + temp[i + 1]);
            }
        }
    } // end BLOCK0

#pragma hls_design
    void BLOCK1(hls::stream<uint5>& a, hls::stream<uint5>& b) {
#pragma HLS PIPELINE II = 1
        PASS:for (ap_uint<3> i = 0; i < 2; i++) {
            if (!a.empty()) b.write(a.read());
        }
    } // end BLOCK1
   public:
    top_chan() {} // required constructor

#pragma hls_design interface
    void run(hls::stream<uint4>& in, hls::stream<uint5>& out) {
#pragma HLS STREAM variable=tmp depth=2
        BLOCK0(in, tmp);
        BLOCK1(tmp, out);
    }
};

void top(hls::stream<uint4>& in, hls::stream<uint5>& out);
