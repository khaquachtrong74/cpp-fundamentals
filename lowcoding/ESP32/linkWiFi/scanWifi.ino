#include <WiFi.h>
#include <WiFiScan.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  Serial.println("Starting scan...");

  int16_t n = WiFi.scanNetworks();
  Serial.println("Scan done");
  if (n == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.printf("%d: %s (%ddBm)\n", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
      delay(10);
    }
  }
  Serial.println("");

  // Wait a few seconds before scanning again
  delay(5000);
}
