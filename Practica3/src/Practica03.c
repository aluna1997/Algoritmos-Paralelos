#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define DESDE 3
#define HASTA 17
#define MAX_HILOS  1000

float aplica_funcion(float x);


float aplica_funcion(float x)
{
  return (100 - (pow(x - 10,4)) + (50*(pow(x - 10,2))) - (8 * x));
}


int main (int argc, char *argv[])
{     
      //Verifica el numero de hilos que se paso como parametro
      if (argc < 2){
         printf("Por favor especifique el numero de hilos\n");
         exit(1);
      }

      int procesadores = 0;
      sscanf(argv[1], "%i", &procesadores);


      if (procesadores < 1 || procesadores > MAX_HILOS){
      printf("Número de hilos no valido (%i)\n", procesadores);
      exit(1);
      }

      float suma_hilo = 0.0;
      float resultado = 0.0;    
      int id_hilo;    
      float incremento = ((float)HASTA - (float)DESDE) / (float)(procesadores * 5);
      float x = DESDE;

      
      omp_set_num_threads(procesadores * 5);

      //Inicia seccion paralela
      #pragma omp parallel private(suma_hilo,id_hilo)
      {
         id_hilo = omp_get_thread_num();
         for(int j = id_hilo; j< (procesadores * 5); j+= (procesadores * 5)){
            suma_hilo += (incremento * (aplica_funcion(x) + aplica_funcion(x + incremento))) / 2.0;
            x += incremento;
         }
            resultado += suma_hilo;
      }//Termina seccion paralela

      printf("El resultado de es %f \n",resultado);
}



