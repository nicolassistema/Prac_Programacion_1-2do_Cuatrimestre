/*
 * harcodDataEmploye.c
 *
 *  Created on: 26 sep. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ArrayAlumnos.h"
#include "hardcodDataAlumno.h"



void hardcodDatosAlumno(Alumno* list, int len)
{
    int i;

    int legajoAlumno[QTY_ALUMNO_TEST] = {1,2,3,4,5};
    char nombreAlumno[QTY_ALUMNO_TEST][LONG_NAME_ALUMNO]= {"Nicolas","Nicolas","Pedro","Juan","Marcelo"};
   int estadoAlumno[QTY_ALUMNO_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};

    for(i=0; i<len; i++)
        {
            list[i].id = legajoAlumno[i];
            strcpy(list[i].name, nombreAlumno[i]);
            list[i].isEmpty = estadoAlumno[i];
        }
}

