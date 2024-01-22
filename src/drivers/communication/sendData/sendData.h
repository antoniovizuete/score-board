#ifndef __SEND_DATA_H__
#define __SEND_DATA_H__

#include <Arduino.h>
#include <esp_now.h>

#include "sendData.h"
#include "../data.h"

void sendData(unsigned int scoreA, unsigned int scoreB, uint8_t broadcastAddress[]);
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);

#endif //__SEND_DATA_H__