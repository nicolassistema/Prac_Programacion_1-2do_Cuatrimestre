/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYENTIDAD_H_
#define CONTRAT_H_

#define TRUE 1
#define FALSE 0
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
#define LONG_NAME_CONTRAT 51
#define QTY_CONTRAT 100
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////

struct
{
int id;
int isEmpty;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
int idPantalla;
char nombreArchivo[LONG_NAME_CONTRAT];
//char NOMBRE2[LONG_NAME_CONTRAT];
int cantDias;
//int NUMERO2;
//float FLOTANTE1;
//float FLOTANTE2;
long long int cuil;


}typedef Contrat;//SOLO SE DEBE HACER REFACTOR EN EL NOMBRE DE LA ENTIDAD
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////


//FUNCIONES MODIFICABLES
int contrat_initArray(Contrat* list, int len); ////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////

int contrat_addArray(Contrat* list, int len, int id,////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      int idPantalla,
		      char* nombreArchivo,
//		      char* NOMBRE2,
		      int cantDias,
//		      int NUMERO2,
//		      float FLOTANTE1,
//		      float FLOTANTE2,
		      long long int cuil
///////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      );
int contrat_printArray(Contrat* list, int length);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int contrat_sortArray(Contrat* list, int len, int order);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
void contrat_headerArray(void);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int contrat_printForId  (Contrat *list, int len, int id);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int contrat_chargeArray (Contrat* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int contrat_updateArray (Contrat* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float contrat_sumaTotal(Contrat* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
float contrat_promedio(Contrat* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int contrat_cantidadSuperiorAlPromedio(Contrat* list, int len);////********MODIFICABLE INTERNAMENTE EN LA FUNCION********////
int contrat_printForIdAux  (Contrat *list, int len, int idAux);
int contrat_findIdArrayByIdAux (Contrat *list, int len, int idAux, int *id);





//FUNCIONES NO MODIFICABLES
int contrat_findArrayById (Contrat *list, int len, int id);
int contrat_removeArray(Contrat* list, int len, int id);
int contrat_searchFree (Contrat* list, int len);
int  contrat_bufferToArray (Contrat* list, Contrat * , int len, int id);
int contrat_arrayToBuffer(Contrat *list,Contrat *listBuffer, int len, int id);
int contrat_deleteArray (Contrat* list, int len);
int contrat_flagLimite(Contrat* list, int len);
int contrat_prepareForDelete (Contrat *list, int len);
int contrat_isEmpty(Contrat* list, int limit, int index);
int contrat_buscarIndiecePorId (Contrat *list, int len, int idBuscar, int *pIndice);



#endif /* ARRAYENTIDAD_H_ */
