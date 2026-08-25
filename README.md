# 🎙️ Voice Controlled Home Automation

A simple **voice-controlled home automation system** using an **ESP32**, **DFRobot DF2301Q (SEN0539) Voice Recognition Module**, and a **2-channel relay module** to control devices such as a **light/bulb and fan** through voice commands.

## 📌 Project Overview

This project allows you to control electrical appliances using predefined voice commands.

The **DF2301Q voice recognition module** recognizes the spoken command and sends a corresponding **Command ID** to the ESP32. The ESP32 then controls the relay module according to the received command.

### Features

* 🎙️ Offline voice command recognition
* 💡 Voice-controlled light/bulb
* 🌀 Voice-controlled fan
* ⚡ ESP32-based control system
* 🔌 2-channel relay module
* 📡 I2C communication with the voice recognition module
* 🖥️ Serial Monitor support for debugging

---

## 🛠️ Components Required

| Component                                          |    Quantity |
| -------------------------------------------------- | ----------: |
| ESP32 DevKit V1                                    |           1 |
| DFRobot DF2301Q / SEN0539 Voice Recognition Module |           1 |
| 2-Channel Relay Module                             |           1 |
| Bulb / Light                                       |           1 |
| Fan                                                |           1 |
| Speaker                                            |           1 |
| Jumper Wires                                       | As required |
| 5V Power Supply                                    |           1 |

---

## 🔌 Pin Connections

### ESP32 → Relay Module

| Relay Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 5V        |
| GND       | GND       |
| IN1       | GPIO 25   |
| IN2       | GPIO 26   |

### DF2301Q → ESP32

| DF2301Q Pin | ESP32 Pin     |
| ----------- | ------------- |
| VCC         | 5V*           |
| GND         | GND           |
| TXD         | GPIO 16 (RX2) |
| RXD         | GPIO 17 (TX2) |

> **Note:** Check your specific DF2301Q/SEN0539 board's power and interface specifications before connecting it directly to the ESP32.

### I2C Version

If your library configuration uses the **I2C version** of the DF2301Q module:

| DF2301Q | ESP32   |
| ------- | ------- |
| SDA     | GPIO 21 |
| SCL     | GPIO 22 |
| VCC     | 5V*     |
| GND     | GND     |

---

## 🎤 Voice Commands

The project uses the following command IDs:

| Voice Command      | Command ID | Action    |
| ------------------ | ---------: | --------- |
| Turn on the light  |        103 | Light ON  |
| Turn off the light |        104 | Light OFF |
| Turn on the fan    |         75 | Fan ON    |
| Turn off the fan   |         76 | Fan OFF   |

The command IDs can be changed according to the commands configured in the DF2301Q voice recognition module.

---

## ⚙️ Working Principle

```text
        Voice Command
              │
              ▼
   ┌─────────────────────┐
   │ DF2301Q Voice       │
   │ Recognition Module  │
   └──────────┬──────────┘
              │
         Command ID
              │
              ▼
       ┌──────────────┐
       │    ESP32     │
       │ Controller   │
       └──────┬───────┘
              │
       ┌──────┴───────┐
       ▼              ▼
   Relay CH1       Relay CH2
       │              │
       ▼              ▼
     Light           Fan
```

For example:

**"Turn on the light" → Command ID 103 → ESP32 → Relay 1 ON → Light ON**

---

## 💻 Software

### Required Software

* Arduino IDE
* ESP32 Board Package
* DFRobot DF2301Q Library

### Required Library

```cpp
#include "DFRobot_DF2301Q.h"
```

Install the required DFRobot library through the Arduino IDE Library Manager or from the DFRobot library repository.

---

## 🚀 Installation

### 1. Install ESP32 Board Support

Add ESP32 board support to Arduino IDE and select:

```text
ESP32 Dev Module
```

### 2. Install the DF2301Q Library

Install the **DFRobot_DF2301Q** library.

### 3. Connect the Hardware

Connect the ESP32, DF2301Q module and relay module according to the wiring table above.

### 4. Upload the Code

Open the Arduino sketch and select the correct:

* Board
* COM Port
* Upload speed

Then upload the program to the ESP32.

### 5. Test Voice Commands

Open the Serial Monitor at:

```text
115200 baud
```

Speak the configured commands and check the received Command ID.

---

## 🔧 Relay Logic

This project assumes an **Active-LOW relay module**.

```cpp
digitalWrite(lightRelay, LOW);   // Light ON
digitalWrite(lightRelay, HIGH);  // Light OFF

digitalWrite(fanRelay, LOW);     // Fan ON
digitalWrite(fanRelay, HIGH);    // Fan OFF
```

If your relay module is **Active-HIGH**, reverse these HIGH/LOW values.

---

## 📷 Wiring Diagram

chack ckt-diagram in the repository:

---

## ⚠️ Safety Warning

The relay output may be connected to **AC mains appliances** such as bulbs and fans.

**Do not work with mains voltage unless you are properly trained and qualified.** Use appropriate insulation, enclosure, fuses/protection, and a correctly rated relay. For a student prototype, testing with a low-voltage load is strongly recommended.

---

## 🔮 Future Improvements

* [ ] Add more appliances
* [ ] Add Wi-Fi control
* [ ] Create a mobile/web dashboard
* [ ] Add appliance status monitoring
* [ ] Add manual switches
* [ ] Add MQTT/Home Assistant integration
* [ ] Add password/security features
* [ ] Add energy monitoring

---

## 👨‍💻 Author

**Sgour**

### Project

**ESP32 Voice Controlled Home Automation**

Built using **ESP32 + DFRobot DF2301Q + Relay Module**.

---

## ⭐ Support

If you find this project useful, consider giving the repository a ⭐ on GitHub!
