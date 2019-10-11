#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* cool_realloc(void* ptr, int size)
{

        if(ptr == NULL)
                return malloc(size);

        if(size == 0)
        {
                free(ptr);
                return NULL;
        }

        void * new_boi = malloc(size);
        //copying content of ptr to new_boi
        memcpy(new_boi, ptr, size);
        free(ptr);

        return new_boi;

}

int main(int argc, char const *argv[]) {

        //array of size 5 ints
        int *arr = (int*) calloc(5, sizeof(int));

        //filling with numbers from 0 to 4
        for(int i = 0; i < 5; i++)
        {
                arr[i] = i;
        }

        //calling CoOl_reAlLoC
        arr = (int*) cool_realloc(arr, sizeof(int) * 7);

        for(int i = 0; i < 7; i++)
                printf("%d ", arr[i]);

        return 0;
}