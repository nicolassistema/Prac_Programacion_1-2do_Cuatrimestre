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

    char nombrePantalla_Pantalla[QTY_PANTALLA_HARDCOD_TEST][LONG_NAME_PANTALLA]= {"Pantalla1","Pantalla2","Pantalla3","Pantalla4","Pantalla5"};
    char direccion_Pantalla[QTY_PANTALLA_HARDCOD_TEST][LONG_NAME_PANTALLA]= {"Direccion1","Direccion1","Direccion1","Direccion1","Direccion1"};
    int tipoPantalla_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {1,2,1,2,1};
    float precio_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {200.00,300.50,450.11,580.00,610.00};


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
