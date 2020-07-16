#include "StatusLED.h"

StatusLED::StatusLED(){};

void StatusLED::setup(int readerNumber, int pin, GameState gameState)
{
    this->pin = pin;
    this->readerNumber = readerNumber;
    this->gameState = gameState;

    pinMode(pin, OUTPUT);
};

void StatusLED::update(){

};