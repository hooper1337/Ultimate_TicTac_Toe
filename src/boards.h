#ifndef ULTIMATE_TICTAC_TOE_BOARDS_H
#define ULTIMATE_TICTAC_TOE_BOARDS_H
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
typedef struct Board{
    char** board;
}Boards;

Boards* initBoards();
#endif //ULTIMATE_TICTAC_TOE_BOARDS_H
