#ifndef BLUETOOTH_H
  #define BLUETOOTH_H
  #include <BluetoothSerial.h>

  class Bluetooth {
    public:
      static void iniciar();
      static void manejar();
      static String leerComando();
  };

#endif