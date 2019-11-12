#include "InputState.h"

#ifndef __BUTTONCOMPONENT_H_INCLUDED__
#define __BUTTONCOMPONENT_H_INCLUDED__

class ButtonComponent
{

public:
    ButtonComponent();

    void setup(int buttonNumber, int pin, InputState inputState);
    void update();

private:
    InputState inputState;
    int buttonNumber;
    int pin;
    int buttonState;
    unsigned long millisLastPressed;


};

#endif