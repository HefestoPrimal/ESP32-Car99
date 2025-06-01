#ifndef UTILS_H
  #define UTILS_H
  #include <Arduino.h>

  #define ruedaDelIzqT1 15
  #define ruedaDelIzqT2 4
  #define ruedaDelDerT1 5
  #define ruedaDelDerT2 18

  #define ruedaTraIzqT1 19
  #define ruedaTraIzqT2 21
  #define ruedaTraDerT1 22
  #define ruedaTraDerT2 23

  #define luces 13
  #define claxon 12
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