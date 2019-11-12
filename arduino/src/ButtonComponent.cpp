#include <Arduino.h>
#include "ButtonComponent.h"
#include "InputState.h"

#define LOGGING true

// constructor
ButtonComponent::ButtonComponent()
{
}

void ButtonComponent::setup(int buttonNumber, int pin, InputState inputState)
{
    this->buttonNumber = buttonNumber;
    this->pin = pin;
    this->inputState = inputState;
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
            switch (this->buttonNumber)
            {
            case 0:
                this->inputState.leftButtonPressed = true;
                Serial.println("pressed button 1");        
                
                break;
            case 1:
                this->inputState.rightButtonPressed = true;
                break;
            }
        }
    }
    else if (newState == LOW && this->buttonState == HIGH)
    {
        // von nicht gedrückt zu gedrückt
        this->millisLastPressed = millis();

        switch (this->buttonNumber)
        {
        case 0:
            this->inputState.leftButtonPressed = false;
            break;
        case 1:
            this->inputState.rightButtonPressed = false;
            break;
        }
    } else {
        switch (this->buttonNumber)
        {
        case 0:
            this->inputState.leftButtonPressed = false;
            break;
        case 1:
            this->inputState.rightButtonPressed = false;
            break;
        }
    }

    this->buttonState = newState;
}