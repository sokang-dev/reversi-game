#ifndef GAME_H
#define GAME_H

#include "gameboard.h"

#define UNDERLINE1 for(i=0; i<10; i++) printf("--------"); printf("\n");
#define UNDERLINE2 for(i=0; i<10; i++) printf("========"); printf("\n");

#define BORDER_WIDTH for(i=0; i<28; i++) printf("*");
#define BORDER_HEIGHT for(i=0; i<15; i++) printf("*"); printf("\n");

/**
 * All directions pieces can be captured in.
 * 
 * Note you are NOT required to use this enum if you don't want to.
 */
typedef enum direction
{
    NORTH_WEST, NORTH, NORTH_EAST, WEST, CENTRE, EAST, SOUTH_WEST, SOUTH, SOUTH_EAST
} Direction;

Player player1, player2;
Player *temp;
Cell board[BOARD_HEIGHT][BOARD_WIDTH];
unsigned redCounter, cyanCounter;
Boolean finished, valid;
char coordinate[10];
unsigned x, y, k, l;
Direction direction;
int i, j;


Player * playGame(Player * first, Player * second);
Boolean makeMove(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]);
Boolean applyMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token);
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token);
void swapPlayers(Player ** first, Player ** second);
void playerDetails(Player *first, Player *second);
void moveValidation(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token);

#endif
