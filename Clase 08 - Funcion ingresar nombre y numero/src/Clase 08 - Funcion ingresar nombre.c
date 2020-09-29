#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define SIZE_NOMBRE 20
#define SIZE_NUMERO 20



int utn_verificadorDeLeras (char pResultado[]);
int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int longitud);
static int utn_verificadorDeNumeros (char *pResultado, int longitud);
static int utn_myGets (char *cadena, int longitud);
int utn_getNumero (char *mensaje, char *mensajeError, char *pNumero, int longitud);

//int utn_getNumero (char *mensaje, char *mensajeError, int *pResultado, int reintentos, int maximo, int minimo);

int main (void)
{
  setbuf (stdout, NULL);

  char pNombre[SIZE_NOMBRE];
  char pNumero[SIZE_NUMERO];
  int retorno;


  printf ("\nutn_getNombre");
  retorno=utn_getNombre ("\nIngrese nombre: ", "\nEl formato del nombre es incorrecto.", pNombre, SIZE_NOMBRE);
  printf ("\nEl nombre ingresado es: %s", pNombre);
  printf("\nEl valor de retorno de la funcion es: %d",retorno);









  printf ("\nutn_getNumero");

  retorno= utn_getNumero ("\nIngrese numero: ", "\nEl formato del numero es incorrecto.", pNumero, SIZE_NUMERO);

 printf ("\nEl numer ingresado es: %s \n", pNumero);
 printf ("\nRetorno de la funcion: %d \n", retorno);



  return 0;
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




static int utn_verificadorDeNumeros (char *pResultado, int longitud)
{
  int i;
  int retorno;

  if (pResultado != NULL && longitud >0)
    {
      for (i = 0; pResultado[i] != '\0'; i++)
	{
	  if (pResultado[i] >= '0' && pResultado[i] <= '9')
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



int utn_getNumero (char *mensaje, char *mensajeError, char *pNumero, int longitud)
{
  int retorno = -1;

  if (mensaje != NULL && mensajeError != NULL && pNumero != NULL && longitud > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	  if (utn_myGets (pNumero, longitud) != -1)
	    {
	      if (utn_verificadorDeNumeros (pNumero, longitud) != -1)
		{
		  retorno = 0;
		}
	      else
		{
		  printf (mensajeError);
		}
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



//-----------------------------------------------------------------------------------------

int utn_verificadorDeLeras (char pResultado[])
{
  int i;
  int retorno;

  if (pResultado != NULL)
    {
      for (i = 0; pResultado[i] != '\0'; i++)
	{
	  if((pResultado[i] < 'a' || pResultado[i] > 'z') && (pResultado[i] < 'A' || pResultado[i] > 'Z'))
	    {
	      retorno = -1;
	      break;
	    }
	  else
	    {
	      retorno = 0;
	    }
	}
    }
  return retorno;
}


int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int longitud)
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
	      if (utn_verificadorDeLeras (auxliar) != -1)
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










