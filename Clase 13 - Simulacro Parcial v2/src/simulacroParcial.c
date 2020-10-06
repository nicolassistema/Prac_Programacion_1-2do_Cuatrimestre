/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================


Parametrizables:

contrat_list:COPIAR Y REEMPLAZAR POR OTRO NOMBRE. EN EL CASO DE 2 ENTIDADES, AGREGAR CON OTRO NOMBRE


 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "arrayContrat.h"
#include "harcodArrayContrat.h"
#include "arrayPantalla.h"
#include "harcodArrayPantalla.h"
#include "utn_input.h"
#include "ContractPantalla.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;

Pantalla pantalla_list[QTY_PANTALLA];
Contrat contrat_list[QTY_CONTRAT];
contrat_initArray(contrat_list, QTY_CONTRAT);
pantalla_initArray(pantalla_list, QTY_PANTALLA);
contrat_hardcodDatosArray(contrat_list, QTY_CONTRAT_HARDCOD_TEST);
pantalla_hardcodDatosArray(pantalla_list, QTY_PANTALLA_HARDCOD_TEST);
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
    	  "5-Contratar publicidad\n"
	      "6-Salir\n\n");
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)//MODIFICAR EN CASO AGREGAR O QUITAR OPCIONES
	{
	  switch (opcion)
	    {
	    case 1:

	      if (contrat_flagLimite (contrat_list, QTY_CONTRAT) != -1)
		{
		  if (contrat_searchFree (contrat_list, QTY_CONTRAT) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA    *********************\n");
		      printf ("*****************************************************\n");
		      if (contrat_chargeArray (contrat_list, QTY_CONTRAT) != 0)
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
	      if (contrat_flagLimite (contrat_list, QTY_CONTRAT) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (contrat_updateArray (contrat_list, QTY_CONTRAT) != 0)
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
	      if (contrat_flagLimite (contrat_list, QTY_CONTRAT) != 0)
	      	{
		  printf ("\n*****************************************************");
		  printf ("\n******************      BAJA    *********************\n");
		  printf ("*****************************************************\n");
	      if(contrat_prepareForDelete (contrat_list,QTY_CONTRAT)==-1)
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
	      if (contrat_flagLimite (contrat_list, QTY_CONTRAT) != 0)
	        {
		 printf ("\n*****************************************************");
		 printf ("\n*****************    INFORMAR    ********************\n");
		 printf ("*****************************************************\n");
	      if(contrat_sortArray(contrat_list, QTY_CONTRAT, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      contrat_headerArray();
	      contrat_printArray(contrat_list, QTY_CONTRAT);
	      printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
//	      printf ("%.2f",contrat_sumaTotal(contrat_list, QTY_CONTRAT));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
//	      printf ("%.2f",contrat_promedio(contrat_list, QTY_CONTRAT));
      	      printf ("\nCANTIDAD DE ENTIDAD QUE SUPERAN EL PROMEDIO: ");
//	      printf ("%d",contrat_cantidadSuperiorAlPromedio(contrat_list, QTY_CONTRAT));
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
	      printf("\nContratar!\n");
	      contratarPublicidad(contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);


	      break;
	    case 6:
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
