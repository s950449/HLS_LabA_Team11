#include "feedback_reconverge.h"

void top(hls::stream<uint4>& din0, hls::stream<uint4>& din1, hls::stream<uint4>& dout) {
    recon_multadd_diff inst;
    inst.run(din0, din1, dout);
}
