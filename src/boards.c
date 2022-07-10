#include "boards.h"

Boards* initBoards(){
    Boards* boards = (Boards*) malloc(9 * sizeof (Boards));
    if(boards == NULL){
        printf("\nError allocating memory for the boards.\n");
        exit(-1);
    }

    for(int i=0; i<9; i++){
        boards[i].board = createBoard(3,3);
        initBoard(boards[i].board);
    }
    return(boards);
}