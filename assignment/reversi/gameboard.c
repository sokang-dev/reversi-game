#include "gameboard.h"

/**
 * Initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens.
 **/
void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			board[i][j] = BLANK;
		}
	}
	
	board[3][3] = RED;
	board[4][4] = RED;
	board[3][4] = CYAN;
	board[4][3] = CYAN;
	//board[0][4] = RED;
}

/**
 * Display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification.
 **/
void displayBoard(
    Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * first, Player * second)
{
	char row[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	printf("%17s%4s%4s%4s%4s%4s%4s%5s", "1", "2", "3", "4", "5", "6", "7", "8\n");
	SPACE;
    BOARD_BORDER2;
	
	for(int i=0; i<8; i++)
	{
		printf("%13d%2s", row[i], "|");
		
		for(int j=0; j<8; j++)
		{			
			switch(board[i][j])
			{
				case BLANK:
				printf("%2s%2s", "", "|");
					break;
				case RED:
					printf("%s%2s%s%2s", COLOR_RED, "O", COLOR_RESET, "|");
					break;
				case CYAN:
					printf("%s%2s%s%2s", COLOR_CYAN, "O", COLOR_RESET, "|");
					break;
			}
		}
				
		printf("\n");
		
		if(i==7)
		{
            SPACE;
			BOARD_BORDER2;
			break;
		}
		
		SPACE;
        BOARD_BORDER1;
	}

}
