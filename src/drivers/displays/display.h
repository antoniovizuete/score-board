#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "displayDriver.h"

extern DisplayDriver *currentDisplayDriver;

void initDisplay(uint8_t broadcastAddress[]);
void alternateScreenState();
void alternateScreenRotation();
void increaseScoreA();
void increaseScoreB();
void decreaseScoreA();
void decreaseScoreB();
void resetScores();
void drawScoreBoard(bool send);
void setScores(int scoreA, int scoreB);


#endif // DISPLAY_H
