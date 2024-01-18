#include <Arduino.h>
#include "display.h"

DisplayDriver *currentDisplayDriver = &tDisplayDriver;
int maxScore = 5;

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
  if (currentDisplayDriver->score_a > maxScore || currentDisplayDriver->score_b >= maxScore)
  {
    resetScores();
    return;
  }
  if (currentDisplayDriver->score_a == maxScore)
  {
    drawScoreBoard();
    delay(500);
    currentDisplayDriver->drawWinner("A");
    return;
  }
  drawScoreBoard();
}
void increaseScoreB()
{
  currentDisplayDriver->score_b++;
  if (currentDisplayDriver->score_b > maxScore || currentDisplayDriver->score_a >= maxScore)
  {
    resetScores();
    return;
  }
  if (currentDisplayDriver->score_b == maxScore)
  {
    drawScoreBoard();
    delay(500);
    currentDisplayDriver->drawWinner("B");
    return;
  }
  drawScoreBoard();
}
void decreaseScoreA()
{
  currentDisplayDriver->score_a = currentDisplayDriver->score_a == 0 ? 0 : currentDisplayDriver->score_a - 1;
  drawScoreBoard();
}
void decreaseScoreB()
{
  currentDisplayDriver->score_b = currentDisplayDriver->score_b == 0 ? 0 : currentDisplayDriver->score_b - 1;
  drawScoreBoard();
}

void resetScores()
{
  currentDisplayDriver->score_a = 0;
  currentDisplayDriver->score_b = 0;
  drawScoreBoard();

}

void drawScoreBoard()
{
  currentDisplayDriver->clearScreen();
  currentDisplayDriver->drawScoreBoard(currentDisplayDriver->score_a, currentDisplayDriver->score_b);
}
