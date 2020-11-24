/*
 * Envios.h
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */

#ifndef ENVIOS_H_
#define ENVIOS_H_

#define NOMBRE_LEN 128


typedef struct
{
    int idProducto;
    char nombreProducto[NOMBRE_LEN];
    int idCamion;
    char zona[NOMBRE_LEN];
    int kmRecorrido;
    int tipoEntrega;
    int costoEnvio;
}Envio;

typedef struct{
	char zonaDestinos[NOMBRE_LEN];
}Zona;


int envio_ordenarID(void* auxUno, void* auxDos);
int filtrarPorCriterio(void* auxElemento,char* criterio);
int seteaNombreArchivo(char*nombre);
int envio_ordenarNombre2(void* EmpUno, void* EmpDos);




Zona* zona_new(void);
int zona_setZonaDestinos(Zona *this, char* zona);
int zona_getZonaDestinos(Zona* this, char* zona);








#endif /* ENVIOS_H_ */
