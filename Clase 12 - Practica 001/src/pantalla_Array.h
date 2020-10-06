/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYENTIDAD_H_
#define PANTALLA_H_

#define TIPO1 1
#define TIPO2 2
#define TRUE 1
#define FALSE 0
#define LONG_NAME_PANTALLA 51
#define QTY_PANTALLA 100

struct
{
int idPantalla;
char namePantalla[LONG_NAME_PANTALLA];
int tipoPantalla;
float precioPublicidad;
char direccion[LONG_NAME_PANTALLA];
int isEmpty;
}typedef Pantalla;



//FUNCIONES QUE SOLICITA EL TP
int pantalla_initArray(Pantalla* list, int len);
int pantalla_addArray(Pantalla* list, int len, int idPantalla, char* nombrePantalla,char* direccion,float precioPublicidad,int tipoPantalla);
int pantalla_findArrayById (Pantalla *list, int len, int idPantalla);
int pantalla_removeArray(Pantalla* list, int len, int idPantalla);
int pantalla_sortArray(Pantalla* list, int len, int order);
int pantalla_printArray(Pantalla* list, int length);






//FUNCIONES COMPLEMENTARIAS A LA BIBLIOTECA
int pantalla_chargeArray (Pantalla* list, int len);
int pantalla_searchFree (Pantalla* list, int len);
int pantalla_updateArray (Pantalla* list, int len);
int  pantalla_bufferToArray (Pantalla* list, Pantalla *auxEmployee, int len, int idPantalla);
int pantalla_printForId  (Pantalla *list, int len, int idPantalla);
int pantalla_arrayToBuffer(Pantalla *list,Pantalla *listBuffer, int len, int idPantalla);
int contratacion_deleteArray (Pantalla* list, int len);
float pantalla_sumaTotal(Pantalla* list, int len);
float pantalla_promedio(Pantalla* list, int len);
int pantalla_cantidadSuperiorAlPromedio(Pantalla* list, int len);
int pantalla_flagLimite(Pantalla* list, int len);
int pantalla_prepareForDelete (Pantalla *list, int len);
int pantalla_isEmpty(Pantalla* list, int limit, int index);
int pantalla_buscarIndiecePorId (Pantalla *list, int len, int idBuscar, int *pIndice);



#endif /* ARRAYENTIDAD_H_ */
