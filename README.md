# 🚪 Touchless Door Opener using Ultrasonic Sensor, Servo, OLED & Buzzer

This Arduino-based project opens and closes a door automatically when someone’s hand is detected nearby — **no physical touch required**. It uses an ultrasonic sensor to detect proximity, rotates a servo to open the door, and displays the status on an OLED screen with a buzzer beep for feedback.

---

## 🛠️ Components Used

| Component              | Quantity | Description                              |
|-----------------------|----------|------------------------------------------|
| Arduino Mega 2560     | 1        | Microcontroller board                    |
| HC-SR04 Ultrasonic Sensor | 1    | Detects nearby hand                      |
| SG90 Servo Motor      | 1        | Controls door movement                   |
| 0.96" OLED Display (I2C) | 1     | Shows "OPEN" / "CLOSED" status           |
| Buzzer                | 1        | Audio feedback when door opens/closes    |
| Jumper Wires & Breadboard | 1    | For connections                          |

---

## ⚙️ Features

- **Touchless activation** using ultrasonic sensor
- **Auto-open/close door** based on hand proximity
- **OLED display** shows live status (`OPEN`, `CLOSED`)
- **Buzzer sound** on open/close for feedback
- Low-power and safe for hygiene-critical environments

---

## 📷 Setup Image

<p align="center">
  <img src="photos/setup.jpg" width="400" alt="Touchless Door Setup"/>
</p>

---

## 🔌 Wiring

| Device       | Arduino Mega Pin |
|--------------|------------------|
| HC-SR04 Trig | D9               |
| HC-SR04 Echo | D8               |
| SG90 Servo   | D7               |
| OLED SCL     | 21 (SCL)         |
| OLED SDA     | 20 (SDA)         |
| Buzzer       | D6               |

---

## 🚀 How It Works

1. The ultrasonic sensor constantly checks for nearby objects.
2. If a hand is detected within 15 cm:
   - The servo rotates to open the door.
   - OLED displays “OPEN”
   - Buzzer beeps once.
3. After a short delay, the servo closes the door, and OLED shows “CLOSED”.

---

## 🧠 Use Cases

- Hospital isolation wards
- Clean rooms / labs
- Public restrooms
- Smart home entrances

---

## 🧪 Getting Started

1. Clone this repo:
   ```bash
   git clone https://github.com/samshoni/Touchless-Door-Opener.git
