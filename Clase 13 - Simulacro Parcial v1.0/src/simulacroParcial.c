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
#include "PantallaContract.h"

#include "utn_input.h"




int main(void) {
setbuf(stdout,NULL);
int opcion;
int bufferID;


Pantalla pantalla_list[QTY_PANTALLA];
Contrat contrat_list[QTY_CONTRAT];
pantalla_initArray(pantalla_list, QTY_PANTALLA);
contrat_initArray(contrat_list, QTY_CONTRAT);
contrat_hardcodDatosArray(contrat_list, QTY_CONTRAT_HARDCOD_TEST);
pantalla_hardcodDatosArray(pantalla_list, QTY_PANTALLA_HARDCOD_TEST);



  do
    {
      printf ("\n*********"
	      "\n* MENU  *"
	      "\n*********"
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////
	      "\n1-Alta de pantalla\n" //listo
	      "2-Modificacion\n" //listo
	      "3-Baja Pantalla\n"//No esta hecho
    	  "4-Contratar una publicidad\n"
	      "5-Modificar condiciones de publicación:\n"
    	  "6-Cancelar contratacion\n"
    	  "7-Consulta facturacion\n"
    	  "8-Listar contrataciones\n"
    	  "9-Listar pantallas\n"
    	  "10-Informar\n"


	      "11-Salir\n\n");
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 11, 3) != -1)//MODIFICAR EN CASO AGREGAR O QUITAR OPCIONES
	{
	  switch (opcion)
	    {
	    case 1:

	      if (pantalla_flagLimite (pantalla_list, QTY_PANTALLA) != -1)
		{
		  if (pantalla_searchFree (pantalla_list, QTY_PANTALLA) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA DE PANTALLA   *********************\n");
		      printf ("*****************************************************\n");
		      if (pantalla_chargeArray (pantalla_list, QTY_PANTALLA) != 0)
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
	      if (pantalla_flagLimite (pantalla_list, QTY_PANTALLA) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (pantalla_updateArray (pantalla_list, QTY_PANTALLA) != 0)
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
	      break;
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
	    	 printf ("\n*****************************************************");
	    			  printf ("\nLISTA DE PANTALLAS    *********************\n");
	    			  printf ("*****************************************************\n");
	      if (contrat_flagLimite (contrat_list, QTY_CONTRAT) != 0)
	        {
	    	  if(contrat_flagLimite (contrat_list, QTY_CONTRAT)!=0)
	    	  {
	    	  pantalla_headerArray();
	    	  pantalla_printArray(pantalla_list, QTY_PANTALLA);

		 printf ("\n*****************************************************");
		 printf ("\n         Contratar una publicidad   \n");
		 printf ("*****************************************************\n");

		 contratPantalla_chargeArray (contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);

	    	  }
	    	  else
	    	  {
	    		 printf ("\nNO HAY PANTALLAS CARGADOS PARA MOSTRAR!\n");
	    	  }
	     	}
	      else
			{
		  printf ("\n***************************************\n");
		  printf ("\nNO HAY CONTRATOS CARGADOS PARA MOSTRAR!\n");
		  printf ("\n***************************************\n");
			}
	      break;

	    case 5:
	        if (contrat_flagLimite (contrat_list, QTY_CONTRAT) != 0)
	   	        {
	   		 printf ("\n*****************************************************");
	   		 printf ("\nModificar condiciones de publicacion:   ********************\n");
	   		 printf ("*****************************************************\n");

	   		contratPantalla_updateDias (contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);
	   	    }
	   	      else
	   			{
	   		  printf ("\n***************************************\n");
	   		  printf ("\nNO HAY ENTIDAD CARGADOS PARA MOSTRAR!\n");
	   		  printf ("\n***************************************\n");
	   			}


	    	break;

	    case 6:
	    	 printf ("\n*****************************************************");
	         printf ("\n   Cancelar contratación ********************\n");
	    	 printf ("*****************************************************\n");

	    	 cancelarContratacion (contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);




	      break;
	    case 7:
	  	   	    	 printf ("\n*****************************************************");
	  	   	         printf ("\n   Consulta facturación: ********************\n");
	  	   	    	 printf ("*****************************************************\n");

	  	   	    consultaFacturacion(contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);




	  	   	      break;
	    case 8:
	   	    	 printf ("\n*****************************************************");
	   	         printf ("\n   Listar contrataciones ********************\n");
	   	    	 printf ("*****************************************************\n");
	   	    	contratMasNomPantalla_headerArray();
	   	    	contratMasNomPantalla_printArray(contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);



	   	      break;
	    case 9:
	 	    	   	    	 printf ("\n*****************************************************");
	 	    	   	         printf ("\n   Listar pantallas ********************\n");
	 	    	   	    	 printf ("*****************************************************\n");

	 	    	   	    	  pantalla_headerArray();
	 	    	   	    	  pantalla_printArray(pantalla_list, QTY_PANTALLA);
	 	    	   	    	  contrat_headerArray();
	 	    	   	    	  contrat_printArray(contrat_list, QTY_CONTRAT);

	 	    	   	      break;
	    case 10:
	    	   	    	 printf ("\n*****************************************************");
	    	   	         printf ("\n   INFORMAR ********************\n");
	    	   	    	 printf ("*****************************************************\n");

	    	   	    	listaClieteCantidadContEImporte(contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);
	    	   	    	clienteConMasImportaAFacturar(contrat_list, QTY_CONTRAT,pantalla_list, QTY_PANTALLA);
	    	   	      break;

	    case 11:


	   	      printf("\nEL PROGRAMA SE CERRO CON EXITO!\n");
	   	      system ("pause");
	   	      return EXIT_SUCCESS;
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
  while (opcion != 11);

	return EXIT_SUCCESS;
}
