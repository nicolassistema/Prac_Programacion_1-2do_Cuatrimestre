/*
 * ArrayAlumnos.h
 *
 *  Created on: 25 sep. 2020
 *      Author: nico
 */

#ifndef ARRAYALUMNOS_H_
#define ARRAYALUMNOS_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_ALUMNO 51
#define QTY_ALUMNO 20
#define MAX_ALUMNO 100


struct
{
int id;
char name[LONG_NAME_ALUMNO];
int isEmpty;
}typedef Alumno;


int initAlumnos(Alumno* list, int len);
int printAlumnos(Alumno* list, int length);
void headerAlumno(void);
int idIncremental(void);
int addAlumno(Alumno* list, int len, int legajo, char* name);
int chargeAlumno (Alumno* list, int len);
int utn_searchFree (Alumno* list, int len);
int findAlumnoById (Alumno *list, int len, int legajo);
int updateAlumno (Alumno *list, int len);
int  bufferToArray (Alumno *list, Alumno *auxAlumno, int len, int legajo);
int printForId  (Alumno *list, int len, int legajo);
int arrayToBuffer(Alumno *list,Alumno *listBuffer, int len, int legajo);
void printForId2  (Alumno  auxAlumno);
int prepareForDelete (Alumno *list, int len);
int removeAlumno(Alumno* list, int len, int legajo);
int sortAlumnos(Alumno* list, int len, int order);
int chargeAlumno (Alumno *list, int len);

/*
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice);
int isEmpty(Alumno* pArray, int limit, int index);
int idIncremental(void);
*/



#endif /* ARRAYALUMNOS_H_ */
