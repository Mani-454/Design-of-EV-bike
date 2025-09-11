// Import the Serial library
import processing.serial.*;

Serial myPort; // The serial port object
int throttle = 0; // Variable to hold the throttle value (0-255)
int rectX = 50;
int rectY = 50;
int rectW = 100;
int rectH = 300;

void setup() {
  size(400, 400); // Create a 400x400 window
  
  // List all available serial ports. You might need to change the [0]
  // to the correct port number for your Arduino.
  printArray(Serial.list());
  String portName = "COM10"; 
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(220); // Light grey background
  fill(100);
  rect(rectX, rectY, rectW, rectH); // Draw the throttle area
  
  // Draw the throttle indicator
  fill(255, 0, 0); // Red
  float indicatorY = map(throttle, 0, 255, rectY + rectH, rectY);
  ellipse(rectX + rectW/2, indicatorY, 40, 40);
  
  // Send the throttle value to the Arduino
  myPort.write(throttle);
  
  // Display the current throttle value
  fill(0);
  textSize(20);
  text("Throttle: " + throttle, 170, 40);
}

// This function runs whenever the mouse is dragged
void mouseDragged() {
  // Check if the mouse is inside the throttle rectangle
  if (mouseX > rectX && mouseX < rectX + rectW && mouseY > rectY && mouseY < rectY + rectH) {
    // Map the mouse's vertical position to a 0-255 throttle value
    throttle = (int) map(mouseY, rectY + rectH, rectY, 0, 255);
  }
}
