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

  button1.setPressMs(5000);
  button1.attachClick(increaseScoreA);

  button2.setPressMs(5000);
  button2.attachClick(increaseScoreB);

  initDisplay();

  drawScoreBoard();
}

void loop() {
  // keep watching the push buttons:
  button1.tick();
  button2.tick();
}
