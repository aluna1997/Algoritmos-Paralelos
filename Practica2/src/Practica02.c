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
		//Tomamos la potencia ingresada en terminal
		sscanf(argv[1], "%i", &potencia);
		//El tamaño de el arreglo a ordenar será de 2^(potencia) + 1, esa posicion extra
		//estará vacia y nos ayudara a no desbordar del arreglo al comparar los elementos impares
		int tamanio = pow(2,potencia) + 1;
		//Inicializamos el arreglo
		int arreglo[tamanio];
		//La siguiente linea nos ayuda a generar nums aleatorios nuevos en cada
		//ejecución del programa
		srand(time(0)); 
		//Llenamos el arreglo de numeros aleatorios entre 0 y 100
		for(int i = 1; i < tamanio; i++){
			arreglo[i] = rand() % 101;
		}
		//Imprimimos en pantalla el arreglo original
		printf("Arreglo inicial: \n");
		for (int i = 1; i < tamanio; i++){
			printf("%i ",arreglo[i]);		
		}
		printf("\n");
		//El numero de procesadores(hilos) a utilizar sera la longitud del arreglo,
		//es decir,un procesador por elemento
		omp_set_num_threads(tamanio);
		//Inicia seccion paralela
		#pragma omp parallel
		{	
			//Contador que se ejecutara tamanio / 2 veces
			int i = 0;
			//Apuntador a los elementos pares del arreglo
			int par = 0;
			//Apuntador a los elementos impares del arreglo
			int impar = 1;
			do{
				//Si el elemento actual es mayor al siguiente,
				//lo intercambiamos, esto para las posiciones pares
				if(arreglo[par + 1] < arreglo[par]){
					int aux = arreglo[par];
					arreglo[par] = arreglo[par + 1];
					arreglo[par + 1] = aux;
				}
				par += 2;
				
				//Si el elemento actual es mayor al siguiente,
				//lo intercambiamos, esto para las posiciones impares
				if(arreglo[impar + 1] < arreglo[impar]){
					int aux = arreglo[impar];
					arreglo[impar] = arreglo[impar + 1];
					arreglo[impar + 1] = aux;
				}

				impar += 2;
				i +=1 ;
					
			}while(i < (tamanio / 2));
		}//Termina seccion paralela
		//Imprimimos en pantalla el arreglo ordenado
		printf("Arreglo ordenado: \n");
		for (int i = 1; i < tamanio; i++){
			printf("%i ",arreglo[i]);		
		}
		printf("\n");
		
		
	}

}
