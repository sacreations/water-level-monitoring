#include <BluetoothSerial.h>
#include "state_storage.h"

BluetoothSerial SerialBT;

String ssid = "";
String password = "";
int waterLevelMode = 50; // Default mode

void setupBluetooth() {
    SerialBT.begin("ESP32_BT");  // Set Bluetooth name
    Serial.println("Bluetooth started. Waiting for commands...");
}

// Function to listen for commands via Bluetooth
void listenForCommands() {
    if (SerialBT.available()) {
        String input = SerialBT.readStringUntil('\n'); // Read input until newline
        input.trim(); // Remove trailing spaces or newline characters

        if (input.startsWith("SSID:") && input.indexOf("PASS:") != -1) {
            int passIndex = input.indexOf("PASS:");
            ssid = input.substring(5, passIndex).trim();        // Extract SSID
            password = input.substring(passIndex + 5).trim();  // Extract Password
            saveWiFiCredentials(ssid, password);
            SerialBT.println("Wi-Fi credentials saved!");
        } else if (input.startsWith("MODE:")) {
            waterLevelMode = input.substring(5).toInt();
            saveWaterLevelMode(waterLevelMode);
            SerialBT.printf("Water level mode set to %d%%.\n", waterLevelMode);
        } else {
            SerialBT.println("Invalid command! Use SSID:<SSID> PASS:<PASSWORD> or MODE:<LEVEL>");
        }
    }
}
