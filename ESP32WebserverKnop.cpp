#include <WiFi.h>
#include <WebServer.h>
#define BUTTON_PIN 21

const char* ssid = "TM-I5-6200 9671";
const char* password = "Framboos123!";
int lastState = LOW;
int currentState;

WebServer server(80); 

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  WiFi.begin (ssid, password);
  server.begin();
}
void loop() {
    currentState = digitalRead(BUTTON_PIN);
    client.println("Tijsjes ESP32 server");
    if (lastState == HIGH && currentState == LOW){
       client.println("De knop is ingedrukt");
       Serial.println("De knop is ingedrukt");
    }
    if (currentState == HIGH && lastState == LOW){
      client.println("de knop is niet ingedrukt");
      Serial.println("de knop is niet ingedrukt");
    }
    lastState = currentState; 
   
}
