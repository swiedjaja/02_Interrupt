#if defined(ESP8266)
  #define LED_RED    D8
  #define LED_YELLOW D7
  #define LED_GREEN  D6
  #define PIN_SW     D5
#elif defined(ESP32)
  #if !defined(LED_BUILTIN) // ESP32Cam
    #define LED_BUILTIN 33
  #endif
  #define LED_FLASH 4
  #define LED_RED    15
  #define LED_YELLOW 14
  #define LED_GREEN   2
  #define PIN_SW      0
#endif

#define LED_BUILTIN_ON  0
#define LED_BUILTIN_OFF 1

#define LED_ON  1
#define LED_OFF 0
