/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================

 */
#include "arrayPantalla.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <conio.h>
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
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		    list[i].isEmpty = TRUE;/////////NO TOCAR////////
		    list[i].id = 0;/////////NO TOCAR////////
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//		    list[i].idAux = 0;/////////NO TOCAR////////
		    strcpy(list[i].nombrePantalla,"VACIO");
		    strcpy(list[i].direccion,"VACIO");
		    list[i].tipoPantalla = 0;
//		    list[i].NUMERO2 = 0;
		    list[i].precio = 0.00;
//		    list[i].FLOTANTE2 = 0.00;
//		    list[i].NUMERO_LARGO = 00000000000000;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
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
int pantalla_addArray(Pantalla* list, int len, int id,
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//		      int idAux,
      		      char* nombrePantalla,
     		      char* direccion,
      		      int tipoPantalla,
//      		      int NUMERO2,
      		      float precio
//      		      float FLOTANTE2,
//      		      long long int NUMERO_LARGO
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
		      )
{
  int i;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (pantalla_isEmpty (list, len, i) == 1)
	    {
	      list[i].id = id;
	      list[i].isEmpty = FALSE;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      //		    list[i].idAux = 0;/////////NO TOCAR////////
	      		    strcpy(list[i].nombrePantalla,nombrePantalla);
	      		    strcpy(list[i].direccion,direccion);
	      		    list[i].tipoPantalla = tipoPantalla;
	      //		    list[i].NUMERO2 = 0;
	      		    list[i].precio = precio;
	      //		    list[i].FLOTANTE2 = 0.00;
	      //		    list[i].NUMERO_LARGO = 00000000000000;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      return 0;
	    }
	}
    }
  return -1;
}




/*
 * headerEmployee : Imprimie en una linea
 * -
 *
 * Retorno: -
 *
 */
void pantalla_headerArray(void)

{
    printf("\n"
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	    "%*s"
//	    "%*s"
	    "%*s"
//	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s",
//	    "%*s"
//	    "%*s",
	   -7, " ID",
//	   -10, " ID AUX",
	   -11," TIPO",
//	   -14," NUMERO2",
	   -16," NOMBRE PANT.",
	   -12," DIRECCION",
	   -12," PRECIO"
//	   -12," FLOTANTE2",
//	     0," NUMERO_LARGO"
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	   "\n-----------------------------------------------------\n");
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
  	    pantalla_headerArray();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE &&
  			    ///Se agrega una condicion mas por si lo que trae es basura
  			    list[i].tipoPantalla > 0)
  			{
  				printf(
//  				       " %-6d "
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
  				       "%-12d " ///NO TOCAR///////
//  				       "%-12d "
  				       "%-10d "
//  					   "%-10d "
  				       "%-13s "
  				       "%-13s "
  				       "%-12.2f "
//  				    "%-12.2f "
//  				     "%lld"
  				       "\n"

  				 //   ,list[i].isEmpty
  				   ,list[i].id ///NO TOCAR///////
//				   ,list[i].idAux
				   ,list[i].tipoPantalla
//				   ,list[i].NUMERO1
				   ,list[i].nombrePantalla
				   ,list[i].direccion
				   ,list[i].precio
//				   ,list[i].FLOTANTE2
//				   ,list[i].NUMERO_LARGO
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				    );
  			}
  		}
  		retorno = 0;
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
	  if (list[i].id == id)
	    {
	      list[i].isEmpty = TRUE;
	      retorno = 0;
	    }
	}
    }
 return retorno;
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
	  if (list[i].id == id)
	    {
	      retorno = id;
	      break;
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
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      if ((order == 0 && strcmp (list[i].nombrePantalla, list[i + 1].nombrePantalla) < 0)||
		  (order == 1 && strcmp (list[i].nombrePantalla, list[i + 1].nombrePantalla) > 0))
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
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
				printf(
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				  //  " %-6d "
				    " %-6d "/////////NO TOCAR//////////////
//				    " %-10d "
				    "%-12d "
//				    "%-12d "
				    "%-13s "
				    "%-13s "
				    "%-12.2f "
//				    "%-12.2f "
//				    "%-30lld"
				    " \n"

				  //  ,list[i].isEmpty
				    ,list[i].id/////////NO TOCAR//////////////
//				    ,list[i].idAux
				    ,list[i].tipoPantalla
//				    ,list[i].NUMERO1
				    ,list[i].nombrePantalla
				    ,list[i].direccion
				    ,list[i].precio
//				    ,list[i].FLOTANTE2
//				    ,list[i].NUMERO_LARGO
				   );
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
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
////////////////////	////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
//      if (utn_getNumero ("Ingrese id Auxiliar: ", "\nError al ingresar. Por favor ", &auxPantalla.idAux, 0, 999, 5)!= 0)
//      		{
//      		  return -1;
//      		}
      if (utn_getNombre ("Ingrese nombre pantalla: ", "\nError al ingresar.\n", auxPantalla.nombrePantalla, LONG_NAME_PANTALLA, 5) != 0)
		{
		  return -1;
		}
      if (utn_getAlfanumerico ("Ingrese direccion: ", "\nError al ingresar.\n", auxPantalla.direccion, LONG_NAME_PANTALLA, 5) != 0)
		{
		  return -1;
		}
      if (utn_getNumero ("Ingrese tipo de pantalla: ", "\nError al ingresar. Por favor ", &auxPantalla.tipoPantalla, 0, 99999, 5)!= 0)
		{
		  return -1;
		}
//      if (utn_getNumero ("Ingrese NUMER2: ", "\nError al ingresar. Por favor ", &auxPantalla.NUMERO2, 0, 99999, 5)!= 0)
//		{
//		  return -1;
//		}
      if (utn_getNumeroFloat (&auxPantalla.precio, "Ingrese precio por dia: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
      		{
		  return -1;
      		}
//      if (utn_getNumeroFloat (&auxPantalla.FLOTANTE2, "Ingrese FLOTANTE2: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
//           	{
//           	  return -1;
//           	}
//      if (utn_getNumeroLong ("Ingrese NUMERO LARGO: ", "\nError al ingresar. Por favor ", &auxPantalla.NUMERO_LARGO, 20010000000, 20999999999, 5)!= 0)
//     		{
//     		  return -1;
//     		}
      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
	  auxPantalla.id = utn_idIncremental ();
	  if(pantalla_addArray (list, len,
				auxPantalla.id,///////NO TOCAR////////////////////////
//				auxPantalla.idAux,
				auxPantalla.nombrePantalla,
				auxPantalla.direccion,
				auxPantalla.tipoPantalla,
//				auxPantalla.NUMERO2,
				auxPantalla.precio
//				auxPantalla.FLOTANTE2,
//				auxPantalla.NUMERO_LARGO
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
				)==0)
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
    			if(list[i].id == id)
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
	    if (list[i].id == id)
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
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      printf ("\n"
		      "1-NOMBRE1\n"
		      "2-NOMBRE2\n"
		      "3-NUMERO1\n"
		      "4-FLOTANTE1\n"
      	      "5-Aceptar Cambios\n"//////NO TOCAR////////////////////////
	      	  "6-Salir\n"//////NO TOCAR////////////////////////
		  );

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\n"
	 		  "NOMBRE DE PANTALLA"
	 		  "\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre de la pantalla: ",  "\nError al ingresar.\n", auxPantalla.nombrePantalla, LONG_NAME_PANTALLA, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\n"
	 		  "DIRECCION"
	 		  "\n********\n");
	 	     if (utn_getAlfanumerico ("Ingrese direccion: ", "\nError al ingresar.\n", auxPantalla.direccion, LONG_NAME_PANTALLA, 5) != 0)
	 	     	 {
	 	     	   return -1;
	 	     	 }
	 	      break;
	 	    case 3:
			printf ("\n"
				"TIPO DE PANTALLA"
				"\n********\n");
			 if (utn_getNumero ("\nIngresar tipo de pantalla: ","\nOpcion Invalida. ", &auxPantalla.tipoPantalla, 1, 99999999, 3) != -1)
			  {
			    return -1;
			  }
			break;
	 	    case 4:
	 	      printf ("\n"
	 		  "PRECIO"
	 		  "\n**********\n");
	 	     if (utn_getNumeroFloat (&auxPantalla.precio, "Ingrese precio por dia: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	    break;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
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
      utn_getNumero ("\nIngrese ID de la ENTIDAD: ", "\nError al ingresar. ", &bufferID, 1, QTY_PANTALLA, 5);
      if (pantalla_findArrayById (list, len, bufferID) != -1)
	{
	  pantalla_printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar ENTIDAD? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
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
/*float pantalla_sumaTotal (Pantalla *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE &&
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].FLOTANTE1 != FALSE
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      )
	    {
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      aux = aux + list[i].FLOTANTE1;
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	    }
	}
      retorno = aux;
    }
  return retorno;
}*/


/** \brief obtiene el promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion sumaTotal para sumar
 * \return 0 si esta ok - -1 si no
 *
 */
/*float pantalla_promedio(Pantalla* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE &&
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].FLOTANTE1 != FALSE
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      )
	    {
	      contador++;
	    }
	}
      retorno = pantalla_sumaTotal (list, len) / contador;
    }
  return retorno;
}*/



/** \brief obtiene la cantidad superior al promedio
 *
 * \param list Employee*
 * \param length int
 * \usa la funcion promedio para obtener el promedio
 * \return 0 si esta ok - -1 si no
 *
 */
/*int pantalla_cantidadSuperiorAlPromedio(Pantalla* list, int len)
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
	  if (list[i].isEmpty == FALSE &&
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      list[i].FLOTANTE1 > aux
///////////////////////////////////////////////////////MODIFICABLE//////////////////////////////////////////////////////////////////////
	      )
	    {
	      contador++;
	    }
	}
      retorno = contador;
    }
  return retorno;
}*/



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






int pantalla_buscarIndiecePorId (Pantalla* list, int len, int idBuscar, int* pIndice)
{
  int retorno = -1;
  int i;

  if (list != NULL && len > 0 && pIndice != NULL)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].id == idBuscar)
	    {
		*pIndice = i;
		retorno = 0;
		break;
	    }
	}
    }
  return retorno;
}




