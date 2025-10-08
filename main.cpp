#include <WiFi.h>
#include <Arduino.h>
#include <ArduinoOTA.h>

const char* ssid = "HTL-WLAN-IoT";
const char* password = "HTL2IoT!";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Gateway (Router IP): ");
  Serial.println(WiFi.gatewayIP()); // Get router's IP address

  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();
  delay(500);
}
