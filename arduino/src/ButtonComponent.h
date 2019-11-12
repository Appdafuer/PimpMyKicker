#include "InputState.h"

#ifndef __BUTTONCOMPONENT_H_INCLUDED__
#define __BUTTONCOMPONENT_H_INCLUDED__

class ButtonComponent
{

public:
    ButtonComponent();

    void setup(int pin, bool *pressed);
    void update();

private:
    bool *pressed;
    int buttonNumber;
    int pin;
    int buttonState;
    unsigned long millisLastPressed;


};

#endif