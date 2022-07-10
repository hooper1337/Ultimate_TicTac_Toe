#include "game.h"
#include "utils.h"

void initGame(Game* game){
    game->tie = 0;
    game->win = 0;
    game->player = 'A';
    game->winboard = createBoard(3,3);
}

char changePlayer(char player){
    char aux;
    if(player == 'A')
        aux = 'B';
    else
        aux = 'A';
    return (aux);
}