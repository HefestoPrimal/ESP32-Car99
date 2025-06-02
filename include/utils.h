#ifndef UTILS_H
  #define UTILS_H
  #include <Arduino.h>

  #define DATA 15
  #define LATCH 4
  #define CLOCK 5

  #define luces 18
  #define claxon 19
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