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
#include "ArrayEmployees.h"
#include "hardcodDataEmploye.h"



void hardcodDatosEmpleado(Employee list[], int len)
{
    int i;

    int idEmpleado[QTY_EMPLOYE_TEST] = {1,2,3,4,5};
    char nombreEmpleado[QTY_EMPLOYE_TEST][LONG_NAME_EMPLOYE]= {"Nicolas","Jose","Pedro","Juan","Marcelo"};
    char apellidoEmpleado[QTY_EMPLOYE_TEST][LONG_NAME_EMPLOYE]= {"Letticugna","Gomez","Gonzalez","Dominguez","Dominguez"};
    float salarioEmpleado[QTY_EMPLOYE_TEST] = {34000.00,40000.50,65000.59,48200.00,29100.00};
    int sectorEmpleado[QTY_EMPLOYE_TEST] = {1,2,3,4,5};
    int estadoEmpleado[QTY_EMPLOYE_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};

    for(i=0; i<len; i++)
        {
            list[i].id = idEmpleado[i];
            strcpy(list[i].name, nombreEmpleado[i]);
            strcpy(list[i].lastName, apellidoEmpleado[i]);
            list[i].salary = salarioEmpleado[i];
            list[i].sector = sectorEmpleado[i];
            list[i].isEmpty = estadoEmpleado[i];
        }
}
