#include "ac_int.h"
#include "ac_channel.h"

#define WIDTH 4
typedef ac_int<4,false> uint4;
typedef ac_int<WIDTH,false> ctrl_type;

class control_mult {
    
  ac_channel<uint4> data_int;
  ac_channel<ctrl_type> ctrl_int;
    
  #pragma hls_design
  void BLOCK0 (ac_channel<uint4> &din,
               ac_channel<uint4> &dout,
               ac_channel<ctrl_type> &ctrl_in,
               ac_channel<ctrl_type> &ctrl_out) {
    ctrl_type temp_int = ctrl_in.read();
    ctrl_out.write(temp_int); // one write
    WRITE:for (ctrl_type i = 0; i != temp_int; i++) {
      dout.write(din.read() * 13);
    }
  }
    
  #pragma hls_design
  void BLOCK1 (ac_channel<uint4> &din,
               ac_channel<uint4> &dout,
               ac_channel<ctrl_type> &ctrl) {
    ctrl_type temp_int = ctrl.read(); // one read
    READ:for (ctrl_type i=0; i != temp_int; i++) {
      dout.write(din.read());
    }
  }
    
  public:
    
  control_mult () {}
    
  #pragma hls_degisn interface
  void top (ac_channel<uint4> &din,
            ac_channel<uint4> &dout,
            ac_channel<ctrl_type> &ctrl) {
    BLOCK0(din,data_int,ctrl,ctrl_int);
    BLOCK1(data_int,dout,ctrl_int);
  }
};

