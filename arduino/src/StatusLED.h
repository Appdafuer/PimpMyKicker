#include <SPI.h>
#include "GameState.h"

#ifndef __STATUSLED_H_INCLUDED__
#define __STATUSLED_H_INCLUDED__

class StatusLED
{

public:
    StatusLED();

    void setup(int readerNumber, int pin, GameState gameState);
    void update();

private:
    int readerNumber;
    int pin;
    GameState gameState;
};

#endif