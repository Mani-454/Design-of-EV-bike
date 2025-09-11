#include <Servo.h>

Servo myESC;

void setup() {
  Serial.begin(9600);
  myESC.attach(9, 1000, 2000); // Attach to pin 9

  // Wait for user to open Serial Monitor
  Serial.println("--- ESC Calibration Sketch ---");
  Serial.println("INSTRUCTIONS:");
  Serial.println("1. Keep your main battery DISCONNECTED.");
  Serial.println("2. Type 'max' and press Enter to begin.");
  while (Serial.available() == 0) {
    // Wait for input
  }
  Serial.readString(); // Clear the input buffer

  // --- Step 1: Send MAX Throttle ---
  myESC.writeMicroseconds(2000);
  Serial.println("\nMax throttle signal (2000µs) sent.");
  Serial.println("--> NOW, connect your main LiPo battery to the ESC.");
  Serial.println("--> Wait for the musical tones and then two beeps.");
  Serial.println("--> Once you hear the two beeps, type 'min' and press Enter.");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "min") {
      // --- Step 2: Send MIN Throttle ---
      myESC.writeMicroseconds(1000);
      Serial.println("\nMin throttle signal (1000µs) sent.");
      Serial.println("--> You should hear a long confirmation beep.");
      Serial.println("Calibration is complete. The ESC is now armed.");
      Serial.println("You can type values between 1000 and 2000 to test the motor.");
    } else {
      // --- Motor Testing ---
      int throttleValue = command.toInt();
      if (throttleValue >= 1000 && throttleValue <= 2000) {
        myESC.writeMicroseconds(throttleValue);
        Serial.print("Motor speed set to: ");
        Serial.println(throttleValue);
      }
    }
  }
}
