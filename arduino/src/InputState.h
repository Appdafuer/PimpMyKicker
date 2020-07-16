#include <SPI.h>

#ifndef __INPUTSTATE_H_INCLUDED__
#define __INPUTSTATE_H_INCLUDED__

class InputState
{

public:
    byte nfcId1[4];
    byte nfcId2[4];
    byte nfcId3[4];
    byte nfcId4[4];

    bool leftButtonPressed;
    bool rightButtonPressed;

    bool newPlayerFound;

    InputState();
    void reset();
};

#endif