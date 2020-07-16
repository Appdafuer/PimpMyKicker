#include <SPI.h>

#ifndef __GAMESTATE_H_INCLUDED__
#define __GAMESTATE_H_INCLUDED__

class GameState
{

public:
    int goals1;
    int goals2;
    bool player1Available;
    bool player2Available;
    bool player3Available;
    bool player4Available;

    bool gameFinished;

    GameState();
    void startNewGame();
};

#endif