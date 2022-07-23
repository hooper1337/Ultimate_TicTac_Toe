#ifndef ULTIMATE_TICTAC_TOE_UI_H
#define ULTIMATE_TICTAC_TOE_UI_H
#include "boards.h"
#include "game.h"
#include "plays.h"

void showBoards(Boards* boards, Game* game);
void startInterface(Boards* boards, Game* game, Plays* plays);
void playMenu(Boards* boards, Game* game, Plays* plays);


#endif //ULTIMATE_TICTAC_TOE_UI_H
