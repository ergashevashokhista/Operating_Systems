#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * show(void*u)
{
    printf("Thread is created \n");
}
int main()
{
    //int n = 0;
    pthread_t tid;
    //scanf("Enter the number n: %d", n);
    for (int i = 0; i < 3; ++i) {

        pthread_create(&tid, NULL, &show, NULL);
        printf("Thread  number : %d\n", i);
    }
    pthread_join(tid, NULL);
   return 0;
 }