#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int a=1;
	int b=9;

	for(int i=1; i<=10; i++)
	{
		for(int j=1; j<=b; j++)
		{
			printf(" ");
		}
		
		for(int j=1; j<=a; j++)
		{
			printf("*");
		}
	
		a++;
		b--;
		printf("\n");
	}

	return EXIT_SUCCESS;
}

