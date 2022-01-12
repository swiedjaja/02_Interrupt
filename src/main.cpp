// use interrupt to detect switch
#include <Arduino.h>
#include "device.h"

const uint8_t arLed[3] = {LED_RED, LED_YELLOW, LED_GREEN};
volatile int nCount = 0;
IRAM_ATTR void onResetCounter()
{
  nCount = 0;
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  #if defined(LED_FLASH)    
    pinMode(LED_FLASH, OUTPUT);
  #endif    
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(PIN_SW, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_SW), onResetCounter, FALLING); // extra checking
  // attachInterrupt(PIN_SW, onResetCounter, FALLING); // no checking
  Serial.println("System ready...");
}

void loop() {
  Serial.printf("Hello World %d\n", nCount);
  digitalWrite(arLed[nCount%3], LED_ON);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_ON);
  delay(100);
  digitalWrite(arLed[nCount%3], LED_OFF);
  digitalWrite(LED_BUILTIN, LED_BUILTIN_OFF);
  nCount++;
  delay(900);
}