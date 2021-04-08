#include <iostream>
#include "hls_stream.h"
#include "class_hier_design.h"

#define len 16
#define outlen (len >> 1)
using namespace std;

int main(void) {
    hls::stream<uint4> din;
    hls::stream<uint5> dout;
    uint5 output;
    int pass = 1;

    for (int i = 0; i < len; i++) din.write(i);

    while (!din.empty()) top(din, dout);

    cout << ">> Start Checking" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < outlen; i++) {
        output = dout.read();
        uint5 expect = 1 + (i << 2);
        cout << "Output: " << output << "\tExpect: " << expect << endl;
        if (output != expect) pass = 0;
    }
    cout << "------------------------" << endl;
    if (!pass) {
        cout << "Failed" << endl;
        return 1;
    }
    cout << "Passed Congrats" << endl;
    return 0;
}

