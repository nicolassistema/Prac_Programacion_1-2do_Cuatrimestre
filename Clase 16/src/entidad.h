/*
 * entidad.h
 *
 *  Created on: 20 oct. 2020
 *      Author: nico
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_

#define LONG 20
#define CANT 5

struct
{
char nombre[LONG];
}typedef Persona;


void addPersona(Persona* list, char nombre[], int id);
void imprimirLista(Persona* list);
int* newArrayInt(int cantidad, int valorInit);


#endif /* ENTIDAD_H_ */
