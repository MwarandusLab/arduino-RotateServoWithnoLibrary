const int servoPin = 9; // Servo signal pin

void setup() {
  pinMode(servoPin, OUTPUT);
}

void loop() {
  rotateFrom0To90(); // Rotate servo from 0 to 90 degrees
  delay(1000); // Wait for 1 second
  rotateFrom90To0(); // Rotate servo from 90 to 0 degrees
  delay(1000); // Wait for 1 second
}

void rotateToAngle(int angle) {
  int pulseWidth = map(angle, 0, 180, 544, 2400); // Map angle to pulse width range
  digitalWrite(servoPin, HIGH); // Start the pulse
  delayMicroseconds(pulseWidth); // Wait for the appropriate length of time
  digitalWrite(servoPin, LOW); // End the pulse
  delay(20); // A small delay to make sure the servo recognizes the end of the command
}

void rotateFrom0To90() {
  for (int angle = 0; angle <= 90; angle++) {
    rotateToAngle(angle);
    delay(15); // Adjust the speed of rotation
  }
}

void rotateFrom90To0() {
  for (int angle = 90; angle >= 0; angle--) {
    rotateToAngle(angle);
    delay(15); // Adjust the speed of rotation
  }
}
