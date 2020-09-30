/*
 * nacionalidad.c
 *
 *  Created on: 29 sep. 2020
 *      Author: nico
 */


/*
 * ArrayNacionalidad.c
 *
 *  Created on: 25 sep. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "ArrayAlumnos.h"
#include "nacionalidad.h"
#include "utn_input.h"


int initNacionalidad(Nacionalidad list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].id = 0;
		    strcpy(list[i].name, "");
		}
		retorno = 0;
	}
	return retorno;
}




int printNacionalidad(Nacionalidad* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
	    headerNacionalidad();
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("%-6d %-6d %-12s\n"
				    ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].name);
			}
		}
		retorno = 0;
	}
	return retorno;
}


void headerNacionalidad(void)
{
    printf("%*s%*s%*s%*s%*s",
	   -7, " LEGAJO",
	   -13," NOMBRE"
	   "\n----------------\n");
}


/*
int utn_searchFree (Nacionalidad *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (isEmpty (list, len, i) == 1)
	    {
	      retorno = TRUE;
	      break;
	    }
	}
    }
  return retorno;
}
*/
/*
int isEmpty(Nacionalidad* list, int limit, int index)
{
  int retorno = FALSE;
  if (list != NULL && list > 0 && index < list)
    {
      if (list[index].isEmpty == TRUE)
	{
	  retorno = TRUE;
	}
    }
  return retorno;
}
*/

int addNacionalidad(Nacionalidad* list, int len, int id, char* name)
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (isEmpty (list, len, i) == 1)
	    {
	      list[i].id = id;
	      strcpy (list[i].name, name);
	      list[i].isEmpty = FALSE;
	      return 0;
	    }
	}
    }
  return -1;
}





int chargeNacionalidad (Nacionalidad *list, int len)
{
  Nacionalidad auxNacionalidad;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre del Nacionalidad: ",  "\nError al ingresar.\n", &auxNacionalidad.name, LONG_NAME_NACIONALIDAD, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNumero ("Ingrese el legajo: ", "\nError al ingresar. Por favor ", &auxNacionalidad.id, 0, 100, 5)!= 0)
	{
	  return -1;
	}

      switch (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	{
	case -1:
	  return -1;
	  break;

	case 1:
	  auxNacionalidad.id = idIncremental ();
	  addNacionalidad (list, len, auxNacionalidad.id, auxNacionalidad.name);
	  return 0;
	  break;

	case 0:
	  return 0;
	  break;

	default:
	  break;
	}
    }

  return -1;
}




int findNacionalidadById (Nacionalidad *list, int len, int id)
{
  int i;
  int retorno = -1;

  if (list != NULL && len > 0 && id != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      retorno = id;
	      break;
	    }
	}

    }
return retorno;
}



int updateNacionalidad (Nacionalidad *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Nacionalidad auxNacionalidad;


  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese el id de la Nacionalidad: ", "\nError al ingresar. ", &bufferID, 1, QTY_NACIONALIDAD, 5);
      printf ("\nEl el legajo seleccionado es: %d\n", bufferID);
      if (findNacionalidadById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  arrayToBuffer(list, &auxNacionalidad,  len,  bufferID);
	  do
	     {
	      printForId  (&auxNacionalidad,len,  bufferID);
	      printf ("\n1-Nombre\n"
		       "2-Id Pais\n"
	      	      "3-Aceptar Cambios\n"
	      	      "4-Salir\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\NOMBRE Nacionalidad\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre Pais: ",  "\nError al ingresar.\n", &auxNacionalidad.name, LONG_NAME_NACIONALIDAD, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;

	 	     case 2:
	 	      printf ("\Legajo\n**********\n");
	 	     if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxNacionalidad.id, 1, 100, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 3:
	 		  printf ("\Grabar cambios\n**********\n");
	 		 switch (utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	 			{
	 			case -1:
	 			  return -1;
	 			  break;

	 			case 1:
	 				 			 bufferToArray (list, &auxNacionalidad,  len, bufferID);

	 			  return 0;
	 			  break;

	 			case 0:
	 			  return 0;
	 			  break;

	 			default:
	 			  break;
	 			}
	 	      break;
	 	    case 6:
	 	      printf ("\nSALIR\n**********\n");
	 	      break;
	 	    default:
	 	      break;
	 	    }
	 	}
	       else
	 	{
	 	  printf ("\nSE TERMINARON LOS REINTENTOS\n");
	 	  system ("pause");
	 	  return EXIT_SUCCESS;
	 	}
	     }
	   while (opcion != 6);

	  if(opcion == 6)
	    {
	      return EXIT_SUCCESS;
	    }
	}//FINAL DEL IF findNacionalidadById
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }//FINAL DEL IF VALIDACION DE NULL PRINCIPAL
  return retorno;
}


int removeNacionalidad(Nacionalidad* list, int len, int id)
{
  int i;
  int retorno;

  if (list != NULL && len > 0 && id > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == id)
	    {
	      list[i].isEmpty = TRUE;
	      retorno = 0;
	    }
	}
    }
 return retorno;
}




int sortNacionalidad(Nacionalidad* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Nacionalidad buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;
	  for (i = 0; i < nuevoLimite; i++)//for(i=0; i<tam-1; i++)
	    {
			  contador++;
			//  if (miArray[i] < miArray[i + 1])
			 if(strcmp(list[i].name,list[i+1].name)>order)
			{
			  flagSwap = 1;
			  buffer = list[i];
			  list[i] = list[i + 1];
			  list[i + 1] = buffer;
			}
			else
			{
				 if(strcmp(list[i].name,list[i+1].name)==0)
				 {
					 if(list[i].id>list[i+1].id)
			{
			  flagSwap = 1;
			  buffer = list[i];
			  list[i] = list[i + 1];
			  list[i + 1] = buffer;
			}

				 }
			}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}













