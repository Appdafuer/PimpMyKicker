#include <SPI.h>
#include <MFRC522.h>
#include "InputState.h"

#ifndef __NFCCOMPONENT_H_INCLUDED__
#define __NFCCOMPONENT_H_INCLUDED__

class NFCComponent
{

public:
    NFCComponent();

    void setup(int readerNumber, int sdaPin, int resetPin, InputState inputState);
    void update();

private:
    InputState inputState;
    int readerNumber;
    int sdaPin;
    int resetPin;
    MFRC522 reader;

    void dump_byte_array(byte *buffer, byte bufferSize);
};

#endif