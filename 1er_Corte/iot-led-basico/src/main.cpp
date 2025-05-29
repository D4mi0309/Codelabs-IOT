#include <Arduino.h>
#define LED 2

//Funcion que se ejecuata al inicializar el programa 
void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT); //Configuración pin #2 como salida
  digitalWrite(LED, 0); 
}

//Funcion similar al main en lenguaje C
//Con la excepcion de que es un loop infinito
void loop() {
  Serial.println("Hola mundo!");
  delay(3000); //Retardo bloqueante
  digitalWrite(LED, 1);
  delay(3000);
  digitalWrite(LED, 0);
}