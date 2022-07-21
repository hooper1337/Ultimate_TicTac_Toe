#include "ui.h"
#include "stdbool.h"
#include "string.h"

void showBoards(Boards* boards, Game* game){
    printf("\n\t BOARDS WON");
    printf("\n\t +-------+\n");
    for(int i=0; i<3; i++) {
        if(i != 0)
            putchar('\n');
        for (int j=0; j<3; j++) {
            if(j==0)
                printf("\t | %c ", game->winboard[i][j]);
            else if(j == 2)
                printf("%c |", game->winboard[i][j]);
            else
                printf("%c ", game->winboard[i][j]);
        }
    }
    printf("\n\t +-------+\n");

    printf("\n\n\tGAME BOARDS\n");
    printf("+------------------------+\n");
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[0].board[0][0], boards[0].board[0][1], boards[0].board[0][2],
           boards[1].board[0][0],boards[1].board[0][1], boards[1].board[0][2],
           boards[2].board[0][0],boards[2].board[0][1],boards[2].board[0][2]);
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[0].board[1][0], boards[0].board[1][1], boards[0].board[1][2],
           boards[1].board[1][0],boards[1].board[1][1], boards[1].board[1][2],
           boards[2].board[1][0],boards[2].board[1][1],boards[2].board[1][2]);
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[0].board[2][0], boards[0].board[2][1], boards[0].board[2][2],
           boards[1].board[2][0],boards[1].board[2][1], boards[1].board[2][2],
           boards[2].board[2][0],boards[2].board[2][1],boards[2].board[2][2]);
    printf("|--------+-------+-------|\n");
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[3].board[0][0], boards[3].board[0][1], boards[3].board[0][2],
           boards[4].board[0][0],boards[4].board[0][1], boards[4].board[0][2],
           boards[5].board[0][0],boards[5].board[0][1],boards[5].board[0][2]);
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[3].board[1][0], boards[3].board[1][1], boards[3].board[1][2],
           boards[4].board[1][0],boards[4].board[1][1], boards[4].board[1][2],
           boards[5].board[1][0],boards[5].board[1][1],boards[5].board[1][2]);
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[3].board[2][0], boards[3].board[2][1], boards[3].board[2][2],
           boards[4].board[2][0],boards[4].board[2][1], boards[4].board[2][2],
           boards[5].board[2][0],boards[5].board[2][1],boards[5].board[2][2]);
    printf("|--------+-------+-------|\n");
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[6].board[0][0], boards[6].board[0][1], boards[6].board[0][2],
           boards[7].board[0][0],boards[7].board[0][1], boards[7].board[0][2],
           boards[8].board[0][0],boards[8].board[0][1],boards[8].board[0][2]);
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[6].board[1][0], boards[6].board[1][1], boards[6].board[1][2],
           boards[7].board[1][0],boards[7].board[1][1], boards[7].board[1][2],
           boards[8].board[1][0],boards[8].board[1][1],boards[8].board[1][2]);
    printf("| %c %c %c  | %c %c %c | %c %c %c |\n",boards[6].board[2][0], boards[6].board[2][1], boards[6].board[2][2],
           boards[7].board[2][0],boards[7].board[2][1], boards[7].board[2][2],
           boards[8].board[2][0],boards[8].board[2][1],boards[8].board[2][2]);
    printf("+------------------------+\n");
}

void startInterface(){
    char option[20] = "";
    bool result = false;

    printf("\nWelcome to ultimate tic-tac-toe.\n\n");
    do {
        printf("\nWhat type of game do you wish?\n1 - Against human.\n2 - Against computer.\n\n>");
        fgets(option, 20, stdin);
        option[strlen(option)-1] = '\0';

        if (strcmp(option, "1\0") == 0) {
            result = true;
            // to do soon
        } else if (strcmp(option, "2\0") == 0) {
            // to do soon
            result = true;
        } else {
            printf("\nThats a not valid type of game.\n");
            result = false;
        }
        fflush(stdin);
    } while (!result);
}