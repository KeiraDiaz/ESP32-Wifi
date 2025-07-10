#include <Arduino.h>
#include <WiFiMulti.h>

#define WIFI_SSID "Hah loser"
#define WIFI_PASSWORD "imagine thinking i would just post my password"

WiFiMulti wifiMulti;

void setup() {
  Serial.begin(921600);
  pinMode(2, OUTPUT);

  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  while (wifiMulti.run() != WL_CONNECTED){
    delay(100);
  }

  Serial.println('Connected');
}

void loop() {
  digitalWrite(2, WiFi.status() == WL_CONNECTED);

}

