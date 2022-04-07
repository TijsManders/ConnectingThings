#define BUTTON_PIN 21
#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "";
const char* password = "";

WiFiClient  client;

unsigned long myChannelNumber = 1;
const char * myWriteAPIKey = "";
int currentState;
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

void setup() {
Serial.begin(115200);
pinMode(BUTTON_PIN, INPUT_PULLUP);
WiFi.mode(WIFI_STA);   
ThingSpeak.begin(client);
}


void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

    currentState = digitalRead(BUTTON_PIN);
    Serial.println(currentState);

    int x = ThingSpeak.writeField(myChannelNumber, 1, currentState, myWriteAPIKey);

    if(x == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(x));
    }
    lastTime = millis();
  }
}
