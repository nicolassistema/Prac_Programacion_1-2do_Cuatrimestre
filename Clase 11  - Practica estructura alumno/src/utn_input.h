/*
 * utn_input.h
 *
 *  Created on: 23 sep. 2020
 *      Author: nico
 */

#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_

static int utn_getInt(int* pResultado); //utilizada en utn_getNumero
static int utn_verificadorDeNumeros(char* cadena,int limite);//utilizada en utn_getInt
int utn_getNumero(char* mensaje,char* mensajeError,int* pResultado,int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_myGets(char* cadena, int longitud);
static int utn_getFloat(float* pFloat);// utilizada en utn_getNumeroFloat
static int utn_esFlotante(char* array,int limite); // utilizada en utn_getFloat
static int utn_getString(char* pResultado,int longitud); //utilizada en utn_getCadena
static int utn_esSoloLetras(char* pResultado,int limite); //utilizada en utn_getString
static int utn_esAlfaNumerica(char* pResultado);
static int utn_esTelefono(char str[]);
int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int longitud, int reintentos);
//int utn_getAceptaRechaza(char* mensaje, char* mensajeError, char yes, char no, int reintentos);
int utn_getAceptaRechaza (char *mensaje, char *mensajeError, char yes, char no);
int contadorEstatico(void);

#endif /* UTN_INPUT_H_ */
