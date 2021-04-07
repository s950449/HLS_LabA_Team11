#include "ac_channel.h"
#include "ac_int.h"

typedef ac_int<4,false> uint4;

struct chanStruct {
    uint4 data[3];
};

class simple_chanstruct {
    
  ac_channel<chanStruct> tmp;
    
  #pragma hls_design
  void BLOCK0( ac_channel<uint4> &din,
               ac_channel<chanStruct> &dout) {
      
    chanStruct tmp;
      
    WRITE:for(ac_int<3,false> i=0; i<3; i++){
      tmp.data[i] = din.read();
    }
    dout.write(tmp);
  }

  #pragma hls_design
  void BLOCK1( ac_channel<chanStruct> &din,
               ac_channel<uint4> &dout) {
      
    chanStruct tmp;
    tmp = din.read();
    READ:for(ac_int<4,true> i =2; i>=0; i--) {
      dout.write(tmp.data[i]);
    }
  }
    
    public :
    
    simple_chanstruct () {}
    
  #pragma hls_design interface
  void run (ac_channel<uint4> &din,
            ac_channel<uint4> &dout) {
      
    BLOCK0(din,tmp);
    BLOCK1(tmp,dout);
  }
};

