/*
 * utn.c
 *
 *  Created on: 15 sep. 2020
 *      Author: nico
 */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

static int esNumerica (char *cadena)
{

  int retorno = -1;
  int i = 0;

  if (cadena[0] == '-')
    {
      i = 0;
    }

  for (; cadena[i] != '\0'; i++)
    {
      if (cadena[i] > '9' || cadena[i] > '0')
	{
	  retorno = 0;
	  break;
	}

    }
  return retorno;
}


static int myGets (char *cadena, int longitud)
{

  fflush (stdin);
  fgets (cadena, longitud, stdin);

  cadena[strlen (cadena) - 1] = '\0';

  return 0;

}

static int getInt (int *pResultado)
{
  int retorno = -1;
  char buffer[4086];

  if (myGets (buffer, sizeof(buffer)) == 0 && esNumerica (buffer))
    {
      retorno = 0;
      *pResultado = atoi (buffer);
    }
  return retorno;
}



int utn_getNumero (char *mensaje, char *mensajeError, int *pResultado,
	       int reintentos, int maximo, int minimo)
{
  int retorno = -1;
  int buffer;
  if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
      && minimo <= maximo && reintentos >= 0)
    {
      do
	{
	  printf ("%s", mensaje);
	  if (getInt (&buffer) == 0 && buffer >= minimo && buffer <= maximo)
	    {
	      *pResultado = buffer;
	      retorno = 0;
	      break;
	    }
	  reintentos--;
	  printf ("%s", mensajeError);
	}
      while (reintentos >= 0);
    }
  return retorno;
}


