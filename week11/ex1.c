#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main(){

    char* text = "This is a nice day";

    size_t size = strlen(text) + 1;

    // resize

    FILE *fp = fopen("ex1.txt", "w");

    ftruncate(fileno(fp), size - 1);    //fileno gets file descriptor of a file from the stream. 
                                        //-1 is in order not to take into account terminator character
    fclose(fp);

    // mapping

    int file = open("ex1.txt", O_RDWR);

    char *map;
    map = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);  // 
    map[0] = 'J';

    for (size_t i = 0; i < size; i++)
    {
        map[i] = text[i];
    }

    return 0;
}