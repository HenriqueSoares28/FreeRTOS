/*

// Touch read example

#include <Arduino.h>
#define TOUCH_PIN 32
void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    if(touchRead(TOUCH_PIN) < 50){
        Serial.println("Touch detected");
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else{
        Serial.println("Touch not detected");
        digitalWrite(LED_BUILTIN, LOW);
    }
    delay(100);
}
*/