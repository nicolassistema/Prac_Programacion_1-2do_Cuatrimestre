#include <stdio.h>
#include <stdlib.h>


/*
 * utn_Getfloat : Pide al usuario un numero
 * pNumero: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * min: valor minimo valido (inclusive)
 * reintentos: cantidad de ingresos fallidos
 * mensaje: El mensaje que imprime para pedir un valor
 * mensajeError: mensaje que imprime si el rango no es valido
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

int utn_Getfloat(char* mensaje, char* mensajeError, float* pNumero, int reintentos)
{
	float numero;
	int resultado;
	int retorno = -1;

	printf("\n%s", mensaje);
	fflush(stdin);
	resultado= scanf("%f", &numero);

	while(resultado == 0 && reintentos > 0)
		{
			reintentos--;
			printf("\n%s", mensajeError);
			fflush(stdin);
			resultado= scanf("%f", &numero);
		}

	if(resultado != 0)
		{
			*pNumero = numero;
			retorno = 0;
			return retorno;
		}
	return retorno;
}

//=====================================================================================


/*
 * utn_GetInt : Pide al usuario un numero
 * pNumero: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * min: valor minimo valido (inclusive)
 * reintentos: cantidad de ingresos fallidos
 * mensaje: El mensaje que imprime para pedir un valor
 * mensajeError: mensaje que imprime si el rango no es valido
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */


int utn_GetInt(char* mensaje, char* mensajeError, int* pNumero, int reintentos)
{
	int numero;
	int resultado;
	int retorno = -1;

	printf("\n%s", mensaje);
	fflush(stdin);
	resultado= scanf("%d", &numero);

	while(resultado == 0 && reintentos > 0)
		{
			reintentos--;
			printf("\n%s", mensajeError);
			fflush(stdin);
			resultado= scanf("%d", &numero);
		}

	if(resultado != 0)
		{
			*pNumero = numero;
			retorno = 0;
			return retorno;
		}

	return retorno;
}

//=====================================================================================

/*
 * utn_GetChar : Pide al usuario un numero
 * pNumero: Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * min: valor minimo valido (inclusive)
 * reintentos: cantidad de ingresos fallidos
 * mensaje: El mensaje que imprime para pedir un valor
 * mensajeError: mensaje que imprime si el rango no es valido
 * Retorno: 0: si esta todo OK. -1: Si hubo un error
 */

//FALTA MEJORAR ESTA FUNCION YA QUE "char" es un tipo de dato generico para el tipo de entrada
int utn_GetChar(char* mensaje, char* mensajeError, char* pDato, int reintentos)
{
	char dato;
	int resultado;
	int retorno = -1;
if(mensaje != NULL && mensajeError != NULL && pDato != NULL )
{
	printf("\n%s", mensaje);
	fflush(stdin);
	resultado= scanf("%c", &dato);
	while(resultado == 0 && reintentos > 0)
		{
			reintentos--;
			printf("\n%s", mensajeError);
			fflush(stdin);
			resultado= scanf("%c", &dato);
		}

	if(resultado != 0)
		{
			*pDato = dato;
			retorno = 0;
			return retorno;
		}
}

	return retorno;
}


