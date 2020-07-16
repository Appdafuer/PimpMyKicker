#include <SPI.h>
#include "InputState.h"
#include "GameState.h"

#ifndef __GAMEMANAGER_H_INCLUDED__
#define __GAMEMANAGER_H_INCLUDED__

class GameManager
{

public:
    GameManager();

    void setup(InputState *inputState, GameState *gameState);
    void update();

private:
    InputState *inputState;
    GameState *gameState;
};

#endif