#include "utils.h"

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

int randomNumber(int min, int max){
    time_t t;
    srand((unsigned)time(&t));

    return rand() % max + min;
}
