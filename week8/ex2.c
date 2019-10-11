#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int mb = 1024*1024;
    for (int i = 0; i < 10; i++) {
        printf("cycle %d \n",i+1);
        memset(calloc(10*mb, 1), 0, 10*mb);
        sleep(1);
    }
    return 0;
}
// "wmstat" is a tool to collect and report data about 
// the systems memory, swap. processor resource utilization
// in real time.


// "si" and "so" fields indicate the systems physical memory
// is full so swap file is being used.
// we use just virtual memory, never swap to disk and it supposed to be 0.
// So that we never switch to the physical memory 
// si and so fields never change(they will stay zeros),
 
