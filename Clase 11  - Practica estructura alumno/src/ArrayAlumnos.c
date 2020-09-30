/*
 * ArrayAlumnos.c
 *
 *  Created on: 25 sep. 2020
 *      Author: nico
 */
#include "ArrayAlumnos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn_input.h"


int initAlumno(Alumno list[], int len)
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




int printAlumnos(Alumno* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
	    headerAlumno();
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


void headerAlumno(void)
{
    printf("%*s%*s%*s%*s%*s",
	   -7, " LEGAJO",
	   -13," NOMBRE"
	   "\n----------------\n");
}



int utn_searchFree (Alumno *list, int len)
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


int isEmpty(Alumno* list, int limit, int index)
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


int addAlumno(Alumno* list, int len, int id, char* name)
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


int idIncremental(void)
{
    static int id = 0;
    id++;
    return id;
}





int chargeAlumno (Alumno *list, int len)
{
  Alumno auxAlumno;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre del alumno: ",  "\nError al ingresar.\n", &auxAlumno.name, LONG_NAME_ALUMNO, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNumero ("Ingrese el legajo: ", "\nError al ingresar. Por favor ", &auxAlumno.id, 0, 100, 5)!= 0)
	{
	  return -1;
	}

      switch (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n'))
	{
	case -1:
	  return -1;
	  break;

	case 1:
	  auxAlumno.id = idIncremental ();
	  addAlumno (list, len, auxAlumno.id, auxAlumno.name);
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




int findAlumnoById (Alumno *list, int len, int id)
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

int printForId  (Alumno *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    headerAlumno();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].id != FALSE )
  			{
  				printf("%-6d %-6d %-12s \n"
  				    ,list[i].isEmpty
  				    ,list[i].id
  				    ,list[i].name);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}




int arrayToBuffer(Alumno *list,Alumno *listBuffer, int len, int id)
{
 // Alumno buffer;
  int retorno = -1;
    int i;
    	if(list != NULL && len > 0)
    	{
    	      for( i=0;i<len;i++)
    		{
    			//if(list[i].id == id && list[i].isEmpty == FALSE && list[i].sector != FALSE)
    			if(list[i].id == id)
    			{
    			*listBuffer=list[i];

    			}
    		}
    		retorno = 0;
    	}
return retorno;
}


int bufferToArray(Alumno *list, Alumno *listBuffer, int len, int id)
{
  int i;
  int retorno = -1;
  if (list != NULL && listBuffer != NULL && len > 0)
    {

	for (i = 0; i < len; i++)
	  {
	    if (list[i].id == id)
	      {
		list[i] = *listBuffer;
		retorno = 0;
	      }
	  }
    }
  return retorno;
}




int updateAlumno (Alumno *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Alumno auxAlumno;


  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese el legajo del alumno: ", "\nError al ingresar. ", &bufferID, 1, QTY_ALUMNO, 5);
      printf ("\nEl el legajo seleccionado es: %d\n", bufferID);
      if (findAlumnoById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  arrayToBuffer(list, &auxAlumno,  len,  bufferID);
	  do
	     {
	      printForId  (&auxAlumno,len,  bufferID);
	      printf ("\n1-Nombre\n"
		       "2-Legajo\n"
	      	      "3-Aceptar Cambios\n"
	      	      "4-Salir\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\NOMBRE ALUMNO\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", &auxAlumno.name, LONG_NAME_ALUMNO, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;

	 	     case 2:
	 	      printf ("\Legajo\n**********\n");
	 	     if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxAlumno.id, 1, 100, 5)!= 0)
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
	 				 			 bufferToArray (list, &auxAlumno,  len, bufferID);

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
	}//FINAL DEL IF findAlumnoById
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }//FINAL DEL IF VALIDACION DE NULL PRINCIPAL
  return retorno;
}


int removeAlumno(Alumno* list, int len, int id)
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


int prepareForDelete (Alumno *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese legajo del Alumno: ", "\nError al ingresar. ", &bufferID, 1, QTY_ALUMNO, 5);
      if (findAlumnoById (list, len, bufferID) != -1)
	{
	  printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar empleado? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      removeAlumno (list, len, bufferID);
	      retorno = 1;
	    }
	}
    }
  return retorno;
}



int sortAlumnos(Alumno* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Alumno buffer;
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













