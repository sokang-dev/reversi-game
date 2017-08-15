#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, n;

   
   n = 20;
   
   /* Intializes random number generator */
   srand(time(NULL));

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < 20 ; i++ ) 
   {
      printf("%d \n", (rand() % 2) + 1);
   }
   
   return(0);
}