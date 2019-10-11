#include  <stdio.h>
#include  <signal.h>
#include  <stdlib.h>
#include <sys/types.h>

void sig_handler(int signo)
{
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGKILL)
        printf("received SIGKILL\n");
    else if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}

int  main(void)
{
    signal(SIGINT, sig_handler);
    while (1)
        pause();
    return 0;
}

void  sig_handler(int signo)
{
    char  c;
    pid_t pid;
    pid = fork();
    signal(signo, SIG_IGN);
    printf("did you hit Ctrl-C?\n"
           "Do you really want to quit? [y/n] ");
    c = getchar();
    if (c == 'y' || c == 'Y')
    kill(pid, SIGSTOP);
    //printf("the process is killed");
    else
        signal(SIGINT, sig_handler);
    getchar(); // Get new line character
    exit(0);
} 