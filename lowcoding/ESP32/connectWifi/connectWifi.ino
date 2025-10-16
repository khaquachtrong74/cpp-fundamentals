#include<WiFi.h>
const char* ssid = "TECNO POVA 5";
const char* password = "dzkpq5zd4ydiddq";
void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println(ssid);
  Serial.println(password);
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop() {
     if (WiFi.status() != WL_CONNECTED) {
       // Handle disconnection, e.g., attempt to reconnect
       Serial.println("Disconnected from WiFi");
       WiFi.begin(ssid, password);
     }
   }
