/*
 ============================================================================
 Name        : Test.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Pedir 5 numeros


 - OP1 - Calcular Maximo
 - OP2 - Calcular Promedio
 - OP3 - Calcular Minimo
 -
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Prototipo
int
getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
	int maximo, int minimo);
float
promedio (int arrayInt[], int numero);

int
main (void)
{

  setbuf (stdout, NULL);
  int variableInt;
  char aMensaje[200];
  int arrayInt[5];
  int flagCargaCorrecta = 0;

  int j;
  int max;

  for (int i = 0; i < 5; i++)
    {
      sprintf (aMensaje, "\nNumero %d: ", i + 1);
      if (getInt (aMensaje, "Fuera de rango [0-1000]\n", &variableInt, 5, 1000,
		  0) != 0)
	{
	  printf ("GAME OVER");
	  flagCargaCorrecta = -1;
	  break;
	}
      else
	{
	  arrayInt[i] = variableInt;
	}
    }
  if (flagCargaCorrecta == 0)
    {

      printf ("El total es: %.2f", promedio (arrayInt, 5));

    }

  return EXIT_SUCCESS;
}

/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int
getInt (char *mensaje, char *mensajeError, int *pResultado, int reintentos,
	int maximo, int minimo)
{
  int retorno = -1;
  int bufferInt;
  int resultadoScanf;
  if (mensaje != NULL && mensajeError != NULL && pResultado != NULL
      && reintentos >= 0 && maximo >= minimo)
    {
      do
	{
	  printf ("%s", mensaje);
	  fflush (stdin); // fflush // __fpurge
	  resultadoScanf = scanf ("%d", &bufferInt);
	  if (resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
	    {
	      retorno = 0;
	      *pResultado = bufferInt;
	      break;
	    }
	  else
	    {
	      printf ("%s", mensajeError);
	      reintentos--;
	    }
	}
      while (reintentos >= 0);
    }
  return retorno;
}

float
promedio (int arrayInt[], int numero)
{
  int i;
  int acumludaros;
  float resultado;

  for (i = 0; i < numero; i++)
    {
      acumludaros = acumludaros + arrayInt[i];

    }

  resultado = (float) acumludaros / i;

  return resultado;

}
