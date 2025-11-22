#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22
#define LDR_PIN 34
#define LED_PIN 2

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

WiFiClient espClient;;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println("Conectando ao WiFi...");
}

void callback(char* topic, byte* payload, unsigned int lenght) {
  String msg;
  for (unsigned int i = 0; i < lenght; i++)
    msg += (char)payload[i];

  if (String(topic) == "inclusao/device/cmd") {
    if (msg == "ALERTA") digitalWrite(LED_PIN, HIGH);
    if (msg == "NORMAL") digitalWrite(LED_PIN, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Inclusao")) {
      client.subscribe("inclusao/device/cmd");
    } else {
      delay(2000);
    }
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int ldr = analogRead(LDR_PIN);

  String payload = "{";
  payload += "\"temp\":" + String(t) + ",";
  payload += "\"umidade\":" + String(h) + ",";
  payload += "\"luminosidade\":" + String(ldr);
  payload += "}";

  client.publish("inclusao/device/data", payload.c_str());
  Serial.println(payload);

  delay(4000);
}