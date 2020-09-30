/*
 * alumno.c
 *
 *  Created on: 29 sep. 2020
 *      Author: nico
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn.h"
#include "alumno.h"

static int alumno_generarNuevoId (void);

// intentar fn modificar pensar dejar de pedir indice al user






 // agregar lo de isempty y el indice por defecto



int alumno_init(Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	if (pArrayAlumnos != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


int alumno_alta (Alumno * pArrayAlumnos, int limite){
int retorno = -1;
int indice;

Alumno bufferAlumno;
	if (pArrayAlumnos != NULL && limite >0)
	{
		if (alumno_buscarLibreRef (pArrayAlumnos, limite, &indice) == 0)
		{
				if (utn_getnumero(&bufferAlumno.id, "\n Legajo?", "error",  MIN_LEGAJO, MAX_LEGAJO,2) == 0 &&
					utn_getNombre(bufferAlumno.nombre, LONG, " \n Ingrese nombre","ERROR",3) == 0)
				{
						pArrayAlumnos[indice] = bufferAlumno;
						pArrayAlumnos[indice].id = alumno_generarNuevoId();
						pArrayAlumnos[indice].isEmpty = FALSE;
				} else
					{
						printf("error");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
	return retorno ;
	}


int alumno_imprimir (Alumno * pArrayAlumnos , int limite) {
	int retorno = -1;
	if (pArrayAlumnos != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Legajo: %d - ID %d",pArrayAlumnos[i].nombre,pArrayAlumnos[i].legajo , pArrayAlumnos[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}


int alumno_baja (Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	int buffer;
			if (pArrayAlumnos != NULL && limite>0){
			alumno_imprimir(pArrayAlumnos, limite);
			utn_getnumero(&buffer,"Ingrese legajo de alumno a borrar","Error", MIN_LEGAJO, MAX_LEGAJO,3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrayAlumnos[i].legajo){
					pArrayAlumnos[i].isEmpty = TRUE;
				}
			}
		}

	return retorno;

}
// ver de no perder el ID y usar las nuevas FN
int alumno_modificar (Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	char modificar[20];
	int buffer;
	Alumno bufferAlumno;
			if (pArrayAlumnos != NULL && limite>0){
			alumno_imprimir(pArrayAlumnos, limite);
			utn_getnumero(&buffer,"Ingrese ID de alumno a modificar","Error", MIN_LEGAJO, MAX_LEGAJO,3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrayAlumnos[i].id){
				utn_getNombre(modificar, 20, "Que desea modificar? (nombre / legajo)", "error", 2);
				if (strcmp(modificar, "legajo") == 0){
					if (utn_getnumero(&bufferAlumno.legajo, "\n Nuevo Legajo?", "error",  MIN_LEGAJO, MAX_LEGAJO,2) == 0){
							pArrayAlumnos[i].legajo = bufferAlumno.legajo;
					} else {
						printf("horror");
					}
				}else {
					if (utn_getNombre(bufferAlumno.nombre, LONG, " \n Ingrese nuevo nombre","ERROR",3) == 0){
						strncpy(pArrayAlumnos[i].nombre,bufferAlumno.nombre,LONG);
				}else {
					printf("horror");
				}
				}
				}
			}
		}

	return retorno;

}

int alumno_imprimirIndice (Alumno * pArrayAlumnos, int limite, int indice){
	int retorno = -1;
		if (pArrayAlumnos != NULL && limite >0){

				if(pArrayAlumnos[indice].isEmpty == FALSE)
				{
					printf("\nNombre: %s - Legajo: %d",pArrayAlumnos[indice].nombre,pArrayAlumnos[indice].legajo);
				}

			retorno = 0;
		}
	return retorno;
}

int alumno_buscarLibre (Alumno * pArrayAlumnos, int limite){
	int retorno = -1;
	int i ;
		if (pArrayAlumnos != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArrayAlumnos[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int alumno_buscarLibreRef (Alumno * pArrayAlumnos, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayAlumnos != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrayAlumnos[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

static int alumno_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int alumno_buscarIndice (Alumno * pArrayAlumnos, int limite, int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayAlumnos != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayAlumnos[i].id == idBuscar)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
				}
			}
			else
			{
				printf("errrror");
			}
		return retorno;
		}

