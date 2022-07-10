#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

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
    return (matrix);
}

void initBoard(char** board){
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = '_';
}