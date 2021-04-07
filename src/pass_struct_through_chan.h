#include "hls_stream.h"
#include "ap_int.h"

typedef ap_uint<4> uint4;

struct chanStr
#pragma HLS ARRAY_MAP variable=data horizontal
uct {
    uint4 data[3];
};

class simple_chanstruct {
    
  hls::stream<chanStruct> tmp;
    
  #pragma hls_design
  void BLOCK0( hls::stream<uint4> &din,
               hls::stream<chanStruct> &dout) {
#pragma HLS PIPELINE II=1
      
    chanStruct tmp;
      
    WRITE:for(ap_uint<3> i=0; i<3; i++){
      tmp.data[i] = din.read();
    }
    dout.write(tmp);
  }

  #pragma hls_design
  void BLOCK1( hls::stream<chanStruct> &din,
               h
#pragma HLS PIPELINE II=1
ls::stream<uint4> &dout) {
      
    chanStruct tmp;
    tmp = din.read();
    READ:for(ap_int<4> i =2; i>=0; i--) {
      dout.write(tmp.data[i]);
    }
  }
    
    public :
    
    simple_chanstruct () {}
    
  #pragma hls_design interface
  void run (hls::stream<uint4> &din,
            hls::stream<uint4> &dout) {
      
    BLOCK0(din,tmp);
    BLOCK1(tmp,dout);
  }
};
