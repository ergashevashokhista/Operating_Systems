#include <stdio.h> 
#include <time.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
extern int errno;

int main() 
{ 
    struct rusage usage;
    int mb = 1024*1024;
    for (int i = 0; i < 10; i++) { 
        memset(calloc(10*mb, 1), 1, 10*mb);
        if (getrusage(RUSAGE_SELF, &usage)) {
            printf("Error %d\n", errno);
        }
        printf("ru_maxrss = %ld\n",(usage).ru_maxrss);
        delay(1); 
    } 
   
    return 0; 
}
// "errno" is the header file that defines int variable errno
// set by system calls and some library functions so that
// when error appears to indicate what went wrong.

// "getrusage "- gets resource usage(as well as memory usage)
// it can get resource usage of the calling process, child process
// calling process and threads.
// "get maximum resident set size" - because we wanna know 
// how much memory are we using after allocation of memory
// we wanna know how much memory belongs(currently resident) to the proces


// The "ru_maxrs"s field of struct rusage is the "high water mark" for the resident set size.
//  It indicates the peak RAM use for this process (when using RUSAGE_SELF).