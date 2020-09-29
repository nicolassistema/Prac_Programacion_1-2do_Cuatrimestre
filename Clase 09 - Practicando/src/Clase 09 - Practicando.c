/*
 ============================================================================
 Name        : Clase.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn_input.h"

#define SIZE_NOMBRE 50


int main(void) {

setbuf(stdout,NULL);

//char auxiliar[SIZE_NOMBRE] = "Nicolas";
char pNombre[SIZE_NOMBRE] ;



utn_getNombre ("Ingrese un numbre: ", "Ingreso invalido. ", &pNombre,  SIZE_NOMBRE,3);

 //   strncpy (pNombre, auxiliar, SIZE_NOMBRE);



printf("\nEl nombre ingresado es: %s\n", pNombre);




	return EXIT_SUCCESS;
}


