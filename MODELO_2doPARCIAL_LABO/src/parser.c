/*
 * parser.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Envios.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 *
 */
int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEnvio)
{
		int retorno = -1;
		Envio* auxEnvio;
		 char auxiliarId[4096];
		 char auxiliarNombre[4096];
		 char auxiliarIdCammion[4096];
		 char auxiliarZona[4096];
		 char auxiliarKmRecorrido[4096];
		 char auxiliarTipoEntrega[4096];
		 char auxiliarCostoEnvio[4096] = "0";
		 int contadorEnvio=0;



		if(pFile != NULL && pArrayListEnvio != NULL)
		{
				do
				{
					if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxiliarId,auxiliarNombre,auxiliarIdCammion,auxiliarZona,auxiliarKmRecorrido,auxiliarTipoEntrega)== 6)
					{
						if(envio_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarIdCammion,auxiliarZona,auxiliarKmRecorrido,auxiliarTipoEntrega,auxiliarCostoEnvio) >= 0)
						{

							auxEnvio = (Envio*) envio_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarIdCammion,auxiliarZona,auxiliarKmRecorrido,auxiliarTipoEntrega,auxiliarCostoEnvio);
							if(ll_add(pArrayListEnvio,auxEnvio)==0)
							{
							retorno = 0;
							contadorEnvio++;

							}

						}
					}
				}while(!feof(pFile));
		}
		printf("Se cargaron %d envios\n",contadorEnvio);
		return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param pFile FILE* Puntero al archivo a ser descargado
 * \param pArrayListEmployee LinkedList* Puntero a la lista a ser cargada
 * \return int (-1) ERROR  0) OK
 *
 */
int parser_EnvioFromBinary(FILE* pFile , LinkedList* pArrayListEnvio)
{
	int retorno = -1;
		Envio* auxPEnvio;
		Envio auxEnvio;
	    char auxiliarId[4096];
	    char auxiliarNombre[4096];
		char auxiliarIdCammion[4096];
		char auxiliarZona[4096];
		char auxiliarKmRecorrido[4096];
		char auxiliarTipoEntrega[4096];;
		char auxiliarCostoEnvio = '0';
		int contadorEnvio=0;

		if(pFile != NULL && pArrayListEnvio != NULL)
		{
			if(pFile != NULL)
			{

				do
				{
					if(fread(&auxEnvio,sizeof(Envio),1, pFile)==1)
					{
		                sprintf(auxiliarId, "%d", auxEnvio.idProducto);
		                strcpy(auxiliarNombre, auxEnvio.nombreProducto);
		                sprintf(auxiliarIdCammion, "%d", auxEnvio.idCamion);
		                strcpy(auxiliarZona, auxEnvio.zona);
		                sprintf(auxiliarKmRecorrido, "%d", auxEnvio.kmRecorrido);
		                sprintf(auxiliarTipoEntrega, "%d", auxEnvio.tipoEntrega);

						if(envio_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarIdCammion,auxiliarZona,auxiliarKmRecorrido,auxiliarTipoEntrega,auxiliarCostoEnvio) >= 0)
						{
							auxPEnvio = (Envio*) envio_newParametrosTxt(auxiliarId,auxiliarNombre,auxiliarIdCammion,auxiliarZona,auxiliarKmRecorrido,auxiliarTipoEntrega,auxiliarCostoEnvio);
							if(ll_add(pArrayListEnvio,auxPEnvio)==0)
							{
								retorno = 0;
								contadorEnvio++;
							}

						}
					}
				}while(!feof(pFile));
			}
		}
		printf("Se cargaron %d envios\n",contadorEnvio);
		return retorno;
}
