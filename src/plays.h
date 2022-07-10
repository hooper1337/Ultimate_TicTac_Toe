#ifndef ULTIMATE_TICTAC_TOE_PLAYS_H
#define ULTIMATE_TICTAC_TOE_PLAYS_H

typedef struct Play{
    int row;
    int column;
    char player;
    int board;
    struct Plays* nextplay;
}Plays;

#endif //ULTIMATE_TICTAC_TOE_PLAYS_H
