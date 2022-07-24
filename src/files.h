#ifndef ULTIMATE_TICTAC_TOE_FILES_H
#define ULTIMATE_TICTAC_TOE_FILES_H
#include  "boards.h"
#include "game.h"
void saveGame(Boards* boards, Game* game, struct Play* plays);
void loadGame(Boards* boards, Game* game, struct Play** plays);
#endif //ULTIMATE_TICTAC_TOE_FILES_H
