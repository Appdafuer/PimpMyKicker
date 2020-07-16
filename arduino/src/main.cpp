
/**
   --------------------------------------------------------------------------------------------------------------------
   Example sketch/program showing how to read data from more than one PICC to serial.
   --------------------------------------------------------------------------------------------------------------------
   This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid

   Example sketch/program showing how to read data from more than one PICC (that is: a RFID Tag or Card) using a
   MFRC522 based RFID Reader on the Arduino SPI interface.

   Warning: This may not work! Multiple devices at one SPI are difficult and cause many trouble!! Engineering skill
            and knowledge are required!

   @license Released into the public domain.

   Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS 1    SDA(SS)      ** custom, take a unused pin, only HIGH/LOW required *
   SPI SS 2    SDA(SS)      ** custom, take a unused pin, only HIGH/LOW required *
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15

*/

#include <SPI.h>
#include "InputState.h"
#include "GameState.h"
#include "GameManager.h"
#include "NFCComponent.h"
#include "StatusLED.h"
#include "ButtonComponent.h"
#include "DisplayComponent.h"

#define LOGGING true

// READERS

#define NR_OF_READERS 4

// PIN Numbers : RESET + SDAs
#define RST_PIN 49
#define SS_1_PIN 46 //schwarz Abwehr
#define SS_2_PIN 42 //schwarz Sturm
#define SS_3_PIN 40 //weiß Sturm
#define SS_4_PIN 44 //weiß Abwehr

#define STATUS_LED_NFC_1_PIN 9
#define STATUS_LED_NFC_2_PIN 10
#define STATUS_LED_NFC_3_PIN 11
#define STATUS_LED_NFC_4_PIN 12

byte ssPins[] = {SS_1_PIN, SS_2_PIN, SS_3_PIN, SS_4_PIN};
byte statusLedPins[] = {STATUS_LED_NFC_1_PIN, STATUS_LED_NFC_2_PIN, STATUS_LED_NFC_3_PIN, STATUS_LED_NFC_4_PIN};

NFCComponent nfcComponents[NR_OF_READERS];
StatusLED statusLEDs[NR_OF_READERS];

// DISPLAYS

DisplayComponent display1;
DisplayComponent display2;

// BUTTONS

#define DASH_BUTTON_1 9
#define LED_DASH_BUTTON_1 38

#define DASH_BUTTON_2 10
#define LED_DASH_BUTTON_2 39

ButtonComponent dashButtonComponent1;
ButtonComponent dashButtonComponent2;

// RUNLOOP

InputState inputState;
GameManager gameManager;
GameState gameState;

void setupInput()
{
  for (int i = 0; i < NR_OF_READERS; i++)
  {
    nfcComponents[i].setup(i, ssPins[i], RST_PIN, inputState);
  }
  dashButtonComponent1.setup(DASH_BUTTON_1, &inputState.leftButtonPressed);
  dashButtonComponent2.setup(DASH_BUTTON_2, &inputState.rightButtonPressed);
}

void setupLogic()
{
  // still work in progress. when commented in it doesn't work!
  gameManager.setup(&inputState, &gameState);
}

void setupOutput()
{
  for (int i = 0; i < NR_OF_READERS; i++)
  {
    statusLEDs[i].setup(i, statusLedPins[i], gameState);
  }
  display1.setup(0, &gameState.goals1);
  display2.setup(1, &gameState.goals2);
}

void setup()
{
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial)
    ; // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

  SPI.begin(); // Init SPI bus

  setupInput();
  setupLogic();
  setupOutput();
}

void updateInput()
{
  for (int i = 0; i < NR_OF_READERS; i++)
  {
    nfcComponents[i].update();
  }
  dashButtonComponent1.update();
  dashButtonComponent2.update();
}
void updateLogic()
{
  gameManager.update();
}

void updateOutput()
{
  for (int i = 0; i < NR_OF_READERS; i++)
  {
    statusLEDs[i].update();
  }
  display1.update();
  display2.update();
}

void loop()
{
  updateInput();
  updateLogic();
  updateOutput();
}
