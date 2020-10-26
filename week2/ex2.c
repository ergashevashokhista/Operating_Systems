#include <stdio.h>
#include <string.h> 

//#define directive allows the definition of macros within your source code
//macro definitions allow constant values to be declared for usage throughout the code 

#define MAX_LEN 40 

int main(void)
{
	char s[MAX_LEN]; 	//declare a variable to store a string and get it from console
	int i;
	
	printf("Enter a string: ");
	fgets(s, MAX_LEN, stdin);   //specify the max length that it should take, and it gets the whole line from the stdin
	//scanf("%s", s); 			
	printf("The reverse of the string is: ");

	for(i=strlen(s)-1; i>=0; i--) //go through char by char and print every char
	{
		if(s[i] == '\n'){
			continue;
		}else{
			putchar(s[i]);
		}
	}
	printf("\n");
	return 0;
}
