#include <iostream>
#include "hls_stream.h"
#include "pass_struct_through_chan.h"

#define len 9

using namespace std;

int main(void) {
    hls::stream<uint4> din, dout;
    uint4 output;
    int pass = 1;

    for (int i = 0; i < len; i++) din.write(i);

    top(din, dout);

    cout << ">> Start Checking" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < len; i++) {
        output = dout.read();
        uint4 expect = (i / 3) * 3 + 2 - i % 3;
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
