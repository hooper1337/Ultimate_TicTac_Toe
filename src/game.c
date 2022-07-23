#include <time.h>
#include "game.h"
#include "string.h"
#include "stdbool.h"
#include "ctype.h"


void initGame(Game* game){
    game->tie = 0;
    game->win = 0;
    game->player = 'A';
    game->currentBoard = 0;
    game->winboard = createBoard(3,3);
    initBoard(game->winboard);
}

void changePlayer(Game* game){
    if(game->player == 'A')
        game->player = 'B';
    else
        game->player = 'A';
}

void placePiece(char** board, int row, int column, char player){
    if(player == 'A')
        board[row][column] = 'X';
    else
        board[row][column] = 'O';
}

int validatePosition(char* row, char* column){
    int r=0;
    int c=0;
    if(strlen(row) == 1 && strlen(column) == 1)
        if (isdigit(row[0]) == 1 && isdigit(column[0]) == 1) {
            r = atoi(row);
            c = atoi(column);
            if ((r < 3 && r >= 0) || (c < 3 && c >= 0))
                return 1;
        }
    return 0;
}

int getNextBoard(int r, int c){
    return c+(r*3);
}

void playBot(Boards* boards, Game* game){
    int r=0;
    int c=0;
    srand(time(0));
    r = rand() % 3;
    c = rand() % 3;
    placePiece(boards[game->currentBoard].board, r, c, game->player);
    verifyBoardWin(boards, game->currentBoard, game->player, game->winboard);
    printf("\nBot played in board [%d], row [%d] column[%d].\n", game->currentBoard, r, c);
    changePlayer(game);
    game->currentBoard = getNextBoard(r,c);
}

int verifyBoardWin(Boards* boards, int currentBoard, char player, char** winBoard){
    if(verifyRow(boards,currentBoard, player) == 1)
        printf("\nPlayer [%c] won board [%d] by row.\n", player, currentBoard);
    else if(verifyColumn(boards,currentBoard,player) == 1)
        printf("\nPlayer [%c] won board [%d] by column.\n", player, currentBoard);
    else if(verifyDiagonal(boards, currentBoard, player) == 1)
        printf("\nPlayer [%c] won board [%d] by diagonal.\n", player, currentBoard);
    else
        return 0;
    if(currentBoard == 0 || currentBoard == 1 || currentBoard == 2)
        placePiece(winBoard, 0, currentBoard, player);
    else if(currentBoard == 3 || currentBoard == 4 || currentBoard == 5)
        placePiece(winBoard, 1, currentBoard-3, player);
    else if(currentBoard == 6 || currentBoard == 7 || currentBoard == 8)
        placePiece(winBoard, 2, currentBoard-6, player);
    return 1;
}

int verifyRow(Boards* boards, int currentBoard, char player){
    int count = 0;

    for(int i=0; i<3;) {
        for (int j = 0; j < 3; j++) {
            if (player == 'A') {
                if (boards[currentBoard].board[i][j] == 'X')
                    count++;
            }
            else {
                if (boards[currentBoard].board[i][j] == 'O')
                    count++;
            }
            if(count == 3)
                return 1;
        }
        count=0;
        i++;
    }
    return 0;
}

int verifyColumn(Boards* boards, int currentBoard, char player){
    int count = 0;
    for(int i=0; i<3;) {
        for (int j = 0; j < 3; j++) {
            if (player == 'A') {
                if (boards[currentBoard].board[j][i] == 'X')
                    count++;
            }
            else {
                if (boards[currentBoard].board[j][i] == 'O')
                    count++;
            }
            if(count == 3)
                return 1;
        }
        count=0;
        i++;
    }
    return 0;
}

int verifyDiagonal(Boards* boards, int currentBoard, char player){
    int count = 0;
    int i=0, j=0;
    for(i; i<3;)
        for (j; j < 3;) {
            if (player == 'A') {
                if (boards[currentBoard].board[i][j] == 'X')
                    count++;
            } else {
                if (boards[currentBoard].board[i][j] == 'O')
                    count++;
            }
            i++;
            j++;
        }
    if(count == 3)
        return 1;
    count = 0;
    i=0;
    j=2;
    for(i; i<3;)
        for(j; j>=0;){
            if (player == 'A') {
                if (boards[currentBoard].board[i][j] == 'X')
                    count++;
            } else {
                if (boards[currentBoard].board[i][j] == 'O')
                    count++;
            }
            i++;
            j--;
        }
    return count == 3 ? 1 : 0;
}


void playGame(Boards* boards, Game* game, Plays* plays){
    char row[20] = "";
    char column[20] = "";
    int r = 0;
    int c = 0;
    bool result = false;
    do{
        printf("\nPlayer [%c] you are playing in board [%d].\n", game->player, game->currentBoard);
        printf("\nIntroduce the row you wish to play.\n>");
        fgets(row, 20, stdin);
        row[strlen(row)-1] = '\0';
        printf("\nIntroduce the column you wish to play.\n>");
        fgets(column, 20, stdin);
        column[strlen(column)-1] = '\0';
        if(validatePosition(row, column) == 1) {
            r = atoi(row);
            c = atoi(column);
            placePiece(boards[game->currentBoard].board, r, c, game->player);
            verifyBoardWin(boards, game->currentBoard, game->player, game->winboard);
            changePlayer(game);
            game->currentBoard = getNextBoard(r,c);
            if(game->type == 2)
                playBot(boards, game);
            result = true;
        }else
            printf("\nYou cant play in that position.\n");
    }while(!result);
}
