#include <Arduino.h>
#include <OneButton.h>
#include <WiFi.h>
#include <esp_now.h>

#include "drivers/displays/display.h"
#include "drivers/communication/espnow.h"

OneButton button1(PIN_BUTTON_1);
OneButton button2(PIN_BUTTON_2);

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void setup()
{
  
  Serial.begin(115200);
  Serial.setTimeout(0);
  delay(100);
  Serial.println("Starting 'Goal tracker'...");

  initEspNow(broadcastAddress);

  button1.setPressMs(2000);
  button1.attachClick(increaseScoreA);
  button1.attachDoubleClick(decreaseScoreA);
  button1.attachDuringLongPress(resetScores);

  button2.setPressMs(2000);
  button2.attachClick(increaseScoreB);
  button2.attachDoubleClick(decreaseScoreB);

  initDisplay(broadcastAddress);

  drawScoreBoard(false);
}

void loop() {
  // keep watching the push buttons:
  button1.tick();
  button2.tick();
}
