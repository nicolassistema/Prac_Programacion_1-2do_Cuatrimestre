/*
 * Controller.c
 *
 *  Created on: 24 nov. 2020
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cliente.h"
#include "Venta.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>








/**
 * \brief Busca un empleado por ID
 * \param pArrayListCliente LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

static int idMaximoEncontradoCliente(LinkedList* pArrayListCLiente, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Cliente* auxiliarCliente;
	Cliente* auxEmplo;

	if(pArrayListCLiente != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListCLiente);i++)
		{
			auxEmplo = ll_get(pArrayListCLiente,i);
			cliente_getId(auxEmplo,&idAuxiliar);
			if(!flag)
			{
			    auxiliarCliente = ll_get(pArrayListCLiente,i);
				cliente_getId(auxiliarCliente,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}






#define LEN_AUX 128

static int idMaximoEncontrado(LinkedList* pArrayListCliente, int* idMaximo);



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListCliente LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
/*
int controller_loadFromText(char* path , LinkedList* pArrayListCliente)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListCliente != NULL)
	{

		pArch = fopen(path, "rw");
		if(pArch != NULL && parser_ClienteFromText(pArch,pArrayListCliente)==0)
		{
			printf("Archivo cargado existosamente\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}

	return retorno;
}
*/
/** \brief Carga los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListCliente LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
/*
int controller_loadFromBinary(char* path , LinkedList* pArrayListCliente)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListCliente != NULL)
	{

		pArch = fopen(path, "rb");
		if(pArch != NULL && parser_ClienteFromBinary(pArch,pArrayListCliente)==0)
		{
			printf("Archivo cargado existosamente\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}

	return retorno;
}
*/

/** \brief Alta de empleados
 * \param pArrayListCliente LinkedList* Puntero a la lista del tipo LinkedList* donde será añadido el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_addCliente(LinkedList* pArrayListCliente)
{
	int retorno=-1;
	Cliente* pAuxiliarCliente;
	int idAux;
	char auxNombre[LEN_AUX];
	char auxApellido[LEN_AUX];
	int cuit;
	int cantidadVentas = 0;


	if(pArrayListCliente != NULL)
	{
		if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
		    !(utn_getApellido(auxNombre, LEN_AUX,"Ingrese apellido\n", "Valor incorrecto\n",2)) &&
		    !(utn_getIdentityDocument(&cuit, CUIT_LEN, "\nIngrese cuit: ",  "\nError!", 3)))
		{
			if(ll_len(pArrayListCliente) == 0)
			{
				idAux = 0;
			}
			else
			{
				idMaximoEncontrado(pArrayListCliente, &idAux);
				idAux = idAux + 1;
			}


			if(cliente_newParametros(idAux,auxNombre,auxApellido,cantidadVentas,cuit) >= 0)
			{
			    pAuxiliarCliente = (Cliente*)cliente_newParametros(idAux,auxNombre,auxApellido,cantidadVentas,cuit);
				ll_add(pArrayListCliente,pAuxiliarCliente);

				retorno = 0;
				printf("Cliente creado correctamente en la ubicación %d\n", idAux);
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListCliente LinkedList* Puntero a la lista del tipo LinkedList* donde será modificado el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_editCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	Cliente* auxCliente;
	int index;
	int auxID;
	int opcionAux;
	char auxNombre[LEN_AUX];
	int auxHsTrabajadas;
	int sueldo;


	if(pArrayListCliente != NULL)
	{
		controller_ListCliente(pArrayListCliente);
		if(!utn_getNumero(&auxID,"Ingrese el ID que desea editar\n","ID inválido\n",0,ll_len(pArrayListCliente), 2))
		{
			index = controller_buscarPorIdArray(pArrayListCliente, auxID);
			auxCliente = (Cliente*)ll_get(pArrayListCliente,index);
			if(auxCliente != NULL)
			{
				Cliente_imprimir(auxCliente);


				if(!utn_getNumero(&opcionAux,"Confirma modificar el empleado? [0-NO/1-SI]\n","Opción inválida\n",0,1,2) && opcionAux == 1)
				{
					if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
					   !(utn_getNumero(&auxHsTrabajadas,"Ingrese horas trabajadas\n", "Valor incorrecto\n",1, 1000,2)) &&
					   !(utn_getNumero(&sueldo,"Ingrese sueldo\n", "Valor incorrecto\n",1, 1000000,2)))
					{
					retorno = 0;
					Cliente_setNombre(auxCliente, auxNombre);
					Cliente_setHorasTrabajadas(auxCliente, auxHsTrabajadas);
					Cliente_setSueldo(auxCliente,sueldo);
					}
				}
			}

		}


	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListCliente LinkedList* Puntero a la lista a ser actualizada
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_removeCliente(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	int auxID;
	int opcionAux;
	int index;
	Cliente* auxCliente;

	if(pArrayListCliente != NULL)
	{
		controller_ListCliente(pArrayListCliente);
		if(!utn_getNumero(&auxID,"Ingrese el ID que desea eliminar\n","ID inválido\n",0,ll_len(pArrayListCliente), 2))
		{
			index = controller_buscarPorIdArray(pArrayListCliente, auxID);
			auxCliente = (Cliente*)ll_get(pArrayListCliente,index);
			if(auxCliente != NULL)
			{
				Cliente_imprimir(auxCliente);

				if(!utn_getNumero(&opcionAux,"Confirma eliminar el empleado? [0-NO/1-SI]\n","Opción inválida\n",0,1,2) && opcionAux == 1)
				{
					retorno = 0;
					ll_remove(pArrayListCliente,index);
					Cliente_delete(auxCliente);
					printf("Empleado eliminado correctamente\n");
				}
			}
		}
	}
	return retorno;
}


/** \brief Listar empleados
 * \param pArrayListCliente LinkedList* Puntero a la lista a ser impresa
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_ListCliente(LinkedList* pArrayListCliente)
{
	int retorno=-1;
	int i;
	Cliente* bufferpCliente;
	bufferpCliente = envio_new();

	if(pArrayListCliente != NULL)
	{
		retorno=0;

		for(i=0;i<ll_len(pArrayListCliente);i++)
		{
			bufferpCliente = ll_get(pArrayListCliente,i);
			Cliente_imprimir(bufferpCliente);
		}

	}
	return retorno;
}



/** \brief Ordenar empleados
 * \param pArrayListCliente LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */

/*
int controller_sortCliente(LinkedList* pArrayListCliente)
{
		int retorno = -1;
		int opcion;
	 	int (*Cliente_pFordenarNombre)(void*, void*) = Cliente_ordenarNombre;


		if(pArrayListCliente != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese órden [1-descendente / 0-ascendente]\n","Valor inválido\n",0,1,2))
			{
				printf("Espere, se está cargando la lista\n");
				if(ll_sort(pArrayListCliente,Cliente_pFordenarNombre,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListCliente(pArrayListCliente);
				}
			}
		}

		return retorno;
}
*/

/** \brief Ordenar empleados por ID
 * \param pArrayListCliente LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */

/*
int controller_sortClientebyID(LinkedList* pArrayListCliente)
{
		int retorno = -1;
		int opcion;
//	 	int (*Cliente_ordenarID)(void*, void*) = Cliente_pFordenarID;


		if(pArrayListCliente != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese órden [1-ascendente / 0-descendente]\n","Valor inválido\n",0,1,2))
			{
				printf("Espere, se está cargando la lista\n");
				if(ll_sort(pArrayListCliente,Cliente_ordenarID,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListCliente(pArrayListCliente);
				}
			}
		}

		return retorno;
}
*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListCliente LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListCliente)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	int auxiliarHsTrab;
	int auxSueldo;
	Cliente* auxEmpleado;

	if(pArrayListCliente != NULL && path != NULL)
	{

		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			retorno=0;
			for(i=0;i<ll_len(pArrayListCliente);i++)
			{
				auxEmpleado = (Cliente*)ll_get(pArrayListCliente,i);
				if(auxEmpleado != NULL)
				{
					if(!envio_getId(auxEmpleado,&auxiliarId) &&
					   !Cliente_getNombre(auxEmpleado,auxiliarNombre) &&
					   !Cliente_getHorasTrabajadas(auxEmpleado,&auxiliarHsTrab) &&
					   !Cliente_getSueldo(auxEmpleado,&auxSueldo))
					{
						fprintf(fpArchivo,"%d,%s,%d,%d\n",auxiliarId,auxiliarNombre,auxiliarHsTrab,auxSueldo);
					}
				}

			}
			fclose(fpArchivo);
			printf("Archivo guardado correctamente\n");

		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.dat (modo binario).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListCliente LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListCliente)
{
	int retorno=-1;
		int i;
		FILE* fpArchivo;
		Cliente* auxEmpleado;
		int contadorCliente = 0;
		int len;

		if(pArrayListCliente != NULL && path != NULL)
		{
			len = ll_len(pArrayListCliente);

			fpArchivo = fopen(path,"wb");
			if(fpArchivo != NULL)
			{
				retorno=0;
				for(i=0;i<len;i++)
				{
					auxEmpleado = ll_get(pArrayListCliente, i);
					if(fwrite(auxEmpleado, sizeof(Cliente),1,fpArchivo)==1)
					{
						contadorCliente++;
					}
				}
				fclose(fpArchivo);
				printf("Archivo cargado correctamente\n");
				printf("Se guardaron %d empleados\n",contadorCliente);
			}
		}
		return retorno;
}



/**
 * \brief Busca un empleado por ID
 * \param pArrayListCliente LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */


int controller_buscarPorIdArray(LinkedList* pArrayListCliente, int id)
{
	int retorno=-1;
	int i;
	int idAux;
	Cliente* auxEmpleado;

	if(pArrayListCliente != NULL && id >= 0)
	{
		retorno = -2;
		for(i=0;i<ll_len(pArrayListCliente);i++)
		{
			auxEmpleado = ll_get(pArrayListCliente,i);
			envio_getId(auxEmpleado, &idAux);

			if( idAux == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}



/**
 * \brief Busca un empleado por ID
 * \param pArrayListCliente LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

static int idMaximoEncontrado(LinkedList* pArrayListCliente, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Cliente* auxiliarCliente;
	Cliente* auxEmplo;

	if(pArrayListCliente != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListCliente);i++)
		{
			auxEmplo = ll_get(pArrayListCliente,i);
			envio_getId(auxEmplo,&idAuxiliar);
			if(!flag)
			{
				auxiliarCliente = ll_get(pArrayListCliente,i);
				envio_getId(auxiliarCliente,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}

int controller_containsElemento(LinkedList* pArrayListCliente, Cliente* empleado )
{
	int retorno = -1;
	if(pArrayListCliente != NULL)
	{
		if(ll_contains(pArrayListCliente,empleado)==1)
		{
			printf("Empleado encontrado\n");
			retorno = 0;
		}
	}

	return retorno;
}


