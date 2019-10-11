#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
// function declaration 
void sigterm(); 

  
// driver code 
void main() 
{ 
    int pid; 
  
    /* get child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGTERM, sigterm); 
        for (;;) {
              printf("i AM ALIVE\n");
        };/* loop for ever */
    } 
  
    else /* parent */
    { /* pid hold id of child */
  
        sleep(1); /* pause for 3 secs */
        printf("\nPARENT: sending SIGTERM\n\n"); 
        kill(pid, SIGTERM); 

    } 
} 
  
// sighup() function definition 
void sigterm() 
  
{ 
    signal(SIGTERM, sigterm); /* reset signal */
    printf("CHILD: I have received a SIGTERM\n"); 
    exit(0);
} 
