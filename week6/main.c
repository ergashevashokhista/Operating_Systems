#include <stdlib.h>
#include <stdio.h>

void main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = i;
    }

    
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", *(arr + i));
    }
    free(arr);
}