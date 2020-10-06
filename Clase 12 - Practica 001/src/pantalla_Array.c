/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================


Parametrizables:






 */
#include "pantalla_Array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn_input.h"




/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int pantalla_initArray(Pantalla list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].idPantalla = 0;
		    strcpy(list[i].namePantalla, "");
		    strcpy(list[i].direccion,"");
		    list[i].precioPublicidad = 0.00;
		    list[i].tipoPantalla = 0;
		}
		retorno = 0;
	}
	return retorno;
}



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int pantalla_addArray(Pantalla* list, int len, int idPantalla, char* nombrePantalla,char* direccion,float precioPublicidad,int tipoPantalla)
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (pantalla_isEmpty (list, len, i) == 1)
	    {
	      list[i].isEmpty = FALSE;
	      list[i].idPantalla =idPantalla;
	      strcpy(list[i].namePantalla,nombrePantalla );
	      strcpy(list[i].direccion,direccion );
	      list[i].precioPublicidad = precioPublicidad;
	      list[i].tipoPantalla =tipoPantalla  ;
	      return 0;
	    }
	}
    }
  return -1;
}


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int pantalla_findArrayById (Pantalla *list, int len, int id)
{
  int i;
  int retorno = -1;

  if (list != NULL && len > 0 && id != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].idPantalla == id)
	    {
	      retorno = id;
	      break;
	    }
	}
    }
return retorno;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int pantalla_removeArray(Pantalla* list, int len, int id)
{
  int i;
  int retorno;

  if (list != NULL && len > 0 && id > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].idPantalla == id)
	    {
	      list[i].isEmpty = TRUE;
	      retorno = 0;
	    }
	}
    }
 return retorno;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int pantalla_sortArray(Pantalla* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Pantalla buffer;
  int nuevoLimite;

  if (list != NULL && len >= 0)
    {
      nuevoLimite = len - 1;
      do
	{
	  flagSwap = 0;

	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
	      if ((order == 0 && strcmp (list[i].tipoPantalla, list[i + 1].tipoPantalla) < 0)||
		  (order == 1 && strcmp (list[i].tipoPantalla, list[i + 1].tipoPantalla) > 0))
		  //*******************En caso de ordenamiento por 2 condiciones, descomentar lo de abajo
		/*  ||(0==strcmp (list[i].lastName, list[i + 1].lastName) &&
		      (((list[i].sector > list[i + 1].sector)&&(order == 1))
			  ||((list[i].sector < list[i + 1].sector) &&(order == 0)))))*/
		{
		  flagSwap = 1;
		  buffer = list[i];
		  list[i] = list[i + 1];
		  list[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}



/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int pantalla_printArray(Pantalla* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf(" %-6d %-12s %-13d %-12.2f %s \n"
				 //   ,list[i].isEmpty
				    ,list[i].idPantalla
				    ,list[i].namePantalla
				    ,list[i].tipoPantalla
				    ,list[i].precioPublicidad
				    ,list[i].direccion);
			}
		}
		retorno = 0;
	}
	return retorno;
}



/** \brief Buscar espacio libre en el array
 *
 * \param list Employee*
 * \param length int
 * Usa la funcion isEmpty para obtener
 * lugar vacio mediante un for que recorre el array
 * \return 1 si esta ok - 0 si no
 *
 */
int pantalla_searchFree (Pantalla *list, int len)
{
  int i;
  int retorno = FALSE;

  if (list != NULL && list > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (pantalla_isEmpty (list, len, i) == 1)
	    {
	      retorno = TRUE;
	      break;
	    }
	}
    }
  return retorno;
}





/** \brief Buscar espacio bacio en el array
 *
 * \param list Employee*
 * \param length int
 * \return 1 si esta ok - 0 si no
 *
 */
int pantalla_isEmpty(Pantalla* list, int limit, int index)
{
  int retorno = FALSE;
//  if (list != NULL && list > 0 && index < list)
    if (list != NULL && list > 0)
    {
      if (list[index].isEmpty == TRUE)
	{
	  retorno = TRUE;
	}
    }
  return retorno;
}



/** \brief conjunto  de funcione de entrada de datos por consola
 *
 * \param list Employee*
 * \param length int
 * usa la funcion utn_getNombre para obtener nombre o apelleido
 * usa la funcion utn_getNumeroFloat para obtener numero flotante
 * usa la funcion utn_getNumero para obtener numero entero
 * usa la funcion idIncremental para obtener id incremental
 * usa la funcion addEmployee para impactar los datos ingresados al array
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_chargeArray (Pantalla *list, int len)
{
  Pantalla auxPantalla;
  int retorno = -1;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre de la pantalla: ",  "\nError al ingresar.\n", auxPantalla.namePantalla, LONG_NAME_PANTALLA, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNombre ("Ingrese direccion: ",  "\nError al ingresar.\n", auxPantalla.direccion, LONG_NAME_PANTALLA, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNumeroFloat (&auxPantalla.precioPublicidad, "Ingrese precio publicidad: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	{
	  return -1;
	}
      if (utn_getNumero ("Ingrese tipo de pantalla: ", "\nError al ingresar. Por favor ", &auxPantalla.tipoPantalla, 0, 2, 5)!= 0)
	{
	  return -1;
	}
      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
	  auxPantalla.idPantalla = utn_idIncremental ();
	  if(pantalla_addArray (list, len, auxPantalla.idPantalla, auxPantalla.namePantalla, auxPantalla.tipoPantalla, auxPantalla.precioPublicidad, auxPantalla.direccion)==0)
	  {
	      retorno = 0;
	  }
	  printf ("\n*****************************************************");
          printf ("\n                    ALTA EXITOSA!                  \n");
	  printf ("*****************************************************\n\n");
	}
      else
	{
	  retorno = 0;
	}
    }
  return retorno;
}



/** \brief imprime el array a partir del id
 *
 * \param list Employee*
 * \param length int
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_printForId  (Pantalla *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    utn_headerArray();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].idPantalla == id && list[i].isEmpty == FALSE && list[i].direccion != FALSE )
  			{
  				printf(" %-6d %-12s %-13d %-12.2f %s \n"
  				 //   ,list[i].isEmpty
  				    ,list[i].idPantalla
  				    ,list[i].namePantalla
  				    ,list[i].tipoPantalla
  				    ,list[i].precioPublicidad
  				    ,list[i].direccion);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}



/** \brief vuelca datos del array a un array auxiliar partiendo del id
 *
 * \param list Employee*
 * \param list Employee* --> array auxiliar
 * \param length int
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_arrayToBuffer(Pantalla *list,Pantalla *listBuffer, int len, int id)
{
  int retorno = -1;
    int i;
    	if(list != NULL && len > 0)
    	{
    	      for( i=0;i<len;i++)
    		{
    			if(list[i].idPantalla == id)
    			{
    			*listBuffer=list[i];
    			}
    		}
    		retorno = 0;
    	}
return retorno;
}




/** \brief vuelca datos del array auxiliar a un array  partiendo del id
 *
 * \param list Employee*
 * \param list Employee* --> array auxiliar
 * \param length int
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_bufferToArray(Pantalla *list, Pantalla *listBuffer, int len, int id)
{
  int i;
  int retorno = -1;
  if (list != NULL && listBuffer != NULL && len > 0)
    {

	for (i = 0; i < len; i++)
	  {
	    if (list[i].idPantalla == id)
	      {
		list[i] = *listBuffer;
		retorno = 0;
	      }
	  }
    }
  return retorno;
}




/** \brief conjunto  de funcione de entrada de datos por consola
 *
 * \param list Employee*
 * \param length int
 * usa la funcion utn_getNumero para ingresar id
 * usa la funcion findEmployeeById para buscar id
 * usa la funcion arrayToBuffer para volcar datos de un array a un array auxiliar por medio del id
 * usa la funcion printForId para imprimir el array  por medio del id
 *  usa la funcion utn_getNumero para obtener opcion
 * usa la funcion utn_getNombre para obtener nombre o apelleido
 * usa la funcion utn_getNumeroFloat para obtener numero flotante
 * usa la funcion utn_getNumero para obtener numero entero
 * usa la funcion utn_getAceptaRechaza para aceptar o rechazar ingreso de datos
 * usa la funcion idIncremental para obtener id incremental
 * usa la funcion bufferToArray para volcar datos de un array auxiliar a un array  por medio del id
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_updateArray (Pantalla *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Pantalla auxPantalla;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID de la pantalla: ", "\nError al ingresar. ", &bufferID, 1, QTY_PANTALLA, 5);
      if (pantalla_findArrayById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  pantalla_arrayToBuffer(list, &auxPantalla,  len,  bufferID);
	  do
	     {
	      pantalla_printForId  (&auxPantalla,len,  bufferID);
	      printf ("\n1-Nombre pantalla\n"
		      "2-Tipo de pantalla\n"
	      	      "3-Precio por dia\n"
	      	      "4-Direccion\n"
	      	      "5-Aceptar Cambios\n"
	      	      "6-Salir\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\nNOMBRE PANTALLA\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre de la pantalla: ",  "\nError al ingresar.\n", auxPantalla.namePantalla, LONG_NAME_PANTALLA, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\nTIPO PANTALLA\n********\n");
	 	     if (utn_getNumero ("Ingrese el tipo: ", "\nError al ingresar. Por favor ", &auxPantalla.tipoPantalla, 0, 2, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	    case 3:
	 	      printf ("\nPRECIO X DIA\n**********\n");
	 	     if (utn_getNumeroFloat (&auxPantalla.precioPublicidad, "Ingrese precio por dia: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	      break;
	 	    case 4:
	 	      printf ("\nDIRECCION\n**********\n");
	 	     if (utn_getNombre ("Ingrese direccion: ",  "\nError al ingresar.\n", auxPantalla.direccion, LONG_NAME_PANTALLA, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 5:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 		    pantalla_bufferToArray (list, &auxPantalla,  len, bufferID);
	 		    printf ("\n*************************************\n");
	 		    printf ("\nLOS CAMBIOS SE GRABARON EXITOSAMENTE!\n");
	 		    printf ("\n*************************************\n\n");
	 		   }
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
	}
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }
  return retorno;
}




/** \brief obtiene array por medio del id y luedo realiza baja logica del mismo
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion utn_getNumero para obtener numero entero
 * \usa la funcion findEmployeeById para obtener array partiendo del id
 * \usa la funcion printForId imprime array partiendo del id
 * \usa la funcion utn_getAceptaRechaza para aceptar o rechazar ingreso de datos
 * \usa la funcion removeEmployee para realizar la baja logica
 * \param id int
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_prepareForDelete (Pantalla *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID de la pantalla: ", "\nError al ingresar. ", &bufferID, 1, QTY_PANTALLA, 5);
      if (pantalla_findArrayById (list, len, bufferID) != -1)
	{
	  pantalla_printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar pantalla? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      pantalla_removeArray (list, len, bufferID);
	      retorno = 1;
	      printf ("\n*****************************************************");
	      printf ("\n             ELIMINACION EXITOSA!\n");
	      printf ("*****************************************************\n\n");
	    }
	}
      else
  	{
  	  printf ("\nEl ID NO existe\n");
  	}
    }
  return retorno;
}



/** \brief obtiene la suma de los valores del array
 *
 * \param list Employee*
 * \param length int
 * \return 0 si esta ok - -1 si no
 *
 */
float pantalla_sumaTotal (Pantalla *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].precioPublicidad != FALSE)
	    {
	      aux = aux + list[i].precioPublicidad;
	    }
	}
      retorno = aux;
    }
  return retorno;
}


/** \brief obtiene el promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion sumaTotal para sumar
 * \return 0 si esta ok - -1 si no
 *
 */
float pantalla_promedio(Pantalla* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].precioPublicidad != FALSE)
	    {
	      contador++;
	    }
	}
      retorno = pantalla_sumaTotal (list, len) / contador;
    }
  return retorno;
}



/** \brief obtiene la cantidad superior al promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta ok - -1 si no
 *
 */
int pantalla_cantidadSuperiorAlPromedio(Pantalla* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = pantalla_promedio (list, len);
  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].precioPublicidad > aux)
	    {
	      contador++;
	    }
	}
      retorno = contador;
    }
  return retorno;
}



/** \brief recorre el array y devuelve si esta full o si esta vacio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta vacio - > 0 si contiene datos- -1 si no
 *
 */
int pantalla_flagLimite(Pantalla* list, int len)
{
  int retorno = -1;
  int i;
  int contador = 0;

  for (i = 0; i < len; i++)
    {
      if (i <= len && list[i].isEmpty == FALSE)
	{
	  contador++;
	}
    }
  if (contador == 0)
    {
      retorno = 0;
    }
  else if (contador > 0 && contador != len)
    {
      retorno = contador;
    }
  return retorno;
}






int pantalla_buscarIndiecePorId (Pantalla *list, int len, int idBuscar, int *pIndice)
{
  int retorno = -1;
  int i;

  if (list != NULL && len > 0 && pIndice != NULL)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].idPantalla == idBuscar)
	    {
		*pIndice = i;
		retorno = 0;
		break;
	    }
	}
    }
  return retorno;
}




