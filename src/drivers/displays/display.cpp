#include <Arduino.h>
#include "display.h"
#include "../communication/espnow.h"

DisplayDriver *currentDisplayDriver = &tDisplayDriver;
int maxScore = 5;
uint8_t* currentBroadcastAddress;

void drawScoreBoard(bool send)
{
  currentDisplayDriver->clearScreen();
  currentDisplayDriver->drawScoreBoard(currentDisplayDriver->score_a, currentDisplayDriver->score_b);
  if (send) {
    sendData(currentDisplayDriver->score_a, currentDisplayDriver->score_b, currentBroadcastAddress);
  }
}

// Initialize the display
void initDisplay(uint8_t broadcastAddress[])
{
  currentDisplayDriver->initDisplay();
  currentBroadcastAddress = broadcastAddress;
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
    drawScoreBoard(true);
    delay(500);
    currentDisplayDriver->drawWinner("A");
    return;
  }
  drawScoreBoard(true);
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
    drawScoreBoard(true);
    delay(500);
    currentDisplayDriver->drawWinner("B");
    return;
  }
  drawScoreBoard(true);
}
void decreaseScoreA()
{
  currentDisplayDriver->score_a = currentDisplayDriver->score_a == 0 ? 0 : currentDisplayDriver->score_a - 1;
  drawScoreBoard(true);
}
void decreaseScoreB()
{
  currentDisplayDriver->score_b = currentDisplayDriver->score_b == 0 ? 0 : currentDisplayDriver->score_b - 1;
  drawScoreBoard(true);
}

void resetScores()
{
  currentDisplayDriver->score_a = 0;
  currentDisplayDriver->score_b = 0;
  drawScoreBoard(true);
}

void setScores(int scoreA, int scoreB)
{
  bool send = false;
  currentDisplayDriver->score_a = scoreA;
  currentDisplayDriver->score_b = scoreB;
  if (currentDisplayDriver->score_a == maxScore)
  {
    drawScoreBoard(send);
    delay(500);
    currentDisplayDriver->drawWinner("A");
    return;
  }
  if (currentDisplayDriver->score_b == maxScore)
  {
    drawScoreBoard(send);
    delay(500);
    currentDisplayDriver->drawWinner("B");
    return;
  }
  drawScoreBoard(send);
}