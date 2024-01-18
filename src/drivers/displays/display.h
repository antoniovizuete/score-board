#ifndef DISPLAY_H
#define DISPLAY_H

#include "displayDriver.h"

extern DisplayDriver *currentDisplayDriver;

void initDisplay();
void alternateScreenState();
void alternateScreenRotation();
void increaseScoreA();
void increaseScoreB();
void decreaseScoreA();
void decreaseScoreB();
void resetScores();
void drawScoreBoard();


#endif // DISPLAY_H
