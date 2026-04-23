
Temporizador 555 + Flip-Flop + Arduino

Este proyecto implementa un sistema embebido para la generación, acondicionamiento y medición de señales digitales. Se utiliza un circuito integrado NE555 en configuración astable para generar una señal periódica, la cual es posteriormente procesada mediante un flip-flop 74HC74 para corregir el duty cycle y dividir la frecuencia.

El sistema emplea un Arduino Uno como plataforma de adquisición de datos, permitiendo medir parámetros fundamentales de la señal como periodo, frecuencia y ciclo de trabajo (duty cycle) mediante técnicas de muestreo por polling, sin el uso de interrupciones.

Los resultados obtenidos son visualizados en tiempo real a través del Serial Monitor y Serial Plotter, permitiendo analizar el comportamiento de la señal, así como evaluar su estabilidad, precisión y posibles variaciones (jitter).

Este proyecto integra conceptos de electrónica analógica, lógica digital y sistemas embebidos, constituyendo una solución práctica para el estudio y análisis de señales digitales en entornos educativos.
