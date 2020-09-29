
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

/**
 * \brief Realiza el alta de un alumno solo si el indice corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_alta(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(	arrayAlumnos != NULL && limite > 0 &&
		indice >=0 &&
		indice < limite &&
		arrayAlumnos[indice].isEmpty == TRUE)
	{
		if(	utn_getInt("\nLegajo?","\nError",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
			utn_getNombre("\n Nombre?","\nError",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			arrayAlumnos[indice] = bufferAlumno;
			arrayAlumnos[indice].isEmpty = FALSE;
			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_modificar(Alumno arrayAlumnos[],int limite,int indice)
{
	int retorno = -1;
	return retorno;
}



/**
 * \brief Imprime los alumnos cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Legajo: %d",pArrayAlumnos[i].nombre,pArrayAlumnos[i].legajo);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_initArray(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}






int alumno_printById(Alumno* pArray, int limit, int index)
{
		int retorno = -1;
		if(pArray != NULL && limit > 0 && index < limit)
		{
			if(pArray[index].isEmpty == FALSE)
			{
				printf("Nombre: %s - Legajo: %d\n",pArray[index].nombre, pArray[index].legajo);
				retorno = 0;
			}
		}
		return retorno;
}




int isEmpty(Alumno* pArray, int limit, int index)
{
		int retorno = -1;
		if(pArray != NULL && limit > 0 && index < limit)
		{
			if(pArray[index].isEmpty == -1)
			{
			       printf("El indice del item vacio es: %i",index );
			retorno = 0;
			}
		}
		return retorno;
}





int
alumno_alta (Alumno *pArrayAlumnos, int limite)
{
  int retorno = -1;
  int indice;
  Alumno bufferAlumno;
  if (pArrayAlumnos != NULL && limite > 0)
    {
      if (isEmpty (arrayAlumnos, limite, indice) == 0)
	{
	  if (utn_getnumero (&bufferAlumno.legajo, "\n Legajo?", "error", MIN,
			     MAX, 2) == 0
	      && utn_getNombre (bufferAlumno.nombre, MAX_NOMBRE,
				" \n Ingrese nombre", "Nombre invalido. ", 3)
		  == 0)
	    {
	      pArrayAlumnos[indice] = bufferAlumno;
	      pArrayAlumnos[indice].isEmpty = FALSE;
	      pArrayAlumnos[indice].legajo =
		  idIncrementalConVariableEstatica ();

	    }
	  else
	    {
	      printf ("horror");
	    }
	}
      else
	{
	  printf (" \n No quedan espacios libres");
	}
    }
  return retorno;
}


int idIncremental(void)
{
    static int id = 0;
    id++;
    return id;
}
