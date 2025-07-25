#include <Arduino.h>
#include <WiFiMulti.h>

#define WIFI_SSID "yuh uh"
#define WIFI_PASSWORD "nuh uh"

WiFiMulti wifiMulti;

void setup() {
  Serial.begin(921600);
  pinMode(2, OUTPUT);

  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (wifiMulti.run() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nConnected to WiFi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  IPAddress ip;
  if (WiFi.hostByName("google.com", ip)) {
    Serial.print("google.com resolves to: ");
    Serial.println(ip);
  } else {
    Serial.println("DNS resolution failed.");
  }
}


void loop() {
  digitalWrite(2, WiFi.status() == WL_CONNECTED);

}

