/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYENTIDAD_H_
#define ALUMNO_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_ALUMNO 51
#define QTY_ALUMNO 100

struct
{
int id;
char name[LONG_NAME_ALUMNO];
char lastName[LONG_NAME_ALUMNO];
float salary;
int sector;
int isEmpty;
}typedef Alumno;



//FUNCIONES QUE SOLICITA EL TP
int utn_initArray(Alumno* list, int len);
int utn_addArray(Alumno* list, int len, int id, char* name,char* lastName,float salary,int sector);
int utn_findArrayById (Alumno *list, int len, int id);
int utn_removeArray(Alumno* list, int len, int id);
int utn_sortArray(Alumno* list, int len, int order);
int utn_printArray(Alumno* list, int length);






//FUNCIONES COMPLEMENTARIAS A LA BIBLIOTECA
int utn_chargeArray (Alumno* list, int len);
int utn_searchFree (Alumno* list, int len);
int utn_updateArray (Alumno* list, int len);
int  bufferToArray (Alumno* list, Alumno *auxEmployee, int len, int id);
int printForId  (Alumno *list, int len, int id);
int arrayToBuffer(Alumno *list,Alumno *listBuffer, int len, int id);
void printForId2  (Alumno* auxEmployee);
int deleteEmployee (Alumno* list, int len);
float sumaTotal(Alumno* list, int len);
float promedio(Alumno* list, int len);
int cantidadSuperiorAlPromedio(Alumno* list, int len);
int flagLimite(Alumno* list, int len);
int prepareForDelete (Alumno *list, int len);
int isEmpty(Alumno* list, int limit, int index);




#endif /* ARRAYENTIDAD_H_ */
