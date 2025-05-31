#include "control.h"
#include "utils.h"

void Control::iniciar() {
  Utils::imprimirSerial("Control iniciado", "verde");
}

void Control::moverRuedas(char ruedasIzq, char ruedasDer) {
  // Mover las ruedas según los comandos recibidos
  if (ruedasIzq == 'A') {
    digitalWrite(ruedaDelIzqT1, HIGH);
    digitalWrite(ruedaTraIzqT1, HIGH);
    digitalWrite(ruedaDelIzqT2, LOW);
    digitalWrite(ruedaTraIzqT2, LOW);
  } else if (ruedasIzq == 'R') {
    digitalWrite(ruedaDelIzqT1, LOW);
    digitalWrite(ruedaTraIzqT1, LOW);
    digitalWrite(ruedaDelIzqT2, HIGH);
    digitalWrite(ruedaTraIzqT2, HIGH);
  } else {
    digitalWrite(ruedaDelIzqT1, LOW);
    digitalWrite(ruedaTraIzqT1, LOW);
    digitalWrite(ruedaDelIzqT2, LOW);
    digitalWrite(ruedaTraIzqT2, LOW);
  }

  if (ruedasDer == 'A') {
    digitalWrite(ruedaDelDerT1, HIGH);
    digitalWrite(ruedaTraDerT1, HIGH);
    digitalWrite(ruedaDelDerT2, LOW);
    digitalWrite(ruedaTraDerT2, LOW);
  } else if (ruedasDer == 'R') {
    digitalWrite(ruedaDelDerT1, LOW);
    digitalWrite(ruedaTraDerT1, LOW);
    digitalWrite(ruedaDelDerT2, HIGH);
    digitalWrite(ruedaTraDerT2, HIGH);
  } else {
    digitalWrite(ruedaDelDerT1, LOW);
    digitalWrite(ruedaTraDerT1, LOW);
    digitalWrite(ruedaDelDerT2, LOW);
    digitalWrite(ruedaTraDerT2, LOW);
  }
}

void Control::testGeneral() {
  Utils::imprimirSerial("Ejecutando test general de control", "cyan");

  // Prueba de luces
  Utils::imprimirSerial("Probando luces...");
  digitalWrite(luces, HIGH);
  delay(2000);
  digitalWrite(luces, LOW);

  // Prueba de claxon
  Utils::imprimirSerial("Probando claxon...");
  digitalWrite(claxon, HIGH);
  delay(500);
  digitalWrite(claxon, LOW);

  // Prueba de ruedas
  Utils::imprimirSerial("Probando ruedas adelante...", "amarillo");
  moverRuedas('A', 'A');
  delay(2000);
  moverRuedas('D', 'D'); // Detener ruedas
  delay(1000);

  Utils::imprimirSerial("Probando ruedas reversa...", "amarillo");
  moverRuedas('R', 'R');
  delay(2000);
  moverRuedas('D', 'D'); // Detener ruedas
  delay(1000);

  Utils::imprimirSerial("Test general completado", "verde");
}
