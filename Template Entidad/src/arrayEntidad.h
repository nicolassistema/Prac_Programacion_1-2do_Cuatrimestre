/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYENTIDAD_H_
#define ARRAYENTIDAD_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_EMPLOYE 51
#define QTY_ENTIDAD 100

struct
{
int id;
char name[LONG_NAME_EMPLOYE];
char lastName[LONG_NAME_EMPLOYE];
float salary;
int sector;
int isEmpty;
}typedef Entidad;



//FUNCIONES QUE SOLICITA EL TP
int utn_initArray(Entidad* list, int len);
int utn_addArray(Entidad* list, int len, int id, char* name,char* lastName,float salary,int sector);
int utn_findArrayById (Entidad *list, int len, int id);
int utn_removeArray(Entidad* list, int len, int id);
int utn_sortArray(Entidad* list, int len, int order);
int utn_printArray(Entidad* list, int length);






//FUNCIONES COMPLEMENTARIAS A LA BIBLIOTECA
int utn_chargeArray (Entidad* list, int len);
int utn_searchFree (Entidad* list, int len);
int utn_updateArray (Entidad* list, int len);
int  utn_bufferToArray (Entidad* list, Entidad *auxEmployee, int len, int id);
int utn_printForId  (Entidad *list, int len, int id);
int utn_arrayToBuffer(Entidad *list,Entidad *listBuffer, int len, int id);
int utn_deleteArray (Entidad* list, int len);
float utn_sumaTotal(Entidad* list, int len);
float utn_promedio(Entidad* list, int len);
int utn_cantidadSuperiorAlPromedio(Entidad* list, int len);
int utn_flagLimite(Entidad* list, int len);
int utn_prepareForDelete (Entidad *list, int len);
int utn_isEmpty(Entidad* list, int limit, int index);




#endif /* ARRAYENTIDAD_H_ */
