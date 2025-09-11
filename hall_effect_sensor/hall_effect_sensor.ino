const int hallPin1 = 4;
const int hallPin2 = 6;
const int hallPin3 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(hallPin1, INPUT);
  pinMode(hallPin2, INPUT);
  pinMode(hallPin3, INPUT);
}

void loop() {
  int hallState1 = digitalRead(hallPin1);
  int hallState2 = digitalRead(hallPin2);
  int hallState3 = digitalRead(hallPin3);
  
  Serial.print("H1: ");
  Serial.println(hallState1);

  delay(100); // Adjust delay as needed
}
