#include "DisplayComponent.h"

DisplayComponent::DisplayComponent(){};

void DisplayComponent::setup(int displayIndex, int *score)
{
    this->displayIndex = displayIndex;
    this->score = score;
};

void DisplayComponent::update()
{
    int number = *score % 10;

    switch (number)
    {
    case 0:

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, LOW);

        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);
        break;
    case 1:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, LOW);

        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);

        break;
    case 2:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, LOW);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        break;

    case 3:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, LOW);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        break;

    case 4:

        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, LOW);

        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);

        break;

    case 5:
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, LOW);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);
        break;

    case 6:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        break;

    case 7:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, LOW);
        break;

    case 8:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        break;

    case 9:
        digitalWrite(SEGMENT_DISPLAY_1_UP_LEFT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_RIGHT - displayIndex, HIGH);

        digitalWrite(SEGMENT_DISPLAY_1_MIDDLE - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP_RIGHT - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_UP - displayIndex, HIGH);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN_LEFT - displayIndex, LOW);
        digitalWrite(SEGMENT_DISPLAY_1_DOWN - displayIndex, HIGH);
        break;

    default:
        break;
    }
};