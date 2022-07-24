#ifndef ULTIMATE_TICTAC_TOE_UTILS_H
#define ULTIMATE_TICTAC_TOE_UTILS_H
#include "boards.h"
#include "game.h"
void freeBoards(Boards* boards);
void freeWinBoard(Game* game);
void freeList(struct Play* play);
void freeAll(Boards* boards, Game* game, struct Play* play);
#endif //ULTIMATE_TICTAC_TOE_UTILS_H
