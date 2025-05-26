#ifndef UTILS_H
  #define UTILS_H
  #include <Arduino.h>

  #define ruedaDelIzq 21
  #define ruedaDelDer 22
  #define ruedaTraIzq 23
  #define ruedaTraDer 19
  #define luces 18
  #define claxon 5
  #define LED_STATUS 2

  extern bool DEBUG;

  class Utils {
    public:
      static void iniciar(); 
      static void imprimirSerial(String mensaje, String color = "blanco");
      static void blinkPin(int pin, int times, int delayTime);
      static void manejoLed(int pin, int tiempo, int frecuencia);
  };
#endif