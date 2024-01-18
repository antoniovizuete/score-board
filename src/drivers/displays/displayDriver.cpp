#include "displayDriver.h"

#include <TFT_eSPI.h>
#include "media/Free_Fonts.h"

#define WIDTH 340
#define HEIGHT 170

TFT_eSPI tft = TFT_eSPI();              // Invoke library, pins defined in User_Setup.h
TFT_eSprite sprite = TFT_eSprite(&tft); // Invoke library sprite

void fillBackground(void)
{
  sprite.fillRect(0, 0, WIDTH/2, HEIGHT, TFT_RED);
  sprite.fillRect((WIDTH/2) - 1, 0, WIDTH/2, HEIGHT, TFT_GREEN);
}

void displayInitialiaze(void)
{
  tft.init();
  tft.setRotation(3);
  tft.setSwapBytes(true);             // Swap the colour byte order when rendering
  sprite.createSprite(WIDTH, HEIGHT); // Background Sprite
  sprite.setSwapBytes(true);
}

void clearScreen(void)
{
  fillBackground();
  sprite.pushSprite(0, 0);
}

void displayToggleOnOff(void)
{
  int screen_state = digitalRead(TFT_BL);
  Serial.println("Switching display state");
  digitalWrite(TFT_BL, !screen_state);
}

void displayToggleRotation(void)
{
  tft.getRotation() == 1 ? tft.setRotation(3) : tft.setRotation(1);
}

void drawScore(unsigned int score, uint16_t bgColor, int32_t x) {
  sprite.setFreeFont(FMB24);
  sprite.setTextSize(3);
  sprite.setTextColor(TFT_BLACK, bgColor);

  sprite.drawString(std::to_string(score).c_str(), x, 25, GFXFF);
}

void displayDrawScoreBoard(unsigned int scoreA,unsigned int scoreB)
{
  Serial.println("Drawing scoreboard");
  Serial.printf("Score A: %d\n", scoreA);
  Serial.printf("Score B: %d\n", scoreB);

  fillBackground();

  drawScore(scoreA, TFT_RED, (WIDTH / 24) * 3);
  drawScore(scoreB, TFT_GREEN, (WIDTH / 24) * 15);

  sprite.pushSprite(0, 0);
}

DisplayDriver tDisplayDriver = {
    displayInitialiaze,
    displayToggleOnOff,
    displayToggleRotation,
    displayDrawScoreBoard,
    clearScreen,
    0,
    0,
    WIDTH,
    HEIGHT};
