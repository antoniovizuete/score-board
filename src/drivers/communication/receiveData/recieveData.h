#ifndef __RECEIVE_DATA_H__
#define __RECEIVE_DATA_H__

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include "../data.h"
#include "../../displays/display.h"

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);

#endif // __RECEIVE_DATA_H__