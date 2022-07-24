#include <stdio.h>
#include "boards.h"
#include "game.h"
#include "ui.h"

int main(){
    Game game = {0};
    struct Play* plays = NULL;
    Boards* boards = initBoards();
    initGame(&game);
    startInterface(boards, &game, &plays);
    return 1;
}