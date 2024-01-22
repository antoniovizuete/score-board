#ifndef __ESPNOW_H__
#define __ESPNOW_H__

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include "sendData/sendData.h"
#include "receiveData/recieveData.h"


void initEspNow(uint8_t broadcastAddress[]);

#endif // __ESP_NOW_H__
