# HealthPad

*HealthPad: LED-guided pill reminder and tracking system for daily medication adherence.*

---

## Table of Contents

* [Overview](#overview)
* [Features](#features)
* [Hardware Requirements](#hardware-requirements)
* [Software Setup](#software-setup)
* [Installation](#installation)
* [Usage](#usage)
* [Development](#development)
* [Contributing](#contributing)
* [License](#license)
* [Troubleshooting](#troubleshooting)
* [Credits](#credits)

---

## Overview

> This repository contains firmware and related code for the HealthPad, a consumer device that reminds users when to take their medication via LED indicators and tracks pill usage with magnetic sensors.

---

## Features

* LED ring for real-time pill reminders
* Magnetic sensor for pill bottle detection
* Mobile integration via Bluetooth/WiFi
* Local data logging and sync
* OTA (Over-the-Air) firmware updates
---

## Hardware Requirements

* HealthPad 2025
---

## Software Setup

* PlatformIO / Arduino IDE
* ESP32 board support package
* Adafruit NeoPixel Library
* Wifi.h library 

---

## Usage

1. Plug in the device.
2. Upload script while holding down "download" button on ESP32
4. Place pill bottles with attached magnets on the pad.
5. When it's time to take your pill, the LED will turn red.
6. Once the bottle is removed and returned, the status will update to blue (pill taken).

---

## Troubleshooting

| Issue                       | Solution                                              |
| --------------------------- | ----------------------------------------------------- |
| LEDs not lighting up        | Check power supply and LED data pin connection        |
| Sensor not detecting bottle | Ensure magnet polarity is correct and sensor is wired |
| WiFi not connecting         | Double-check `wifi_credentials.h` or serial monitor   |

---

## Credits


| Cavan Bannon | HealthPoint |
| ------------ | ----------- |

---

