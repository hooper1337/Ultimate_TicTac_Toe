#ifndef ULTIMATE_TICTAC_TOE_BOARDS_H
#define ULTIMATE_TICTAC_TOE_BOARDS_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Board{
    char** board;
    int won;
}Boards;

Boards* initBoards();
char** createBoard(int rows, int columns);
void initBoard(char** board);

#endif //ULTIMATE_TICTAC_TOE_BOARDS_H
