#include <Servo.h>

const int LDR1Pin = D1;  // GPIO5
const int LDR2Pin = D2;  // GPIO4

Servo solarServo;

void setup() {
  Serial.begin(9600);
  
  solarServo.attach(D4);  // GPIO2, compatible PWM pin on ESP8266

  pinMode(LDR1Pin, INPUT);
  pinMode(LDR2Pin, INPUT);
}

void loop() {
  int LDR1Value = digitalRead(LDR1Pin);
  int LDR2Value = digitalRead(LDR2Pin);

  Serial.print("LDR1: "); Serial.print(LDR1Value);
  Serial.print(" | LDR2: "); Serial.println(LDR2Value);

  if (LDR1Value == LOW && LDR2Value == HIGH) {
    solarServo.write(180);  // Move towards LDR1
  }
  else if (LDR2Value == LOW && LDR1Value == HIGH) {
    solarServo.write(0);  // Move towards LDR2
  }
  else {
    solarServo.write(90);  // Center
  }

  delay(200);
}
