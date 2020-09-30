/*
 * nacionalidad.h
 *
 *  Created on: 29 sep. 2020
 *      Author: nico
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_


#define TRUE 1
#define FALSE 0
#define LONG_NAME_NACIONALIDAD 51
#define QTY_NACIONALIDAD 20
#define MAX_NACIONALIDAD 100


struct
{
int id;
char name[LONG_NAME_NACIONALIDAD];
int isEmpty;
}typedef Nacionalidad;


int initNacionalidads(Nacionalidad* list, int len);
int printNacionalidads(Nacionalidad* list, int length);
void headerNacionalidad(void);
int idIncremental(void);
int addNacionalidad(Nacionalidad* list, int len, int legajo, char* name);
int chargeNacionalidad (Nacionalidad* list, int len);
//int utn_searchFree (Nacionalidad* list, int len);
int findNacionalidadById (Nacionalidad *list, int len, int legajo);
int updateNacionalidad (Nacionalidad *list, int len);
//int  bufferToArray (Nacionalidad *list, Nacionalidad *auxNacionalidad, int len, int legajo);
//int printForId  (Nacionalidad *list, int len, int legajo);
//int arrayToBuffer(Nacionalidad *list,Nacionalidad *listBuffer, int len, int legajo);
//void printForId2  (Nacionalidad  auxNacionalidad);
//int prepareForDelete (Nacionalidad *list, int len);
int removeNacionalidad(Nacionalidad* list, int len, int legajo);
int sortNacionalidads(Nacionalidad* list, int len, int order);
int chargeNacionalidad (Nacionalidad *list, int len);

/*
int Nacionalidad_alta(Nacionalidad arrayNacionalidads[],int limite,int indice);
int Nacionalidad_imprimir(Nacionalidad* pArrayNacionalidads, int limite);
int Nacionalidad_initArray(Nacionalidad* pArrayNacionalidads, int limite);
int Nacionalidad_modificar(Nacionalidad arrayNacionalidads[],int limite,int indice);
int isEmpty(Nacionalidad* pArray, int limit, int index);
int idIncremental(void);
*/



#endif /* NACIONALIDAD_H_ */
