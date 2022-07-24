#ifndef ULTIMATE_TICTAC_TOE_GAME_H
#define ULTIMATE_TICTAC_TOE_GAME_H
#include "boards.h"

typedef struct Game{
    char player;
    int tie;
    int win;
    int type;
    int nPlays;
    int currentBoard;
    char** winboard;
}Game;

struct Play{
    int row;
    int column;
    char player;
    int board;
    struct Play* nextplay;
};

void initGame(Game* game);
void changePlayer(Game* game);
void playGame(Boards* boards, Game* game, struct Play** plays);
int placePiece(char** board, int row, int column, char player);
int getNextBoard(int r, int c);
int validatePosition(char* row, char* column);
void playBot(Boards* boards, Game* game, struct Play** plays);
int verifyRow(char** board, char player);
int verifyColumn(char** board, char player);
int verifyDiagonal(char** board, char player);
int verifyBoardWin(char** board, int currentBoard,char player, char** winBoard, Boards* boards);
int verifyGlobalWinner(char** board, char player, Game* game);
void insertNode(struct Play** play, int row, int column, char player, int board);
void showPlays(struct Play* play, Game* game);
int verifyTie(Game* game);
#endif //ULTIMATE_TICTAC_TOE_GAME_H
