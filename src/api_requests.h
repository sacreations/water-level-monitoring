#include <HTTPClient.h>

String apiEndpoint = "http://your-api-server.com/api"; // Replace with your API endpoint

// Fetch water level from the API
int fetchWaterLevel() {
    HTTPClient http;
    http.begin(apiEndpoint + "/water-level");
    int httpCode = http.GET();

    if (httpCode == 200) {
        String payload = http.getString();
        int waterLevel = payload.toInt();
        Serial.printf("Fetched water level: %d%%\n", waterLevel);
        http.end();
        return waterLevel;
    } else {
        Serial.printf("Failed to fetch water level. HTTP code: %d\n", httpCode);
        http.end();
        return -1; // Indicates an error
    }
}

// Update motor state to the API
void updateMotorState(String state) {
    HTTPClient http;
    http.begin(apiEndpoint + "/motor");
    http.addHeader("Content-Type", "application/json");

    String payload = "{\"state\":\"" + state + "\"}";
    int httpCode = http.POST(payload);

    if (httpCode == 200) {
        Serial.println("Motor state updated successfully!");
    } else {
        Serial.printf("Failed to update motor state. HTTP code: %d\n", httpCode);
    }

    http.end();
}
