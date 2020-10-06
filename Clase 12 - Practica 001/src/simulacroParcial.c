/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================


Parametrizables:

ENTIDAD: Mensaje de ok y error
entidad_list: variable del tipo Entidad





 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "pantalla_Array.h"
#include "pantalla_HarcodArray.h"
#include "contratacion.h"
#include "contratacion_harcodArray.h"
#include "utn_input.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;

Pantalla pantallaList[QTY_PANTALLA];
pantalla_initArray(pantallaList, QTY_PANTALLA);
pantalla_hardcodDatosArray(pantallaList, QTY_CONTRATACION_TEST);
  do
    {
      printf ("\n*********"
	      "\n* MENU  *"
	      "\n*********"
	      "\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-Salir\n\n");


      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
	{
	  switch (opcion)
	    {
	    case 1:

	      if (pantalla_flagLimite (pantallaList, QTY_PANTALLA) != -1)
		{
		  if (pantalla_searchFree (pantallaList, QTY_PANTALLA) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA    *********************\n");
		      printf ("*****************************************************\n");
		      if (pantalla_chargeArray (pantallaList, QTY_PANTALLA) != 0)
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
	      if (pantalla_flagLimite (pantallaList, QTY_PANTALLA) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (pantalla_updateArray (pantallaList, QTY_PANTALLA) != 0)
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
	      if (pantalla_flagLimite (pantallaList, QTY_PANTALLA) != 0)
	      	{
		  printf ("\n*****************************************************");
		  printf ("\n******************      BAJA    *********************\n");
		  printf ("*****************************************************\n");
	      if(pantalla_prepareForDelete (pantallaList,QTY_PANTALLA)==-1)
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
	      if (pantalla_flagLimite (pantallaList, QTY_PANTALLA) != 0)
	        {
		 printf ("\n*****************************************************");
		 printf ("\n*****************    INFORMAR    ********************\n");
		 printf ("*****************************************************\n");
	   /*   if(pantalla_sortArray(pantallaList, QTY_PANTALLA, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}*/
	      utn_headerArray();
	      pantalla_printArray(pantallaList, QTY_PANTALLA);
	   /*   printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",pantalla_sumaTotal(pantallaList, QTY_PANTALLA));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",pantalla_promedio(pantallaList, QTY_PANTALLA));
      	      printf ("\nCANTIDAD DE ENTIDAD QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",pantalla_cantidadSuperiorAlPromedio(pantallaList, QTY_PANTALLA));
	      printf ("\n*****************************************************\n");*/
	     	}
	      else
			{
		  printf ("\n***************************************\n");
		  printf ("\nNO HAY ENTIDAD CARGADOS PARA MOSTRAR!\n");
		  printf ("\n***************************************\n");
			}
	      break;
	    case 5:
	      printf("\nEL RPOGRAMA SE CERRO CON EXITO!\n");
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
