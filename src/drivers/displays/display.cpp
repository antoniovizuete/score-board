#include "display.h"

DisplayDriver *currentDisplayDriver = &tDisplayDriver;

// Initialize the display
void initDisplay()
{
  currentDisplayDriver->initDisplay();
}

// Alternate screen state
void alternateScreenState()
{
  currentDisplayDriver->alternateScreenState();
}

// Alternate screen rotation
void alternateScreenRotation()
{
  currentDisplayDriver->alternateScreenRotation();
}

void increaseScoreA()
{
  currentDisplayDriver->score_a++;
  currentDisplayDriver->clearScreen();
  drawScoreBoard();
}
void increaseScoreB()
{
  currentDisplayDriver->score_b++;
}
void decreaseScoreA()
{
  currentDisplayDriver->score_a--;
}
void decreaseScoreB()
{
  currentDisplayDriver->score_b--;
}

void resetScores()
{
  currentDisplayDriver->score_a = 0;
  currentDisplayDriver->score_b = 0;
}

void drawScoreBoard()
{
  currentDisplayDriver->drawScoreBoard(currentDisplayDriver->score_a, currentDisplayDriver->score_b);
}
