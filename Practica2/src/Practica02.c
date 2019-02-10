#include <stdio.h>
#include <omp.h>
#include <math.h>
#include<time.h> 
#include <stdlib.h>

/* ALGORITMOS PARALELOS
Práctca 2: Ordena un arreglo de forma paralela.
Luna Felipe 313203079*/


//Función qu ejecuta el programa
int main(int argc, char** argv){
	int potencia;

	//Verifica si se le paso un arreglo como parametro, en otro
	//caso deja uno aleatorio
	if (argc < 2){
		printf("Por favor especifique el exponente para definir el tamaño del arreglo\n");
		exit(1);
	}else if(argc == 2){
		sscanf(argv[1], "%i", &potencia);
		int tamanio = pow(2,potencia) + 1;
		int arreglo[tamanio];
		srand(time(0)); 
		for(int i = 1; i < tamanio; i++){
			arreglo[i] = rand() % 101;
		}

		printf("Arreglo inicial: \n");
		for (int i = 0; i < tamanio; i++){
			printf("%i ",arreglo[i]);		
		}
		printf("\n");
		
		omp_set_num_threads(tamanio);
		//Inicia seccion paralela
		#pragma omp parallel
		{
			int i = 0;
			int par = 0;
			int impar = 1;
			do{
				
				
				if(arreglo[par + 1] < arreglo[par]){
					int aux = arreglo[par];
					arreglo[par] = arreglo[par + 1];
					arreglo[par + 1] = aux;
				}
				par += 2;

				
				if(arreglo[impar + 1] < arreglo[impar]){
					int aux = arreglo[impar];
					arreglo[impar] = arreglo[impar + 1];
					arreglo[impar + 1] = aux;
				}

				impar += 2;
				
				i +=1 ;
					
			}while(i < (tamanio / 2));
		}
		
		//Termina seccion paralela
		printf("Arreglo ordenado: \n");
		for (int i = 0; i < tamanio; i++){
			printf("%i ",arreglo[i]);		
		}
		printf("\n");
		
		
	}

}

