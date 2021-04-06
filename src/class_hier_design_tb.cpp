#include <stdio.h>
#include <stdlib.h>
#include "class_hier_design.h"
int main(){
top_chan inst; // instantiate design instance
hls::stream<uint4> din; // instantiate channels
hls::stream<uint5> dout;
// write inputs into din
for (int i = 0; i < 16; i ++){
//uint4 temp = rand() % 15;
	uint4 temp = i;
	din.write(temp);
}
// run design, pass in channels
while (!din.empty()) {//1
inst.run(din,dout);
}
// print output
int count = 0;
while (!dout.empty()) {//1
	std::cout<<"dout["<<count<<"] = "<<dout.read()<<"\n";
//printf("dout[%d] = %d\n",count,dout.read());
count += 1;
}
return 0;
}
