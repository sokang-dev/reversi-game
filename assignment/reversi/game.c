#include "game.h"

/**
 * The heart of the game itself. You should do ALL initialisation required
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random
 * number generator, etc...
 * 
 * Next, you should set the initial player - the initial player is the player
 * whose token was set to RED.
 * 
 * Next you will need to manage the game loop in here. In each loop of the
 * game, you should display the game board, including player scores
 * display whose turn it is, etc... in the format from the assignment
 * specification. Finally at the end of each turn you will calculate the score
 * for each player and store it and then you will need to swap the current player
 * and other player using the swapPlayer() function.
 * 
 * A game will end when either player presses enter on a newline.
 * 
 * When you detect a request to end the game you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score - if its a draw return NULL.
 **/
Player * playGame(Player * first, Player * second)
{
	initFirstPlayer(first);
	initSecondPlayer(second, first->token);
	initBoard(board);
	
	do
	{
		playerDetails(first, second);
		displayBoard(board, first, second);
		makeMove(first, board);
		swapPlayers(&first, &second);
	} while(finished);
	
	
	
    return NULL;
}

/**
 * Prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by
 * surrounding a sequence of one or more enemy pieces with two pieces of our
 * own: one being the new piece to be placed and the other a piece already
 * on the board. This function then validates that a valid move has been entered
 * and calls the applyMove() function to do the actual work of capturing pieces.
 * 
 * FALSE is returned if an empty line is entered (to end the game), otherwise
 * the prompt will continue until a valid move is entered and then TRUE is returned.
 **/
Boolean makeMove(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    if(player1.token == RED)
		*player = player1;
	else
		*player = player2;
	
	printf("It is %s's turn.\n", player->name);
	printf("Please enter x and y coordinates separated by a comma: ");
	fgets(coordinate, sizeof(coordinate), stdin);
	
	if(coordinate[0] == '\n')
	{
		finished = FALSE;
		return FALSE;
	}
	else
	{	
		sscanf(coordinate, "%u,%u", &y, &x);
		applyMove(board, x, y, player->token);
		finished = TRUE;
		return TRUE;
	}
	
}

/**
 * Applys the move requested by the user to the game board.
 * 
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured.
 * 
 * If there are no pieces that can be captured in any direction it is an
 * invalid move and FALSE is returned (with no changes to the board occurring),
 * otherwise TRUE is returned, the pieces are captured and the token is
 * placed on the board.
 **/
Boolean applyMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token)
{
	if(token == RED)		
		board[y-1][x-1] = RED;
	else
		board[y-1][x-1] = CYAN;
	
    return FALSE;
}

/**
 * Simply counts how many locations contain the token specified on board.
 **/
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token)
{
    return 0;
}

/**
 * Swaps the two player pointers so that first points to second and vice versa.
 **/
void swapPlayers(Player ** first, Player ** second)
{
	*first = *second;
	*second = *first;
}




void playerDetails(Player * first, Player * second)
{
    printf("\n");
    BORDER_WIDTH;
    printf("  ");
    BORDER_WIDTH;
    printf("\n");
    printf("%-4s%s%4s", "*", "Player One's Details", "*");
    printf("  %-4s%s%5s", "*", "Player Two's Details", "*\n");
    BORDER_WIDTH;
    printf("  ");
    BORDER_WIDTH;
    printf("\n");
    
    
    //printf("*-------------------------*\n");
    
    
    
    printf("*Name:  %-19s*", first->name);
    printf("  *Name:  %-19s*\n", second->name);
    
    printf("*%s%-19d*", "Score: ", first->score);
    printf("  *%s%-19d*\n", "Score: ", second->score);
    
    printf("*%s", "Token: ");
    if(player1.token == RED)
		printf("%s%s%-22s*", COLOR_RED, "O", COLOR_RESET);
	else
		printf("%s%s%-22s*", COLOR_CYAN, "O", COLOR_RESET);
    
    printf("  *%s", "Token: ");
    if(player1.token == CYAN)
		printf("%s%s%-22s*\n", COLOR_RED, "O", COLOR_RESET);
	else
		printf("%s%s%-22s*\n", COLOR_CYAN, "O", COLOR_RESET);
    BORDER_WIDTH;
    printf("  ");
    BORDER_WIDTH;
    printf("\n\n");
    
    
    
    
    
    
    /*
	printf("\n");
	UNDERLINE2;
	printf("Player One's Details\n");
	printf("--------------------\n");
	printf("Name: %-25s", first->name);
	printf("%s%d", "Score: ", first->score);
	printf("%20s", "Token: ");
	if(player1.token == RED)
		printf("%s%s%s\n", COLOR_RED, "O", COLOR_RESET);
	else
		printf("%s%s%s\n", COLOR_CYAN, "O", COLOR_RESET);
	UNDERLINE1;
	
	printf("Player Two's Details\n");
	printf("--------------------\n");
	printf("Name: %-25s", second->name);
	printf("%s%d", "Score: ", second->score);
	printf("%20s", "Token: ");
	if(player1.token == CYAN)
		printf("%s%s%s\n", COLOR_RED, "O", COLOR_RESET);
	else
		printf("%s%s%s\n", COLOR_CYAN, "O", COLOR_RESET);
	UNDERLINE2;
	printf("\n");
    */
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

