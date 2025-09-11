// Pins connected to Hall sensors
const int hallSensor1Pin = 2; // e.g. green wire sensor
const int hallSensor2Pin = 3; // e.g. yellow wire sensor
const int hallSensor3Pin = 4; // e.g. blue wire sensor

void setup() {
  Serial.begin(9600);
  pinMode(hallSensor1Pin, INPUT);
  pinMode(hallSensor2Pin, INPUT);
  pinMode(hallSensor3Pin, INPUT);
  
  Serial.println("Starting Hall sensor alignment test...");
  Serial.println("Sensor1  Sensor2  Sensor3");
}

void loop() {
  int sensor1State = digitalRead(hallSensor1Pin);
  int sensor2State = digitalRead(hallSensor2Pin);
  int sensor3State = digitalRead(hallSensor3Pin);

  Serial.print(sensor1State);
  Serial.print("          ");
  Serial.print(sensor2State);
  Serial.print("          ");
  Serial.println(sensor3State);

  delay(100); // Adjust delay for easier observation
}
