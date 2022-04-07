#define led 2
#include <WiFi.h>
#include <PubSubClient.h>
 
const char* ssid = "TM-I5-6200 9671";
const char* password = "Framboos123!";
const char* mqtt_server="192.168.137.182";
const int mqttPort = 1883;
const char* mqttUser = "mqtt username";
const char* mqttPassword = "mqtt password";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
Serial.begin(115200);
pinMode (led, OUTPUT);
digitalWrite(led, HIGH);
WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.println("Connecting to WiFi..");
}
 
Serial.println("Connected to the WiFi network");
 
client.setServer(mqtt_server, mqttPort);
 
while (!client.connected()) {
Serial.println("Connecting to MQTT...");
 
if (client.connect("ESP32Client")) {
 
Serial.println("connected");
 
} else {
 
Serial.print("failed with state ");
Serial.print(client.state());
delay(2000);
 
}
}
}
 
void loop() {
client.loop();
client.subscribe("Raspberry/NaarESP32");

if (String(topic) == "Raspberry/NaarESP32") {
  Serial.println("Lamp gaat");
  if (messageTemp == "aan") {
    Serial.println("aan");
    digitalWrite(led, HIGH);
  }
  
}
if (String(topic) == "Raspberry/NaarESP32") {
  Serial.println("Lamp gaat");
  if (messageTemp == "aan") {
    Serial.println("aan");
    digitalWrite(led, HIGH);
  }
   
}
}
