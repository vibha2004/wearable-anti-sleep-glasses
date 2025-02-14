// Pin Definitions
int eyeBlinkPin = A0;       // Eye blink sensor connected to analog pin A0
int buzzerVibratorPin = 13; // Buzzer and vibrator connected to digital pin 13

// Threshold for blink detection (you may need to adjust this based on your sensor)
int blinkThreshold = 300;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize the buzzer and vibrator pin as an OUTPUT
  pinMode(buzzerVibratorPin, OUTPUT);
  
  // Initialize the eye blink sensor pin as an INPUT
  pinMode(eyeBlinkPin, INPUT);
}

void loop() {
  // Read the value from the eye blink sensor
  int sensorValue = analogRead(eyeBlinkPin);
  
  // Print the sensor value to the serial monitor (for debugging)
  Serial.println(sensorValue);

  // If the sensor value exceeds the threshold, blink is detected
  if (sensorValue > blinkThreshold) {
    // Wait for 3 seconds before activating the buzzer and vibrator
    delay(3000);  
      
    // Activate the buzzer and vibrator
    digitalWrite(buzzerVibratorPin, HIGH);  // Turn on buzzer and vibrator
    delay(500);  // Keep them on for 500 milliseconds
    digitalWrite(buzzerVibratorPin, LOW);   // Turn off buzzer and vibrator
  }
  
  // Short delay before reading the sensor again
  delay(100);
}

