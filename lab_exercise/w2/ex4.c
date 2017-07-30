#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char c1, c2, c3;
	int k;
	float x;
	double y;

	while(1)
	{
		printf("\n%s\n%s\n%s\n%s", "input the following: three characters,",
		" an int,", " a float,", " and a double: ");

		if(scanf(" %c%c%c%d%f%lf", &c1, &c2, &c3, &k, &x, &y) != 6)
		{
			printf("Invalid or incomplete input\n\n");
			break;
		}
	
		printf("\nHere is the data that you typed in: \n");
		printf("%3c%3c%3c%5d%17e%17e\n\n", c1, c2, c3, k, x, y);
	}

	return EXIT_SUCCESS;
}
