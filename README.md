# ♿ Arduino-Based Hand Gesture Controlled Wheelchair

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-Nano-00979D?style=for-the-badge&logo=arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/Embedded-C/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Sensor-ADXL335-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Motor%20Driver-L298N-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/PCB-Designed-green?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Project-Robotics-purple?style=for-the-badge"/>
</p>

<p align="center">
  <b>A low-cost gesture-controlled wheelchair prototype based on embedded sensing, 
  directional decision-making, and motor control.</b>
</p>

---

## 📌 Overview

The **Arduino-Based Hand Gesture Controlled Wheelchair** is a low-cost robotic mobility prototype designed to allow a wheelchair user to control movement using simple hand gestures.

Instead of relying on conventional manual wheel rotation or external physical controls, the system uses an **ADXL335 three-axis analog accelerometer** to detect changes in hand orientation and movement.

The accelerometer readings are processed by an **Arduino Nano**, converted into directional control signals, and passed through an encoder-decoder communication stage before reaching the motor-control subsystem.

The system supports four primary movement directions:

- ⬆️ Forward
- ⬇️ Backward
- ⬅️ Left
- ➡️ Right

A stop state is also implemented when the sensor values remain within the defined directional thresholds.

The overall concept was motivated by the goal of developing an accessible and affordable mobility system that could reduce the need for continuous assistance from another person.

---

# 🎯 Project Objectives

The primary objectives of the project were:

- Develop a **low-cost gesture-controlled wheelchair**.
- Reduce the requirement for continuous assistance for physically challenged users.
- Make wheelchair operation simpler and more intuitive.
- Translate natural hand movements into wheelchair navigation commands.
- Build a functional prototype using readily available electronic components.
- Integrate sensing, embedded processing, communication, and motor control into a single system.
- Design supporting PCB layouts for the encoder and decoder circuits.

The project documentation specifically identifies affordability, reduced dependence on assistance, and ease of wheelchair operation as its core objectives.

---

# 🧠 System Concept

The fundamental idea is simple:

```text
        Human Hand Gesture
                │
                ▼
        ┌───────────────┐
        │   ADXL335     │
        │ Accelerometer │
        └───────┬───────┘
                │
          Analog X/Y Data
                │
                ▼
        ┌───────────────┐
        │  Arduino Nano │
        │   Controller  │
        └───────┬───────┘
                │
          Direction Logic
                │
                ▼
        ┌───────────────┐
        │    HT12E      │
        │    Encoder    │
        └───────┬───────┘
                │
        Encoded Data
                │
                ▼
        ┌───────────────┐
        │    HT12D      │
        │    Decoder    │
        └───────┬───────┘
                │
        Direction Signals
                │
                ▼
        ┌───────────────┐
        │    L298N      │
        │ Motor Driver  │
        └───────┬───────┘
                │
          ┌─────┴─────┐
          ▼           ▼
     Left Motor   Right Motor
          │           │
          └─────┬─────┘
                ▼
          Wheelchair Motion
