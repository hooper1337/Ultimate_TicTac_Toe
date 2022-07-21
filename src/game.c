#include "game.h"
#include "boards.h"

void initGame(Game* game){
    game->tie = 0;
    game->win = 0;
    game->player = 'A';
    game->winboard = createBoard(3,3);
    initBoard(game->winboard);
}

char changePlayer(char player){
    char aux;
    if(player == 'A')
        aux = 'B';
    else
        aux = 'A';
    return (aux);
}