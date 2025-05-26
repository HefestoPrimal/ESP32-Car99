#include "utils.h"
#include "bluetooth.h"
#include "control.h"

String version = "1.0.0"; // Proyecto, Mejora, Corrección

void setup() {
  Bluetooth::iniciar();

  Utils::imprimirSerial("Iniciando sistema...", "cyan");

  Utils::iniciar();

  Utils::imprimirSerial("Sistema iniciado correctamente", "verde");
}

void loop() {
}
