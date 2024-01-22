#include "recieveData.h"

scores_message receivedData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&receivedData, incomingData, sizeof(receivedData));
  setScores(receivedData.scoreA, receivedData.scoreB);
  Serial.print("Score A: ");
  Serial.println(receivedData.scoreA);
  Serial.print("Score B: ");
  Serial.println(receivedData.scoreB);
  Serial.println();
}