#include <stdio.h>

int add(int num1, int num2)
{	

	return num1+num2;	
}

int main()
{
	int num1=0;
	int num2=0;
	int (*function)(int, int) = add;
	scanf("%d %d", &num1,&num2);
	int c = (*function)(num1, num2);
	printf("%d\n", c);
}
