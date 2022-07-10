#ifndef ULTIMATE_TICTAC_TOE_GAME_H
#define ULTIMATE_TICTAC_TOE_GAME_H
typedef struct game{
    char player;
    int tie;
    int win;
    char** winboard;
}Game;

void initGame(Game* game);
char changePlayer(char player);
#endif //ULTIMATE_TICTAC_TOE_GAME_H
