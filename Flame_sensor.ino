#define BUZZER_PIN D3  // Pin connected to the Buzzer
#define SENSOR_PIN D0  // Pin connected to the Flame Sensor

void setup() {
  Serial.begin(115200);          // Start serial communication at 115200 baud rate
  pinMode(BUZZER_PIN, OUTPUT);   // Set the Buzzer pin as OUTPUT
  pinMode(SENSOR_PIN, INPUT);    // Set the Flame Sensor pin as INPUT
}

void loop() {
  int sensorValue = digitalRead(SENSOR_PIN); // Read the flame sensor value
  
  if (sensorValue == LOW) { // Flame detected (sensor output LOW)
    Serial.println("WARNING! A flame has been detected.");
    digitalWrite(BUZZER_PIN, HIGH); // Turn on the Buzzer
  } else {
    Serial.println("No flame detected.");
    digitalWrite(BUZZER_PIN, LOW); // Turn off the Buzzer
  }
  
  delay(1000); // Wait for a second before the next reading
}
