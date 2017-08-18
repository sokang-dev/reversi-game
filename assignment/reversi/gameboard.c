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
	for(d=0; d<8; d++)
	{
		for(e=0; e<8; e++)
		{
			board[d][e] = BLANK;
		}
	}
	
	board[3][3] = RED;
	board[4][4] = RED;
	board[3][4] = CYAN;
	board[4][3] = CYAN;
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
	space();
    border2();
    
    /*SPACE;
    BOARD_BORDER2;*/
	
	for(i=0; i<8; i++)
	{
		printf("%13d%2s", row[i], "|");
		
		for(j=0; j<8; j++)
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
            space();
            border2();
            
            /*SPACE;
			BOARD_BORDER2;*/
			break;
		}
		
		space();
        border1();
        
        /*SPACE;
        BOARD_BORDER1;*/
	}
}

void border1()
{
    for(a=0; a<6; a++) 
        printf("------"); 
    printf("\n");
}

void border2()
{
    for(b=0; b<6; b++) 
        printf("======"); 
    printf("\n");
}

void space()
{
    for(c=0; c<11; c++) 
        printf(" ");
}
