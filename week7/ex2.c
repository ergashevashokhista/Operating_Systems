#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter number of array elements: ");
    scanf("%d", &n);
    int *ptr;
    ptr = malloc(n * sizeof(int));
    if(ptr){
        for(int i=0; i<n; i++){
            ptr[n]=n;
        }
        for(int i=0; i<n; i++){
            printf("ptr[%d]== %d\n", i, i);
        }
    }
    free(ptr);
}