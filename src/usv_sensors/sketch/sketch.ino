#include <Arduino.h>
#include <Arduino_RouterBridge.h>
// #include <OneWire.h>   // 수온 센서 미사용
// #include <SPI.h>       // WS2812 LED 미사용
#include <math.h>
// #include "adc_accumulator.h"

// =================================================
// 분수 펌프 릴레이 (NEROMART RELAY-M1(CH1)-5V, 옵토 입력 Active LOW)
//
// 배선:
//   릴레이 VCC -> 아두이노 3.3V   (★ 5V에서 변경.
//                 Uno Q GPIO가 3.3V라 VCC=5V면 IN=HIGH일 때도
//                 옵토 LED 양단에 1.7V가 남아 릴레이가 안 떨어졌음)
//   릴레이 GND -> 아두이노 GND
//   릴레이 IN  -> 아두이노 D7
//   12V 배터리 + -> 릴레이 COM,  릴레이 NO -> 펌프 +
//   12V 배터리 - -> 펌프 -       (배터리 GND와 보드 GND는 연결하지 않음)
// =================================================
const int PUMP_PIN = 7;
const bool PUMP_ACTIVE_LOW = true;   // VCC를 3.3V로 옮겨도 극성은 그대로

bool pumpOn = false;


// =================================================
// 미사용 센서 설정 (수온 / pH / DO / 탁도 / GPS / LED)
// =================================================
/*
#define TEMP_PIN 4
#define PH_PIN A1
#define DO_PIN A5
#define TURBIDITY_PIN A0

#define NUMPIXELS 15
#define LED_DATA_PIN 11
const int LED_BRIGHTNESS = 50;
const uint32_t LED_SPI_HZ = 3000000;
#define LED_RESET_BYTES 4
#define LED_LATCH_US 300
uint32_t ledLastShowUs = 0;
uint8_t ledSpiBuf[LED_RESET_BYTES + NUMPIXELS * 12 + LED_RESET_BYTES];
uint8_t ledPixels[NUMPIXELS][3];

#define ADC_BITS 12
#define ADC_MAX 4095.0
#define ADC_REFERENCE_V 3.3
#define ADC_REFERENCE_MV 3300.0
#define SAMPLE_COUNT 40

#define PH7_BUFFER_VALUE 7.00
