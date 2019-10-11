#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <signal.h> /*for signal() and raise()*/

void hello(int signum){
  printf("It terminated\n");
}

int main(){
    int i = 0;
    
 
  signal(SIGTERM, hello);
    int pid;
    pid = fork();
    //printf("pid= %d\n", pid);
    //sleep(10);
    if(pid == 0){
             for(i=1; i<=10; i++) {
            printf("%d I'm alive\n ", i);
           /** put process to sleep for 1 sec */
            sleep(1);
        }
        signal(SIGTERM, hello);
        raise(SIGTERM);
    }
       
} 