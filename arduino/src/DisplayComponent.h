#include "GameState.h"

#ifndef __DISPLAYCOMPONENT_H_INCLUDED__
#define __DISPLAYCOMPONENT_H_INCLUDED__

#define SEGMENT_DISPLAY_1_DOT 2
#define SEGMENT_DISPLAY_1_MIDDLE 35     // yellow
#define SEGMENT_DISPLAY_1_UP_LEFT 33    // blue
#define SEGMENT_DISPLAY_1_UP 31         // green
#define SEGMENT_DISPLAY_1_UP_RIGHT 29   // red
#define SEGMENT_DISPLAY_1_DOWN_LEFT 27  // black
#define SEGMENT_DISPLAY_1_DOWN 25       // orange
#define SEGMENT_DISPLAY_1_DOWN_RIGHT 23 // white

class DisplayComponent
{

public:
    DisplayComponent();

    void setup(int displayIndex, int *score);
    void update();

private:
    int displayIndex;
    int *score;
};

#endif