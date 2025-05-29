#include "utils.h"
#include "bluetooth.h"
#include "control.h"

String version = "1.1.0.1"; // Proyecto, Mejora, Corrección, Bug

void setup() {
  Bluetooth::iniciar();

  Utils::imprimirSerial("Iniciando sistema...", "cyan");

  Utils::iniciar();

  Utils::imprimirSerial("Sistema iniciado correctamente", "verde");
}

void loop() {
  Bluetooth::manejar();
  delay(100); // Espera para evitar saturar el loop
}
