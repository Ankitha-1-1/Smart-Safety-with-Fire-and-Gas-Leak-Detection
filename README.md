# 🔥 Smart Safety with Fire and Gas Leak Detection

An IoT-based safety and monitoring system designed to detect **gas leakage and abnormal temperature conditions** in homes, laboratories, and other indoor environments.

The system continuously monitors the environment using an **MQ2 gas sensor** and an **LM35 temperature sensor**. When a dangerous gas level or high temperature is detected, the system activates a **buzzer alarm**, displays the warning on a **16×2 LCD**, and sends an **SMS alert through the SIM800L GSM module**.

---

## 📌 Project Overview

Fire and gas leakage are major safety hazards that can result in property damage, injuries, and loss of life if they are not detected quickly.

The **Smart Safety with Fire and Gas Leak Detection** system provides an affordable and automated solution for early detection.

The Arduino UNO acts as the main controller. It receives sensor readings from the MQ2 gas sensor and LM35 temperature sensor, processes the readings against predefined safety thresholds, and activates appropriate warning mechanisms.

### Main functions

- 🌡️ Real-time temperature monitoring
- 💨 Gas and smoke detection
- 🚨 Automatic buzzer alarm
- 📟 LCD warning and monitoring display
- 📱 SMS notification using GSM
- ⚡ Continuous environmental monitoring

---

## 🎯 Objectives

The main objectives of this project are:

1. To continuously monitor temperature and gas levels.
2. To detect potentially dangerous gas leakage.
3. To identify abnormal temperature conditions that may indicate a fire hazard.
4. To provide an immediate local warning using a buzzer.
5. To display sensor readings and warning messages on an LCD.
6. To notify a user remotely through SMS.
7. To develop a low-cost and easily deployable safety system.

---

## 🏗️ System Architecture

The system consists of sensing, processing, display, and alert components.

```text
                  
                         ┌─────────────────────┐  
                         │     POWER SUPPLY    │
                         └──────────┬──────────┘
                                    │
                                    ▼
        ┌───────────────────────────────────────────────┐
        │                 ARDUINO UNO                   │
        │              MAIN CONTROLLER                  │
        │                                               │
        │  • Reads sensor values                        │
        │  • Checks safety thresholds                   │
        │  • Controls alarm and display                 │
        │  • Triggers GSM notification                  │
        └───────┬──────────────┬───────────────┬────────┘
                │              │               │
       Sensor Inputs           │          Alert / Output
                │              │               │
        ┌───────┴───────┐      │      ┌────────┴─────────┐
        │               │      │      │                  │
        ▼               ▼      ▼      ▼                  ▼
 ┌─────────────┐ ┌─────────────┐ ┌──────────┐    ┌─────────────┐
 │    LM35     │ │     MQ2     │ │ 16×2 LCD │    │   Buzzer    │
 │ Temperature │ │ Gas / Smoke │ │ Display  │    │   Alarm     │
 │   Sensor    │ │   Sensor    │ └──────────┘    └─────────────┘
 └─────────────┘ └─────────────┘
                                             
                                      ┌─────────────────┐
                                      │     SIM800L     │
                                      │   GSM MODULE    │
                                      └────────┬────────┘
                                               │
                                               ▼
                                      ┌─────────────────┐
                                      │    SMS ALERT    │
                                      │   User's Phone  │
                                      └─────────────────┘
