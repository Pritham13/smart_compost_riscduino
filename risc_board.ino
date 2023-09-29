/*
  1. check temp and moisture level, if temp>35 and moisture<30 then run shaft
  2. shaft turns 90 degree to open water gate
  3. right after this motor starts to turn
*/
unsigned long previousMillis=0;
#include <Servo.h> // Include the Servo library to control the servo motor.

Servo myservo; // Create a Servo object named "myservo" to control the servo.
const int ultrasonicTrigPin = 9; // Define the trigger pin for the ultrasonic sensor.
const int ultrasonicEchoPin = 10; // Define the echo pin for the ultrasonic sensor.
const int soilMoisturePin = A0; // Define the analog pin for the soil moisture sensor.
const int tempPin = A2; // Define the analog pin for the temperature sensor.
const int servoPin = 6; // Define the pin connected to the servo motor.
const int motorEnablePin1 = 2;  // L293D Motor Driver input 1
const int motorEnablePin2 = 3;  // L293D Motor Driver input 2

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate.
  myservo.attach(servoPin); // Attach the servo to pin 6.

  pinMode(ultrasonicTrigPin, OUTPUT); // Set ultrasonic trigger pin as an OUTPUT.
  pinMode(ultrasonicEchoPin, INPUT); // Set ultrasonic echo pin as an INPUT.

  pinMode(soilMoisturePin, INPUT); // Set soil moisture pin as an INPUT.
  pinMode(tempPin, INPUT); // Set temperature pin as an INPUT.

  pinMode(servoPin, OUTPUT); // Set servo pin as an OUTPUT.
  
  // Set motorEnablePin1 as an OUTPUT to control the direction of the motor.
  pinMode(motorEnablePin1, OUTPUT);
  // Set motorEnablePin2 as an OUTPUT to control the direction of the motor.
  pinMode(motorEnablePin2, OUTPUT);

}

void loop() {
  unsigned long currentMillis = millis(); // Get the current value of millis().
  unsigned long interval=20000;

  // Check if it's time to run the code based on the defined interval.
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // Update the previousMillis value.

    float temperatureC = temp_sensor(); // Read the temperature sensor.
    int distance_cm = ultrasonic(); // Read the ultrasonic sensor.
    int soilMoisture = soil_sensor(); // Read the soil moisture sensor.

    // Check conditions for running the motor and shaft.
  if (temperatureC > 35 && soilMoisture < 30) {
    // Turn on the motor using the L293D motor driver.
    digitalWrite(motorEnablePin1, HIGH);
    digitalWrite(motorEnablePin2, LOW);
    run_shaft();
  } else {
    // Turn off the motor if conditions are not met.
    digitalWrite(motorEnablePin1, LOW);
    digitalWrite(motorEnablePin2, LOW);
  }
    
    // Check if the distance measured by the ultrasonic sensor is within a specific range.
    // Turns on the water supply once the waste reaches certain quantity in the bin.
    if (distance_cm < 30) {
      run_shaft(); // Run the water shaft (servo motor).
    }
  }
}

// Function to control the servo motor to run the shaft to let in water.
void run_shaft() {
  int pos = 0;
    // Move the servo from 0 to 90 degrees.
    // Turn on water supply.
    for (pos = 0; pos <= 90; pos += 1) {
      myservo.write(pos); // Set the servo position.
      delay(10); // Delay to control the speed of movement.
    }
    delay(10000);
  
    // Move the servo from 90 to 0 degrees (backwards).
    // Turn off water supply.
    for (pos = 90; pos >= 0; pos -= 1) {
      myservo.write(pos); // Set the servo position.
      delay(10); // Delay to control the speed of movement.
    }
}

// Function to read the ultrasonic sensor.
int ultrasonic() {
  long duration;
  int distance_cm;

  digitalWrite(ultrasonicTrigPin, LOW); // Ensure the trigger pin is low.
  delayMicroseconds(2); // Short delay.
  digitalWrite(ultrasonicTrigPin, HIGH); // Send a 10us pulse to trigger the sensor.
  delayMicroseconds(10); // Wait for the pulse to settle.
  digitalWrite(ultrasonicTrigPin, LOW); // Turn off the trigger pulse.

  duration = pulseIn(ultrasonicEchoPin, HIGH); // Measure the duration of the echo pulse.
  distance_cm = duration * 0.034 / 2; // Convert duration to distance in centimeters.
  return (distance_cm); // Return the measured distance.
}

// Function to read the soil moisture sensor.
int soil_sensor() {
  int soilMoisture = analogRead(soilMoisturePin); // Read analog value from soil moisture sensor.
  return (soilMoisture); // Return the soil moisture value.
}

// Function to read the temperature sensor.
float temp_sensor() {
  // Map the analog reading to temperature in degrees Celsius.
  float temperatureC = map(((analogRead(tempPin) - 20) * 3.04), 0, 1023, -40, 125);
  // Send temperature value to esp8266 serially.
  Serial.print(temperatureC);
  return (temperatureC); // Return the temperature in degrees Celsius.
}


