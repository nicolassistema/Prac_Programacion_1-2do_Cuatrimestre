/*
 * Controller.h
 *
 *  Created on: 15 nov. 2020
 *      Author: nico
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Envios.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEnvio);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEnvio);
int controller_addEnvio(LinkedList* pArrayListEnvio);
int controller_editEnvio(LinkedList* pArrayListEnvio);
int controller_removeEnvio(LinkedList* pArrayListEnvio);
int controller_ListEnvio(LinkedList* pArrayListEnvio);
int controller_sortEnvio(LinkedList* pArrayListEnvio);
int controller_saveAsText(char* path , LinkedList* pArrayListEnvio);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEnvio);
int controller_buscarPorIdArray(LinkedList* pArrayListEnvio, int id);
int controller_sortEnviobyID(LinkedList* pArrayListEnvio);
int controller_containsElemento(LinkedList* pArrayListEnvio, Envio* envio);
int controller_createListOfZones(LinkedList* listaEnvios);
LinkedList* zona_generateList(LinkedList* listaEnvios);
int controller_printOneZone(void* pElement);
int controller_printListZone(LinkedList* listaEnvios);



#endif /* CONTROLLER_H_ */
