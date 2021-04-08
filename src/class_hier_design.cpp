#include "class_hier_design.h"

void top (hls::stream<uint4> &in, hls::stream<uint5> &out) {
    top_chan inst;
    inst.run(in, out);
}
