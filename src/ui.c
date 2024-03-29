#include "ui.h"
#include "stdbool.h"
#include "string.h"
#include "utils.h"

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

void startInterface(Boards* boards, Game* game, struct Play** plays){
    char option[20] = "";
    bool result = false;

    printf("\nWelcome to ultimate tic-tac-toe.\n");
    do {
        printf("\nWhat do you want to do?\n0 - Load previous game.\n1 - Play against human.\n2 - Play against computer.\n3 - Exit the game.\n\n>");
        fgets(option, 20, stdin);
        option[strlen(option)-1] = '\0';

        if (strcmp(option, "0\0") == 0) {
            loadGame(boards, game, plays);
        }else if (strcmp(option, "1\0") == 0) {
            game->type = 1;
            result = true;
            playMenu(boards, game, plays);
        } else if (strcmp(option, "2\0") == 0) {
            game->type = 2;
            result = true;
            playMenu(boards, game, plays);
        }else if (strcmp(option, "3\0") == 0) {
            freeAll(boards, game, *plays);
            result = true;
        }else
            printf("\nThats a not valid type of game.\n");
        fflush(stdin);
    } while (!result);
}

void playMenu(Boards* boards, Game* game, struct Play** plays){
    char option[20] = "";
    bool result = false;
    do{
        showBoards(boards, game);
        printf("\nWhat do you want to do?\n");
        printf("1 - Place a piece.\n");
        printf("2 - Save the game.\n");
        printf("3 - See 'K' plays.\n");
        printf("4 - Exit the game.\n\n>");
        fgets(option, 20, stdin);
        option[strlen(option)-1] = '\0';
        if (strcmp(option, "1\0") == 0) {
            playGame(boards, game, plays);
        }else if (strcmp(option, "2\0") == 0) {
            result = true;
            saveGame(boards, game, *plays);
            freeAll(boards, game, *plays);
        }else if (strcmp(option, "3\0") == 0) {
            showPlays(*plays, game);
        }else if(strcmp(option, "4\0") == 0){
            freeAll(boards, game, *plays);
            result = true;
        }else
            printf("\nThats not a valid option.\n");
        if(game->win == 1){
            printf("\n\tPlayer [%c] won.\n", game->player);
            showBoards(boards, game);
            resumeOfGame(*plays);
            freeAll(boards, game, *plays);
            break;
        }
        if(verifyTie(game) == 1){
            printf("\nThe game ended in tie.\n");
            freeAll(boards, game, *plays);
            break;
        }
    }while(!result);
}


