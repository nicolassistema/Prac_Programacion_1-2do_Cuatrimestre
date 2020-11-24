/*
 * afiches.c
 *
 *  Created on: 24 nov. 2020
 *      Author: nico
 */

#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>









Cliente* cliente_newParametrosTxt(char* idStr,char* nombreStr,char* apellidoStr)
{
	Cliente* this = NULL;
	this = envio_new();
	if(this != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL)
	{
		if(	cliente_setNombre(this,nombreStr) == -1 ||
			cliente_setApellido(this,apellidoStr) == -1 ||
			cliente_setIdTxt(this,idStr) == -1)
		{
		    cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}

/**
 * \brief Crea un empleado conociendo sus parámetros reales
 * \param id int Id con el que se cargará el empleado
 * \param nombre char* Puntero al nombre
 * \param horasTrabajadasStr int  HorasTrabajadas con las que se cargará el empleado
 * \param sueldo int Sueldo con el que se cargará el empleado
 * \return Retorna un puntero al espacio de memoria donde será guardado el empleado
 *
 */



Cliente* cliente_newParametros(int idStr,char* nombreStr,char* apellidoStr, int cantidadVentas, char* cuit)
{
	Cliente* this = NULL;
	this = envio_new();
	if(this != NULL && nombreStr != NULL &&   apellidoStr != NULL && idStr > 0 && cantidadVentas > 0)

	{
		if(
		    cliente_setNombre(this,nombreStr) == -1 ||
		    cliente_setApellido(this,apellidoStr) == -1 ||
		    cliente_setCuit(this,cuit) == -1 ||
		    cliente_setCantidadVentas(this,cantidadVentas) == -1 ||
		    cliente_setId(this,idStr) == -1
		    )
		{
		    cliente_delete(this);
			this = NULL;
		}
	}
	return this;
}




/**
 * \brief Verifica si la cadena ingresada es un nombre valido, teniendo en cuenta guines y espacios
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '-' && cadena[i] != ' ' &&(cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



/**
 * \brief Validates that what you receive it is valid to a letter, number, dot or hyphen.
 * \param char *string, pointer to the string to be validated
 * \return (0) FALSE (1) TRUE (-1) ERROR
 */
int isValidDocumentNumber(char* string, int len)
{
    int i ;
    int retorno = -1;

    if(string!= NULL && len > 0)
    {
	retorno = TRUE;
        for(i=0; string[i]!= '\0' && i < len; i++)
        {
            if((string[i] < 'a' || string [i] > 'z') && (string[i] < 'A' || string[i] > 'Z')  && (string[i] < '0' || string[i] > '9')
                    && (string[i] != '.' || string[0] == '.') && (string[i] != '-' || string[0] == '-'))
            {
        	retorno = FALSE;
                break;
            }
        }
    }
    return retorno;
}


//Getter and setter////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Cambia el nombre del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente a modificar
 * \param nombre char* Puntero al nombre que se cambiará
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setNombre(Cliente* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}



/**
 * \brief Se obtiene el nombre del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente
 * \param nombre char* Puntero al nombre del cliente mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_getNombre(Cliente* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}



/**
 * \brief Cambia el apellido del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente a modificar
 * \param nombre char* Puntero al nombre que se cambiará
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setApellido(Cliente* this,char* apeliido)
{
	int retorno = -1;
	if(this != NULL && apeliido != NULL)
	{
		if(isValidNombre(apeliido,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->apellido,apeliido,NOMBRE_LEN);
		}
	}
	return retorno;
}



/**
 * \brief Se obtiene el apellido del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente
 * \param nombre char* Puntero al nombre del cliente mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_getApellido(Cliente* this,char* apeliido)
{
	int retorno = -1;
	if(this != NULL && apeliido != NULL)
	{
		retorno = 0;
		strncpy(apeliido,this->apellido,NOMBRE_LEN);
	}
	return retorno;
}




/**
 * \brief Se cambiará el id del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente
 * \param id int ID que se cargará al cliente mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setId(Cliente* this,int idCliente)
{
	int retorno = -1;
	if(this != NULL && idCliente >= 0)
	{
		retorno = 0;
		this->idCliente = idCliente;
	}
	return retorno;
}

/**
 * \brief Se cambiará el id del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente
 * \param id char* Puntero al ID que se cargará al cliente mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_setIdTxt(Cliente* this,char* idCliente)
{
	int retorno = -1;
	if(this != NULL && idCliente != NULL)
	{
		if(esNumerica(idCliente,10))
		{
			retorno = 0;
			this->idCliente = atoi(idCliente);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el id del cliente pasado por parámetro
 * \param this Employee* Puntero al cliente
 * \param id int* Puntero al ID que se obtendrá del cliente mencionado
 * \return int (-1) ERROR y (0) OK
 */


int cliente_getId(Cliente* this,int* idCliente)
{
	int retorno = -1;
	if(this != NULL && idCliente != NULL)
	{
		retorno = 0;
		*idCliente = this->idCliente;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el id del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente
 * \param id char* Puntero al ID que se obtendrá del cliente mencionado
 * \return int (-1) ERROR y (0) OK
 */

int cliente_getIdTxt(Cliente* this,char* idCliente)
{
	int retorno = -1;
	if(this != NULL && idCliente != NULL)
	{
		retorno = 0;
		sprintf(idCliente,"%d",this->idCliente);
	}
	return retorno;
}




/**
 * \brief Cambia el cuit del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente a modificar
 * \param nombre char* Puntero al cuit que se cambiará
 * \return int -1 ERROR y 0 OK
 */


int cliente_setCuit(Cliente* this, char* cuit)
{
	int retorno = -1;
	if (this != NULL && cuit != NULL && isValidDocumentNumber(cuit, NOMBRE_LEN))
	{
		strncpy(this->cuit, cuit, CUIT_LEN);
		retorno = FALSE;
	}
	return retorno;
}

/**
 * \brief Se obtiene el cuit del cliente pasado por parámetro
 * \param this Cliente* Puntero al cliente
 * \param nombre char* Puntero al cuit del cliente mencionado
 * \return int -1 ERROR y 0 OK
 */
int cliente_getCuit(Cliente* this, char* cuit)
{
	int retorno = -1;
	if (this != NULL && cuit != NULL)
	{
		strncpy(cuit, this->cuit, CUIT_LEN);
		retorno = FALSE;
	}
	return retorno;
}


/*
 * \brief Carga la cantidad de ventas por estado en el campo del cliente
 * \param this Cliente* puntero a cliente
 * \param qty int cantidad a cargar
 * \return int Return -1 ERROR - Si el puntero a Cliente* es NULL o si la cantidad no es valida
 * 					  (0) EXITO
 */
int cliente_setCantidadVentas(Cliente* this,int cantidadVentas)
{
	int retorno = -1;
	if (this != NULL && cantidadVentas >= 0)
	{
		this->cantidadVentas = cantidadVentas;
		retorno = FALSE;
	}
	return retorno;
}

/*
 * \brief Obtiene la cantidad de ventas por estado del cliente
 * \param this Cliente* puntero a cliente
 * \param qty int* puntero al espacio donde va a guardar la cantidad obtenida
 * \return int Return -1 ERROR - Si el puntero a Cliente* es NULL o si e puntero a cantidadVentas es NULL
 * 					  0 EXITO
 */
int cliente_getCantidadVentas(Cliente* this,int* cantidadVentas)
{
	int result = -1;
	if (this != NULL && cantidadVentas != NULL)
	{
		*cantidadVentas = this->cantidadVentas;
		result = FALSE;
	}
	return result;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 * \brief Elimina el cliente pasado por parámetro
 * \param this Employee* Puntero al cliente a eliminar
 * \return void
 */


void cliente_delete(Cliente* this)
{
	if(this != NULL)
	{
		free(this);
	}
}





/**
 * \brief Alta de clientes - Solicita los datos de los campos al usuario y lo añade al listado
 * \param listClient LinkedList* puntero a lista clientes
 * \return int Return (-1) ERROR - Si el puntero a LikedList es NULL, si no hay espacio en memoria para un cliente
 * 								   o si el usuario completa erroneamente lo requerido o no lo puede agregar a la lista
 * 					  (-2) ERROR - Si el cuit ingresado ya existe
 * 					  (0) EXITO
 */

/*
int clienteCargaYAgrega(LinkedList* listaClientes)
{
	int retorno = -1;
	Cliente* pClient;
	Cliente buffer;
	int idAux;

	if (listaClientes != NULL)
	{
		pClient = cli_new();
		if(pClient != NULL)
		{
		   	if(utn_getNombre(buffer.nombre, NOMBRE_LEN, "\nIngrese nombre: ", "\nError!", 3) == FALSE
					&& utn_getApellido(buffer.apellido, NOMBRE_LEN, "\nIngrese apellido: ", "\nError!", 3) == FALSE
					&& cliente_getCuit(buffer.cuit, CUIT_LEN, "\nIngrese cuit: ", "\nError!", 3) == FALSE
					&& cliente_validaExistencia(listaClientes,buffer.cuit) == FALSE)
			{


				buffer.idCliente = generateNewIdClient();
				idMaximoEncontradoCliente(listaClientes, &idAux);///// ojo para probar
				 idAux = idAux + 1;
				 buffer.idCliente = idAux;
				if(cliente_setNombre(pClient, buffer.nombre) == FALSE
						&& cliente_setApellido(pClient, buffer.apellido) == FALSE
						&& cliente_setCuit(pClient, buffer.cuit) == FALSE
						&& cliiente_setId(pClient, buffer.idCliente) == FALSE)
				{
				    pClient = (Cliente*)employee_newParametros(idAux,auxNombre,auxHsTrabajadas,sueldo);
				    retorno = ll_add(listaClientes, pClient);
				}
			} else {
			    retorno = -2;
			    cliente_delete(pClient);
			}
		}
	}
	return retorno;
}


*/




/**
 * \brief Verifica si existe un cuit dado en la lista de clientes
 * \param listClient LinkedList* puntero al listado de clientes
 * \param cuit char* cuit a buscar si ya existe
 * \return Return 0 FALSE si no existe 1 TRUE si lo encontro
 */
int cliente_validaExistencia(LinkedList* listaClientes, char* cuit)
{
	int result = FALSE;
	int i;
	char bufferCuit[CUIT_LEN];
	Cliente* pClient;

	if(listaClientes !=  NULL && cuit != NULL)
	{
		for (i = 0; i < ll_len(listaClientes); i++)
		{
			pClient = (Cliente*)ll_get(listaClientes,i);
			if(pClient!= NULL)
			{
				cliente_getCuit(pClient,bufferCuit);
				if (strncmp(bufferCuit,cuit,CUIT_LEN)==0)
				{
					result = TRUE;
					break;
				}
			}
		}
	}
	return result;
}



/**
 * \brief Imprime los datos de un cliente
 * \param this void* puntero a void
 * \return int Return -1 ERROR - Si el puntero a void es NULL
 *0 EXITO
 */
int cliente_printOne(void* this)
{
	int retorno = ERROR;
	Cliente* oneClient;
	Cliente buffer;

	if(this != NULL)
	{
		oneClient = (Cliente*)this;
		if(cliente_getId(oneClient,&buffer.idCliente) == FALSE
				&& cliente_getNombre(oneClient,buffer.nombre) == FALSE
				&& clinte_getApellido(oneClient,buffer.apellido) == FALSE
				&& cliente_getCuit(oneClient,buffer.cuit) == FALSE)
		{
			printf("\nId: %10d -  Nombre: %15s - Apellido: %15s - Cuit: %15s\n",buffer.idCliente,buffer.nombre,buffer.apellido,buffer.cuit);
			retorno = FALSE;
		}
	}
	return retorno;
}
