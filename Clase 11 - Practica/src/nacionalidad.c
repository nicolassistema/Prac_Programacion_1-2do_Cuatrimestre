/*
 * Nacionalidad.c
 *
 *  Created on: 29 sep. 2020
 *      Author: nico
 */

/*
 * Nacionalidad.c
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
#include "Nacionalidad.h"

static int Nacionalidad_generarNuevoId (void);

// intentar fn modificar pensar dejar de pedir indice al user






 // agregar lo de isempty y el indice por defecto



int Nacionalidad_init(Nacionalidad * pArrayNacionalidads, int limite){
	int retorno = -1;
	if (pArrayNacionalidads != NULL && limite >0){
		for (int i = 0; i<limite; i++ )
		{
			pArrayNacionalidads[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}


int Nacionalidad_alta (Nacionalidad * pArrayNacionalidads, int limite){
int retorno = -1;
int indice;

Nacionalidad bufferNacionalidad;
	if (pArrayNacionalidads != NULL && limite >0)
	{
		if (Nacionalidad_buscarLibreRef (pArrayNacionalidads, limite, &indice) == 0)
		{
				if (utn_getnumero(&bufferNacionalidad.id, "\n id?", "error",  MIN_ID, MAX_ID,2) == 0 &&
					utn_getNombre(bufferNacionalidad.nombre, LONG, " \n Ingrese nombre pais","ERROR",3) == 0)
				{
						pArrayNacionalidads[indice] = bufferNacionalidad;
						pArrayNacionalidads[indice].id = Nacionalidad_generarNuevoId();
						pArrayNacionalidads[indice].isEmpty = FALSE;
				} else
					{
						printf("horror");
					}
			} else
			{
				printf(" \n No quedan espacios libres");
			}
		}
	return retorno ;
	}


int Nacionalidad_imprimir (Nacionalidad * pArrayNacionalidads , int limite) {
	int retorno = -1;
	if (pArrayNacionalidads != NULL && limite >0){
		for (int i=0 ; i<limite ; i++)
		{
			if(pArrayNacionalidads[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - id: %d - ID %d",pArrayNacionalidads[i].nombre,pArrayNacionalidads[i].id , pArrayNacionalidads[i].id);
			}
		}
		retorno = 0;
	}
return retorno;
}


int Nacionalidad_baja (Nacionalidad * pArrayNacionalidads, int limite){
	int retorno = -1;
	int buffer;
			if (pArrayNacionalidads != NULL && limite>0){
			Nacionalidad_imprimir(pArrayNacionalidads, limite);
			utn_getnumero(&buffer,"Ingrese id de Nacionalidad a borrar","Error", MIN_ID, MAX_ID,3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrayNacionalidads[i].id){
					pArrayNacionalidads[i].isEmpty = TRUE;
				}
			}
		}

	return retorno;

}
// ver de no perder el ID y usar las nuevas FN
int Nacionalidad_modificar (Nacionalidad * pArrayNacionalidads, int limite){
	int retorno = -1;
	char modificar[20];
	int buffer;
	Nacionalidad bufferNacionalidad;
			if (pArrayNacionalidads != NULL && limite>0){
			Nacionalidad_imprimir(pArrayNacionalidads, limite);
			utn_getnumero(&buffer,"Ingrese ID de Nacionalidad a modificar","Error", MIN_ID, MAX_ID,3);
			for (int i = 0 ; i<limite ;  i++){
				if (buffer == pArrayNacionalidads[i].id){
				utn_getNombre(modificar, 20, "Que desea modificar? (nombre / id)", "error", 2);
				if (strcmp(modificar, "id") == 0){
					if (utn_getnumero(&bufferNacionalidad.id, "\n Nuevo pais?", "error",  MIN_ID, MAX_ID,2) == 0){
							pArrayNacionalidads[i].id = bufferNacionalidad.id;
					} else {
						printf("horror");
					}
				}else {
					if (utn_getNombre(bufferNacionalidad.nombre, LONG, " \n Ingrese nuevo nombre","ERROR",3) == 0){
						strncpy(pArrayNacionalidads[i].nombre,bufferNacionalidad.nombre,LONG);
				}else {
					printf("horror");
				}
				}
				}
			}
		}

	return retorno;

}

int Nacionalidad_imprimirIndice (Nacionalidad * pArrayNacionalidads, int limite, int indice){
	int retorno = -1;
		if (pArrayNacionalidads != NULL && limite >0){

				if(pArrayNacionalidads[indice].isEmpty == FALSE)
				{
					printf("\nNombre: %s - id: %d",pArrayNacionalidads[indice].nombre,pArrayNacionalidads[indice].id);
				}

			retorno = 0;
		}
	return retorno;
}

int Nacionalidad_buscarLibre (Nacionalidad * pArrayNacionalidads, int limite){
	int retorno = -1;
	int i ;
		if (pArrayNacionalidads != NULL && limite >0){
			for ( i = 0; i<limite; i++) {
				if(pArrayNacionalidads[i].isEmpty == TRUE)
					{
					retorno = i;
					break;
					}
			}
		}
	return retorno;
}

int Nacionalidad_buscarLibreRef (Nacionalidad * pArrayNacionalidads, int limite, int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayNacionalidads != NULL && limite >0 && pIndice != NULL){
			for ( i = 0; i<limite; i++) {
				if(pArrayNacionalidads[i].isEmpty == TRUE)
					{
					*pIndice = i;
					retorno = 0;
					break;
					}
			}
		}
	return retorno;
}

static int Nacionalidad_generarNuevoId (void) {
	static int id = 0;
	id = id+1;
	return id;
}

int Nacionalidad_buscarIndice (Nacionalidad * pArrayNacionalidads, int limite, int idBuscar,int * pIndice){
	int retorno = -1;
	int i ;
		if (pArrayNacionalidads != NULL && limite >0 && pIndice != NULL && idBuscar >= 0)
		{
				for ( i = 0; i<limite; i++)
				{
					if(pArrayNacionalidads[i].id == idBuscar)
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


