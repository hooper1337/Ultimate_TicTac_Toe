#include <stdio.h>
#include "boards.h"
#include "plays.h"
#include "game.h"
#include "ui.h"

int main(){
    Game game;
    Plays* plays = NULL;
    Boards* boards = initBoards();
    initGame(&game);
    startInterface(boards, &game, plays);
    return 1;
}