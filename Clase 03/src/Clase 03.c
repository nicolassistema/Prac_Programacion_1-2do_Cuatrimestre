/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//prototipo
int sumaEnteros(int, int );

int main(void) {

//dsdsdsd
//sasas
int a = 6;
int b = 5;

printf("El resultado es %d",sumaEnteros( a,b));

	return EXIT_SUCCESS;
}

//implementacion
int sumaEnteros(int operadorA, int operadorB){

	int resultado;
	resultado = operadorA + operadorB;

	return resultado;
}

