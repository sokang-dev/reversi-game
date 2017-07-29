#include <stdlib.h>
#include <stdio.h>
#define UNDERLINE for(int i=0; i<5; i++) printf("%s", "---------");  printf("\n");

int main(void) {
	
	int num, x;

	printf("Please enter a positive number: ");
	
	if(scanf("%d", &num) != 1) {
		printf("Error: scanf() failed! Program Aborting!\n\n");
		return EXIT_FAILURE;
	}

	printf("\n%-10s%-10s%-8s%-10s%-10s\n", "Number", "Square", "Cube", "Quartic", "Quintic");
	UNDERLINE;

	for(int i=0; i<=num; i++) {
		x=i; printf("%-10d", x);
		x*=i; printf("%-10d", x);
		x*=i; printf("%-10d", x);
		x*=i; printf("%-10d", x);
		x*=i; printf("%-10d", x);
	
		printf("\n");
	}

	UNDERLINE;

	return EXIT_SUCCESS;
}
		
	
