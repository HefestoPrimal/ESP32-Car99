#include "utils.h"

bool DEBUG = true;

void Utils::iniciar() {
  // Configuración inicial si es necesario
  pinMode(LED_STATUS, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(luces, OUTPUT);
  pinMode(claxon, OUTPUT);

  digitalWrite(LED_STATUS, LOW); // Asegurarse de que el LED de estado esté apagado al inicio
  digitalWrite(claxon, LOW);
  digitalWrite(luces, LOW); // Asegurarse de que las luces estén apagadas al inicio

  Utils::blinkPin(LED_STATUS, 3, 250); // Parpadear el LED de estado al iniciar

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

void Utils::manejoLed(int pin, int frecuencia, int tiempo) {
  if (tiempo == 0) {
    imprimirSerial("Tiempo no puede ser cero", "rojo");
    return;
  } else {
    int Tiempo = tiempo * 1000;
    int ciclos = Tiempo / (2 * frecuencia);

    for (int i = 0; i < ciclos; i++) {
      digitalWrite(pin, HIGH);
      delay(frecuencia);
      digitalWrite(pin, LOW);
      delay(frecuencia);
    }
  }
}
