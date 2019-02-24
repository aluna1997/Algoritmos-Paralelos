ALGORITMOS PARALELOS
Práctica03
Luna Felipe 313203079

Para compilar el programa hacemos:
 - gcc Practica03.c -o Practica03.out -fopenmp -lm
donde fopenmp es la biblioteca que usamos para el uso de hilos y
lm la biblioteca para hacer funciones matemáticas.

Para ejecutar el programa:
 - ./Practica02.out 2 N
   donde N será el número de procesadores(hilos) a utilzar multiplicados 
   por 5, por ejemplo, si N = 5, se ejecutará con 5 * 5 = 25 hilos.