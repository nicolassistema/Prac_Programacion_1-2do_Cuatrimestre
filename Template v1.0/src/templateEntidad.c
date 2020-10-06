/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================


Parametrizables:

template_list:COPIAR Y REEMPLAZAR POR OTRO NOMBRE. EN EL CASO DE 2 ENTIDADES, AGREGAR CON OTRO NOMBRE


 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "harcodArray.h"
#include "arrayEntidad.h"
#include "utn_input.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;

Template template_list[QTY_TEMPLATE];
template_initArray(template_list, QTY_TEMPLATE);
template_hardcodDatosArray(template_list, QTY_TEMPLATE_HARDCOD_TEST);
  do
    {
      printf ("\n*********"
	      "\n* MENU  *"
	      "\n*********"
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////
	      "\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-Salir\n\n");
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)//MODIFICAR EN CASO AGREGAR O QUITAR OPCIONES
	{
	  switch (opcion)
	    {
	    case 1:

	      if (template_flagLimite (template_list, QTY_TEMPLATE) != -1)
		{
		  if (template_searchFree (template_list, QTY_TEMPLATE) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA    *********************\n");
		      printf ("*****************************************************\n");
		      if (template_chargeArray (template_list, QTY_TEMPLATE) != 0)
			{
			  printf ("\n*****************************\n");
			  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
			  printf ("\n*****************************\n");
			}
		    }
		}
	      else
		{
		  printf ("\n*******************************************\n");
		  printf ("\nLA CANTIDAD DE ENTIDAD LLEGO A SU LIMITE!\n");
		  printf ("\n*******************************************\n");
		}

	      break;
	    case 2:
	      if (template_flagLimite (template_list, QTY_TEMPLATE) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (template_updateArray (template_list, QTY_TEMPLATE) != 0)
		    {
		      printf ("\n******\n");
		      printf ("\nERROR!\n");
		      printf ("\n******\n");
		    }
		}
	      else
		{
		  printf ("\n*****************************************\n");
		  printf ("\nNO HAY ENTIDAD CARGADOS PARA MODIFICAR!\n");
		  printf ("\n*****************************************\n");

		}
	      break;//
	    case 3:
	      if (template_flagLimite (template_list, QTY_TEMPLATE) != 0)
	      	{
		  printf ("\n*****************************************************");
		  printf ("\n******************      BAJA    *********************\n");
		  printf ("*****************************************************\n");
	      if(template_prepareForDelete (template_list,QTY_TEMPLATE)==-1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      	}
	      else
	      		{
		  printf ("\n****************************************\n");
		  printf ("\nNO HAY ENTIDAD CARGADOS PARA ELIMINAR!\n");
		  printf ("\n****************************************\n");
	      		}
	      break;
	    case 4:
	      if (template_flagLimite (template_list, QTY_TEMPLATE) != 0)
	        {
		 printf ("\n*****************************************************");
		 printf ("\n*****************    INFORMAR    ********************\n");
		 printf ("*****************************************************\n");
	      if(template_sortArray(template_list, QTY_TEMPLATE, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      template_headerArray();
	      template_printArray(template_list, QTY_TEMPLATE);
	      printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",template_sumaTotal(template_list, QTY_TEMPLATE));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",template_promedio(template_list, QTY_TEMPLATE));
      	      printf ("\nCANTIDAD DE ENTIDAD QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",template_cantidadSuperiorAlPromedio(template_list, QTY_TEMPLATE));
	      printf ("\n*****************************************************\n");
	     	}
	      else
			{
		  printf ("\n***************************************\n");
		  printf ("\nNO HAY ENTIDAD CARGADOS PARA MOSTRAR!\n");
		  printf ("\n***************************************\n");
			}
	      break;
	    case 5:
	      printf("\nEL PROGRAMA SE CERRO CON EXITO!\n");
	      system ("pause");
	      return EXIT_SUCCESS;
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  printf ("\n*****************************\n");
	  printf ("\nSE TERMINARON LOS REINTENTOS!\n");
	  printf ("\n*****************************\n");
	  //return EXIT_SUCCESS;
	}
    }
  while (opcion != 5);

	return EXIT_SUCCESS;
}
