/*
 ============================================================================

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

#include "hardcodDataAlumno.h"
#include "ArrayAlumnos.h"
#include "nacionalidad.h"
#include "utn_input.h"


int main(void) {

setbuf(stdout,NULL);

int opcion;
int retorno;

Nacionalidad nacionalidadList[QTY_NACIONALIDAD];
Alumno alumnoList[QTY_ALUMNO];
initAlumno(alumnoList, QTY_ALUMNO);
//hardcodDatosAlumno(&alumnoList, QTY_ALUMNO_TEST);


  do
    {
      printf ("\n1-Alta\n"
	      "2-Modificacion\n"
	      "3-Baja\n"
	      "4-Informar\n"
	      "5-Salir\n");

      if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 5, 3) != -1)
	{
	  switch (opcion)
	    {
	    case 1:
	      printf ("\nALTA\n**********\n");

	      //addEmployee(alumnoList, QTY_EMPLOYE, 6, "NICOLAS","LETTICGUGNA",90000,8);

	      if (utn_searchFree(alumnoList, QTY_ALUMNO) == TRUE)
		{

		  if(chargeAlumno (alumnoList, QTY_ALUMNO) != 0)
		    {
		      printf ("\nSE TERMINARON LOS REINTENTOS\n");
		      system ("pause");
		      return EXIT_SUCCESS;
		    }

		}
	    // system ("pause");
	      break;
	    case 2:
	      printf ("\MODIFICACION\n**********\n");
	      updateAlumno (&alumnoList, QTY_ALUMNO);
	      break;
	    case 3:
	      printf ("\nBAJA\n**********\n");
	      prepareForDelete (&alumnoList,QTY_ALUMNO);
	      break;
	    case 4:
	      printf ("\nINFORMAR\n**********\n");
	     // sortAlumnos(alumnoList, QTY_ALUMNO, 1);
	      printAlumnos(alumnoList, QTY_ALUMNO);


	      break;
	    case 5:
	      printf ("\nSALIR\n**********\n");
	      break;
	    default:
	      break;
	    }
	}
      else
	{
	  printf ("\nSE TERMINARON LOS REINTENTOS\n");
	  system ("pause");
	  return EXIT_SUCCESS;
	}
    }
  while (opcion != 5);

	return EXIT_SUCCESS;
}
