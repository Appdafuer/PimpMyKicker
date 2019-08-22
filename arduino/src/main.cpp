#include <Arduino.h>
/*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>
#include <MFRC522.h>

// #define RST_PIN 43 // SPI Reset Pin
// #define SS_PIN 42  // SPI Slave Select Pin

#define RST_PIN_2 45 // SPI Reset Pin
#define SS_PIN_2 44  // SPI Slave Select Pin

// #define RST_PIN_3 49 // SPI Reset Pin
// #define SS_PIN_3 48  // SPI Slave Select Pin

// MFRC522 mfrc522(SS_PIN, RST_PIN); // Instanz des MFRC522 erzeugen

MFRC522 mfrc522_2(SS_PIN_2, RST_PIN_2); // Instanz des MFRC522 erzeugen

// MFRC522 mfrc522_3(SS_PIN_3, RST_PIN_3); // Instanz des MFRC522 erzeugen

void setup()
{
  // Diese Funktion wird einmalig beim Start ausgeführt
  Serial.begin(9600); // Serielle Kommunikation mit dem PC initialisieren
  SPI.begin();        // Initialisiere SPI Kommunikation
  // mfrc522.PCD_Init();   // Initialisiere MFRC522 Lesemodul
  mfrc522_2.PCD_Init(); // Initialisiere MFRC522 Lesemodul
  // mfrc522_3.PCD_Init(); // Initialisiere MFRC522 Lesemodul
  Serial.print("Hello 3");
}

void loop()
{
  // Diese Funktion wird in Endlosschleife ausgeführt

  // Nur wenn eine Karte gefunden wird und gelesen werden konnte, wird der Inhalt von IF ausgeführt
  // PICC = proximity integrated circuit card = kontaktlose Chipkarte
  // if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())
  // {
  //   Serial.print("Gelesene UID:");
  //   for (byte i = 0; i < mfrc522.uid.size; i++)
  //   {
  //     // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
  //     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
  //     Serial.print(mfrc522.uid.uidByte[i], HEX);
  //   }
  //   Serial.println();

  //   // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
  //   mfrc522.PICC_HaltA();
  //   delay(1000);
  // }

  if (mfrc522_2.PICC_IsNewCardPresent() && mfrc522_2.PICC_ReadCardSerial())
  {
    Serial.print("Gelesene UID 2:");
    for (byte i = 0; i < mfrc522_2.uid.size; i++)
    {
      // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
      Serial.print(mfrc522_2.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522_2.uid.uidByte[i], HEX);
    }
    Serial.println();

    // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
    mfrc522_2.PICC_HaltA();
    delay(1000);
  }

  // if (mfrc522_3.PICC_IsNewCardPresent() && mfrc522_3.PICC_ReadCardSerial())
  // {
  //   Serial.print("Gelesene UID 3:");
  //   for (byte i = 0; i < mfrc522_3.uid.size; i++)
  //   {
  //     // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
  //     Serial.print(mfrc522_3.uid.uidByte[i] < 0x10 ? " 0" : " ");
  //     Serial.print(mfrc522_3.uid.uidByte[i], HEX);
  //   }
  //   Serial.println();

  //   // Versetzt die gelesene Karte in einen Ruhemodus, um nach anderen Karten suchen zu können.
  //   mfrc522_3.PICC_HaltA();
  //   delay(1000);
  // }
}