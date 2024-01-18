#include <Arduino.h>
#include <OneButton.h>

#include "drivers/displays/display.h"

OneButton button1(PIN_BUTTON_1);
OneButton button2(PIN_BUTTON_2);

void setup()
{
  
  Serial.begin(115200);
  Serial.setTimeout(0);
  delay(100);
  Serial.println("Starting 'Goal tracker'...");

  button1.setPressMs(2000);
  button1.attachClick(increaseScoreA);
  button1.attachDoubleClick(decreaseScoreA);
  button1.attachDuringLongPress(resetScores);

  button2.setPressMs(2000);
  button2.attachClick(increaseScoreB);
  button2.attachDoubleClick(decreaseScoreB);

  initDisplay();

  drawScoreBoard();
}

void loop() {
  // keep watching the push buttons:
  button1.tick();
  button2.tick();
}
