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

int main(void) {
setbuf(stdout,NULL);

int a;
int b;
int c;
int direccion;

//Con sizeof se obtiene lo que pesa la variable
printf("el size de a es: %d\n", sizeof(a));
//Se obtiene la direccion memoria
printf("LA direccion de memoria de a es: %d\n", &a);
//Se obtiene la direccion memoria pero en hexadecimal
printf("LA direccion de memoria en formato hexadecimal a es: %p\n", &a);
 direccion = &a;
 printf("LA direccion de memoria de a es: %d\n", direccion);






	return EXIT_SUCCESS;
}
