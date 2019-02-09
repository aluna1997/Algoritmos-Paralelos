/*
	ARREGLOS
	- Son estáticos: al declarar su tamaño no cambia
*/
#include <stdio.h>
int main(){
	int sizeA;
	int arreglo[4] = {3,4,1,5};
	//printf("%i\n", arreglo[2]);
	printf("Tamaño del arreglo: \n");
	scanf("%i",&sizeA);
	int edades[sizeA];
	for(int i = 0;i < sizeA;i++){
		printf("Ingresa el valor: %i\n",i + 1);
		scanf("%i",&edades[i]);
	}
	printf("Los valores del arreglo son: \n");
	for(int i= 0;i < sizeA;i++){
		printf("%i-", edades[i]);
	}
	printf("\n");

	return 0;
}