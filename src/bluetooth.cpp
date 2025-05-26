#include "bluetooth.h"
#include "utils.h"
#include "control.h"

bool estadoLuces = false;

void Bluetooth::iniciar() {
  Serial.begin(115200);
  while (!Serial) {
    Utils::blinkPin(LED_STATUS, 1, 200); // Esperar a que la conexión serial esté lista
    Utils::imprimirSerial("Esperando conexión serial...", "amarillo");
    delay(100);
  }
  Utils::imprimirSerial("Bluetooth iniciado");
}

void Bluetooth::manejar() {
  if (Serial.available()) {
    String comando = Bluetooth::leerComando();
    if (comando == "A") {
      Utils::imprimirSerial("Adelante", "cyan");
      Control::moverRuedas('A', 'A'); // Mover ruedas adelante
    } else if (comando == "R") {
      Utils::imprimirSerial("Reversa", "cyan");
      Control::moverRuedas('R', 'R'); // Mover ruedas en reversa
    } else if (comando == "P") {
      Utils::imprimirSerial("Parar", "cyan");
      Control::moverRuedas('D', 'D'); // Detener ruedas
    } else if (comando == "I") {
      Utils::imprimirSerial("Izquierda", "cyan");
      Control::moverRuedas('D', 'A'); // Mover ruedas a la izquierda
    } else if (comando == "D") {
      Utils::imprimirSerial("Derecha", "cyan");
      Control::moverRuedas('A', 'D'); // Mover ruedas a la derecha
    } else if (comando == "L") {
      estadoLuces = !estadoLuces; // Cambiar estado de las luces
      estadoLuces ? Utils::imprimirSerial("Luces encendidas", "cyan") : Utils::imprimirSerial("Luces apagadas", "cyan"); // Cambiar estado de las luces
      digitalWrite(luces, estadoLuces); // Encender luces
    } else if (comando == "C") {
      Utils::imprimirSerial("Claxon activado", "cyan");
      Utils::blinkPin(claxon, 3, 300); // Activar claxon
    }
  }
}

String Bluetooth::leerComando() {
  String comando = "";
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      if (comando.length() > 0) {
        return comando; // Retornar el comando completo
      }
    } else {
      comando += c; // Agregar caracter al comando
    }
  }
  return ""; // Retornar cadena vacía si no hay comando
}
