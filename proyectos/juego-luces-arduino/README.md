# Juego de Luces Interactivo

## Descripción

Proyecto basado en Arduino que controla 6 LEDs mediante un pulsador, ejecutando diferentes patrones de iluminación.

---

## Características

* Secuencia
* Carrusel
* Parpadeo
* Aleatorio
* Onda ascendente

---

## Componentes

* Arduino
* 6 LEDs
* 6 resistencias de 220Ω
* 1 pulsador

---

## Conexión

* LEDs conectados a los pines digitales 2 al 7
* Pulsador conectado al pin 8 con INPUT_PULLUP

---

## Funcionamiento

El sistema inicia apagado. Al presionar el botón, se activa el primer patrón y cada pulsación cambia secuencialmente entre los distintos modos de iluminación.

---

## Conceptos aplicados

* Control de flujo con switch-case
* Uso de millis() para evitar delay
* Debounce por software
* Máquina de estados

---

## Archivos

* codigo.ino

---

## Autor

Wagner Balcazar


Enlace de Simulación Wokwi: https://wokwi.com/projects/461300940964528129
