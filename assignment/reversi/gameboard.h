#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "player.h"

#define BOARD_HEIGHT 8
#define BOARD_WIDTH BOARD_HEIGHT
#define BOARD_BORDER1 for(int i=0; i<6; i++) printf("------"); printf("\n");
#define BOARD_BORDER2 for(int i=0; i<6; i++) printf("======"); printf("\n");

void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH]);
void displayBoard(
    Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * first, Player * second);

Cell board[BOARD_HEIGHT][BOARD_WIDTH];

#endif
