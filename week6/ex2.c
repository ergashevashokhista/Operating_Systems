#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main (void) {
    char* string = "Hello";
    char buf[1024];
    int fds[2];
    pipe(fds);
    printf("buf content before: %s\n", buf);
    pid_t pid;
    pid = fork();
    if (pid > 0) {
        close(fds[0]);
        write(fds[1], string, 6);
        exit(EXIT_SUCCESS);
    } else if (pid == 0)
    {   close(fds[1]);
        read(fds[0], buf, 6);
        printf("buf content after: %s\n", buf);
        exit(EXIT_SUCCESS);
    } else 
    {
        printf("Error: Child process could not be created\n");
    }
    return 0;
    }