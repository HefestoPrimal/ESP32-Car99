#include "bluetooth.h"
#include "utils.h"
#include "control.h"

BluetoothSerial SerialBT; // Crear instancia de BluetoothSerial

bool estadoLuces = false;

void Bluetooth::iniciar() {
  Serial.begin(9600);
  SerialBT.begin("Buggy BT"); // Nombre del dispositivo Bluetooth
  while (!Serial) {
    Utils::blinkPin(LED_STATUS, 2, 750); // Esperar a que la conexión serial esté lista
    Utils::imprimirSerial("Esperando conexión serial...", "amarillo");
    delay(100);
  }
  Utils::imprimirSerial("\nBluetooth iniciado");
}

void Bluetooth::manejar() {
  if (SerialBT.available()) {
    String comando = Bluetooth::leerComando();
    Utils::blinkPin(LED_STATUS, 2, 50); // Parpadear LED de estado al recibir un comando

    if (comando == "A") {
      Utils::imprimirSerial("Adelante ^", "cyan");
      Control::moverRuedas('A'); // Mover ruedas adelante

    } else if (comando == "R") {
      Utils::imprimirSerial("Reversa v", "cyan");
      Control::moverRuedas('R'); // Mover ruedas en reversa

    } else if (comando == "P") {
      Utils::imprimirSerial("Parar -", "cyan");
      Control::moverRuedas('P'); // Detener ruedas

    } else if (comando == "I") {
      Utils::imprimirSerial("Izquierda <", "cyan");
      Control::moverRuedas('I'); // Mover ruedas a la izquierda

    } else if (comando == "D") {
      Utils::imprimirSerial("Derecha >", "cyan");
      Control::moverRuedas('D'); // Mover ruedas a la derecha

    } else if (comando == "L") {
      estadoLuces = !estadoLuces; // Cambiar estado de las luces
      estadoLuces ? Utils::imprimirSerial("Luces encendidas }O{\n", "cyan") : Utils::imprimirSerial("Luces apagadas (O)\n", "cyan"); // Cambiar estado de las luces
      digitalWrite(luces, estadoLuces); // Encender/Apagar luces

    } else if (comando == "C") {
      Utils::imprimirSerial("Claxon activado <})\n", "cyan");
      Utils::blinkPin(claxon, 3, 300); // Activar claxon

    } else if (comando == "T") {
      Utils::imprimirSerial("Test general de control [*]\n", "cyan");
      Control::testGeneral(); // Ejecutar test general de control

    } else {
      Utils::imprimirSerial("[x] - Comando no reconocido: [" + comando + "]\n", "rojo"); // Comando no reconocido
    }
  }
}

String Bluetooth::leerComando() {
  String comando = "";
  while (SerialBT.available()) {
    char c = SerialBT.read();
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
