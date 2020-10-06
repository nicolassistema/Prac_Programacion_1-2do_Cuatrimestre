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

//    int idPantallaAux[QTY_PANTALLA_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    char nombrePantalla_Pantalla[QTY_PANTALLA_HARDCOD_TEST][LONG_NAME_PANTALLA]= {"Nicolas","Nicolas","Pedro","Juan","Marcelo"};
    char direccion_Pantalla[QTY_PANTALLA_HARDCOD_TEST][LONG_NAME_PANTALLA]= {"A_Letticugna","E_Dominguez","C_Gonzalez","Z_Dominguez","E_Dominguez"};
    int tipoPantalla_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {9,10,15,8,5};
//    int NUMERO2_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {9,10,15,8,5};
    float precio_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};
//    float FLOTANTE2_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};
//    long long int NUMERO_LARGO_Pantalla[QTY_PANTALLA_HARDCOD_TEST] = {20323205103000,20323205103000,20323205103000,20323205103000,20323205103000};


    for(i=0; i<len; i++)
        {
            list[i].id = idPantalla[i];/////////NO TOCAR////////
            list[i].isEmpty = estadoPantalla[i];/////////NO TOCAR////////

 //           list[i].idAux = idPantallaAux[i];
            strcpy(list[i].nombrePantalla, nombrePantalla_Pantalla[i]);
            strcpy(list[i].direccion, direccion_Pantalla[i]);
            list[i].tipoPantalla = tipoPantalla_Pantalla[i];
//            list[i].NUMERO2 = NUMERO2_Pantalla[i];
            list[i].precio = precio_Pantalla[i];
//            list[i].FLOTANTE2 = FLOTANTE2_Pantalla[i];
//            list[i].NUMERO_LARGO = NUMERO_LARGO_Pantalla[i];


        }
}
