#include <stdio.h>

int main(){
	int num1;
	int num2;
	int resultado;
	printf("Ingrese el primer valor\n");
	//Scanf necesita dos argumentos: el tipo de dato que se va a leer
	//por teclado (%d se refiere a decimal) y donde se guardará el valor
	//ingresado usamos el operador de referencia & y una variable para
	//almacenar el valor
	scanf("%d",&num1);
	printf("Ingrese el segundo valor\n");
	scanf("%d",&num2);
	//De igual manera puede hacerse para +, -, *, /
	resultado = num1 + num2;
	printf("El resultado de la suma es: %d\n",resultado);
	return 0;
}

//-------------- PRECEDANCIA DE OPERADORES ---------------------------//
/*
				1 -> *, /, %
				2 -> +, -
*/




