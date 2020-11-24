/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "utn_input.h"
#include "ArrayEmployees.h"
#include "hardcodDataEmploye.h"

int main(void) {
setbuf(stdout,NULL);
int opcion;
//Employee employeeList[QTY_EMPLOYE];
Employee * employeeList[QTY_EMPLOYE]; // Esto contiene un array de punteros
p_InitEmployees(employeeList, QTY_EMPLOYE);
p_HardcodDatosEmpleado(employeeList);



/////MANEJO DE ARCHIVOS//////////////////////////////////////////////////////////////////////////
FILE * archivo;//Se genera un puntero a FILE

archivo = fopen("archivo.txt","wb");//Se genera archivo en modo escribir binario



////////////////////////////////////////////////////////////////////////////////////////////////






  do
    {
      printf ("\n*********"
	      "\n* MENU  *"
	      "\n*********"
	      "\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-GRABAR\n\n"
    		  "6-LEER\n\n"
    		  "7-Salir\n\n");

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 7, 3) != -1)
	{
	  switch (opcion)
	    {
	    case 1:

	    	p_ChargeEmployee (employeeList);
/*	      if (flagLimite (employeeList, QTY_EMPLOYE) != -1)
		{
		  if (utn_searchFree (employeeList, QTY_EMPLOYE) == TRUE)
		    {
		      printf ("\n*****************************************************");
		      printf ("\n******************      ALTA    *********************\n");
		      printf ("*****************************************************\n");
		      if (chargeEmployee (employeeList, QTY_EMPLOYE) != 0)
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
		  printf ("\nLA CANTIDAD DE EMPLEADOS LLEGO A SU LIMITE!\n");
		  printf ("\n*******************************************\n");
		}*/
	      break;
	    case 2:
	    	p_UpdateEmployee (employeeList, QTY_EMPLOYE);
/*	      if (flagLimite (employeeList, QTY_EMPLOYE) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n***************    MODIFICAR    *********************\n");
		  printf ("*****************************************************\n");
		  if (updateEmployee (employeeList, QTY_EMPLOYE) != 0)
		    {
		      printf ("\n******\n");
		      printf ("\nERROR!\n");
		      printf ("\n******\n");
		    }
		}
	      else
		{
		  printf ("\n*****************************************\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MODIFICAR!\n");
		  printf ("\n*****************************************\n");
		}*/
	      break;
	    case 3:
/*	      if (flagLimite (employeeList, QTY_EMPLOYE) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n******************      BAJA    *********************\n");
		  printf ("*****************************************************\n");*/
		  if (p_PrepareForDelete (employeeList, QTY_EMPLOYE) == -1)
		    {
		      printf ("\n******\n");
		      printf ("\nERROR!\n");
		      printf ("\n******\n");
		    }
/*		}
	      else
		{
		  printf ("\n****************************************\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA ELIMINAR!\n");
		  printf ("\n****************************************\n");
	}*/
	      break;
	    case 4:
	    	/*	      if (flagLimite (employeeList, QTY_EMPLOYE) != 0)
		{
		  printf ("\n*****************************************************");
		  printf ("\n*****************    INFORMAR    ********************\n");
		  printf ("*****************************************************\n");
		  if (sortEmployees (employeeList, QTY_EMPLOYE, 1) == -1)
		    {
		      printf ("\n******\n");
		      printf ("\nERROR!\n");
		      printf ("\n******\n");
		    }       */
		  headerEmployee ();
		  //printEmployees (employeeList, QTY_EMPLOYE);
		  p_PrintEmployees(employeeList,QTY_EMPLOYE);



/*		  printf ("\n*****************************************************\n");
		  printf ("TOTAL DE LOS SALARIOS: ");
		  printf ("%.2f", sumaTotal (employeeList, QTY_EMPLOYE));
		  printf ("\nPROMEDIO DE LOS SALARIOS: ");
		  printf ("%.2f", promedio (employeeList, QTY_EMPLOYE));
		  printf ("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO: ");
		  printf ("%d",cantidadSuperiorAlPromedio (employeeList, QTY_EMPLOYE));
		  printf ("\n*****************************************************\n");
		}
	      else
		{
		  printf ("\n***************************************\n");
		  printf ("\nNO HAY EMPLEADOS CARGADOS PARA MOSTRAR!\n");
		  printf ("\n***************************************\n");
		}          */
	      break;
			case 5:
				printf ("\n*****************************************************");
			    printf ("\n*****************    GRABAR EN ARCHIVO    ********************\n");
				printf ("*****************************************************\n");

				p_EscribeArchivoTexto(employeeList,QTY_EMPLOYE);



				break;
			case 6:
				printf ("\n*****************************************************");
				printf ("\n*****************    LEER DE ARCHIVO    ********************\n");
				printf ("*****************************************************\n");
				p_LeerArchivoTexto_Parser(employeeList,QTY_EMPLOYE);




				break;
			case 7:
				printf("\nEL RPOGRAMA SE CERRO CON EXITO!\n");
				system("pause");
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
	}
    }
  while (opcion != 7);

	return EXIT_SUCCESS;
}