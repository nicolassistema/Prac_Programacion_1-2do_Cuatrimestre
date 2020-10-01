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
#include "harcodArray.h"
#include "arrayEntidad.h"
#include "utn_input.h"



int main(void) {
setbuf(stdout,NULL);
int opcion;

Entidad entidad_list[QTY_ENTIDAD];
utn_initArray(entidad_list, QTY_ENTIDAD);
hardcodDatosArray(entidad_list, QTY_ENTIDAD_TEST);
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

	      if (utn_flagLimite (entidad_list, QTY_ENTIDAD) != -1)
		{
		  if (utn_searchFree (entidad_list, QTY_ENTIDAD) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA    *********************\n");
		      printf ("*****************************************************\n");
		      if (utn_chargeArray (entidad_list, QTY_ENTIDAD) != 0)
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
	      if (utn_flagLimite (entidad_list, QTY_ENTIDAD) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (utn_updateArray (entidad_list, QTY_ENTIDAD) != 0)
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
	      if (utn_flagLimite (entidad_list, QTY_ENTIDAD) != 0)
	      	{
		  printf ("\n*****************************************************");
		  printf ("\n******************      BAJA    *********************\n");
		  printf ("*****************************************************\n");
	      if(utn_prepareForDelete (entidad_list,QTY_ENTIDAD)==-1)
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
	      if (utn_flagLimite (entidad_list, QTY_ENTIDAD) != 0)
	        {
		 printf ("\n*****************************************************");
		 printf ("\n*****************    INFORMAR    ********************\n");
		 printf ("*****************************************************\n");
	      if(utn_sortArray(entidad_list, QTY_ENTIDAD, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      utn_headerArray();
	      utn_printArray(entidad_list, QTY_ENTIDAD);
	      printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",utn_sumaTotal(entidad_list, QTY_ENTIDAD));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",utn_promedio(entidad_list, QTY_ENTIDAD));
      	      printf ("\nCANTIDAD DE ENTIDAD QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",utn_cantidadSuperiorAlPromedio(entidad_list, QTY_ENTIDAD));
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
