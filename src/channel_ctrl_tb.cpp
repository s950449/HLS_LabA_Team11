#include <iostream>
#include "hls_stream.h"
#include "channel_ctrl.h"

#define len 4

using namespace std;

int main (void) {
    hls::stream<uint4> din, dout;
    hls::stream<ctrl_type> ctrl;
    uint4 output;
    int pass = 1;
    
    for(int i=0; i<len; i++)
        din.write(i);

    ctrl.write(len);

    top(din, dout, ctrl);

    cout << ">> Start Checking" << endl;
    cout << "------------------------" << endl;
    for(int i=0; i<len; i++){
    	output = dout.read();
    	cout << "Output: " << output << "\tExpect: " << uint4(i * 13) << endl;
        if(output != uint4(i * 13))
            pass = 0;
    }
    cout << "------------------------" << endl;
    
    if(!pass) {
        cout << "Failed" << endl;
        return 1;
    }

    cout << "Passed Congrats" << endl;
    return 0;
}
