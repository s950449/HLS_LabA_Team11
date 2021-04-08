#include "duplicate_io_ctrl.h"

void top (hls::stream<dat_type> &din0,
          hls::stream<dat_type> &din1,
          hls::stream<dat_type> &dout0,
          hls::stream<dat_type> &dout1,
          hls::stream<ctr_type> &ctrl) {
	control_mult inst;
    inst.run(din0, din1, dout0, dout1, ctrl);
}
