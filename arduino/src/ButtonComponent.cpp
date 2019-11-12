#include <Arduino.h>
#include "ButtonComponent.h"
#include "InputState.h"

#define LOGGING true

// constructor
ButtonComponent::ButtonComponent()
{
}

void ButtonComponent::setup(int pin, bool *pressed)
{
    this->pin = pin;
    this->pressed = pressed;
    this->buttonState = HIGH;
    this->millisLastPressed = 0;
    pinMode(pin, INPUT_PULLUP);
}

void ButtonComponent::update()
{
    int newState = digitalRead(this->pin);
    if (newState == HIGH && this->buttonState == LOW)
    {
        // von gedrückt zu nicht gedrückt

        unsigned long now = millis();
        unsigned long duration = now - this->millisLastPressed;

        if (duration > 50 && duration < 1000)
        {
            // von down nach up
            *pressed = true;
        }
    }
    else if (newState == LOW && this->buttonState == HIGH)
    {
        // von nicht gedrückt zu gedrückt
        this->millisLastPressed = millis();

        *pressed = false;
    } else {
        *pressed = false;
    }

    this->buttonState = newState;
}