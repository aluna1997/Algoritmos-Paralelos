/*
	VARIABLES
*/
#include <stdio.h>
int main(){
	char c = 'y'; //Tamaño de 1 byte 0.. 255
	int a = 20; //Tamaño de 2 bytes -32768.. 32767
	short e = -1; //Tamaño de 2 bytes -128.. 127
	unsigned int u = 25; //Tamaño de 2 bytes, no permite negativos, 0.. 65535
	long l = 5897; //Tamaño de 4 bytes -2147483648.. 2147483647
	float f = 45.56; //Tamaño de 4 bytes
	double d = 12334.66644; //Tamaño de 8 bytes
	printf("%c\n", c);
	printf("%i\n", a);
	printf("%i\n", e);
	printf("%i\n", u);
	printf("%li\n", l);
	printf("%.2f\n", f); //Imprimir dos decimales
	printf("%.2f\n", d); //Imprimir dos decimales
	return 0;
}
