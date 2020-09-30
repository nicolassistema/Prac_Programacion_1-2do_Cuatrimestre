/*
 * Nacionalidad.h
 *
 *  Created on: 29 sep. 2020
 *      Author: nico
 */

#ifndef Nacionalidad_H_
#define Nacionalidad_H_

#define LONG 50
#define SIZESTRUCT_Nacionalidad 3
#define TRUE 1
#define FALSE 0
#define MIN_ID 1
#define MAX_ID 5


typedef struct {
	char nombre[LONG];
	int isEmpty;
	int id;
	} Nacionalidad;


	int Nacionalidad_alta (Nacionalidad * pArrayNacionalidads, int limite);
	int Nacionalidad_init(Nacionalidad * pArrayNacionalidads, int limite);
	int Nacionalidad_imprimir (Nacionalidad * pArrayNacionalidads , int limite);
	int Nacionalidad_baja (Nacionalidad * pArrayNacionalidads, int limite);
	int Nacionalidad_modificar (Nacionalidad * pArrayNacionalidads, int limite);
	int Nacionalidad_imprimirIndice (Nacionalidad * pArrayNacionalidads, int limite, int indice);
	int Nacionalidad_buscarLibre (Nacionalidad * pArrayNacionalidads, int limite);
	int Nacionalidad_buscarLibreRef (Nacionalidad * pArrayNacionalidads, int limite, int * pIndice);
	int Nacionalidad_alta2 (Nacionalidad * pArrayNacionalidads, int limite);
	int Nacionalidad_buscarIndice (Nacionalidad * pArrayNacionalidads, int limite, int idBuscar,int * pIndice);

#endif /* Nacionalidad_H_ */
