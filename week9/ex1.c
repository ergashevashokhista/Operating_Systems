#include <stdio.h>
#include <stdlib.h>
#define DEFAULT 10
#define NUMBER_BITS 16
/*
	10 hit = 9.000000 miss = 991.000000 ratio = 0.009082
	50 hit = 51.000000 miss = 949.000000 ratio = 0.053741
	100 hit = 94.000000 miss = 906.000000 ratio = 0.103753
*/
typedef struct page
{
	int id;
	unsigned counter : NUMBER_BITS;
} page;

FILE *file;

int main(int argc, char const *argv[])
{
	float hit = 0, miss = 0;
	int num_of_pages = DEFAULT;
	printf("Print the number of pages\n");
	scanf("%d", &num_of_pages);

	file = fopen("input.txt", "r");

	page *pages = calloc(num_of_pages, sizeof(page));

	int cur_page = 0;

	for (int i = 0; i < num_of_pages; i++)
	{
		pages[i].counter = 0;
		pages[i].id = -1;
	}

	while (fscanf(file, "%d", &cur_page) != EOF)
	{
		// printing the current status for each page
		for (int i = 0; i < num_of_pages; i++)
		{
			printf("i = %d id = %d", i, pages[i].id);
			char buffer[64];
			
			snprintf(buffer, sizeof(buffer), "%d", pages[i].counter);
			printf(" %s\n", buffer);
		}
		// candidate means the page index where you can allocate/find the value(cur_page)
		int candidate = -1;
		// least: is trying to identify the lowest counter in case you could match the current page among the existing pages
		int least = pages[0].counter;
		for (int i = 0; i < num_of_pages; i++)
		{
			//This operation is dividing by 2 the counter for the page "i"
			pages[i].counter >>= 1;
			//IF the pages is free and you could find a match yet, then mean the candidate is the current index
			if (pages[i].id == -1 && candidate == -1)
			{
				candidate = i;
			}
			// if you current page mathces with a existing page, then you take the index to add a mark in that page
			if (pages[i].id == cur_page)
			{
				candidate = i;
			}
			//Incomplete step: indentifing the least accessed page.
			if (least > pages[i].counter && candidate == -1)
			{
				least = pages[i].counter;
			}
		}

		//printf("Page candidate number %d\n", candidate);
		//printf("current page number %d\n", cur_page);
		//printf("Page candidate value 1 %d\n", pages[candidate].counter);
		
		// if you found the page then, you will introduce a new mark 
		// this operation works in binary level, since is easier to operate.
		if (pages[candidate].id == cur_page)
		{
			// if you found the page then, you will introduce a new mark 
			// this operation works in binary level, since is easier to operate.
			// ex. counter 0000 1000 0000 0000			
			pages[candidate].counter |= 1 << (NUMBER_BITS - 1);
			// ex. counter after the operation 1000 1000 0000 0000			
			hit++;
		}
		else
		{
			// in case the current page is not in cache
			// then you need to allocate it in a free page or in the least commonly used page
			
			miss++;
			pages[candidate].counter = 0;
			pages[candidate].id = cur_page;
			//and mark in the counter as accessed in the last round
			//1000 0000 0000 0000			
			pages[candidate].counter |= 1 << (NUMBER_BITS - 1);
			
			
		}
		
		printf("Page candidate value 2 %d\n", pages[candidate].counter);
		
		candidate = -1;
		printf("\n");
	}

	printf("hit = %f miss = %f ratio = %f\n", hit, miss, hit / miss);

	return 0;
}