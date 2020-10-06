/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include "harcodArrayPantalla.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "arrayPantalla.h"



void pantalla_hardcodDatosArray(Pantalla list[], int len)
{
    int i;

    int idPantalla[QTY_PANTALLA_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    int estadoPantalla[QTY_PANTALLA_HARDCOD_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////
    char nombrePantalla_Pantalla[QTY_PANTALLA_HARDCOD_TEST][LONG_NAME_PANTALLA]= {"pantalla1","pantalla2","pantalla3","pantalla4","pantalla15"};
    char direccion_Pantalla[QTY_PANTALLA_HARDCOD_TEST][LONG_NAME_PANTALLA]= {"direccion1","direccion2","direccion3","direccion4","direccion5"};
    int tipoPantalla_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {1,2,1,1,2};
    float precio_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};



    for(i=0; i<len; i++)
        {
            list[i].id = idPantalla[i];/////////NO TOCAR////////
            list[i].isEmpty = estadoPantalla[i];/////////NO TOCAR////////
            strcpy(list[i].nombrePantalla, nombrePantalla_Pantalla[i]);
            strcpy(list[i].direccion, direccion_Pantalla[i]);
            list[i].tipoPantalla = tipoPantalla_Pantalla[i];
            list[i].precio = precio_Pantalla[i];



        }
}
