#define BLYNK_TEMPLATE_ID           "TMPL3WGU_oHZ2"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "t96i4cs7T1TRy2ivgxfP__iHdH6P_u2r"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YourNetworkName";  // Replace with your WiFi network name
char pass[] = "YourPassword";     // Replace with your WiFi password

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  
  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  // Initialize Blynk with your authorization token and WiFi credentials
}

void loop() {
  Blynk.run();  // Continuously run Blynk to handle communication
  
  if (Serial.available() > 0) {
    String receivedData = Serial.readStringUntil('\n');  // Read data from Arduino's serial connection
    
    Blynk.virtualWrite(V1, receivedData);  // Send the received data to virtual pin V1 in the Blynk app
  }
}
