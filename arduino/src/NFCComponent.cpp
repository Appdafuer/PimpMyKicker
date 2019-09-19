#include "NFCComponent.h"
#include "InputState.h"

#define LOGGING true

// constructor
NFCComponent::NFCComponent()
{
}

void NFCComponent::setup(int readerNumber, int sdaPin, int resetPin, InputState inputState)
{
    this->readerNumber = readerNumber;
    this->sdaPin = sdaPin;
    this->resetPin = resetPin;
    this->inputState = inputState;

    reader.PCD_Init(sdaPin, resetPin);
    Serial.print(F("Reader "));
    // Serial.print(reader);
    Serial.print(F(": "));
    reader.PCD_DumpVersionToSerial();
    reader.PCD_SetAntennaGain(reader.RxGain_max);
}

void NFCComponent::update()
{
    // Looking for new cards
    if (reader.PICC_IsNewCardPresent() && reader.PICC_ReadCardSerial())
    {

        Serial.print(F("Reader "));
        Serial.print(readerNumber);
        Serial.print(F(": Card UID:"));
        dump_byte_array(reader.uid.uidByte, reader.uid.size);
        Serial.println();

        switch (readerNumber)
        {
        case 1:
            memcpy(inputState.nfcId1, reader.uid.uidByte, reader.uid.size);
            break;
        case 2:
            memcpy(inputState.nfcId2, reader.uid.uidByte, reader.uid.size);
            break;
        case 3:
            memcpy(inputState.nfcId3, reader.uid.uidByte, reader.uid.size);
            break;
        case 4:
            memcpy(inputState.nfcId4, reader.uid.uidByte, reader.uid.size);
            break;
        default:
            break;
        };

        // Halt PICC
        reader.PICC_HaltA();
        // Stop encryption on PCD
        reader.PCD_StopCrypto1();
    }
    else
    {
        // todo create inputState Array for nfc ids
        byte noAdress[10] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
        switch (readerNumber)
        {
        case 1:
            memcpy(inputState.nfcId1, noAdress, reader.uid.size);
            break;
        case 2:
            memcpy(inputState.nfcId2, noAdress, reader.uid.size);
            break;
        case 3:
            memcpy(inputState.nfcId3, noAdress, reader.uid.size);
            break;
        case 4:
            memcpy(inputState.nfcId4, noAdress, reader.uid.size);
            break;
        default:
            break;
        };
    }
}

/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void NFCComponent::dump_byte_array(byte *buffer, byte bufferSize)
{
    for (byte i = 0; i < bufferSize; i++)
    {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}