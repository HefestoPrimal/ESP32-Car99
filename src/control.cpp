#include "control.h"
#include "utils.h"

void Control::iniciar() {
  Utils::imprimirSerial("Control iniciado", "verde");
}

/*
  * Distribución Pines 595
  Q0 - Motor delantero derecho T1 - (Adelante)
  Q1 - Motor delantero derecho T2 - (Reversa)
  Q2 - Motor trasero derecho T1 - (Adelante)
  Q3 - Motor trasero derecho T2 - (Reversa)
  Q4 - Motor delantero izquierdo T1 - (Adelante)
  Q5 - Motor delantero izquierdo T2 - (Reversa)
  Q6 - Motor trasero izquierdo T1 - (Adelante)
  Q7 - Motor trasero izquierdo T2 - (Reversa)
*/

const byte movimientoMotores[13] = {
  0b00000000, // Detener
  0b01010101, // Adelante
  0b10101010, // Reversa
  0b10100101, // Izquierda
  0b01011010, // Derecha
  // *Test
  0b00010000, // Motor Del Izq Ad
  0b00100000, // Motor Del Izq At
  0b00000001, // Motor Del Der Ad
  0b00000010, // Motor Del Der At
  0b01000000, // Motor Tra Izq Ad
  0b10000000, // Motor Tra Izq At
  0b00000100, // Motor Tra Der Ad
  0b00001000  // Motor Tra Der At
};

void Control::moverRuedas(char movimiento) {
  // Mover las ruedas según los comandos recibidos
  if (movimiento == 'A') {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[1]); // Adelante
    digitalWrite(LATCH, HIGH);
    Utils::imprimirSerial("Avanzando hacia adelante", "amarillo");

  } else if (movimiento == 'R') {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[2]); // Reversa
    digitalWrite(LATCH, HIGH);
    Utils::imprimirSerial("Avanzando de reversa", "amarillo");

  } else if (movimiento == 'P') {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[0]); // Detener
    digitalWrite(LATCH, HIGH);
    Utils::imprimirSerial("Detenerse", "amarillo");

  } else if (movimiento == 'D') {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[4]); // Derecha
    digitalWrite(LATCH, HIGH);
    Utils::imprimirSerial("Girando a la derecha", "amarillo");

  } else if (movimiento == 'I') {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[3]); // Izquierda
    digitalWrite(LATCH, HIGH);
    Utils::imprimirSerial("Girando a la izquierda", "amarillo");

  } else {
    Utils::imprimirSerial("Comando no reconocido: " + String(movimiento), "rojo");
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
  Utils::imprimirSerial("Probando ruedas...", "amarillo");

  for (int i = 5; i <= 12; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[i]); // Activar motor específico
    digitalWrite(LATCH, HIGH);

    delay(5000); // Espera para que el motor se active
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, movimientoMotores[0]); // Detener
    digitalWrite(LATCH, HIGH);
    delay(1000); // Espera antes de pasar al siguiente motor
    Utils::imprimirSerial("Prueba " + String(i - 4) + " completada\n");
  }

  Utils::imprimirSerial("Test general completado", "verde");
}
