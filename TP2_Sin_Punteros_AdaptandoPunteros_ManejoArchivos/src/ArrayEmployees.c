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
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn_input.h"




/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		    list[i].isEmpty = TRUE;
		    list[i].id = 0;
		    strcpy(list[i].name, "");
		    strcpy(list[i].lastName,"");
		    list[i].salary = 0.00;
		    list[i].sector = 0;
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
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector)
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
	      strcpy (list[i].lastName, lastName);
	      list[i].salary = salary;
	      list[i].sector = sector;
	      list[i].isEmpty = FALSE;
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
int findEmployeeById (Employee *list, int len, int id)
{
	int i;
	int index = -1;
//  int retorno = -1;

	if (list != NULL && len > 0 && id != 0)
	{
		for (i = 0; i < len; i++)
		{

			if (list[i].id == id && list[i].isEmpty == FALSE)
			{
				index = i;
				break;
			}
		}
	}
	return index;
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
int removeEmployee(Employee* list, int len, int id)
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


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  Employee buffer;
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
	      if ((order == 0 && strcmp (list[i].lastName, list[i + 1].lastName) < 0)||
		  (order == 1 && strcmp (list[i].lastName, list[i + 1].lastName) > 0)||
		  (0==strcmp (list[i].lastName, list[i + 1].lastName) &&
		      (((list[i].sector > list[i + 1].sector)&&(order == 1))
			  ||((list[i].sector < list[i + 1].sector) &&(order == 0)))))
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
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	if(list != NULL && length > 0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id != FALSE  &&  list[i].sector != FALSE && list[i].salary > 1)
			{
				printf("%-6d %-12s %-13s %-12.2f %d \n"
				  //  ,list[i].isEmpty
				    ,list[i].id
				    ,list[i].name
				    ,list[i].lastName
				    ,list[i].salary
				    ,list[i].sector);
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
int utn_searchFree (Employee *list, int len)
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





/** \brief Buscar espacio bacio en el array
 *
 * \param list Employee*
 * \param length int
 * \return 1 si esta ok - 0 si no
 *
 */
int isEmpty(Employee* list, int limit, int index)
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
int chargeEmployee (Employee *list, int len)
{
  Employee auxEmployee;
  int retorno = -1;

  if (list != NULL && len > 0)
    {
      if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", auxEmployee.name, LONG_NAME_EMPLOYE, 5) != 0)
	{
	  return -1;
	}
     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", auxEmployee.lastName, LONG_NAME_EMPLOYE, 5) != 0)
	{
	  return -1;
	}
      if (utn_getNumeroFloat (&auxEmployee.salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	{
	  return -1;
	}
      if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxEmployee.sector, 0, 100, 5)!= 0)
	{
	  return -1;
	}
      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
	  auxEmployee.id = idIncremental ();
	  if(addEmployee (list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector)==0)
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
int printForId  (Employee *list, int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    headerEmployee();
  		for( i=0;i<len;i++)
  		{
  			if(list[i].id == id && list[i].isEmpty == FALSE && list[i].sector != FALSE )
  			{
  				printf(" %-6d %-12s %-13s %-12.2f %d \n"
  				  //  ,list[i].isEmpty
  				    ,list[i].id
  				    ,list[i].name
  				    ,list[i].lastName
  				    ,list[i].salary
  				    ,list[i].sector);
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
int arrayToBuffer(Employee *list,Employee *listBuffer, int len, int id)
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
int bufferToArray(Employee *list, Employee *listBuffer, int len, int id)
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
int updateEmployee (Employee *list, int len)
{
  int bufferID;
  int retorno = -1;
  int opcion;
  Employee auxEmployee;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_EMPLOYE, 5);
      if (findEmployeeById (list, len, bufferID) != -1)
	{
	  retorno = 0;
	  arrayToBuffer(list, &auxEmployee,  len,  bufferID);
	  do
	     {
	      printForId  (&auxEmployee,len,  bufferID);
	      printf ("\n1-Nombre\n"
		      "2-Apellido\n"
	      	      "3-Salario\n"
	      	      "4-Sector\n"
	      	      "5-Aceptar Cambios\n"
	      	      "6-Salir\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\nNOMBRE\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", auxEmployee.name, LONG_NAME_EMPLOYE, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\nAPELLIDO\n********\n");
	 	     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", auxEmployee.lastName, LONG_NAME_EMPLOYE, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	    case 3:
	 	      printf ("\nSALARIO\n**********\n");
	 	     if (utn_getNumeroFloat (&auxEmployee.salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	      break;
	 	    case 4:
	 	      printf ("\nSECTOR\n**********\n");
	 	     if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxEmployee.sector, 1, 100, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 5:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 		    bufferToArray (list, &auxEmployee,  len, bufferID);
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
int prepareForDelete (Employee *list, int len)
{
  int retorno = -1;
  int bufferID;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_EMPLOYE, 5);
      if (findEmployeeById (list, len, bufferID) != -1)
	{
	  printForId (list, len, bufferID);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar empleado? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
	      removeEmployee (list, len, bufferID);
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
float sumaTotal (Employee *list, int len)
{
  int i;
  float retorno = -1;
  float aux = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].id != FALSE  &&  list[i].sector != FALSE && list[i].salary > 1)
	    {
	      aux = aux + list[i].salary;
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
float promedio(Employee* list, int len)
{
  int i;
  float retorno = -1;
  int contador = 0;

  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].isEmpty == FALSE && list[i].id != FALSE  &&  list[i].sector != FALSE && list[i].salary > 1)
	    {
	      contador++;
	    }
	}
      retorno = sumaTotal (list, len) / contador;
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
int cantidadSuperiorAlPromedio(Employee* list, int len)
{

  int i;
  int retorno = -1;
  int contador = 0;
  float aux;

  aux = promedio (list, len);
  if (list != NULL && len > 0)
    {
      for (i = 0; i < len; i++)
	{

	  if (list[i].isEmpty == FALSE &&  list[i].id != FALSE  &&  list[i].sector != FALSE &&list[i].salary > aux)
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
int flagLimite(Employee* list, int len)
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



////******************************TRABAJO CON PUNTEROS***************************

int p_InitEmployees(Employee* list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
		   list[i]=NULL;
		  // *(list+i)=NULL;
		}
		retorno = 0;
	}
	return retorno;
}







int printEmploye(Employee* aux)
{
    int output = -1;
    if(aux!=NULL)
    {
        printf("%-6d %-12s %-13s %-12.2f %d \n"
        		,aux->id
				,aux->name
				,aux->lastName
				,aux->salary
				,aux->sector);
        output = 0;
    }
    return output;
}



int p_PrintEmployees(Employee* list[], int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for( i=0;i<len;i++)
		{
				printEmploye(list[i]);
		}
		retorno = 0;
	}
	return retorno;
}


int p_FindEmployeeById (Employee *list[], int len, int id)
{
	int i;
	int index = -1;

	if (list != NULL && len > 0 && id != 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i] != NULL && list[i]->id == id)
			{
					index = i;
					break;
			}
		}
	}
	return index;
}


void cliente_delete(Employee* aux)
{
	if(aux!=NULL)
	{
		free(aux);
	}
}


int p_RemoveEmployee(Employee* list[], int len, int id)
{
	int retorno;
	int index;

	if (list != NULL && len > 0 && id > 0)
	{
		index = p_FindEmployeeById (list, len, id);
		if (index!=-1)
		{
			cliente_delete(list[index]);
			list[index]=NULL;
		}
	}
	return retorno;
}


int p_PrintForId  (Employee *list[], int len, int id)
{
  int retorno = -1;
  int i;
  	if(list != NULL && len > 0)
  	{
  	    headerEmployee();
  		for( i=0;i<len;i++)
  		{
  			if(list[i]->id == id)
  			{
  				printf(" %-6d %-12s %-13s %-12.2f %d \n"
  				    ,list[i]->id
  				    ,list[i]->name
  				    ,list[i]->lastName
  				    ,list[i]->salary
  				    ,list[i]->sector);
  			}
  		}
  		retorno = 0;
  	}
 return retorno;
}



int p_PrepareForDelete (Employee *list[], int len)
{
  int retorno = -1;
  int bufferID;
  int index;

  if (list != NULL && len > 0)
    {
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_EMPLOYE, 5);
      index= p_FindEmployeeById (list, len, bufferID);

      if (index != -1)
	{
    	  headerEmployee ();
    	  printEmploye(list[index]);
	  retorno = utn_getAceptaRechaza ("\nAcepta eliminar empleado? s/n: ", "ERROR al ingresar opcion. \n", 's','n');
	  if (retorno == 1)
	    {
		  p_RemoveEmployee (list, len, bufferID);
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



//********Getter and Setter******///////////////////////////////////////////////////////
int employee_setName(Employee* this,char* name)
{
	int retorno = -1;
	if(this != NULL && name != NULL)
	{
			retorno = 0;
			strncpy(this->name,name,LONG_NAME_EMPLOYE);
	}
	return retorno;
}


int employee_getName(Employee* this,char* name)
{
	int retorno = -1;
	if(this != NULL && name != NULL)
	{
		retorno = 0;
		strncpy(name,this->name,LONG_NAME_EMPLOYE);
	}
	return retorno;
}




int employee_setLastName(Employee* this,char* lastName)
{
	int retorno = -1;
	if(this != NULL && lastName != NULL)
	{
			retorno = 0;
			strncpy(this->lastName,lastName,LONG_NAME_EMPLOYE);
	}
	return retorno;
}


int employee_getLastName(Employee* this,char* lastName)
{
	int retorno = -1;
	if(this != NULL && lastName != NULL)
	{
		retorno = 0;
		strncpy(lastName,this->lastName,LONG_NAME_EMPLOYE);
	}
	return retorno;
}



int employee_setSalary(Employee* this, float salary)
{
	int retorno = -1;
	if(this != NULL && salary > 0)
	{
			retorno = 0;
			this->salary = salary;
	}
	return retorno;
}


int employee_getSalary(Employee* this,float salary)
{
	int retorno = -1;
	if(this != NULL && salary > 0)
	{
		retorno = 0;
		salary = this->salary;
	}
	return retorno;
}


int employee_getSalarioTxt(Employee* this,char* salario)
{
	int retorno = -1;
	if(this != NULL && salario != NULL)
	{
		retorno = 0;
		sprintf(salario,"%.2f",this->salary);
	}
	return retorno;
}


int employee_setSalarioTxt(Employee* this,char* salario)
{
	int retorno = -1;
	if(this != NULL && salario >= 0)
	{
		retorno = 0;
		this->salary = atof(salario);
	}
	return retorno;
}



int employee_setSector(Employee* this,int sector)
{
	int retorno = -1;
	if(this != NULL && sector > 0)
	{
			retorno = 0;
			this->sector = sector;
	}
	return retorno;
}


int employee_getSector(Employee* this,int sector)
{
	int retorno = -1;
	if(this != NULL && sector > 0)
	{
		retorno = 0;
		sector = this->sector;
	}
	return retorno;
}

int employee_getSectorTxt(Employee* this,char* sector)
{
	int retorno = -1;
	if(this != NULL && sector != NULL)
	{
		retorno = 0;
		sprintf(sector,"%d",this->sector);
	}
	return retorno;
}


int employee_setSectorTxt(Employee* this,char* sector)
{
	int retorno = -1;
	if(this != NULL && sector >= 0)
	{
		retorno = 0;
		this->sector = atoi(sector);
	}
	return retorno;
}





int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
			retorno = 0;
			this->id = id;
	}
	return retorno;
}


int employee_getId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		retorno = 0;
		id = this->id;
	}
	return retorno;
}


int employee_getIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}


int employee_setIdTxt(Employee* this,char * id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = atoi(id);
	}
	return retorno;
}




//********Getter and Setter******///////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

Employee* employee_new(void)
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}


Employee* p_Employee_newConParametros( int id, char* name,char* lastName,float salary,int sector)
{
	Employee* this = NULL;
	this = employee_new();

	if(this != NULL && name != NULL && lastName !=  NULL && salary > 0 && sector > 0)

	{
		if(
			employee_setId(this,id) == -1 ||
			employee_setName(this, name) == -1 ||
		    employee_setLastName(this, lastName) == -1 ||
			employee_setSalary(this, salary) == -1 ||
			employee_setSector(this, sector) == -1)
		{
			cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}




int pEmployee_buscarLibreArray(Employee *arrayPunteros[], int limite)
{
	int retorno = -1;
	int i;

	if(arrayPunteros != NULL && limite > 0)
	{
		retorno = -2;
		for(i=0; 0<limite; i++)
		{
			if(arrayPunteros[i]== NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}










int p_AddEmployee(Employee *arrayPunteros[],int limite, int idAux,char * auxName,char * auxLastname,float auxSalary,int auxSector)
{
  int retorno = -1;
  int indiceLibre = 0;

  if (arrayPunteros != NULL && limite > 0)
    {
	  printf("ALGO DEBE DEVOLVER: %d", indiceLibre);
	  indiceLibre =pEmployee_buscarLibreArray(arrayPunteros,limite);

	 if(indiceLibre >= 0)
	 {
		 arrayPunteros[indiceLibre] = p_Employee_newConParametros( idAux, auxName,auxLastname,auxSalary,auxSector);
		 retorno = indiceLibre;
	 }

    }
  return retorno;
}





int p_ChargeEmployee (Employee *list)
{
  int retorno = -1;
  char auxName[LONG_NAME_EMPLOYE];
  char auxLastname[LONG_NAME_EMPLOYE];
  float auxSalary;
  int auxSector;
  int idAux;

  if (list != NULL)
    {
	  if(utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", auxName, LONG_NAME_EMPLOYE, 5) == 0       		&&
		 utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", auxLastname, LONG_NAME_EMPLOYE, 5) == 0  		&&
		 utn_getNumeroFloat (&auxSalary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)== 0 	&&
		 utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", &auxSector, 0, 100, 5)== 0
	  	 )
	  {

		  if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
		  	{
			  idAux = idIncremental ();
			  p_AddEmployee(list, QTY_EMPLOYE, idAux, auxName, auxLastname, auxSalary, auxSector);
		  	  retorno = 0;
		  	  printf ("\n*****************************************************");
		      printf ("\n                    ALTA EXITOSA!                  \n");
		  	  printf ("*****************************************************\n\n");
		  	}
		        else
		  	{
		  	  retorno = -1;
		  	}
	  }
    }
  return retorno;
}




int p_ArrayToBufferByIndex(Employee *list[],Employee *listBuffer, int index)
{
  int retorno = -1;
    	if(list != NULL && index >= 0)
    	{
    			*listBuffer=*list[index];
    			 retorno = 0;
    	}
return retorno;
}




int p_BufferToArrayByIndex(Employee *list[], Employee *listBuffer,  int index)
{
  int retorno = -1;
    	if(list != NULL && index >= 0)
    	{
    		*list[index] = *listBuffer;
    			 retorno = 0;
    	}
return retorno;
}


int p_UpdateEmployee (Employee *list, int len)
{
	int bufferID;
	int retorno = -1;
	int opcion;
	int index;

	char auxName[LONG_NAME_EMPLOYE];
	char auxLastname[LONG_NAME_EMPLOYE];
	float auxSalary;
	int auxSector;


  Employee * auxEmployee = NULL;
  auxEmployee = (Employee*)malloc(sizeof(Employee));




  if (list != NULL && len > 0)
    {
	  headerEmployee ();
	  p_PrintEmployees(list, len);
      utn_getNumero ("\nIngrese ID del empleado: ", "\nError al ingresar. ", &bufferID, 1, QTY_EMPLOYE, 5);


      index= p_FindEmployeeById (list, len, bufferID);

printf("\nLO QUE DE VUELVE: %d\n",index);

      if ( index >= 0)
	{
	  retorno = 0;


	  p_ArrayToBufferByIndex(list,auxEmployee, index);


	  do
	     {
		  headerEmployee ();
		  printEmploye(auxEmployee);
	      printf ("\n1-Nombre\n"
		          "2-Apellido\n"
	      	      "3-Salario\n"
	      	      "4-Sector\n"
	      	      "5-Aceptar Cambios\n"
	      	      "6-Salir\n");

	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 6, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
	 	      printf ("\nNOMBRE\n******\n");

	 	     if (utn_getNombre ("Ingrese nombre del empleado: ",  "\nError al ingresar.\n", auxEmployee->lastName, LONG_NAME_EMPLOYE, 5) != 0)
	 	    	{
	 	    	  return -1;
	 	    	}
	 	      break;
	 	    case 2:
	 	      printf ("\nAPELLIDO\n********\n");
	 	     if (utn_getNombre ("Ingrese apellido del empleado: ", "\nError al ingresar.\n", auxEmployee->lastName, LONG_NAME_EMPLOYE, 5) != 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	    case 3:
	 	      printf ("\nSALARIO\n**********\n");
	 	     if (utn_getNumeroFloat (&auxEmployee->salary, "Ingrese salario del empleado: ", "\nError al ingresar. Por favor ", 1, 9999999, 5)!= 0)
	 	     	{
	 	     	  return -1;
	 	     	}
	 	      break;
	 	    case 4:
	 	      printf ("\nSECTOR\n**********\n");
	 	     if (utn_getNumero ("Ingrese el sector: ", "\nError al ingresar. Por favor ", auxEmployee->sector, 1, 100, 5)!= 0)
	 	   	{
	 	   	  return -1;
	 	   	}
	 	      break;
	 	   case 5:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
 			 p_BufferToArrayByIndex(list,auxEmployee, index);

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



///////MANEJO DE ARCHIVOS///////////////////////////////////////////////////////////////////

/*
p_LeeArchivoBinario(Employee * arrayEmpleados[])
{

Employee * auxEmployee = NULL;
int fin = 1;
int i = 0;
FILE * archivo;//Se genera un puntero a FILE
archivo = fopen("archivo.txt","wb");//Se genera archivo en modo escribir binario





do{

	fin= fread(&auxEmployee,sizeof(Employee),1,archivo);

	if(fin ==1 )
	{





		i++;
	}


}while(feof(archivo) == 0);


}


p_EscribeArchivoBinario(Employee * arrayEmpleados[], int len)
{

	FILE * archivo;//Se genera un puntero a FILE
int i;

	for(i=0; i < len ; i++)
	{
		fwrite(arrayEmpleados[i],sizeof(Employee), 1, archivo);
	}



}


*/
p_EscribeArchivoTexto(Employee * arrayEmpleados[], int len)
{
	FILE *archivo; //Se genera un puntero a FILE
	archivo = fopen("archivo.csv", "wb");
	int i;
	char idAux[32];
	char nombreAux[51];
	char apellidoAux[51];
	char salarioAux[32];
	char sectorAux[16];

	for (i = 0; i < len; i++)
	{
		if (arrayEmpleados[i] != NULL)
		{
			employee_getIdTxt(arrayEmpleados[i], idAux);
			employee_getName(arrayEmpleados[i], nombreAux);
			employee_getLastName(arrayEmpleados[i], apellidoAux);
			employee_getSalarioTxt(arrayEmpleados[i], &salarioAux);
			employee_getSectorTxt(arrayEmpleados[i], &sectorAux);

			printf("%s,%s,%s,%s,%s\n", idAux, nombreAux, apellidoAux,salarioAux, sectorAux);
			fprintf(archivo, "%s,%s,%s,%s,%s\n", idAux, nombreAux, apellidoAux,salarioAux, sectorAux);
		}
	}
	fclose(archivo);
}




p_LeerArchivoTexto_Parser(Employee *arrayEmpleados[], int len)
{

	FILE *archivo; //Se genera un puntero a FILE
	archivo = fopen("archivo.csv", "rb");
	Employee * employeeAux[100];
	Employee * aux;
	int index = 0;
	int i;
	char buffer [128];
	char idAux [128];
	char auxName[LONG_NAME_EMPLOYE];
	char auxLastname[LONG_NAME_EMPLOYE];
	char auxSalary[128];
	char auxSector[128];


	if(archivo!=NULL)
	{
		do
		{
			if(fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,auxName,auxLastname,auxSalary,auxSector)==5)
			{
				printf("%s - %s - %s - %s - %s\n",idAux,auxName,auxLastname,auxSalary,auxSector);
				aux=p_Employee_newConParametros(atoi(idAux), auxName,auxLastname,atof(auxSalary),atoi(auxSector));
				if(aux!=NULL)
				{
					arrayEmpleados[index] = aux;
					index++;
				}
			}
			else
			{
				break;
			}
		}while(feof(archivo)==0);

		for(i=0;i<index;i++)
		{
			printf("\nid: %d - nombre: %s - apellido: %s - Salario: %.2f - Sector: %d",
					arrayEmpleados[i]->id,
					arrayEmpleados[i]->name,
					arrayEmpleados[i]->lastName,
					arrayEmpleados[i]->salary,
					arrayEmpleados[i]->sector
					);
		}
	}
}













