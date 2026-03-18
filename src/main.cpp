#include <Arduino.h>

// Fazendo o "merge" lógico dos seus arquivos de sensores
#include "alerta.h"
#include "sensor_agua.h"
#include "sensor_gas.h"
#include "sensor_pir.h"
#include "sensor_temperatura.h"
#include "sensor_umidade.h"

void setup() {
  Serial.begin(115200);
  
  // Chame aqui as funções de inicialização que estão dentro dos seus .h
  // Exemplo: setupGas(); 
  
  Serial.println("Sistema de Sensores Integrado!");
}

void loop() {
  // Chame aqui as funções de leitura dos seus sensores
  // Exemplo: 
  // float temp = lerTemperatura();
  // Serial.println(temp);
  
  delay(2000); 
}