/*
 ============================================================================
Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el área de un círculo cuyo radio es ingresado por el usuario.
 Documentar las funciones al estilo Doxygen.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

//Prototipo

int main(void) {
	setbuf(stdout,NULL);

char numero1;
//int resultado;
//int numero2;
//float resultado;






//Prueba de funciones

if(utn_GetChar("\nIngresar un numero: ", "El numero es incorrecto, ingresar numero: ", &numero1,3) == 0 ){
	//printf("\nEl numero ingresao es: %.2f", numero1);
	printf("\nEntro en el true de if");
	printf("\nEl dato ingresado es: %c", numero1);
}else{

	printf("\nLA cantidad de reintentos supero el maximo permitido");
}





	return EXIT_SUCCESS;
}



