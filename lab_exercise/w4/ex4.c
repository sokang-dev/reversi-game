#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	void funct(int *p, int num);
	int a[5] = {10, 20, 30, 40, 50};
	funct(a+2, 2);
	return EXIT_SUCCESS;
}

void funct(int *p, int num)
{
	int i, sum = 0;
	for (i = 1; i < num; ++i)
		sum += *(p + i);

	printf("sum=%d\n", sum);
	return;
}
