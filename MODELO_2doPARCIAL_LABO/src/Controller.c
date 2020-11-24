/*
 * Controller.c
 *
 *  Created on: 15 nov. 2020
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Envios.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>


#define LEN_AUX 128

static int idMaximoEncontrado(LinkedList* pArrayListEnvios, int* idMaximo);



/** \brief Carga los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEnvios LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListEnvios != NULL)
	{

	   pArch = fopen(path, "rw");
		if(pArch != NULL && parser_EnvioFromText(pArch,pArrayListEnvios)==0)
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

/** \brief Carga los datos de los envios desde el archivo data.dat (modo binario).
 *
 * \param path char* Nombre del archivo a cargar
 * \param pArrayListEnvios LinkedList* Puntero del tipo LinkedList* a la lista donde se guardará la información
 * \return int 0 si salió OK o (-1) ERROR
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListEnvios != NULL)
	{

		pArch = fopen(path, "rb");
		if(pArch != NULL && parser_EnvioFromBinary(pArch,pArrayListEnvios)==0)
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



/** \brief Alta de envios
 * \param pArrayListEnvios LinkedList* Puntero a la lista del tipo LinkedList* donde será añadido el envio
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_addEnvio(LinkedList* pArrayListEnvios)
{
	int retorno=-1;
	Envio* pAuxiliarEnvio;
	int auxId;
	char auxNombre[LEN_AUX];
	int auxIdCamion;
	char auxZona[LEN_AUX];
	int auxKmRecorrido;
	int auxTipoEntrega;
	int auxCostoEnvio = 0;


	if(pArrayListEnvios != NULL)
	{
		if(
		   !(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre del producto\n", "Valor incorrecto\n",2)) &&
		   !(utn_getNumero(&auxIdCamion,"Ingrese id del camion\n", "Valor incorrecto\n",1, 1000,2)) &&
		   !(utn_getNombre(auxZona, LEN_AUX,"Ingrese la zona\n", "Valor incorrecto\n",2)) &&
		   !(utn_getNumero(&auxKmRecorrido,"Ingrese km recorridos\n", "Valor incorrecto\n",1, 1000,2)) &&
		   !(utn_getNumero(&auxTipoEntrega,"Ingrese tipo de entrega (1, 2 o 3)\n", "Valor incorrecto\n",1, 3,2)))
		{
			if(ll_len(pArrayListEnvios) == 0)
			{
				auxId = 0;
			}
			else
			{
				idMaximoEncontrado(pArrayListEnvios, &auxId);
				auxId = auxId + 1;
			}
			if(envio_newParametros(auxId,auxNombre,auxIdCamion,auxZona,auxKmRecorrido,auxTipoEntrega,auxCostoEnvio) >= 0)
			{
				pAuxiliarEnvio = (Envio*)envio_newParametros(auxId,auxNombre,auxIdCamion,auxZona,auxKmRecorrido,auxTipoEntrega,auxCostoEnvio);
				ll_add(pArrayListEnvios,pAuxiliarEnvio);

				retorno = 0;
				printf("Envio creado correctamente en la ubicación %d\n", auxId);
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 * \param pArrayListEnvios LinkedList* Puntero a la lista del tipo LinkedList* donde será modificado el empleado
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_editEnvio(LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	Envio* auxEnvio;
	int index;
	int opcionAux;
	int auxId;
	char auxNombre[LEN_AUX];
	int auxIdCamion;
	char auxZona[LEN_AUX];
	int auxKmRecorrido;
	int auxTipoEntrega;
//	int auxCostoEnvio = 0;


	if(pArrayListEnvios != NULL)
	{
		controller_ListEnvio(pArrayListEnvios);
		if(!utn_getNumero(&auxId,"Ingrese el ID que desea editar\n","ID inválido\n",0,ll_len(pArrayListEnvios), 2))
		{
			index = controller_buscarPorIdArray(pArrayListEnvios, auxId);
			auxEnvio = (Envio*)ll_get(pArrayListEnvios,index);
			if(auxEnvio != NULL)
			{
				envio_imprimir(auxEnvio);


				if(!utn_getNumero(&opcionAux,"Confirma modificar el envio? [0-NO/1-SI]\n","Opción inválida\n",0,1,2) && opcionAux == 1)
				{
					if( !(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre del producto\n", "Valor incorrecto\n",2)) &&
					    !(utn_getNumero(&auxIdCamion,"Ingrese el numero del camion\n", "Valor incorrecto\n",1, 1000,2)) &&
					    !(utn_getNombre(auxZona, LEN_AUX,"Ingrese la zona\n", "Valor incorrecto\n",2)) &&
					    !(utn_getNumero(&auxKmRecorrido,"Ingrese km recorridos\n", "Valor incorrecto\n",1, 1000,2)) &&
					    !(utn_getNumero(&auxTipoEntrega,"Ingrese tipo de entrega\n", "Valor incorrecto\n",1, 3,2)))
					{
					retorno = 0;
					envio_setNombre(auxEnvio, auxNombre);
					envio_setIdCamion(auxEnvio, auxIdCamion);
					envio_setZona(auxEnvio, auxZona);
					envio_setKmRecorrido(auxEnvio, auxKmRecorrido);
					envio_setTipoEntrega(auxEnvio, auxTipoEntrega);
					}
				}
			}

		}


	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEnvios LinkedList* Puntero a la lista a ser actualizada
 * \return int Retorna 0 OK o (-1) ERROR
 *
 */
int controller_removeEnvio(LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	int auxID;
	int opcionAux;
	int index;
	Envio* auxEnvio;

	if(pArrayListEnvios != NULL)
	{
		controller_ListEnvio(pArrayListEnvios);
		if(!utn_getNumero(&auxID,"Ingrese el ID que desea eliminar\n","ID inválido\n",0,ll_len(pArrayListEnvios), 2))
		{
			index = controller_buscarPorIdArray(pArrayListEnvios, auxID);
			auxEnvio = (Envio*)ll_get(pArrayListEnvios,index);
			if(auxEnvio != NULL)
			{
				envio_imprimir(auxEnvio);

				if(!utn_getNumero(&opcionAux,"Confirma eliminar envio? [0-NO/1-SI]\n","Opción inválida\n",0,1,2) && opcionAux == 1)
				{
					retorno = 0;
					ll_remove(pArrayListEnvios,index);
					envio_delete(auxEnvio);
					printf("Envio eliminado correctamente\n");
				}
			}
		}
	}
	return retorno;
}


/** \brief Listar empleados
 * \param pArrayListEnvios LinkedList* Puntero a la lista a ser impresa
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_ListEnvio(LinkedList* pArrayListEnvios)
{
	int retorno=-1;
	int i;
	Envio* bufferpEnvio;
	bufferpEnvio = envio_new();

	if(pArrayListEnvios != NULL)
	{
		retorno=0;

		for(i=0;i<ll_len(pArrayListEnvios);i++)
		{
			bufferpEnvio = ll_get(pArrayListEnvios,i);
			envio_imprimir(bufferpEnvio);
		}

	}
	return retorno;
}




/** \brief Ordenar empleados
 * \param pArrayListEnvios LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */


int controller_sortEnvio(LinkedList* pArrayListEnvios)
{
		int retorno = -1;
		int opcion = 1;
	 	int (*envio_pFordenarNombre)(void*, void*) = envio_ordenarNombre2;


		if(pArrayListEnvios != NULL)
		{
			retorno=0;

				printf("Espere, se está cargando la lista\n");
				if(ll_sort(pArrayListEnvios,envio_pFordenarNombre,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListEnvio(pArrayListEnvios);
				}

		}
		return retorno;
}








/** \brief Ordenar empleados por ID
 * \param pArrayListEnvios LinkedList* Puntero a la lista a ser ordenada
 * \return int 0 OK, (-1) ERROR
 *
 */


int controller_sortEnviobyID(LinkedList* pArrayListEnvios)
{
		int retorno = -1;
		int opcion;
//	 	int (*envio_pFordenarID)(void*, void*) = envio_pFordenarID;


		if(pArrayListEnvios != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese órden [1-ascendente / 0-descendente]\n","Valor inválido\n",0,1,2))
			{
				printf("Espere, se está cargando la lista\n");
				if(ll_sort(pArrayListEnvios,envio_ordenarID,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListEnvio(pArrayListEnvios);
				}
			}
		}

		return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* Puntero al archivo a ser guardado
 * \param pArrayListEnvios LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEnvios)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	int auxId;
	char auxNombre[LEN_AUX];
	int auxIdCamion;
	char auxZona[LEN_AUX];
	int auxKmRecorrido;
	int auxTipoEntrega;
	int auxCostoEnvio;
	Envio* auxEnvio;

	if(pArrayListEnvios != NULL && path != NULL)
	{

		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			retorno=0;
			for(i=0;i<ll_len(pArrayListEnvios);i++)
			{
				auxEnvio = (Envio*)ll_get(pArrayListEnvios,i);
				if(auxEnvio != NULL)
				{
					if(!envio_getId(auxEnvio,&auxId) &&
					   !envio_getNombre(auxEnvio,auxNombre) &&
					   !envio_getIdCamion(auxEnvio,&auxIdCamion) &&
					   !envio_getZona(auxEnvio,auxZona) &&
					   !envio_getKmRecorrido(auxEnvio,&auxKmRecorrido) &&
					   !envio_getTipoEntrega(auxEnvio,&auxTipoEntrega) &&
					   !envio_getCostoEnvio(auxEnvio,&auxCostoEnvio))

					{
						fprintf(fpArchivo,"%d,%s,%d,%s,%d,%d,%d\n",auxId,auxNombre,auxIdCamion,auxZona,auxKmRecorrido,auxTipoEntrega,auxCostoEnvio);
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
 * \param pArrayListEnvios LinkedList* Puntero a la lista a ser guardada
 * \return int 0 OK, (-1) ERROR
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEnvios)
{
	int retorno=-1;
		int i;
		FILE* fpArchivo;
		Envio* auxEnvio;
		int contadorEnvio = 0;
		int len;

		if(pArrayListEnvios != NULL && path != NULL)
		{
			len = ll_len(pArrayListEnvios);

			fpArchivo = fopen(path,"wb");
			if(fpArchivo != NULL)
			{
				retorno=0;
				for(i=0;i<len;i++)
				{
					auxEnvio = ll_get(pArrayListEnvios, i);
					if(fwrite(auxEnvio, sizeof(Envio),1,fpArchivo)==1)
					{
						contadorEnvio++;
					}
				}
				fclose(fpArchivo);
				printf("Archivo cargado correctamente\n");
				printf("Se guardaron %d empleados\n",contadorEnvio);
			}
		}
		return retorno;
}



/**
 * \brief Busca un empleado por ID
 * \param pArrayListEnvios LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */


int controller_buscarPorIdArray(LinkedList* pArrayListEnvios, int id)
{
	int retorno=-1;
	int i;
	int idAux;
	Envio* auxEnvio;

	if(pArrayListEnvios != NULL && id >= 0)
	{
		retorno = -2;
		for(i=0;i<ll_len(pArrayListEnvios);i++)
		{
			auxEnvio = ll_get(pArrayListEnvios,i);
			envio_getId(auxEnvio, &idAux);

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
 * \param pArrayListEnvios LinkedList* Puntero a la lista que será evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

static int idMaximoEncontrado(LinkedList* pArrayListEnvios, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Envio* auxiliarEnvio;
	Envio* auxEnvio;

	if(pArrayListEnvios != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListEnvios);i++)
		{
			auxEnvio = ll_get(pArrayListEnvios,i);
			envio_getId(auxEnvio,&idAuxiliar);
			if(!flag)
			{
				auxiliarEnvio = ll_get(pArrayListEnvios,i);
				envio_getId(auxiliarEnvio,&idAuxMaximo);
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





int controller_containsElemento(LinkedList* pArrayListEnvios, Envio* envio )
{
	int retorno = -1;
	if(pArrayListEnvios != NULL)
	{
		if(ll_contains(pArrayListEnvios,envio)==1)
		{
			printf("Envio encontrado\n");
			retorno = 0;
		}
	}

	return retorno;
}




static int zoneIsInList(LinkedList* listZona, char* zona)
{
	int result = 0;
	int i;
	char bufferZona[NOMBRE_LEN];
	Zona* pZona;

	for (i = 0; i < ll_len(listZona); i++)
	{
		pZona = ll_get(listZona,i);
		zona_getZonaDestinos(pZona,bufferZona);
		if (strncmp(bufferZona,zona,NOMBRE_LEN)==0)
		{
			result = 1;
			break;
		}
	}
	return result;
}



int controller_createListOfZones(LinkedList* pArrayListEnvios)
{
	int result = -1;
	LinkedList* listaZonas;

	if(pArrayListEnvios != NULL)
	{
		listaZonas = zona_generateList(pArrayListEnvios);
		controller_printListZone(listaZonas);
		result = 0;

	}
	return result;
}




LinkedList* zona_generateList(LinkedList* pArrayListEnvios)
{
	LinkedList* listaZonas = NULL;
    Envio* pElement;
    Zona* pElementZona;
    int i;
    char bufferZonaEnvios[NOMBRE_LEN];

    if(pArrayListEnvios != NULL)
    {
    	listaZonas = ll_newLinkedList();
    	if(listaZonas != NULL)
    	{
    		for(i=0;i<ll_len(pArrayListEnvios);i++)
    		{
    			pElement = (Envio*) ll_get(pArrayListEnvios,i);
    			envio_getZona(pElement,bufferZonaEnvios);
				if(zoneIsInList(listaZonas,bufferZonaEnvios)==0)
				{
					pElementZona = zona_new();
					if(pElementZona != NULL)
					{
						zona_setZonaDestinos(pElementZona,bufferZonaEnvios);
						ll_add(listaZonas,pElementZona);
					} else {
						ll_deleteLinkedList(listaZonas);
						listaZonas = NULL;
						break;
					}
				}
			}
		}
	}
    return listaZonas;
}

int controller_printOneZone(void* pElement)
{
	int returnAux = -1;
	Zona* unaZona;
	char bufferZona[NOMBRE_LEN];

	if(pElement != NULL)
	{
		unaZona = (Zona*)pElement;
		zona_getZonaDestinos(unaZona,bufferZona);
		printf("\n %s",bufferZona);
		returnAux = 0;
	}
	return returnAux;
}




int controller_printListZone(LinkedList* listaZonas)
{
	int returnAux = -1;

	if(listaZonas != NULL)
	{
		printf("\n%s","ZONAS: ");
		returnAux = ll_map(listaZonas,controller_printOneZone);
	}
	return returnAux;
}


