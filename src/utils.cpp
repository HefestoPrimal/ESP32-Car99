#include "utils.h"

bool DEBUG = true;

void Utils::iniciar() {
  // Configuración inicial si es necesario
  pinMode(LED_STATUS, OUTPUT);
  pinMode(ruedaDelIzqT1, OUTPUT);
  pinMode(ruedaDelDerT1, OUTPUT);
  pinMode(ruedaTraIzqT1, OUTPUT);
  pinMode(ruedaTraDerT1, OUTPUT);
  pinMode(ruedaDelIzqT2, OUTPUT);
  pinMode(ruedaDelDerT2, OUTPUT);
  pinMode(ruedaTraIzqT2, OUTPUT);
  pinMode(ruedaTraDerT2, OUTPUT);
  pinMode(luces, OUTPUT);
  pinMode(claxon, OUTPUT);

  digitalWrite(LED_STATUS, LOW); // Asegurarse de que el LED de estado esté apagado al inicio
  digitalWrite(ruedaDelIzqT1, LOW);
  digitalWrite(ruedaDelDerT1, LOW);
  digitalWrite(ruedaTraIzqT1, LOW);
  digitalWrite(ruedaTraDerT1, LOW);
  digitalWrite(ruedaDelIzqT2, LOW);
  digitalWrite(ruedaDelDerT2, LOW);
  digitalWrite(ruedaTraIzqT2, LOW);
  digitalWrite(ruedaTraDerT2, LOW);
  digitalWrite(claxon, LOW);
  digitalWrite(luces, LOW); // Asegurarse de que las luces estén apagadas al inicio

  Utils::blinkPin(LED_STATUS, 3, 350); // Parpadear el LED de estado al iniciar

  imprimirSerial("Utils iniciados", "verde");
}

void Utils::imprimirSerial(String mensaje, String color) {
  if (DEBUG) {
    if (color == "rojo") {
      Serial.print("\033[31m");
    } else if (color == "verde") {
      Serial.print("\033[32m");
    } else if (color == "amarillo") {
      Serial.print("\033[33m");
    } else if (color == "cyan") {
      Serial.print("\033[36m");
    } else {
      Serial.print("\033[0m");
    }
    Serial.println(mensaje);
    Serial.print("\033[0m"); // Reset color
  }
  /*
  Mensaje regular: Blanco
  Mensaje de error: Rojo
  Mensaje de éxito: Verde
  Mensaje de advertencia: Amarillo
  Mensaje informativo: Cyan
  */
}

void Utils::blinkPin(int pin, int times, int delayTime) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
}

void Utils::manejoLed(int pin, int tiempo, int frecuencia) {
  int tiempoEncendido = tiempo / 2;
  int tiempoApagado = tiempo - tiempoEncendido;

  for (int i = 0; i < frecuencia; i++) {
    digitalWrite(pin, HIGH);
    delay(tiempoEncendido);
    digitalWrite(pin, LOW);
    delay(tiempoApagado);
  }
}
