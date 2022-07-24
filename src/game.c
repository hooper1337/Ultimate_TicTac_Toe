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
    game->nPlays = 0;
    initBoard(game->winboard);
}

void changePlayer(Game* game){
    if(game->player == 'A')
        game->player = 'B';
    else
        game->player = 'A';
}

int placePiece(char** board, int row, int column, char player){
    if(player == 'A'){
        if(board[row][column] == '_'){
            board[row][column] = 'X';
            return 1;
        }
    }else{
        if(board[row][column] == '_'){
            board[row][column] = 'O';
            return 1;
        }
    }
    return 0;
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

void playBot(Boards* boards, Game* game, struct Play** plays){
    int r=0;
    int c=0;
    srand(time(0));
    r = rand() % 3;
    c = rand() % 3;
    while(boards[game->currentBoard].won == 1){
        int board = rand() % 9;
        game->currentBoard = board;
    }
    while(placePiece(boards[game->currentBoard].board, r, c, game->player) != 1){
        r = rand() % 3;
        c = rand() % 3;
    }
    game->nPlays++;
    insertNode(plays,r,c,game->player,game->currentBoard);
    verifyBoardWin(boards[game->currentBoard].board, game->currentBoard, game->player, game->winboard, boards);
    printf("\nBot played in board [%d], row [%d] column[%d].\n", game->currentBoard, r, c);
    changePlayer(game);
    game->currentBoard = getNextBoard(r,c);
}

int verifyGlobalWinner(char** board, char player, Game* game){
    if(verifyRow(board,player) == 1 || verifyColumn(board,player) == 1 || verifyDiagonal(board,player) == 1){
        game->win = 1;
        return 1;
    }
    return 0;
}

int verifyBoardWin(char** board, int currentBoard, char player, char** winBoard, Boards* boards){
    if(verifyRow(board,player) == 1){
        printf("\nPlayer [%c] won board [%d] by row.\n", player, currentBoard);
        boards[currentBoard].won = 1;
    }
    else if(verifyColumn(board,player) == 1){
        printf("\nPlayer [%c] won board [%d] by column.\n", player, currentBoard);
        boards[currentBoard].won = 1;
    }
    else if(verifyDiagonal(board, player) == 1){
        printf("\nPlayer [%c] won board [%d] by diagonal.\n", player, currentBoard);
        boards[currentBoard].won = 1;
    }
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

int verifyRow(char** board, char player){
    int count = 0;

    for(int i=0; i<3;) {
        for (int j = 0; j < 3; j++) {
            if (player == 'A') {
                if (board[i][j] == 'X')
                    count++;
            }
            else {
                if (board[i][j] == 'O')
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

int verifyColumn(char** board, char player){
    int count = 0;
    for(int i=0; i<3;) {
        for (int j = 0; j < 3; j++) {
            if (player == 'A') {
                if (board[j][i] == 'X')
                    count++;
            }
            else {
                if (board[j][i] == 'O')
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

int verifyDiagonal(char** board, char player){
    int count = 0;
    int i=0, j=0;
    for(i; i<3;)
        for (j; j < 3;) {
            if (player == 'A') {
                if (board[i][j] == 'X')
                    count++;
            } else {
                if (board[i][j] == 'O')
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
                if (board[i][j] == 'X')
                    count++;
            } else {
                if (board[i][j] == 'O')
                    count++;
            }
            i++;
            j--;
        }
    return count == 3 ? 1 : 0;
}


void playGame(Boards* boards, Game* game, struct Play** plays){
    char row[20] = "";
    char column[20] = "";
    int r = 0;
    int c = 0;
    bool result = false;

    do{
        while(boards[game->currentBoard].won == 1){
            srand(time(0));
            int board = rand() % 9;
            game->currentBoard = board;
        }
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
            if(placePiece(boards[game->currentBoard].board, r, c, game->player) == 1){
                game->nPlays++;
                insertNode(plays,r,c,game->player,game->currentBoard);
                verifyBoardWin(boards[game->currentBoard].board, game->currentBoard, game->player, game->winboard, boards);
                if(verifyGlobalWinner(game->winboard, game->player, game) == 1 && game->win == 1)
                    break;
                changePlayer(game);
                game->currentBoard = getNextBoard(r,c);
            }else
                printf("\nYou cant play there because there is a piece in that position.\n");
            if(game->type == 2)
                playBot(boards, game, plays);
            result = true;
        }else
            printf("\nThats not a valid position\n");
    }while(!result);
}

void insertNode(struct Play** play, int row, int column, char player, int board){
    struct Play* newNode;
    newNode = malloc(sizeof (struct Play));
    if(newNode == NULL){
        printf("\nError allocating memory for the new play.\n");
        return;
    }
    newNode->row = row;
    newNode->column = column;
    newNode->player = player;
    newNode->board = board;
    newNode->nextplay = (*play);
    (*play) = newNode;
}

int validateNumberOfPlays(char* plays, Game* game){
    int number=0;
    if(strlen(plays) == 1){
        if (isdigit(plays[0]) == 1)
            number = atoi(plays);
    }else if(strlen(plays) == 2){
        if(strcmp(plays, "10\0") == 0)
            number = atoi(plays);
    }else{
        printf("\nThats not a valid number of plays.\n");
        return 0;
    }if(number == 0){
        printf("\nYou cant see 0 plays.\n");
        return 0;
    }if(number > 10){
        printf("\nYou cant see more than 10 plays.\n");
        return 0;
    }if(number > game->nPlays){
        printf("\nGame only has %d plays yet.\n", game->nPlays);
        return 0;
    }
    return 1;
}

void showPlays(struct Play* play, Game* game) {
    char plays[20];
    int counter = 0;
    int playsCounter = 0;
    printf("\nHow many plays do you want to see?\n\n>");
    fgets(plays, 20, stdin);
    plays[strlen(plays)-1] = '\0';

    if(validateNumberOfPlays(plays, game) == 1){
        playsCounter = atoi(plays);
        printf("\nPlays:\n");
        while (counter < playsCounter) {
            printf("\nPlayer: %c", play->player);
            printf("\nBoard: %d", play->board);
            printf("\nRow: %d", play->row);
            printf("\nColumn: %d\n", play->column);
            play = play->nextplay;
            counter++;
        }
        printf("\n");
    }else
        return;
}
