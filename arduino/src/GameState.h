#include <SPI.h>

#ifndef __GAMESTATE_H_INCLUDED__
#define __GAMESTATE_H_INCLUDED__

class GameState
{

public:
    int goals1;
    int goals2;
    byte *playerId1;
    byte *playerId2;
    byte *playerId3;
    byte *playerId4;

    bool gameFinished;

    GameState();
    void startNewGame();
};

#endif