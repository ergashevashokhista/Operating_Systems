
//  Created by Shokhista Ergasheva on 25.08.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h> //needed for almost all C program. Helps to get and print the data
#include <limits.h> //limits.h contains a macro INT_MAX which provides us the maximum value for an integer
#include <float.h> //contains FLT_MAX and DBL_MAX

int main(void) //the only function written by the programmer
{
	int a = INT_MAX; /* add variables declaration and assignment statements*/
	float b = FLT_MAX;
	double c = DBL_MAX;
	
	//add printf statements for size of data types and to print maximum values
	//sizeof() gives also integer value, format specifier for sizeof is %lu - unsigned integer
	//NOTE: to have portable code, better to use %zu on compilers C99 and forward standards
	printf("Size of a = %lu\nSize of b = %lu\nSize of c = %lu\n", sizeof(a), sizeof(b), sizeof(c));
	printf("INT_MAX = %d\nFLT_MAX = %.2f\nDBL_MAX = %lf\n",a, b, c );
	

	return 0;
}
