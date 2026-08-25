#include "DFRobot_DF2301Q.h"
#include <Wire.h>

// Relay pins for Bulb and Fan
#define lightRelay 25
#define fanRelay   26

// ESP32 I2C pins
#define SDA_PIN 21
#define SCL_PIN 22

// I2C communication with SEN0539 / DF2301Q
DFRobot_DF2301Q_I2C asr;

void setup() {
  Serial.begin(115200);

  // Initialize I2C for ESP32
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize relay pins
  pinMode(lightRelay, OUTPUT);
  pinMode(fanRelay, OUTPUT);

  // Relays initially OFF
  // Most relay modules are Active LOW
  digitalWrite(lightRelay, HIGH);
  digitalWrite(fanRelay, HIGH);

  // Initialize SEN0539 voice recognition module
  while (!(asr.begin())) {
    Serial.println("Communication with SEN0539 failed!");
    Serial.println("Check SDA, SCL, VCC and GND connections.");
    delay(3000);
  }

  Serial.println("SEN0539 initialized successfully!");

  // Voice module settings
  asr.setVolume(7);
  asr.setMuteMode(0);
  asr.setWakeTime(255);

  uint8_t wakeTime = asr.getWakeTime();

  Serial.print("Wake-up Time = ");
  Serial.println(wakeTime);
}

void loop() {

  // Get recognized voice command ID
  uint8_t CMDID = asr.getCMDID();

  switch (CMDID) {

    // Turn ON Light
    case 103:
      digitalWrite(lightRelay, LOW);
      Serial.println("Turn ON Light - Command ID: 103");
      break;

    // Turn OFF Light
    case 104:
      digitalWrite(lightRelay, HIGH);
      Serial.println("Turn OFF Light - Command ID: 104");
      break;

    // Turn ON Fan
    case 75:
      digitalWrite(fanRelay, LOW);
      Serial.println("Turn ON Fan - Command ID: 75");
      break;

    // Turn OFF Fan
    case 76:
      digitalWrite(fanRelay, HIGH);
      Serial.println("Turn OFF Fan - Command ID: 76");
      break;

    default:
      if (CMDID != 0) {
        Serial.print("Unknown Command ID = ");
        Serial.println(CMDID);
      }
      break;
  }

  delay(300);
}