#include <WiFi.h>
#inc


const char* ssid     = "Free-Wifi Here!";
WiFiServer server(80);
String header;
void setup() {
  Serial.begin(9600);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, NULL);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.begin();
  
}
void loop(){
  WiFiClient client = server.available();   
  if(!client) return;

  Serial.println("New Client");
}
