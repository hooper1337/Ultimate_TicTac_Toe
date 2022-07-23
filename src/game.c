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

void placePiece(Boards* boards, int board, int row, int column, char player){
    if(player == 'A')
        boards[board].board[row][column] = 'X';
    else
        boards[board].board[row][column] = 'O';
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

void playGameAgainstHuman(Boards* boards, Game* game, Plays* plays){
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
            placePiece(boards, game->currentBoard, r, c, game->player);
            changePlayer(game);
            game->currentBoard = getNextBoard(r,c);
            result = true;
        }else
            printf("\nYou cant play in that position.\n");
    }while(!result);
}
