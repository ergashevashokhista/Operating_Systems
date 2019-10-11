#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <zconf.h>
#include <stdlib.h>
#define MAX 256

int main(void){
    char* s = (char*)malloc(sizeof(char)*MAX);
    int exit = 0;
    while (exit==0){
        scanf("%s", s);
        if(*s=='e'){
            exit =1;
        }
        else{
            system(s);
        }
    }
}