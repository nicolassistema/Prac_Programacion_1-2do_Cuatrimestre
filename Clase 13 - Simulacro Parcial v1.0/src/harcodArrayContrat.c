/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include "harcodArrayContrat.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "arrayContrat.h"



void contrat_hardcodDatosArray(Contrat list[], int len)
{
    int i;

    int idContrato[QTY_CONTRAT_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    int estadoTemplate[QTY_CONTRAT_HARDCOD_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////

    int idPantalla[QTY_CONTRAT_HARDCOD_TEST] = {1,2,3,5,4};/////////NO TOCAR////////
    char nombreArchivo[QTY_CONTRAT_HARDCOD_TEST][LONG_NAME_CONTRAT]= {"Archivo_1","Archivo_2","Archivo_3","Archivo_4","Archivo_5"};
    int cantDias[QTY_CONTRAT_HARDCOD_TEST] = {9,10,15,8,5};
    long long int cuil[QTY_CONTRAT_HARDCOD_TEST] = {20323205109,20323205109,20323205103001,20323205103003,20323205103003};


    for(i=0; i<len; i++)
        {
            list[i].id = idContrato[i];/////////NO TOCAR////////
            list[i].isEmpty = estadoTemplate[i];/////////NO TOCAR////////

            list[i].idPantalla = idPantalla[i];
            strcpy(list[i].nombreArchivo, nombreArchivo[i]);
            list[i].cantDias = cantDias[i];
            list[i].cuil= cuil[i];


        }
}
