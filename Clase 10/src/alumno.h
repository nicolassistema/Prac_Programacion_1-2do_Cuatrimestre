/*
 * alumno.h
 *
 *  Created on: 24 sep. 2020
 *      Author: nico
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_



#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_ALUMNOS 5
#define MIN_LEGAJO 50
#define MAX_LEGAJO 9999

typedef struct
{
	char nombre[LONG_NOMBRE];
	int legajo;
	int isEmpty;
}Alumno;

int alumno_alta(Alumno arrayAlumnos[],int limite,int indice);
int alumno_imprimir(Alumno* pArrayAlumnos, int limite);
int alumno_initArray(Alumno* pArrayAlumnos, int limite);
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice);
int isEmpty(Alumno* pArray, int limit, int index);
int idIncremental(void);
#endif /* ALUMNO_H_ */
