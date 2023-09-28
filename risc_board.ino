/*
  1. check temp and moisture level, if temp>35 and moisture<30 then run shaft
  2. shaft turns 90 degree to open water gate
  3. rught after this motor starts to turn
*/
#include <Servo.h>

     Servo myservo;
     const int ultrasonicTrigPin = 9;
     const int ultrasonicEchoPin = 10;
     const int soilMoisturePin = A0;
     const int tempPin = A2;
     const int servoPin = 6;
     const int motor = 13;
     unsigned long previousMillis = 0;
     const long interval = 5000;  

void setup() {
       Serial.begin(9600);
       myservo.attach(6, 500, 2500);

       pinMode(ultrasonicTrigPin, OUTPUT);
       pinMode(ultrasonicEchoPin, INPUT);

       pinMode(soilMoisturePin, INPUT);
       pinMode(tempPin, INPUT);

       pinMode(servoPin, OUTPUT);
       pinMode(motor, OUTPUT);
}



void loop(){
     unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;

    float temperatureC = temp_sensor();
    int distance_cm = ultrasonic();
    int soilMoisture = soil_sensor();
    
    if (temperatureC > 30 || soilMoisture < 60) {
      digitalWrite(motor, HIGH);
      run_shaft();
    } else {
      digitalWrite(motor, LOW);
    }

    if (distance_cm > 30 && distance_cm <40) {
      run_shaft();
    }
    
  }
}

void run_shaft() {
    int pos = 0;
    int i;
   for (i = 0; i < 5; i += 1) {
    for (pos = 0; pos <= 180; pos += 1) {
      myservo.write(pos);
      delay(7);
    }

    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(7);
    }
   }
   delay(5000);
}

    
// Ultrasonic Sensor           
int ultrasonic() {
      long duration;
      int distance_cm;

      digitalWrite(ultrasonicTrigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(ultrasonicTrigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(ultrasonicTrigPin, LOW);
      duration = pulseIn(ultrasonicEchoPin, HIGH);
      distance_cm = duration * 0.034 / 2;
      return (distance_cm);
}

// Soil Moisture Sensor
int soil_sensor() {
  int soilMoisture = analogRead(soilMoisturePin);
  return (soilMoisture);
}

// Temperature Sensor
float temp_sensor() {
  float temperatureC = map(((analogRead(tempPin) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print("\nTemperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  return (temperatureC);
}

