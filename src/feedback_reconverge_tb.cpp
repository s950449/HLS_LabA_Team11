#include <iostream>
#include "hls_stream.h"
#include "feedback_reconverge.h"

#define len 10

using namespace std;

int main(void) {
    hls::stream<uint4> din0, din1, dout;
    uint4 output;
    int pass = 1;

    for (int i = 0; i < len; i++) {
        din0.write(i << 1);
        din1.write(i);
    }

    while (!din0.empty() && !din1.empty()) top(din0, din1, dout);

    cout << ">> Start Checking" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < len; i++) {
        output = dout.read();
        uint4 expect = i * 38 - 111;
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
