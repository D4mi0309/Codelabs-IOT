#include <WiFi.h>
#include "libWifi.h"

void conectarWifi(const char* ssid, const char* pass){
    WiFi.begin(ssid, pass);
    Serial.print("Estableciendo conexion WiFi..");
    while(WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.print(".");
    }
    Serial.println("\nConectado a la red WiFi");
    Serial.print("\nDireccion IP: ");
    Serial.println(WiFi.localIP());
  }