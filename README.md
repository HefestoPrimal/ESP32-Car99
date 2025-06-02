# ESP Car 32

Proyecto para controlar un coche con 4 motores, un juego de luces frontales 
y un claxon con una ESP32 con Bluetooth. Los 4 motores se pueden mover hacia
adelante y hacia atras individualmente, en vez de utilizar 8 salidas para
todos los motores se optimiza utilizando un 74HC595

## Pines:
  - ESP32 - Nombre - Componente
    * 15 - DATA   - (14 - 74HC595)
    * 4  - LATCH  - (12 - 74HC595)
    * 5  - CLOCK  - (11 - 74HC595)
    * 18 - LUCES  - (LEDS)
    * 19 - CLAXON - (BUZZER)
    * 2  - STATUS - (LED INTEGRADO DE LA ESP32)
    * /  -   Q0   - (Motor Izquierdo Delantero Terminal 1 [Adelante])
    * /  -   Q1   - (Motor Izquierdo Delantero Terminal 2 [Reversa])
    * /  -   Q2   - (Motor Derecho Delantero Terminal 1 [Adelante])
    * /  -   Q3   - (Motor Derecho Delantero Terminal 2 [Reversa])
    * /  -   Q4   - (Motor Izquierdo Trasero Terminal 1 [Adelante])
    * /  -   Q5   - (Motor Izquierdo Trasero Terminal 2 [Reversa])
    * /  -   Q6   - (Motor Izquierdo Trasero Terminal 1 [Adelante])
    * /  -   Q7   - (Motor Izquierdo Trasero Terminal 2 [Reversa])

## Uso

 - Encender el ESP32.
 - Esperar a que el LED parpadee 3 veces indicando que el Bluetooth esta encendido y listo para recibir datos
 - Se puede utilizar una aplicación de Terminal Bluetooth con parámetros ajustables y enviar comandos a través de botones personalizables, ejemplo: 
 https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal
 - Usar los comandos para controlar el coche desde la aplicación
   - A -> Avanzar
   - P -> Parar
   - I -> Izquierda
   - D -> Derecha
   - L -> Luces
   - C -> CLaxón
   - T -> Test general (Enciende las luces, el claxon y mueve cada rueda al frente y atras individualmente)

## Autor

 - Angel (HefestoPrimal)

## Licencia

 - Libre
