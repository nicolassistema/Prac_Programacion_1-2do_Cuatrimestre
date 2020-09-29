#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "alumno.h"

#define QTY_ALUMNOS 5


int main(void)
{


  setbuf(stdout,NULL);
	int op;
	int indice;
	Alumno arrayAlumnos[5];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getInt("\n1-Alta\n2-Mostrar\n3-Salir","\nError",&op,2,8,1);
		switch(op)
		{
			case 1:
				if(utn_getInt("\nIndice?","\nError",&indice,2,QTY_ALUMNOS-1,0) == 0)
				// alumno_buscarLibre(arrayAlumnos,QTY_ALUMNOS)
				{
					//alumno_alta(arrayAlumnos,QTY_ALUMNOS,indice);

				}
				break;
			case 2:
				 //alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 3:
				//alumno_baja(arrayAlumnos,QTY_ALUMNOS,indice);
				break;
			case 4:
				//alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
				break;
			case 5:
				alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
				break;

		}
	}while(op != 8);
	return EXIT_SUCCESS;
}
