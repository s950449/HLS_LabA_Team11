#include "pass_struct_through_chan.h"

void top(hls::stream<uint4>& din, hls::stream<uint4>& dout) {
    simple_chanstruct inst;
    inst.run(din, dout);
}
