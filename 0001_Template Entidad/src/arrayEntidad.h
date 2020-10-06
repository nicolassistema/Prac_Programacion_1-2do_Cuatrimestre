/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYENTIDAD_H_
#define CONTRATACION_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_CONTRATACION 51
#define QTY_CONTRATACION 100

struct
{
int id;
char name[LONG_NAME_CONTRATACION];
char lastName[LONG_NAME_CONTRATACION];
float salary;
int sector;
int isEmpty;
}typedef Contratacion;



//FUNCIONES QUE SOLICITA EL TP
int contratacion_initArray(Contratacion* list, int len);
int contratacion_addArray(Contratacion* list, int len, int id, char* name,char* lastName,float salary,int sector);
int contratacion_findArrayById (Contratacion *list, int len, int id);
int contratacion_removeArray(Contratacion* list, int len, int id);
int contratacion_sortArray(Contratacion* list, int len, int order);
int contratacion_printArray(Contratacion* list, int length);






//FUNCIONES COMPLEMENTARIAS A LA BIBLIOTECA
int contratacion_chargeArray (Contratacion* list, int len);
int contratacion_searchFree (Contratacion* list, int len);
int contratacion_updateArray (Contratacion* list, int len);
int  contratacion_bufferToArray (Contratacion* list, Contratacion *auxEmployee, int len, int id);
int contratacion_printForId  (Contratacion *list, int len, int id);
int contratacion_arrayToBuffer(Contratacion *list,Contratacion *listBuffer, int len, int id);
int contratacion_deleteArray (Contratacion* list, int len);
float contratacion_sumaTotal(Contratacion* list, int len);
float contratacion_promedio(Contratacion* list, int len);
int contratacion_cantidadSuperiorAlPromedio(Contratacion* list, int len);
int contratacion_flagLimite(Contratacion* list, int len);
int contratacion_prepareForDelete (Contratacion *list, int len);
int contratacion_isEmpty(Contratacion* list, int limit, int index);
int contratacion_buscarIndiecePorId (Contratacion *list, int len, int idBuscar, int *pIndice);



#endif /* ARRAYENTIDAD_H_ */
