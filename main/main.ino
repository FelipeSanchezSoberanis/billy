#include <Servo.h>

#define ANGLE_STEP 45;

Servo servo;

int angle;
String input;

void setup() {
    Serial.begin(9600);

    servo.attach(9);

    angle = 0;
    input = "";
}

void loop() {
    if (Serial.available()) {
        input = Serial.readString();
        input.trim();
        input.toLowerCase();
    }

    if (input == "spin") {
        angle += ANGLE_STEP;
        servo.write(angle);
        input = "";
    }

    if (input == "reset") {
        angle = 0;
        servo.write(angle);
        input = "";
    }
}
