/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef PANTALLAARRAYENTIDAD_H_
#define PANTALLA_H_

#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_PANTALLA 51
#define QTY_PANTALLA 100
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

struct
{
int id;
int isEmpty;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//int idAux;
char nombrePantalla[LONG_NAME_PANTALLA];
char direccion[LONG_NAME_PANTALLA];
int tipoPantalla;
//int NUMERO2;
float precio;
//float FLOTANTE2;
//long long int NUMERO_LARGO;


}typedef Pantalla;//SOLO SE DEBE HACER REFACTOR EN EL NOMBRE DE LA ENTIDAD
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////


//FUNCIONES MODIFICABLES
int pantalla_initArray(Pantalla* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int pantalla_addArray(Pantalla* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//		      int idAux,
		      char* nombrePantalla,
		      char* direccion,
		      int tipoPantalla,
//		      int NUMERO2,
		      float precio
//		      float FLOTANTE2,
//		      long long int NUMERO_LARGO
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int pantalla_printArray(Pantalla* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int pantalla_sortArray(Pantalla* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void pantalla_headerArray(void);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int pantalla_printForId  (Pantalla *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int pantalla_chargeArray (Pantalla* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int pantalla_updateArray (Pantalla* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
//float pantalla_sumaTotal(Pantalla* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
//float pantalla_promedio(Pantalla* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
//int pantalla_cantidadSuperiorAlPromedio(Pantalla* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////






//FUNCIONES NO MODIFICABLES
int pantalla_findArrayById (Pantalla *list, int len, int id);
int pantalla_removeArray(Pantalla* list, int len, int id);
int pantalla_searchFree (Pantalla* list, int len);
int  pantalla_bufferToArray (Pantalla* list, Pantalla * , int len, int id);
int pantalla_arrayToBuffer(Pantalla *list,Pantalla *listBuffer, int len, int id);
int pantalla_deleteArray (Pantalla* list, int len);
int pantalla_flagLimite(Pantalla* list, int len);
int pantalla_prepareForDelete (Pantalla *list, int len);
int pantalla_isEmpty(Pantalla* list, int limit, int index);
int pantalla_buscarIndiecePorId (Pantalla *list, int len, int idBuscar, int *pIndice);



#endif /* ARRAYENTIDAD_H_ */
