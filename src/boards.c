#include "boards.h"

Boards* initBoards(){
    Boards* boards = (Boards*) malloc(9 * sizeof (Boards));
    if(boards == NULL){
        printf("\nError allocating memory for the boards.\n");
        exit(-1);
    }

    for(int i=0; i<9; i++){
        boards[i].board = createBoard(3,3);
        boards[i].won = 0;
        initBoard(boards[i].board);
    }
    return boards;
}

char** createBoard(int rows, int columns){
    char** matrix = NULL;

    matrix = malloc(sizeof(char*)*rows);
    if(matrix == NULL)
        return NULL;

    for(int i=0; i<rows; i++){
        matrix[i] = malloc(sizeof(char)*columns);
        if(matrix[i] == NULL){
            for(int j=0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void initBoard(char** board){
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = '_';
}
