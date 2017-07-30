#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("*%s*\n*%20s*\n*%20.4s*\n*%.4s*\n*%-s*\n*%-20s*\n*%-20.4s*\n*%-.4s*\n",
	"Hello World", "Hello World", "Hello World", "Hello World", "Hello World", 
	"Hello World", "Hello World", "Hello World");

	return EXIT_SUCCESS;
}

