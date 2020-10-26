#include <stdio.h>
#include <stdlib.h> //is used for memeory allocation, process control, conversions and so on

void print_triangle(int n);

int main(int argc, char *argv[]){ //argc - argument count, argv- argument value array of char pointers
	int n;
	if(argc<2){
		printf("Missing paramter value\n");
		return EXIT_FAILURE;
	}
	if (sscanf(argv[1], "%d", &n)!=1){
		printf("Wrong paramter value\n");
		return EXIT_FAILURE;
	}
	print_triangle(n);
	return EXIT_SUCCESS;
}
void print_triangle(int n){
	for (int i = 0, k = 1; i <= n-1; i++, k+=2)
	{
		for (int j = 2*n-i-1; j>0; j--)
		{
			printf(" ");
		}
		for (int l = 0; l < k; l++)
		{
			printf("*");
		}
		printf("\n");
	}	
}