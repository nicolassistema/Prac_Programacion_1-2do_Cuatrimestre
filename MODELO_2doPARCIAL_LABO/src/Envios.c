/*
 * Envios.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */

#include "Envios.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>



#define LEN_AUX 128

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);



/**
 * \brief Crea un espacio de memoria para un envio
 * \param Void No recibe parámetros
 * \return Retorna un puntero al espacio de memoria donde será guardado el envio
 *
 */

Envio* envio_new(void)
{
	Envio* auxiliarE = NULL;
	auxiliarE = (Envio*) malloc(sizeof(Envio));
	return auxiliarE;
}



/**
 * \brief Crea un envio conociendo sus parámetros
 * \param idStr char* Puntero id
 * \param nombreStr char* Puntero al nombre
 * \param idCamionStr char* Puntero nombre
 * \param zonaStr char* Puntero zona
 * \param kmRecorridoStr char* Puntero Km recorridos
 * \param tipoEntregaStr char* Puntero tipo de entrega
 * \param costoEnvioStr char* Puntero costo de envio
 * \return Retorna un puntero al espacio de memoria donde será guardado el envio
 *
 */

Envio* envio_newParametrosTxt(char* idStr,char* nombreStr,char* idCamionStr,char* zonaStr,char* kmRecorridoStr,char* tipoEntregaStr,char* costoEnvioStr)
{
	Envio* this = NULL;
	this = envio_new();
	if(this != NULL &&
			idStr != NULL &&
			nombreStr != NULL &&
			idCamionStr != NULL &&
			zonaStr != NULL &&
			kmRecorridoStr != NULL &&
			tipoEntregaStr != NULL &&
			costoEnvioStr != NULL)
	{
		if(
		    envio_setIdTxt(this,idStr) == -1 ||
			envio_setNombre(this,nombreStr) == -1 ||
			envio_setIdCamionTxt(this,idCamionStr) == -1 ||
			envio_setZona(this,zonaStr) == -1 ||
			envio_setKmRecorridoTxt(this,kmRecorridoStr) == -1 ||
			envio_setTipoEntregaTxt(this,tipoEntregaStr) == -1 ||
			envio_setCostoEnvioTxt(this,costoEnvioStr) == -1)
		{
			envio_delete(this);
			this = NULL;
		}
	}
	return this;
}



/**
 * \brief Crea un envio conociendo sus parámetros reales
 * \param id int Id con el que se cargará el envio
 * \param nombre char* Puntero al nombre
 * \param idCamion int idCamion con el que se cargará el id del camion
 * \param zona char* Puntero al zona
 * \param kmRecorrido int kmRecorrido con el que se cargará el los km del recorrido
 * \param tipoEntrega int tipoEntrega con el que se cargará el tipo de recorrido
 * \param costoEnvio int costoEnvio con el que se cargará el costo del envio
 * \return Retorna un puntero al espacio de memoria donde será guardado el envio
 *
 */

Envio* envio_newParametros(int idStr,char* nombreStr,int idCamionStr,char* zonaStr,int kmRecorridoStr,int tipoEntregaStr,int costoEnvioStr)
{
	Envio* this = NULL;
	this = envio_new();
	if(this != NULL &&
				idStr > 0 &&
				nombreStr != NULL &&
				idCamionStr > 0 &&
				zonaStr != NULL &&
				kmRecorridoStr > 0 &&
				tipoEntregaStr > 0 &&
				costoEnvioStr > 0)
	{
		if(
				  envio_setId(this,idStr) == -1 ||
				  envio_setNombre(this,nombreStr) == -1 ||
				  envio_setIdCamion(this,idCamionStr) == -1 ||
				  envio_setZona(this,zonaStr) == -1 ||
				  envio_setKmRecorrido(this,kmRecorridoStr) == -1 ||
				  envio_setTipoEntrega(this,tipoEntregaStr) == -1 ||
				  envio_setCostoEnvio(this,costoEnvioStr) == -1)
		{
			envio_delete(this);
			this = NULL;
		}
	}
	return this;
}


/**
 * \brief Elimina el empleado pasado por parámetro
 * \param this Employee* Puntero al empleado a eliminar
 * \return void
 */


void envio_delete(Envio* this)
{
	if(this != NULL)
	{
		free(this);
	}
}



//----Getter And Setter-----------------------------------------------------------------------------------------------------------------------


/**
 * \brief Se cambiará el id del envio pasado por parámetro
 * \param this Envio* Puntero al envio
 * \param id int ID que se cargará al envio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setId(Envio* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->idProducto = id;
	}
	return retorno;
}

/**
 * \brief Se cambiará el id del envio pasado por parámetro
 * \param this Envio* Puntero al envio
 * \param id char* Puntero al ID que se cargará al envio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setIdTxt(Envio* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->idProducto = atoi(id);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el id del envio pasado por parámetro
 * \param this Envio* Puntero al envio
 * \param id int* Puntero al ID que se obtendrá del envio mencionado
 * \return int (-1) ERROR y (0) OK
 */


int envio_getId(Envio* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->idProducto;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el id del envio pasado por parámetro
 * \param this Envio* Puntero al envio
 * \param id char* Puntero al ID que se obtendrá del envio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getIdTxt(Envio* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->idProducto);
	}
	return retorno;
}


/**
 * \brief Cambia el nombre del envio pasado por parámetro
 * \param this Envio* Puntero al envio a modificar
 * \param nombre char* Puntero al envio que se cambiará
 * \return int (-1) ERROR y (0) OK
 */

int envio_setNombre(Envio* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombreProducto ,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}



/**
 * \brief Se obtiene el nombre del envio pasado por parámetro
 * \param this Envio* Puntero al empleado
 * \param nombre char* Puntero al nombre del envio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getNombre(Envio* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombreProducto,NOMBRE_LEN);
	}
	return retorno;
}


/**
 * \brief Se cambiará el id del camion pasado por parámetro
 * \param this Envio* Puntero al camion
 * \param id int ID que se cargará al camion mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setIdCamion(Envio* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->idCamion = id;
	}
	return retorno;
}

/**
 * \brief Se cambiará el id del camion pasado por parámetro
 * \param this Envio* Puntero al camion
 * \param id char* Puntero al ID que se cargará al camion mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setIdCamionTxt(Envio* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->idCamion = atoi(id);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el id del camion pasado por parámetro
 * \param this Envio* Puntero al camion
 * \param id int* Puntero al ID que se obtendrá del camion mencionado
 * \return int (-1) ERROR y (0) OK
 */


int envio_getIdCamion(Envio* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->idCamion;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el id del camion pasado por parámetro
 * \param this Envio* Puntero al camion
 * \param id char* Puntero al ID que se obtendrá del camion mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getIdCamionTxt(Envio* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->idCamion);
	}
	return retorno;
}



/**
 * \brief Cambia el nombre de la zona pasada por parámetro
 * \param this Envio* Puntero al zona a modificar
 * \param nombre char* Puntero al envio que se cambiará
 * \return int (-1) ERROR y (0) OK
 */

int envio_setZona(Envio* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->zona ,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}



/**
 * \brief Se obtiene el nombre de la zona pasado por parámetro
 * \param this Envio* Puntero a al envio
 * \param nombre char* Puntero a la zona del envio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getZona(Envio* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->zona,NOMBRE_LEN);
	}
	return retorno;
}



/**
 * \brief Se cambiará el kmRecorrido pasado por parámetro
 * \param this Envio* Puntero al kmRecorrido
 * \param id int ID que se cargará al kmRecorrido mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setKmRecorrido(Envio* this,int kmRecorrido)
{
	int retorno = -1;
	if(this != NULL && kmRecorrido >= 0)
	{
		retorno = 0;
		this->kmRecorrido = kmRecorrido;
	}
	return retorno;
}

/**
 * \brief Se cambiará el  kmRecorrido pasado por parámetro
 * \param this Envio* Puntero al kmRecorrido
 * \param id char* Puntero al ID que se cargará al kmRecorrido mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setKmRecorridoTxt(Envio* this,char* kmRecorrido)
{
	int retorno = -1;
	if(this != NULL && kmRecorrido != NULL)
	{
		if(esNumerica(kmRecorrido,10))
		{
			retorno = 0;
			this->kmRecorrido = atoi(kmRecorrido);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el  kmRecorrido pasado por parámetro
 * \param this Envio* Puntero al kmRecorrido
 * \param id int* Puntero al ID que se obtendrá del kmRecorrido mencionado
 * \return int (-1) ERROR y (0) OK
 */


int envio_getKmRecorrido(Envio* this,int* kmRecorrido)
{
	int retorno = -1;
	if(this != NULL && kmRecorrido != NULL)
	{
		retorno = 0;
		*kmRecorrido = this->kmRecorrido;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el  kmRecorrido pasado por parámetro
 * \param this Envio* Puntero al kmRecorrido
 * \param id char* Puntero al ID que se obtendrá del kmRecorrido mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getKmRecorridoTxt(Envio* this,char* kmRecorrido)
{
	int retorno = -1;
	if(this != NULL && kmRecorrido != NULL)
	{
		retorno = 0;
		sprintf(kmRecorrido,"%d",this->kmRecorrido);
	}
	return retorno;
}


/**
 * \brief Se cambiará el tipoEntrega pasado por parámetro
 * \param this Envio* Puntero al tipoEntrega
 * \param id int ID que se cargará al tipoEntrega mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setTipoEntrega(Envio* this,int tipoEntrega)
{
	int retorno = -1;
	if(this != NULL && tipoEntrega >= 0)
	{
		retorno = 0;
		this->tipoEntrega = tipoEntrega;
	}
	return retorno;
}

/**
 * \brief Se cambiará el  tipoEntrega pasado por parámetro
 * \param this Envio* Puntero al tipoEntrega
 * \param id char* Puntero al ID que se cargará al tipoEntrega mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setTipoEntregaTxt(Envio* this,char* tipoEntrega)
{
	int retorno = -1;
	if(this != NULL && tipoEntrega != NULL)
	{
		if(esNumerica(tipoEntrega,10))
		{
			retorno = 0;
			this->tipoEntrega = atoi(tipoEntrega);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el  tipoEntrega pasado por parámetro
 * \param this Envio* Puntero al tipoEntrega
 * \param id int* Puntero al ID que se obtendrá del tipoEntrega mencionado
 * \return int (-1) ERROR y (0) OK
 */


int envio_getTipoEntrega(Envio* this,int* tipoEntrega)
{
	int retorno = -1;
	if(this != NULL && tipoEntrega != NULL)
	{
		retorno = 0;
		*tipoEntrega = this->tipoEntrega;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el  tipoEntrega pasado por parámetro
 * \param this Envio* Puntero al tipoEntrega
 * \param id char* Puntero al ID que se obtendrá del tipoEntrega mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getTipoEntregaTxt(Envio* this,char* tipoEntrega)
{
	int retorno = -1;
	if(this != NULL && tipoEntrega != NULL)
	{
		retorno = 0;
		sprintf(tipoEntrega,"%d",this->tipoEntrega);
	}
	return retorno;
}



/**
 * \brief Se cambiará el costoEnvio pasado por parámetro
 * \param this Envio* Puntero al costoEnvio
 * \param id int ID que se cargará al costoEnvio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setCostoEnvio(Envio* this,int costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio >= 0)
	{
		retorno = 0;
		this->costoEnvio = costoEnvio;
	}
	return retorno;
}

/**
 * \brief Se cambiará el  costoEnvio pasado por parámetro
 * \param this Envio* Puntero al costoEnvio
 * \param id char* Puntero al ID que se cargará al costoEnvio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_setCostoEnvioTxt(Envio* this,char* costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio != NULL)
	{
		if(esNumerica(costoEnvio,10))
		{
			retorno = 0;
			this->costoEnvio = atoi(costoEnvio);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendrá el  costoEnvio pasado por parámetro
 * \param this Envio* Puntero al costoEnvio
 * \param id int* Puntero al ID que se obtendrá del costoEnvio mencionado
 * \return int (-1) ERROR y (0) OK
 */


int envio_getCostoEnvio(Envio* this,int* costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio != NULL)
	{
		retorno = 0;
		*costoEnvio = this->costoEnvio;
	}
	return retorno;
}


/**
 * \brief Se obtendrá el  costoEnvio pasado por parámetro
 * \param this Envio* Puntero al costoEnvio
 * \param id char* Puntero al ID que se obtendrá del costoEnvio mencionado
 * \return int (-1) ERROR y (0) OK
 */

int envio_getCostoEnvioTxt(Envio* this,char* costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio != NULL)
	{
		retorno = 0;
		sprintf(costoEnvio,"%d",this->costoEnvio);
	}
	return retorno;
}


Zona* zona_new(void)
{
	return (Zona*) malloc(sizeof(Zona));
}

int zona_setZonaDestinos(Zona *this, char* zona)
{
	int result = -1;

	if (this != NULL && zona != NULL)// && isValidLetters(zona, ZONE_LEN))
	{
		strncpy(this->zonaDestinos, zona, NOMBRE_LEN);
		result = 0;
	}
	return result;
}

int zona_getZonaDestinos(Zona* this, char* zona)
{
    int result = -1;
    if (this != NULL && zona != NULL)
    {
        strncpy(zona, this->zonaDestinos, NOMBRE_LEN);
        result = 0;
    }
    return result;
}


//--------------------------------------------------------------------------------------------------------------------------------------------



/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}




/**
 * \brief Verifica si la cadena ingresada es un nombre valido, teniendo en cuenta guiones y espacios
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
 * \brief Ordena por nombre
 * \param EmpUno void* Puntero al Empleado que se busca ordenar
 * \param EmpDos void* Puntero al Empleado que se busca ordenar
 * \return int Retorna 0 (Si ambos parámetros son iguales)
 * 					   1 (Si EmpDos es mayor)
 * 					   -1 (Si EmpUno es mayor)
 */


int envio_ordenarNombre2(void* EmpUno, void* EmpDos)
{
	int retorno = 0;
	char auxNombre[NOMBRE_LEN];
	char auxNombreDos[NOMBRE_LEN];
	Envio* auxUno;
	Envio* auxDos;

		auxUno = (Envio*)EmpUno;
		auxDos = (Envio*)EmpDos;
		if(auxUno != NULL && auxDos != NULL)
		{

			if(envio_getZona(auxUno,auxNombre)== 0 &&
			    envio_getZona(auxDos,auxNombreDos)== 0)
			{
				 if(strncmp(auxNombre,auxNombreDos,NOMBRE_LEN)>0)
				 {
					 retorno = -1;
				 }
				 else if(strncmp(auxNombre,auxNombreDos,NOMBRE_LEN) < 0)
				{
					retorno = 1;
				}
			}
		}
	return retorno;
}





/**
 * \brief Ordena por ID
 * \param EmpUno void* Puntero al Envio que se busca ordenar
 * \param EmpDos void* Puntero al Envio que se busca ordenar
 * \return int Retorna 0 (Si ambos parámetros son iguales)
 * 					   -1 (Si auxDos es mayor)
 * 					   1 (Si auxUno es mayor)
 */


int envio_ordenarID(void* auxUno, void* auxDos)
{
  int retorno = 0;
  int auxIntUno;
  int auxIntDos;

  Envio *auxiliarEnvio;
  Envio *auxEnvio;

  auxiliarEnvio = (Envio*) auxUno;
  auxEnvio = (Envio*) auxDos;

  envio_getId (auxiliarEnvio, &auxIntUno);
  envio_getId (auxEnvio, &auxIntDos);

  if (auxIntUno > auxIntDos)
    {
      retorno = 1;
    }
  else if (auxIntUno < auxIntDos)
    {
      retorno = -1;
    }
  return retorno;
}





/**
 * \brief Imprime los datos de un Envio
 * \param pElemento Puntero al Envio que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int envio_imprimir(Envio* this)
{
	int retorno=-1;
	char auxId[LEN_AUX];
	char auxNombre[LEN_AUX];
	char auxIdCamion[LEN_AUX];
	char auxZona[LEN_AUX];
	char auxKmRecorrido[LEN_AUX];
	char auxTipoEntrega[LEN_AUX];
	char auxCostoEnvio[LEN_AUX];



	if(this != NULL)
	{
		retorno = 0;
		envio_getIdTxt(this,auxId);
		envio_getNombre(this,auxNombre);
		envio_getIdCamionTxt(this,auxIdCamion);
		envio_getZona(this,auxZona);
		envio_getKmRecorridoTxt(this,auxKmRecorrido);
		envio_getTipoEntregaTxt(this,auxTipoEntrega);
		envio_getCostoEnvioTxt(this,auxCostoEnvio);

		printf("ID: %5s | %10s | Id de cammion: %s | Zona: %10s | Km recorridos: %5s | Tipo de entrega: %5s | Costo de envio: %1s\n",auxId,auxNombre,auxIdCamion,auxZona,auxKmRecorrido,auxTipoEntrega,auxCostoEnvio);
		printf("----------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}




int calcularCostos(Envio* pArrayListEnvio)
{
  int retorno = -1;
  int auxKmRecorrido;
  int auxTipoEntrega;
  int arrayTipo[3]={350,420,275};
  int auxCostoEnvio;
  Envio * auxEnvio;
  int i;

  if(pArrayListEnvio != NULL)
  	{
  		retorno=0;
  		for(i=0;i<ll_len(pArrayListEnvio);i++)
  		{
		    auxEnvio = (Envio*)ll_get(pArrayListEnvio,i);
		    envio_getKmRecorrido(auxEnvio,&auxKmRecorrido);
		    envio_getTipoEntrega(auxEnvio,&auxTipoEntrega);
		  if(auxKmRecorrido<50)
		    {
		    auxCostoEnvio= (auxKmRecorrido * 150)+arrayTipo[auxTipoEntrega];
		    envio_setCostoEnvio(auxEnvio, auxCostoEnvio);
		    }
		  else
		    {
              	    auxCostoEnvio = (auxKmRecorrido * 100)+arrayTipo[auxTipoEntrega];
		    envio_setCostoEnvio(auxEnvio, auxCostoEnvio);
		    }
		  ll_set(pArrayListEnvio, i, auxEnvio);
  		}
  	}
  return retorno;
}



void MayToMin(char string[])
{
	int i=0;
	int desp='A'-'a';
	for (i=0;string[i]!='\0';++i)
	{
		if(string[i]>='A'&&string[i]<='Z')
		{
			string[i]=string[i]-desp;
		}
	}
}








int filtrarPorCriterio(void* auxElemento,char* criterio)
{
	int retorno = -1;
	Envio* auxiliarElemento = (Envio*)auxElemento;
	char auxiliarNombre[NOMBRE_LEN];
	char aux[NOMBRE_LEN];


  strcpy(aux, criterio);
  MayToMin(aux);//buscar funcion que desestima mayuscula y minunscula para mejorar funcion

	if(auxElemento != NULL)
	{
	    envio_getZona(auxiliarElemento,auxiliarNombre);// este es el core del criterio
		  if(strncmp( auxiliarNombre, aux, sizeof(auxiliarNombre) )==0)
		{
			retorno = 1;
		}
		else
		{
		       retorno = 0;
		}
	}
	return retorno;
}




int seteaNombreArchivo(char*nombre)
{

//char auxiliarNombre[NOMBRE_LEN];
//strncpy(auxiliarNombre ,nombre,NOMBRE_LEN);


strcat( nombre, ".csv" );



}










