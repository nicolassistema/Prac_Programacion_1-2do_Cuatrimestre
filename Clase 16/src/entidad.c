/*
 * entidad.c
 *
 *  Created on: 20 oct. 2020
 *      Author: nico
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_input.h"
#include "entidad.h"
#define LONG 20
#define CANT 5





void addPersona(Persona* list, char *nombre, int id)
{
  int i;

  for(i=0;i<CANT;i++)
  {
	  if(id == i)
	  {
		  strcpy(list[i].nombre, nombre);
	  }



  }



void  imprimirLista(Persona* list)
  {
int i;



	  for(i=0;i<10;i++)
	    {
	     printf("Nombre: %s", list[i].nombre);

	    }


  }

}





int* newArrayInt(int cantidad, int valorInit)
	{
		int *pArray;
		int i;

		pArray = (int*) malloc(sizeof(int) * cantidad);//--> En esta linea se reserva espacio de memoria para incrementar el pArry
		if (pArray != NULL)
		{
			for (int i = 0; i < cantidad; i++)
			{
				pArray[i] = valorInit;
			}
		}
		return pArray;////--> pArray es retornado en la funcion
	}


