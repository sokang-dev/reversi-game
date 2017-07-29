#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int x, y, z;
	printf("Enter three numbers: ");
	scanf("%d %d %d", &x, &y, &z);
	printf("The sum of %d, %d, and %d, is: %d\n", x, y, z, x+y+z);
	return EXIT_SUCCESS;
}


