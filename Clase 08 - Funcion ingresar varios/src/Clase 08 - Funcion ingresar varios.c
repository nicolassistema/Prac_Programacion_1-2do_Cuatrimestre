#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define SIZE_NOMBRE 20
#define SIZE_NUMERO 20


static int utn_myGets (char *pEntrada, int longitud);
static int utn_verificadorAlfanumerico (char pResultado[]);
int utn_getAlfanumerico (char *mensaje, char *mensajeError, char *pNombre, int longitud);
int utn_getNumero (char *mensaje, char *mensajeError, char *pNumero, int longitud);
static int utn_myGetsEnteros (char *pEntrada, int longitud);
int validaEntero (char *numero);

int main(void) {

	  setbuf (stdout, NULL);


	  char pNombre[SIZE_NOMBRE];
	  char pNumero[SIZE_NUMERO];
	  int retorno;



/*
	  printf ("\nutn_getNombre");
	  retorno=utn_getAlfanumerico ("\nIngrese palabra alfanumerica: ", "\nEl formato del nombre es incorrecto.", pNombre, SIZE_NOMBRE);
	  printf ("\nEl nombre ingresado es: %s", pNombre);
	  printf("\nEl valor de retorno de la funcion es: %d",retorno);

*/

	  printf ("\nutn_getNumero");

	  retorno= utn_getNumero ("\nIngrese numero: ", "\nEl formato del numero es incorrecto.", pNumero, SIZE_NUMERO);

	 printf ("\nEl numero ingresado es: %s \n", pNumero);
	 printf ("\nRetorno de la funcion: %d \n", retorno);



	return EXIT_SUCCESS;
}



static int utn_myGetsEnteros (char *pEntrada, int longitud)
{
  int i;
  int retorno = -1;
  int retorno1 = -1;
  int retorno2 = -1;
  int retorno3 = -1;
  int retorno4 = -1;
  int retorno5 = -1;
  int contador = 0;
  int auxiliar;

  fflush (stdin);
  if (pEntrada != NULL && longitud > 0
      && fgets (pEntrada, longitud, stdin) == pEntrada && pEntrada[1] != '\0' && atoi (pEntrada) != 0)
    {
      retorno = 0;
    }
  for (i = 0; pEntrada[i - 1] != '\0'; i++)
    {
      if (pEntrada[i] == '-')
	{
	  contador++;
	}
      if (pEntrada[i - 2] >= '0' && pEntrada[i - 2] <= '9')
	{
	  retorno2 = 0;
	}
      else
	{
	  retorno2 = -1;
	}
    }
  if (pEntrada[0] != ' ')
    {
      retorno4 = 0;
    }

  for (i = 0; pEntrada[i] != '\0'; i++)
    {

      if (isspace (pEntrada[i - 1]) != 0)
	{
	  retorno5 = -1;
	  break;
	}
      else
	{
	  retorno5 = 0;

	}
    }

  if (pEntrada[strlen (pEntrada) - 1] != '-' && pEntrada[0] != '\0')
    {
      retorno3 = 0;
    }

  if (contador < 2)
    {
      retorno1 = 0;
    }


  if (retorno == 0 && retorno1 == 0 && retorno2 == 0 && retorno3 == 0 && retorno4 == 0 && retorno5 == 0)
    {
      return 0;
    }
  else
    {
      return -1;
    }
  return 0;
}



int utn_getNumero (char *mensaje, char *mensajeError, char *pNumero, int longitud)
{
  int retorno = -1;

  if (mensaje != NULL && mensajeError != NULL && pNumero != NULL && longitud > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	  //   scanf ("%s", pNumero); // --> para que acepte espacio , descomentar scanf y comentar " if (utn_myGets (pNumero, longitud) != -1)"
	  if (utn_myGetsEnteros (pNumero, longitud) != -1)
	    {
//	      if (utn_verificadorDeNumerosConSigno (pNumero, longitud) != -1)
//		{
		  retorno = 0;
//		}
//	      else
//		{
//		  printf (mensajeError);
//		}
	    }
	  else
	    {
	      printf (mensajeError);
	    }
	}
      while (retorno != 0);
    }
  return retorno;
}







static int utn_myGets (char *pEntrada, int longitud)
{

    if (pEntrada != NULL && longitud > 0 && fgets (pEntrada, longitud, stdin) == pEntrada && pEntrada[1] != '\0')
    {
      fflush (stdin);
      if (pEntrada[strlen (pEntrada) - 1] == '\n')

	{
	  pEntrada[strlen (pEntrada) - 1] = '\0';
	}
      return 0;
    }
  return -1;
}




static int utn_verificadorAlfanumerico (char pResultado[])
{
  int i;
  int retorno;

  if (pResultado != NULL)
    {
      for (i = 0; pResultado[i] != '\0'; i++)
	{
	  if ((pResultado[i] >= 'a' && pResultado[i] <= 'z') || (pResultado[i] >= 'A' && pResultado[i] <= 'Z') || (pResultado[i] >= '0' && pResultado[i] <= '9'))
	    {
	      retorno = 0;
	    }
	  else
	    {
	      retorno = -1;
	      break;
	    }
	}
    }
  return retorno;
}




int utn_getAlfanumerico (char *mensaje, char *mensajeError, char *pNombre, int longitud)
{
  char auxliar[longitud];
  int retorno = -1;

  if (mensaje != NULL && mensajeError != NULL && pNombre != NULL && longitud > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	//   scanf ("%s", auxliar); // --> para que acepte espacio , descomentar scanf y comentar " if (utn_myGets (auxliar, longitud) != -1)"
	  if (utn_myGets (auxliar, longitud) != -1)
	   {
	      if (utn_verificadorAlfanumerico (auxliar) != -1)
		{
		  strncpy (pNombre, auxliar, longitud);
		  retorno = 0;
		}
	      else
		{
		  printf (mensajeError);

		}
	    }else
	      {
		 printf (mensajeError);
	      }
	}
      while (retorno != 0);
    }
  return retorno;
}
