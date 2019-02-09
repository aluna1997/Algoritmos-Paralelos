/*
	DIRECTIVAS DEL PREPROCESADOR
	Son aquellas que contienen bibliotecas y macros todas estas comienzan
	con "#".
	Para hacer referencia a estas podemos usar:
	 - "#include" cuando se trata de la biblioteca estandar de c.
	 - "#include "nombre_archivo"" cuando se trata de un archivo en la
	 	carpeta actual.
*/
#include <stdio.h>
/*
	Con la directiva define podemos definir constantes y macros
*/
#define PI 3.14159
#define CUBO(a) a*a*a
int main(){
	float suma;
	suma = PI + 3.0;
	float cubo = CUBO(suma);
	printf("%f\n", suma);
	printf("%f\n", cubo);
	return 0;

}