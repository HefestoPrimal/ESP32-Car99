#ifndef CONTROL_H
  #define CONTROL_H

  class Control {
    public:
      static void iniciar();
      static void moverRuedas(char ruedasIzq, char ruedasDer); // 'A' Adelante 'R' Reversa 'D' Detener
      static void testGeneral();
  };

#endif