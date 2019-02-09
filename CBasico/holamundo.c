//Las lineas que comuenzan con # son procesadas por el preprocesador
//antes de que el programa se compile.

//La linea siguiente en particular indica al preprocesador que incluya
//en el programa el contenido del encabezado estandar de entrada y salida.

//Asi que este encabezado contiene informacion para llamar a las bibliotecas
//de entrada y salida.
#include <stdio.h>
//La linea de escape "/n" la reconoce el compilador y agregara un salto 
//de linea a la cadena.
int main(){
	printf("Hola Mundo\n");
	return 0;
}