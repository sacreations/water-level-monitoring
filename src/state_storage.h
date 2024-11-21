#include <Preferences.h>

Preferences preferences;

// Save Wi-Fi credentials
void saveWiFiCredentials(const String& ssid, const String& password) {
    preferences.begin("wifi", false);
    preferences.putString("ssid", ssid);
    preferences.putString("password", password);
    preferences.end();
    Serial.println("Wi-Fi credentials saved!");
}

// Load Wi-Fi credentials
void loadWiFiCredentials(String& ssid, String& password) {
    preferences.begin("wifi", true);
    ssid = preferences.getString("ssid", "");
    password = preferences.getString("password", "");
    preferences.end();
}

// Save motor state
void saveMotorState(const String& state) {
    preferences.begin("motor", false);
    preferences.putString("state", state);
    preferences.end();
    Serial.println("Motor state saved!");
}

// Load motor state
String loadMotorState() {
    preferences.begin("motor", true);
    String state = preferences.getString("state", "OFF"); // Default to "OFF"
    preferences.end();
    return state;
}

// Save water level maintenance mode
void saveWaterLevelMode(int level) {
    preferences.begin("water_mode", false);
    preferences.putInt("level", level);
    preferences.end();
    Serial.println("Water level mode saved!");
}

// Load water level maintenance mode
int loadWaterLevelMode() {
    preferences.begin("water_mode", true);
    int level = preferences.getInt("level", 50); // Default to 50%
    preferences.end();
    return level;
}
