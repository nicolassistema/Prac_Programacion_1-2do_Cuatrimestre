/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "harcodArray.h"
#include "arrayEntidad.h"



void pantalla_hardcodDatosArray(Contratacion list[], int len)
{
    int i;

    int idEmpleado[QTY_CONTRATACION_TEST] = {1,2,3,4,5};
    char nombreEmpleado[QTY_CONTRATACION_TEST][LONG_NAME_CONTRATACION]= {"Nicolas","Nicolas","Pedro","Juan","Marcelo"};
    char apellidoEmpleado[QTY_CONTRATACION_TEST][LONG_NAME_CONTRATACION]= {"A_Letticugna","E_Dominguez","C_Gonzalez","Z_Dominguez","E_Dominguez"};
    float salarioEmpleado[QTY_CONTRATACION_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};
    int sectorEmpleado[QTY_CONTRATACION_TEST] = {9,10,15,8,5};
    int estadoEmpleado[QTY_CONTRATACION_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};

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
