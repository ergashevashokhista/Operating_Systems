#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE(20);

void buble_sort(int arr[], int arr_len);
void swap(int *a, int *b);
void print_array(int arr[], int arr_size);

int main(void){
	int arr[]={3, 0, 1, 8, 7, 2, 5, 4, 6, 9};
	buble_sort(arr, ARR_SIZE(arr));
	print_array(arr, ARR_SIZE(arr));
	return EXIT_SUCCESS;
}

void buble_sort(int arr[], int arr_len){ 
	int i, j;

	for (int i = 0; i < arr_len; j++)
	{
		for (int j = 0; j < arr_len; j++)
		{
			if (arr[j]>arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void print_array(int arr[], int arr_size){
	int i=0;

	for (int i = 0; i < arr_size; i++)
	{
		printf("%d\n", arr[i]);
	}
}