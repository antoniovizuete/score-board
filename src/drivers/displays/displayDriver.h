#ifndef DISPLAYDRIVER_H_
#define DISPLAYDRIVER_H_

#include "../devices/device.h"

typedef void (*AlternateFunction)(void);
typedef void (*DriverInitFunction)(void);
typedef void (*ScreenFunction)(void);
typedef void (*DrawScoreBoardFunction)(unsigned int scoreA, unsigned int scoreB);
typedef void (*DrawWinnerFunction)(char *winner );

typedef struct
{
  DriverInitFunction initDisplay;
  AlternateFunction alternateScreenState;
  AlternateFunction alternateScreenRotation;
  DrawScoreBoardFunction drawScoreBoard;
  ScreenFunction clearScreen;
  DrawWinnerFunction drawWinner;
  int score_a;
  int score_b;
} DisplayDriver;

extern DisplayDriver *currentDisplayDriver;
extern DisplayDriver tDisplayDriver;

#endif // DISPLAYDRIVER_H_

void drawScoreA(unsigned int scoreA);
