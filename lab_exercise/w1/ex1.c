#include <stdlib.h>
#include <stdio.h>

/** Computing the distance of a marathon in kilometres **/

int main(void)
{
	int miles, yards;
	float kilometres;
	
	yards = 26;
	miles = 385;

	kilometres = 1.609 * (miles + yards / 1760); 
	
	printf("%d miles, %d yards = %.2f kilometres\n", miles, yards, kilometres);

	return EXIT_SUCCESS;
}
