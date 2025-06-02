# ESP Car 32

Proyecto para controlar un coche con 4 motores, un juego de luces frontales 
y un claxon con una ESP32 con Bluetooth. Los 4 motores se pueden mover hacia
adelante y hacia atras individualmente, utilizando 8 salidas para cada
terminal de motor

## Pines:
  ESP32 Nombre Componente
    15 -   Q0   - (Motor Izquierdo Delantero Terminal 1 [Adelante])
    4  -   Q1   - (Motor Izquierdo Delantero Terminal 2 [Reversa])
    5  -   Q2   - (Motor Derecho Delantero Terminal 1 [Adelante])
    18 -   Q3   - (Motor Derecho Delantero Terminal 2 [Reversa])
    19 -   Q4   - (Motor Izquierdo Trasero Terminal 1 [Adelante])
    21 -   Q5   - (Motor Izquierdo Trasero Terminal 2 [Reversa])
    22 -   Q6   - (Motor Izquierdo Trasero Terminal 1 [Adelante])
    23 -   Q7   - (Motor Izquierdo Trasero Terminal 2 [Reversa])
    13 - LUCES  - (LEDS)
    12 - CLAXON - (BUZZER)
    2  - STATUS - (LED INTEGRADO DE LA ESP32)

## Uso

 - Encender el ESP32.
 - Esperar a que el LED parpadee 3 veces indicando que el Bluetooth esta encendido y listo para recibir datos
 - Usar los comandos para controlar el coche
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
