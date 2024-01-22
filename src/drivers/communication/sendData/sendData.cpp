#include "sendData.h"

// Create a struct_message called myData
scores_message myData;

void sendData(unsigned int scoreA, unsigned int scoreB, uint8_t broadcastAddress[]) 
{
  // Set values to send
  myData.scoreA = scoreA;
  myData.scoreB = scoreB;
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
   
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
}


void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}