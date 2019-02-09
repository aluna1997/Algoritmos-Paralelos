#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>

/* ALGORITMOS PARALELOS
Práctca 1: Realiza la suma de los primeros 1,000,000,000 numeros naturales 
de forma paralela y lleva registro del tiempo de ejecución
Luna Felipe 313203079*/

//Función que ejecuta la suma en paralelo
int exec_wt_nthreads(int argc, char** argv, int numHilos, int pri){
	//Nos permiten medir el tiempo de ejecucion
	struct timeval inicio, fin;
	//Guarda el tiempo al inicio del programa
	gettimeofday(&inicio, NULL);
	int tiempo, idHilo;
	long int suma, sumaHilo;

	omp_set_num_threads(numHilos);

	//Inicia seccion paralela
	#pragma omp parallel private(idHilo, sumaHilo)
    {
		idHilo = omp_get_thread_num();
		if (idHilo == 0 && pri == 1){
			printf ("Iniciando calculo con %i hilos\n", omp_get_num_threads());
		}
		
		//Cada hilo realiza una suma parcial
		int i;
		for (i = idHilo; i<1000000000; i += numHilos){
			sumaHilo += i;
		}
		
		//Cada hilo actualiza la suma total con su resultado parcial
		suma += sumaHilo;
	}//Fin de seccion paralela

	//Guarda el tiempo al final del programa
	gettimeofday(&fin, NULL); 
	tiempo = (fin.tv_sec - inicio.tv_sec)* 1000000 + (fin.tv_usec - inicio.tv_usec);
	//Bandera para imprimir resultado en consola
	if (pri == 1){
		printf("Suma: %li  \nTiempo de ejecución: %d microsegundos\n",suma, tiempo); //imprime resultados
	}
	//Necesitaremos el tiempo para proximos calculos
	return tiempo;
}

//Función que calcula la aceleración
float speedup(int secuencial, int no_secuencial){
	return ((float)secuencial / (float)no_secuencial);
}

//Función que calcula la eficiencia
float eficiencia(float spped_up, int num_hilos){
	return spped_up / (float)num_hilos;
}

//Función que calcula la fracción serial
float fraccion_serial(float spped_up, int num_hilos){
	return (((1.0 / spped_up) - (1.0 / (float)num_hilos)) / (1.0 - (1.0 / (float)num_hilos)));
}

//Función qu ejecuta el programa
int main(int argc, char** argv){
	//Limite superior (arbitrario) del numero de hilos
	int MAX_HILOS = 200; 
	int numHilos;

	//Verifica el numero de hilos que se paso como parametro
	if (argc < 2){
		printf("Por favor especifique el numero de hilos\n");
		exit(1);
	}
	sscanf(argv[1], "%i", &numHilos);
	if (numHilos < 1 || numHilos > MAX_HILOS){
		printf("Número de hilos no valido (%i)\n", numHilos);
		exit(1);
	}

	//Ejecución de la suma en secuencial
	float secuencial = exec_wt_nthreads(argc, argv, 1, 0);
	//Ejecución de la suma en paralelo
	float no_secuencial = exec_wt_nthreads(argc, argv, numHilos, 1);
	
	//Aceleración
	float spped_up = speedup(secuencial,no_secuencial);
	//Eficiencia
	float efici = eficiencia(spped_up,numHilos);
	//Fracción serial
	float frac = fraccion_serial(spped_up,numHilos);

	printf("Speedup: %f \n",spped_up); 
	printf("Eficiencia: %f \n",efici);
	printf("Fracción serial: %f \n",frac); 

}
