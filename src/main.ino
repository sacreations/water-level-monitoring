#include <Arduino.h>
#include "bluetooth_setup.h"
#include "network_config.h"
#include "motor_controller.h"
#include "api_requests.h"
#include "state_storage.h"

void setup() {
    Serial.begin(115200);

    setupBluetooth();
    setupMotorController();

    // Load saved states
    loadWiFiCredentials(ssid, password);
    int savedMode = loadWaterLevelMode();
    Serial.printf("Desired Water Level: %d%%\n", savedMode);

    if (ssid != "" && password != "") {
        connectToWiFi();
    }
}

void loop() {
    // Check and maintain Wi-Fi connection
    checkWiFiConnection();

    // Listen for Bluetooth commands
    listenForCommands();

    // Fetch current water level from the API
    int waterLevel = fetchWaterLevel();
    if (waterLevel != -1) {
        // Load the desired water level mode
        int mode = loadWaterLevelMode();
        controlMotor(waterLevel, mode);
    }

    delay(10000); // Poll every 10 seconds
}
