#include "PiepComponent.h"

#define DURATION 150

PiepComponent::PiepComponent(){};

void PiepComponent::setup(int pin, bool *piep)
{
    this->pin = pin;
    this->piep = piep;
    this->millisStarted = 0;

    pinMode(pin, OUTPUT);
    digitalWrite(this->pin, LOW);
};

void PiepComponent::update()
{
    int now = millis();

    if (*piep)
    {
        this->millisStarted = now;
    }

    if (this->millisStarted + DURATION > now)
    {
        digitalWrite(this->pin, HIGH);
    }
    else
    {
        digitalWrite(this->pin, LOW);
    }
};