/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include "pantalla_HarcodArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "pantalla_Array.h"



void pantalla_hardcodDatosArray(Pantalla list[], int len)
{
    int i;

    int idPantalla[QTY_CONTRATACION_TEST] = {1,2,3,4,5};
    char nombrePantalla[QTY_CONTRATACION_TEST][LONG_NAME_PANTALLA]= {"philco","philco","philco","philco","sony"};
    char direccion[QTY_CONTRATACION_TEST][LONG_NAME_PANTALLA]= {"AAAAAAAAA","BBBBBBBBB","CCCCCCCC","DDDDDDDD","EEEEEEEE"};
    float precioPantalla[QTY_CONTRATACION_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};
    int tipoPantalla[QTY_CONTRATACION_TEST] = {1,2,2,1,2};
    int estadoPantalla[QTY_CONTRATACION_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};



    for(i=0; i<len; i++)
        {
            list[i].idPantalla = idPantalla[i];
            strcpy(list[i].namePantalla, nombrePantalla[i]);
            strcpy(list[i].direccion, direccion[i]);
            list[i].precioPublicidad = precioPantalla[i];
            list[i].tipoPantalla = tipoPantalla[i];
            list[i].isEmpty = estadoPantalla[i];
        }
}
