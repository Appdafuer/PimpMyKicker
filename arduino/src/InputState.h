#include <SPI.h>

#ifndef __INPUTSTATE_H_INCLUDED__
#define __INPUTSTATE_H_INCLUDED__

class InputState
{

public:
    // TODO: create array of ids
    byte nfcId1[10];
    byte nfcId2[10];
    byte nfcId3[10];
    byte nfcId4[10];

    bool leftButtonPressed;
    bool rightButtonPressed;

    bool newPlayerFound;

    InputState();
    void reset();
};

#endif