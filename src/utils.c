#include "utils.h"
void freeWinBoard(Game* game){
    for(int i=0; i<3; i++)
        free(game->winboard[i]);
    free(game->winboard);
}

void freeList(struct Play* play){
    struct Play* tmp;
    while(play != NULL){
        tmp = play;
        play = tmp->nextplay;
        free(tmp);
    }
}

void freeBoards(Boards* boards){
    for(int k=0; k<9; k++){
        for(int i=0; i<3; i++)
            free(boards[k].board[i]);
        free(boards[k].board);
    }
    free(boards);
}

void freeAll(Boards* boards, Game* game, struct Play* play){
    freeWinBoard(game);
    freeList(play);
    freeBoards(boards);
}