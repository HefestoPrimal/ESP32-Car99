#ifndef UTILS_H
  #define UTILS_H
  #include <Arduino.h>

  #define ruedaDelIzqT1 21
  #define ruedaDelIzqT2 21
  #define ruedaDelDerT1 22
  #define ruedaDelDerT2 22

  #define ruedaTraIzqT1 23
  #define ruedaTraIzqT2 23
  #define ruedaTraDerT1 19
  #define ruedaTraDerT2 19

  #define luces 15
  #define claxon 4
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