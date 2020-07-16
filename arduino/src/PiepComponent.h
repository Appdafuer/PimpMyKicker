#include <SPI.h>
#include "GameState.h"

#ifndef __PIEPCOMPONENT_H_INCLUDED__
#define __PIEPCOMPONENT_H_INCLUDED__

class PiepComponent
{

public:
    PiepComponent();

    void setup(int pin, bool *piep);
    void update();

private:
    int pin;
    bool *piep;
    int millisStarted;
};

#endif