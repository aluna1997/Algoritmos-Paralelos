#include <stdio.h>
/*
La instrucción if se forma utilizando operadores de igualdad:
  - == x es igual que y
  - != x es diferente de y
  
Y de relación:
  - > x es mayor que y
  - < x es menor que y
  - >= x es mayor o igual que y
  - <= x es menor o igual que y
*/

int main(){
	int edad;
	printf("Ingresa tu edad: \n");
	scanf("%d",&edad);
	if(edad >= 18){
		printf("Eres mayor de edad!\n");
	}else if(edad ==17){
		printf("Casi eres mayor de edad.\n");
	}else{
		printf("Eres menor de edad.\n");
	}
	return 0;
}