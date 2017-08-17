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
	initFirstPlayer(&player1);
	initSecondPlayer(&player2, player1.token);
	initBoard(board);
	
	do
	{
        gameScore(board, player1.token);
		playerDetails(&player1, &player2);
		displayBoard(board, &player1, &player2);
		makeMove(first, board);
		swapPlayers(&first, &second);
	} while(finished);
	
	if(player1.score > player2.score)
    {
        printf("\n%s wins!\n", player1.name);
        return 0;
    }
    else if(player2.score > player1.score)
    {
        printf("\n%s wins!\n", player2.name);
        return 0;
    }
	else
    {
        printf("\nThis game ends with a draw!\n");
        return NULL;
    }   
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
    if(player->token == RED)
		player = &player1;
	else
		player = &player2;
	
	printf("\nIt is %s's turn.\n", player->name);
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
		applyMove(board, y, x, player->token);
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
	direction = 0;
	
	for(int i=2; i>=0; i--)
	{
		
		for(int j=2; j>=0; j--)
		{
			
			if(board[x-1][y-1] == BLANK)
			{
				
				if(token == RED && (x-i) >=0 && (y-j) >= 0)
				{	
				
					
					if(board[x-i][y-j] != CYAN)
					{
						direction++;
						printf("\n6");
						continue;
					}
					
					else
					{
						switch(direction)
						{
							case 0:
								k = -1;
								l = -1;
								break;
							case 1:
								k = -1;
								l = 0;
								break;
							case 2:
								k = -1;
								l = 1;
								break;
							case 3:
								k = 0;
								l = -1;
								break;
							case 4:
								k = 0;
								l = 0;
								break;
							case 5:
								k = 0;
								l = 1;
								break;
							case 6:
								k = 1;
								l = -1;
								break;
							case 7:
								k = 1;
								l = 0;
								break;
							case 8:
								k = 1;
								l = 1;
								break;
						}
						
						while((x-i+k) >= 0 && (x-i+k) < 8 && (y-j+l) >=0 && (y-j+l) < 8)
						{
							if(board[x-i+k][y-j+l] == CYAN)
							{
								
								switch(k)
								{
									case -1:
										k--;
										break;
									case 0:
										break;
									case 1:
										k++;
										break;
								}
								
								switch(l)
								{
									case -1:
										l--;
										break;
									case 0:
										break;
									case 1:
										l++;
										break;
								}
							}
							else if(board[x-i+k][y-j+l] == RED)
							{
							
								board[x-1][y-1] = RED;
								board[x-i][y-j] = RED;
								break;
							}
							else
							{
								direction++;
								printf("\nInvalid Move ");
								break;
							}
						}
					}
				}
				
				else if(token == CYAN && (x-i) >=0 && (y-j) >= 0)
				{
				
				
					
					
					if(board[x-i][y-j] != RED)
					{
						direction++;
					
						continue;
					}
					
					else
					{
						switch(direction)
						{
							case 0:
								k = -1;
								l = -1;
								break;
							case 1:
								k = -1;
								l = 0;
								break;
							case 2:
								k = -1;
								l = 1;
								break;
							case 3:
								k = 0;
								l = -1;
								break;
							case 4:
								k = 0;
								l = 0;
								break;
							case 5:
								k = 0;
								l = 1;
								break;
							case 6:
								k = 1;
								l = -1;
								break;
							case 7:
								k = 1;
								l = 0;
								break;
							case 8:
								k = 1;
								l = 1;
								break;
						}
						
						while((x-i+k) >= 0 && (x-i+k) < 8 && (y-j+l) >=0 && (y-j+l) < 8)
						{
							if(board[x-i+k][y-j+l] == RED)
							{			
								switch(k)
								{
									case -1:
										k--;
										break;
									case 0:
										break;
									case 1:
										k++;
										break;
								}
								
								switch(l)
								{
									case -1:
										l--;
										break;
									case 0:
										break;
									case 1:
										l++;
										break;
								}
							}
							else if(board[x-i+k][y-j+l] == CYAN)
							{
							
								board[x-1][y-1] = CYAN;
								board[x-i][y-j] = CYAN;
								break;
							}
							else
							{
								direction++;
								printf("\nInvalid Move");
								break;
							}
						}
					}
				}
			}
		}
	}
	//board[x-1][y-1] = RED;
	
	return FALSE;
}

void moveValidation(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token)
{
	
}				





/**
 * Simply counts how many locations contain the token specified on board.
 **/
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token)
{
    redCounter = 0;
    cyanCounter = 0;
    
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            switch(board[i][j])
            {
                case RED:
                    redCounter++;                    
                    if(token == RED)
                        player1.score = redCounter;
                    else player2.score = redCounter;
                    break;
                case CYAN:
                    cyanCounter++;
                    if(token == CYAN)
                        player1.score = cyanCounter;
                    else player2.score = cyanCounter;
                    break;
                default:
                    break;
            }
        }
    }
      
    return 0;
}


/**
 * Swaps the two player pointers so that first points to second and vice versa.
 **/
void swapPlayers(Player ** first, Player ** second)
{
	temp = *first;
    *first = *second;
	*second = temp;
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
        
    if(player1.token == RED)
    {
        printf("*Name:  %s%-19s%s*", COLOR_RED, first->name, COLOR_RESET);
        printf("  *Name:  %s%-19s%s*\n", COLOR_CYAN, second->name, COLOR_RESET);
        
        printf("*%s%s%-19d%s*", "Score: ", COLOR_RED, first->score, COLOR_RESET);
        printf("  *%s%s%-19d%s*\n", "Score: ", COLOR_CYAN, second->score, COLOR_RESET);
        
        printf("*%s", "Token: ");
        printf("%s%s%-22s*", COLOR_RED, "O", COLOR_RESET);
        
        printf("  *%s", "Token: ");
        printf("%s%s%-22s*\n", COLOR_CYAN, "O", COLOR_RESET);       
    }
    else
    {
        printf("*Name:  %s%-19s%s*", COLOR_CYAN, first->name, COLOR_RESET);
        printf("  *Name:  %s%-19s%s*\n", COLOR_RED, second->name, COLOR_RESET);
        
        printf("*%s%s%-19d%s*", "Score: ", COLOR_CYAN, first->score, COLOR_RESET);
        printf("  *%s%s%-19d%s*\n", "Score: ", COLOR_RED, second->score, COLOR_RESET);
        
        printf("*%s", "Token: ");
        printf("%s%s%-22s*", COLOR_CYAN, "O", COLOR_RESET);
        
        printf("  *%s", "Token: ");
        printf("%s%s%-22s*\n", COLOR_RED, "O", COLOR_RESET); 
    }
    
    BORDER_WIDTH;
    printf("  ");
    BORDER_WIDTH;
    printf("\n\n");
    
    /*printf("*Name:  %-19s*", first->name);
    printf("  *Name:  %-19s*\n", second->name);
    
    printf("*%s%-19d*", "Score: ", first->score);
   
    
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
    */
}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

