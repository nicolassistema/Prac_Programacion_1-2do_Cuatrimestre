/*
 ============================================================================
 Name        : MODELO_2doPARCIAL_LABO-II.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LEN_AUX 128



int main(void) {
  setbuf(stdout,NULL);

  int option = 0;
  int archivoCargado = 0;
  myBook* myBook,;
  int auxIndice;
  int contadorAux;
  LinkedList* sublista;
  int to;
  int from;
  char  nombreAux [LEN_AUX];



  LinkedList* MyBook = ll_newLinkedList();


  do{
       	utn_getNumero(&option,			  "\n\n1. Cargar archivos\n"
       						  "2. Imprimir Envios\n"
       						  "4. Generar archivo de costos para zona\n"
       						  "6. Salir\n",
   							  "Opción inválida\n",
   							  1,4,2);
           switch(option)
           {
               case 1:
              	 printf("\nCARGAR ARCHIVO\n*********************\n");
               	if(archivoCargado == 0)
               	{
               	    if(!controller_loadFromText("data.csv",listaEnvios))
               	      {
               		archivoCargado = 1;
               	      }
               	}
               	else
               	{
               	    printf("Archivo ya cargado\n");
               	}
                   break;
               case 2:
              	 printf("\niMPRIMIR ENVIOS\n*********************\n");
              	 controller_ListEnvio(listaEnvios);
  		 break;
               case 3:
                         	 printf("\nCALCULAR COSTOS\n*********************\n");
                         	calcularCostos(listaEnvios);
             		 break;
               case 4:
                         	 printf("\nGenerar archivo de costos para zona\n*********************\n");

                  utn_getNombre(nombreAux, LEN_AUX,"Ingrese Zona\n", "Zona incorrecto\n",2);
                  //buscar validacion para que no entre en el resto de las funciones sino encuentra la zona

                       	sublista = ll_filter2(listaEnvios,nombreAux,filtrarPorCriterio);
                    	controller_ListEnvio(sublista);
                        	seteaNombreArchivo(nombreAux);
                         	controller_saveAsText(nombreAux,sublista);


             		 break;
           }
       }while(option != 4);














	return EXIT_SUCCESS;
}
