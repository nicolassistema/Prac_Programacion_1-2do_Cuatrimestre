/*
 ============================================================================
 Name        : Clase.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "entidad.h"
#include "utn_input.h"


#define LONG 20

//limite que hay que cambiar por memoria dinamica
#define CANT 5


int main(void) {
	setbuf(stdout,NULL);




int i;
char pNombre[LONG];
char *arrayNombre;
int id = 0;
Persona perAux[5];
//-----------------------------------------------
do{
	utn_getNombre("Ingrese nombre: ", "El ingreso es incorrecto", pNombre, LONG, 5);
	addPersona(perAux, pNombre, id);

id++;
}while(id < 6);
//-----------------------------------------------
for(i=0;i<CANT;i++)
	    {
	     printf("Nombre: %s %d\n", perAux[i].nombre, i);
}
//-----------------------------------------------


arrayNombre=newArrayInt(10, -1);

for(i=0;i<CANT;i++)
	    {
	     printf("Nombre: %s %d\n", arrayNombre[i], i);
}

	return EXIT_SUCCESS;
}
