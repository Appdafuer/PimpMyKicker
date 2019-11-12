// #include <Arduino.h>

// #define DASH_BUTTON_1 36
// #define LED_DASH_BUTTON_1 38
// #define SEGMENT_DISPLAY_1_DOT 2
// #define SEGMENT_DISPLAY_1_MIDDLE 35     // yellow
// #define SEGMENT_DISPLAY_1_UP_LEFT 33    // blue
// #define SEGMENT_DISPLAY_1_UP 31         // green
// #define SEGMENT_DISPLAY_1_UP_RIGHT 29   // red
// #define SEGMENT_DISPLAY_1_DOWN_LEFT 27  // black
// #define SEGMENT_DISPLAY_1_DOWN 25       // orange
// #define SEGMENT_DISPLAY_1_DOWN_RIGHT 23 // white

// int dashButton1 = 0;
// int count = 0;

// void showCount()
// {

//     int countTo10 = count % 10;

//     switch (countTo10)
//     {
//     case 0:

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, LOW);

//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);
//         break;
//     case 1:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, LOW);

//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);

//         break;
//     case 2:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, LOW);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         break;

//     case 3:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, LOW);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         break;

//     case 4:

//         digitalWrite(SEGMENT_DISPLAY_1_UP, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, LOW);

//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);

//         break;

//     case 5:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, LOW);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);
//         break;

//     case 6:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         break;

//     case 7:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, LOW);
//         break;

//     case 8:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         break;

//     case 9:
//         digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT, HIGH);

//         digitalWrite(SEGMENT_DISPLAY_1_MIDDLE, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_UP, HIGH);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT, LOW);
//         digitalWrite(SEGMENT_DISPLAY_1_DOWN, HIGH);
//         break;

//     default:
//         break;
//     }
// }

// void setup()
// {
//     Serial.begin(9600); // Serielle Kommunikation mit dem PC initialisieren
//     Serial.print("Hello Button");

//     pinMode(DASH_BUTTON_1, INPUT_PULLUP);
//     pinMode(LED_DASH_BUTTON_1, OUTPUT);

//     pinMode(SEGMENT_DISPLAY_1_DOT, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_MIDDLE, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_UP_LEFT, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_UP, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_UP_RIGHT, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_DOWN_LEFT, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_DOWN, OUTPUT);
//     pinMode(SEGMENT_DISPLAY_1_DOWN_RIGHT, OUTPUT);

//     // analogWrite(SEGMENT_DISPLAY_1_DOT, 240);
//     analogWrite(SEGMENT_DISPLAY_1_DOT, 255);
//     digitalWrite(LED_DASH_BUTTON_1, HIGH);

//     showCount();
// }

// void loop()
// {

//     dashButton1 = digitalRead(DASH_BUTTON_1);

//     if (dashButton1 == LOW)
//     {
//         count++;
//         showCount();
//         delay(150);
//     }
//     delay(10);
// }
