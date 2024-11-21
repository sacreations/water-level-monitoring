
# Water Level Monitoring System

## Overview
This project is designed to monitor water levels, control a motor based on user-defined settings, and provide wireless configuration using Wi-Fi and Bluetooth.

---

## Features
1. Fetch and update water level data from a cloud-based API.
2. Control motor state (ON/OFF) based on water level and user-defined mode.
3. Bluetooth setup for configuring Wi-Fi credentials and water level mode.
4. Saves and restores motor state, water level mode, and Wi-Fi credentials.

---

## System Requirements
- ESP32
- Relay module (for motor control)
- Cloud API (supports HTTP GET and POST requests)
- Ultrasonic sensor for get water level
- MariaDB (for cloud database)

---

## Hardware Connections
| Component        | GPIO Pin |
|-------------------|----------|
| Motor Relay       | GPIO 5   |
| Bluetooth (Built-in) | N/A  |

---

## How It Works
1. **Wi-Fi Configuration**:
   - Bluetooth is used to set Wi-Fi credentials.
   - Credentials are stored in non-volatile memory.

2. **Motor Control**:
   - Motor turns ON when water level is below the desired percentage (set by the user).
   - Motor turns OFF when the water level is sufficient.

3. **Cloud Integration**:
   - Updates motor state using `POST /motor`.
   - Updates water level using `POST /api/water-level`

4. **Bluetooth Commands**:
   - Set Wi-Fi credentials: `SSID:<SSID> PASS:<PASSWORD>`
   - Set water level mode: `MODE:<LEVEL>`

---

## API Endpoints
| Endpoint                | Method | Description                           |
|-------------------------|--------|---------------------------------------|
| `/api/water-level`      | POST   | Update the water level (from the app) |
| `/api/motor`            | GET    | Get the current motor state           |
| `/api/motor`            | POST   | Update the motor state                |

---

## Setup Instructions
1. Clone the repository to your local machine.
2. Open the Arduino IDE.
3. Install required libraries:
   - `WiFi`
   - `HTTPClient`
   - `Preferences`
4. Upload the code to your ESP32.
5. Use Bluetooth to set up Wi-Fi credentials.
6. Monitor serial output for logs and debugging.

---

## Bluetooth Commands
- **Set Wi-Fi**:  
  `SSID:YourSSID PASS:YourPassword`  
- **Set Water Level Mode**:  
  `MODE:DesiredPercentage`  

---

## Project Structure
```
/src
  |-- bluetooth_setup.h    # Handles Bluetooth communication
  |-- network_config.h     # Manages Wi-Fi connection
  |-- motor_controller.h   # Controls motor based on water level
  |-- api_requests.h       # Interacts with cloud API
  |-- state_storage.h      # Saves and loads state data
  |-- main.ino             # Main logic and integration
```

---

## Usage Example
1. Start the ESP32.
2. Use a Bluetooth to configure Wi-Fi :
   - `SSID:HomeWiFi PASS:password123`

3. Once connected, the ESP32 fetches water levels and adjusts the motor state automatically.

---

## Contributing
Feel free to contribute by:
- Improving code.
- Adding new features (e.g., sensor integrations, app interfaces).
