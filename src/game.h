#ifndef ULTIMATE_TICTAC_TOE_GAME_H
#define ULTIMATE_TICTAC_TOE_GAME_H
#include "game.h"
#include "plays.h"
#include "boards.h"


typedef struct game{
    char player;
    int tie;
    int win;
    int type;
    int currentBoard;
    char** winboard;
}Game;

void initGame(Game* game);
void changePlayer(Game* game);
void playGame(Boards* boards, Game* game, Plays* plays);
void placePiece(char** board, int row, int column, char player);
int getNextBoard(int r, int c);
int validatePosition(char* row, char* column);
void playBot(Boards* boards, Game* game);
int verifyRow(char** board, char player);
int verifyColumn(char** board, char player);
int verifyDiagonal(char** board, char player);
int verifyBoardWin(char** board, int currentBoard,char player, char** winBoard);
int verifyGlobalWinner(char** board, char player, Game* game);


#endif //ULTIMATE_TICTAC_TOE_GAME_H
