#include <iostream>
#include "hls_stream.h"
#include "duplicate_io_ctrl.h"

#define len 20

using namespace std;

int main(void) {
    hls::stream<dat_type> din0, din1, dout0, dout1;
    hls::stream<ctr_type> ctrl;
    int pass = 1;

    ctrl.write((ctr_type)len);
    for (int i = 0; i < len; i++) {
        din0.write(i);
        din1.write(i);
    }

    top(din0, din1, dout0, dout1, ctrl);

    cout << ">> Start Checking" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < len; i++) {
        dat_type output0 = dout0.read();
        dat_type output1 = dout1.read();
        dat_type expect0 = i * 13;
        dat_type expect1 = i * 111;
        cout << "Output0: " << output0 << "\tExpect: " << expect0 << endl;
        cout << "Output1: " << output1 << "\tExpect: " << expect1 << endl;
        if (output0 != expect0 || output1 != expect1) pass = 0;
    }
    cout << "------------------------" << endl;

    if (!pass) {
        cout << "Failed" << endl;
        return 1;
    }

    cout << "Passed Congrats" << endl;
    return 0;
}
