#include <ESP8266WiFi.h>
#include <DHT_U.h>
#include <max6675.h>
#include <BlynkSimpleEsp8266.h>
#include "meat.h"

#define DHTTYPE DHT22
#define DHTPIN 2 // d4
#define SCK 14 // d5
#define MISO 12 // d6
#define CS 16 // d0

MAX6675 thermocouple(SCK, CS, MISO);

DHT_Unified dht(DHTPIN, DHTTYPE);

float cToF(float c) {
  return (c * 9 / 5) + 32.0;
}

void setup() {
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  Blynk.begin(AUTH, SSID, PASS);

  Serial.write("Connected to Blynk");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  Blynk.run();

  float meat = thermocouple.readFahrenheit();
  Blynk.virtualWrite(7, meat);
  Blynk.virtualWrite(8, meat);

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float ambient = event.temperature;
  Blynk.virtualWrite(0, cToF(ambient));

  dht.humidity().getEvent(&event);
  float humidity = event.relative_humidity;
  Blynk.virtualWrite(1, humidity);


  delay(2500);
}