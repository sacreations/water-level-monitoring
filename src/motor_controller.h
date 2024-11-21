#define MOTOR_PIN 5 // GPIO pin connected to motor relay

void setupMotorController() {
    pinMode(MOTOR_PIN, OUTPUT);
    digitalWrite(MOTOR_PIN, LOW); // Motor OFF by default
}

// Turn the motor ON
void turnMotorOn() {
    digitalWrite(MOTOR_PIN, HIGH);
    saveMotorState("ON");
    Serial.println("Motor turned ON.");
}

// Turn the motor OFF
void turnMotorOff() {
    digitalWrite(MOTOR_PIN, LOW);
    saveMotorState("OFF");
    Serial.println("Motor turned OFF.");
}

// Control motor based on water level and mode
void controlMotor(int waterLevel, int mode) {
    if (waterLevel < mode) {
        turnMotorOn();
    } else {
        turnMotorOff();
    }
}
