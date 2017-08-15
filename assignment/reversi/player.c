#include "player.h"

/**
 * These two functions initialise the player structure at the beginning of the
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the initFirstPlayer()
 * function you should then select a color at random for this player using the
 * rand() function. This token should be assigned to the first player's token.
 * In initSecondPlayer() you should just test the value of token and assign the
 * opposite color to the second player.
 * 
 * Note that an empty name is not valid and the user should be re-prompted.
 **/
void initFirstPlayer(Player * player)
{
	player->score = 2;
	
	/* source code taken and modified from kjfletch from
	 * kjfletch on stackoverflow website
	 * https://stackoverflow.com/questions/1108780/why-do-i-always-get-the-same-sequence-of-random-numbers-with-rand
	 */
	srand(time(NULL));
	if(rand() % 2 + 1 == 1)
		player->token = RED;
	else
		player->token = CYAN;
	
	while(TRUE)
	{
		printf("\nPlease enter the first player's name: ");
		fgets(player->name, sizeof(player->name), stdin);
		
		/*if(fgets(player->name, sizeof(player->name), stdin) == NULL)
			printf("Player's name cannot be emptied!");*/
		
		if(player->name[strlen(player->name) - 1] != '\n')
		{
			printf("Input was too long, try again.\n");
			readRestOfLine();
		}
		else
		{
			player->name[strlen(player->name) - 1] = '\0';
			break;
		}
	}
}

void initSecondPlayer(Player * player, Cell token)
{
	player->score = 2;
	if(token == RED)
		player->token = CYAN;
	else
		player->token = RED;
	
	while(TRUE)
	{
		printf("Please enter the first player's name: ");
		fgets(player->name, sizeof(player->name), stdin);
		
		/*if(fgets(player->name, sizeof(player->name), stdin) == NULL)
			printf("Player's name cannot be emptied!");*/
		
		if(player->name[strlen(player->name) - 1] != '\n')
		{
			printf("Input was too long, try again.\n");
			readRestOfLine();
		}
		else
		{
			player->name[strlen(player->name) - 1] = '\0';
			break;
		}
	}
}

	







