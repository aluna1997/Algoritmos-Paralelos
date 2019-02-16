ALGORITMOS PARALELOS
Práctica02
Luna Felipe 313203079

Para compilar el programa hacemos:
 - gcc Practica02.c -o Practica02.out -fopenmp -lm
donde fopenmp es la biblioteca que usamos para el uso de hilos y
lm la biblioteca para hacer funciones matemáticas.

Para ejecutar el programa:
 - ./Practica02.out 2 N
   donde N es la potencia del tamaño del arreglo, por ejemplo,
   si N=2 tendremos un arreglo de numeros aleatorios de longitud
   2^2=4
