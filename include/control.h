#ifndef CONTROL_H
  #define CONTROL_H

  class Control {
    public:
      static void iniciar();
      static void moverRuedas(char movimiento); // 'A' Adelante 'R' Reversa 'P' Detener 'D' Derecha 'I' Izquierda
      static void testGeneral();
  };

#endif