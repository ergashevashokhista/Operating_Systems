#include <stdio.h> 
#include <time.h> 
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

  
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
  
// Driver code to test above function 
int main() 
{ 
    int* ptr; 
    int i; 
    struct rusage usage;
    int n = 10; 
    printf("Enter number of elements: %d\n", n); 
    for (i = 0; i < n; i++) { 
        ptr = (int*)calloc(i, 1000000*sizeof(char)); 
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage = %ld\n",usage.ru_maxrss);
        delay(1); 
        printf("%d seconds have passed\n", i + 1); 
        printf("value storred in ptr block  : %d \n", ptr[i]); 
    }        
    return 0; 
}