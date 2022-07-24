#ifndef ULTIMATE_TICTAC_TOE_UI_H
#define ULTIMATE_TICTAC_TOE_UI_H
#include "game.h"
#include "boards.h"
void showBoards(Boards* boards, Game* game);
void startInterface(Boards* boards, Game* game, struct Play** plays);
void playMenu(Boards* boards, Game* game, struct Play** plays);
#endif //ULTIMATE_TICTAC_TOE_UI_H
