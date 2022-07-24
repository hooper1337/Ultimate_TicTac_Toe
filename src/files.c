#include "files.h"
void saveGame(Boards* boards, Game* game, struct Play* plays){
    FILE *f;
    f = fopen("data.dat", "wb");
    if(f == NULL){
        printf("\nError opening the desired file.\n");
        return;
    }
    fwrite(&game->nPlays, sizeof (int), 1, f);
    while(plays != NULL){
        fwrite(&plays->player, sizeof(char), 1,f);
        fwrite(&plays->board, sizeof(int), 1 ,f);
        fwrite(&plays->row, sizeof(int), 1 ,f);
        fwrite(&plays->column, sizeof(int), 1, f);
        plays = plays->nextplay;
    }
}

void loadGame(Boards* boards, Game* game, struct Play** plays){
    FILE *f;
    int count = 0;
    char player;
    int board;
    int row;
    int column;
    f = fopen("data.dat", "rb");
    if(f == NULL){
        printf("\nError opening the desired file\n");
        return;
    }
    fread(&game->nPlays, sizeof(int), 1,f);
    while(count < game->nPlays){
        fread(&player, sizeof(char), 1,f);
        fread(&board, sizeof(int), 1, f);
        fread(&row, sizeof(int), 1, f);
        fread(&column, sizeof(int), 1, f);
        placePiece(boards[board].board,row,column,player);
        insertNode(plays, row, column, player, board);
        verifyBoardWin(boards[board].board, board, player, game->winboard, boards);
        count++;
    }
}