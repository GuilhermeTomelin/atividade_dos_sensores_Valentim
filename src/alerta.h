#include <Arduino.h>

// Importando os arquivos conforme solicitado
namespace Agua { #include "sensor_agua.h" }
namespace Gas { #include "sensor_gas.h" }
namespace Pir { #include "sensor_pir.h" }
namespace Temp { #include "sensor_temperatura.h" }
namespace Umid { #include "sensor_umidade.h" } // Assumindo que o 5 é umidade

void setup() {
  Serial.begin(9600);

  // Inicializa cada um usando o "sobrenome" do Namespace
  Agua::setup();
  Gas::setup();
  Pir::setup();
  Temp::setup();
  Umid::setup();

  Serial.println("--- SISTEMA DE ALERTA INICIADO ---");
}

void loop() {
  // Executa os loops individuais
  Agua::loop();
  Gas::loop();
  Pir::loop();
  Temp::loop();
  Umid::loop();

  // --- LÓGICA DE ALERTA E BANCO DE DATOS ---
  verificarErros();
  
  delay(500); 
}

void verificarErros() {
  // Exemplo de lógica: Se o gás subir ou temperatura passar de 40
  // Acessamos as variáveis de dentro dos arquivos usando o prefixo
  if (Gas::nivelGas > 1000 || Temp:: temp > 40.0) {
    enviarParaBanco("ALERTA: Condicao Critica Detectada!");
  }
}

void enviarParaBanco(String msg) {
  // Simulação de envio (via Serial ou HTTP se usar ESP32)
  Serial.print("DATABASE_UPDATE: ");
  Serial.println(msg);
}