#include <Arduino.h>
#include "libWifi.h"
#include <WiFi.h>
#include <HTTPClient.h>

#define LED 2

const char* ssid = "DAMIAN";
const char* pass = "03102003";
const char* thingAPI = "http://codelab.denkitronik.com:8080/thingname/230212034/estado";

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando Cliente HTTP");
  conectarWifi(ssid, pass);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    float temperatura = random(25, 30) + random(0, 100) / 100.0; //Grados Celcius
    float humedad = random(40, 60) + random(0, 100) / 100.0;

    //String url = String(thingspeak_url) + "?api_key=" + api_key + "&field1=" + String(temperatura) + "&field2=" + String(humedad);
    String url = "http://codelab.denkitronik.com:8080/thingname/230212034?humedad=" + String(humedad) + "&temperatura="+String(temperatura);

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Respuesta: " + payload);
    } else {
      Serial.println("Error en la petición: " + String(httpCode));
    }

    http.end();
  } else {
    Serial.println("Conexión WiFi perdida");
  }

  delay(10000); // Diez segundos
}