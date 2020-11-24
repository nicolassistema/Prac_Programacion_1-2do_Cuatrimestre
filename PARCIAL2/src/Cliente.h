/*
 * afiches.h
 *
 *  Created on: 24 nov. 2020
 *      Author: nico
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_LEN 51
#define CUIT_LEN 20
#define ERROR -1
#define SUCCESS 0
#define TRUE 1
#define FALSE 0
#define CLIENT 1
#define SALE 2
#include "LinkedList.h"
#include "utn.h"


typedef struct {
	int idCliente;
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	char cuit[CUIT_LEN];
	int cantidadVentas;
}Cliente;




void cliente_delete(Cliente* this);



int cliente_setNombre(Cliente* this,char* nombre);


int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apeliido);

int cliente_getApellido(Cliente* this,char* apeliido);


int cliente_setId(Cliente* this,int idCliente);


int cliente_setIdTxt(Cliente* this,char* idCliente);

int cliente_getId(Cliente* this,int* idCliente);

int cliente_getIdTxt(Cliente* this,char* idCliente);

int cliente_setCuit(Cliente* this, char* cuit);

int cliente_getCuit(Cliente* this, char* cuit);

int cliente_setCantidadVentas(Cliente* this,int cantidadVentas);

int cliente_getCantidadVentas(Cliente* this,int* cantidadVentas);





#endif /* CLIENTE_H_ */
