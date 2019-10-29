#include <fcntl.h>
#include <unistd.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
//Line buffering - characters are transmitted to the system as
//a block when a new-line character is encountered. Line buffering 
//is meaningful only for text streams and UNIX file system files.

int main(void) {
    FILE *file;     //Initialize the file pointer

    file = freopen("ex2.txt", "w", stdout);     //reopen the file for write operation

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");
    sleep(1);

    fclose(file);       //close the file

    return 0;
}
