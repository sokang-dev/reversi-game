//Testing

#include "reversi.h"


int main()
{	
	do
	{
		menu();
		fgets(&choice, 5, stdin);
		switch(choice)
		{ 
			case '1':
				playGame(&player1, &player2);
				break;
			case '2':
				printf("\nGoodbye.\n\n");
				return EXIT_SUCCESS;
				break;
		}
	} while(!finished);
	
	return EXIT_SUCCESS;
}


void menu()
{
	printf("\nWelcome to Reversi!\n");
	DOUBLE_UNDERLINE;
	printf("Select an option:\n");
	printf("1. Play a game\n");
	printf("2. Quit the program\n");
	printf("Please enter your choice: ");
}
