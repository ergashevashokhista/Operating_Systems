#include <stdio.h>

void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a, b;
	printf("Enter numbers to swap: \n");
	scanf("%d %d", &a, &b);

	swap(&a, &b);

	printf("\nSwapped numbers: ");
	printf("\na = %d", a);
	printf("\nb = %d\n", b);
}