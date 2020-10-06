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

    int idTemplate[QTY_CONTRAT_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    int estadoTemplate[QTY_CONTRAT_HARDCOD_TEST]= {FALSE,FALSE,FALSE,FALSE,FALSE};/////////NO TOCAR////////

    int idPantalla[QTY_CONTRAT_HARDCOD_TEST] = {1,2,3,4,5};/////////NO TOCAR////////
    char nombrePantalla[QTY_CONTRAT_HARDCOD_TEST][LONG_NAME_CONTRAT]= {"Nicolas","Nicolas","Pedro","Juan","Marcelo"};
//    char NOMBRE2_Template[QTY_CONTRAT_HARDCOD_TEST][LONG_NAME_CONTRAT]= {"A_Letticugna","E_Dominguez","C_Gonzalez","Z_Dominguez","E_Dominguez"};
    int cantDias[QTY_CONTRAT_HARDCOD_TEST] = {9,10,15,8,5};
//    int NUMERO2_Template[QTY_CONTRAT_HARDCOD_TEST] = {9,10,15,8,5};
//    float FLOTANTE1_Template[QTY_CONTRAT_HARDCOD_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};
//    float FLOTANTE2_Template[QTY_CONTRAT_HARDCOD_TEST] = {34000.00,40000.50,65000.11,48200.00,29100.00};
    long long int cuil[QTY_CONTRAT_HARDCOD_TEST] = {20323205103000,20323205103000,20323205103000,20323205103000,20323205103000};


    for(i=0; i<len; i++)
        {
            list[i].id = idTemplate[i];/////////NO TOCAR////////
            list[i].isEmpty = estadoTemplate[i];/////////NO TOCAR////////

            list[i].idPantalla = idPantalla[i];
            strcpy(list[i].nombreArchivo, nombrePantalla[i]);
 //           strcpy(list[i].NOMBRE2, NOMBRE2_Template[i]);
            list[i].cantDias = cantDias[i];
//            list[i].NUMERO2 = NUMERO2_Template[i];
//            list[i].FLOTANTE1 = FLOTANTE1_Template[i];
//            list[i].FLOTANTE2 = FLOTANTE2_Template[i];
            list[i].cuil= cuil[i];


        }
}
