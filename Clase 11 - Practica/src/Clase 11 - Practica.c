/*
 ============================================================================
 Name        : Clase.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn.h"
#include "alumno.h"
#include "nacionalidad.h"



int main(void) {
  setbuf(stdout,NULL);

	int opcion;
	int indice;
	int indice2;
	int idBuscar;

	Alumno arrayAlumno[SIZESTRUCT_ALUMNO];
	if (alumno_init(arrayAlumno, SIZESTRUCT_ALUMNO) == 0){
		do {
			 utn_getnumero(&opcion, "\n 1-Alta \n 2- Imprimir \n 3-Baja  \n  4-Modificar \n 5-Imprimir indice \n 6- buscarLibre \n  7- SALIR \n ", "serror",1,7,2);
			 switch (opcion){
			 case 1:
				alumno_alta(arrayAlumno,SIZESTRUCT_ALUMNO);

				 break;

			 case 2:
				alumno_imprimir(arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;

			 case 3:
				 alumno_baja(arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;
			 case 4:
				utn_getnumero (&idBuscar, "Que ID Desea buscar","ERRROR",0,50,2);
				alumno_buscarIndice (arrayAlumno,SIZESTRUCT_ALUMNO,idBuscar,&indice2);
				printf("%d",indice2);
				// alumno_modificar (arrayAlumno,SIZESTRUCT_ALUMNO);
				 break;
			 case 5:
				 utn_getnumero(&indice, "Ingrese indice", "seerror",0,4,2);
				 alumno_imprimirIndice(arrayAlumno,SIZESTRUCT_ALUMNO,indice);
				 break;
			 case 6:
				 indice = alumno_buscarLibre(arrayAlumno,SIZESTRUCT_ALUMNO);
				if (indice != -1){
					printf("El indice libre es: %d", indice);
				} else {
					printf("No hay indices libres :( ");
				}
				break;
			 }
		 }while (opcion != 7);


	}


	return EXIT_SUCCESS;
}
