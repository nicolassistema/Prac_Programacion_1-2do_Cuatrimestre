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

Contratacion entidad_list[QTY_CONTRATACION];
contratacion_initArray(entidad_list, QTY_CONTRATACION);
pantalla_hardcodDatosArray(entidad_list, QTY_CONTRATACION_TEST);
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

	      if (contratacion_flagLimite (entidad_list, QTY_CONTRATACION) != -1)
		{
		  if (contratacion_searchFree (entidad_list, QTY_CONTRATACION) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA    *********************\n");
		      printf ("*****************************************************\n");
		      if (contratacion_chargeArray (entidad_list, QTY_CONTRATACION) != 0)
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
	      if (contratacion_flagLimite (entidad_list, QTY_CONTRATACION) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (contratacion_updateArray (entidad_list, QTY_CONTRATACION) != 0)
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
	      if (contratacion_flagLimite (entidad_list, QTY_CONTRATACION) != 0)
	      	{
		  printf ("\n*****************************************************");
		  printf ("\n******************      BAJA    *********************\n");
		  printf ("*****************************************************\n");
	      if(contratacion_prepareForDelete (entidad_list,QTY_CONTRATACION)==-1)
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
	      if (contratacion_flagLimite (entidad_list, QTY_CONTRATACION) != 0)
	        {
		 printf ("\n*****************************************************");
		 printf ("\n*****************    INFORMAR    ********************\n");
		 printf ("*****************************************************\n");
	      if(contratacion_sortArray(entidad_list, QTY_CONTRATACION, 1) == -1)
		{
		  printf ("\n******\n");
		  printf ("\nERROR!\n");
		  printf ("\n******\n");
		}
	      utn_headerArray();
	      contratacion_printArray(entidad_list, QTY_CONTRATACION);
	      printf ("\n*****************************************************\n");
	      printf ("TOTAL DE LOS SALARIOS: ");
	      printf ("%.2f",contratacion_sumaTotal(entidad_list, QTY_CONTRATACION));
	      printf ("\nPROMEDIO DE LOS SALARIOS: ");
	      printf ("%.2f",contratacion_promedio(entidad_list, QTY_CONTRATACION));
      	      printf ("\nCANTIDAD DE ENTIDAD QUE SUPERAN EL PROMEDIO: ");
	      printf ("%d",contratacion_cantidadSuperiorAlPromedio(entidad_list, QTY_CONTRATACION));
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
