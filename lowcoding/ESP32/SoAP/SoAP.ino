#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const char* STA_SSID = "TECNO POVA 5";
const char* STA_PWD  = "dzkpq5zd4ydiddq";
const char* AP_SSID  = "Free Wifi!";
const char* AP_PWD   = "Abcd123#@!";

WebServer web(80);
DNSServer dns;
IPAddress apIP(192,168,4,1);

void handleRoot() {
  web.send(200, "text/html",
           "<h1>Welcome!</h1><p>You’re online via ESP32 gateway.</p>");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);

  // 1) Kết nối vào mạng chính
  WiFi.begin(STA_SSID, STA_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print('.');
  }
  Serial.println("\nConnected to main WiFi");

  // 2) Phát AP và captive portal
  WiFi.softAPConfig(apIP, apIP, IPAddress(255,255,255,0));
  WiFi.softAP(AP_SSID, AP_PWD);
  dns.start(53, "*", apIP);

  web.on("/", handleRoot);
  web.onNotFound([](){
    web.sendHeader("Location","/",true);
    web.send(302, "text/plain","");
  });
  web.begin();
  Serial.println("Captive portal running");
}

void loop() {
  dns.processNextRequest();
  web.handleClient();
}
