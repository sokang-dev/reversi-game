#ifndef GAME_H
#define GAME_H

#include "gameboard.h"

#define UNDERLINE1 for(int i=0; i<10; i++) printf("--------"); printf("\n");
#define UNDERLINE2 for(int i=0; i<10; i++) printf("========"); printf("\n");

/**
 * All directions pieces can be captured in.
 * 
 * Note you are NOT required to use this enum if you don't want to.
 */
typedef enum direction
{
    NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST
} Direction;

Player player1, player2;

Cell board[BOARD_HEIGHT][BOARD_WIDTH];
Boolean finished;
char coordinate[10];
unsigned x, y;

Player * playGame(Player * first, Player * second);
Boolean makeMove(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH]);
Boolean applyMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token);
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token);
void swapPlayers(Player ** first, Player ** second);
void playerDetails(Player *first, Player *second);

#endif
