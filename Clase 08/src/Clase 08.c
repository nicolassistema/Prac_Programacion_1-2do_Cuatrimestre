/*
 ============================================================================
1) Se tiene el siguiente array de variables del tipo int
int numeros[12]={3,7,4,5,2,3,7,1,7,3,2,7};
Hacer una funcion que reciba el array y su tamaño, y lo imprima. Escribir un programa para probar la funcion.

2) Hacer una funcion que reciba el array del punto 1 y su tamaño, y cuente cuantas veces aparece el numero 7.
 Al terminar de contar, la funcion deberá imprimir por pantalla el valor contado. Escribir un programa para probar la funcion.


 3) Modificar la funcion del punto 2 para que NO imprima el valor contado, sino que lo devuelva por referencia
  (recibiendo la direccion de memoria de una variable donde escribirá el valor contado). Escribir un programa para probar la funcion.



  4) Dada la siguiente cadena de caracteres:
char nombre[8]={'p','e','p','e','1','2','3','\0'};
​
Hacer una funcion que reciba el array y su tamaño, y cuente cuantas veces aparece la letra 'e'.Al terminar de contar,
la funcion deberá imprimir por pantalla el valor contado. Escribir un programa para probar la funcion.

5) Hacer una funcion que reciba el array del punto 4, y verifique que las letras dentro del mismo esten
 en el rango de 'a' a 'z' o de 'A' a 'Z'. Si estan dentro del rango la funcion deberá devolver por valor(usando el return)
  un 0, de lo contrario devolverá -1.


  6) Realizar un programa para probar la funcion del punto 5, permitiendo que el usuario ingrese un texto y
   luego validando si lo ingresado es un nombre válido. Usar scanf para tomar el texto.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define SIZE_NUM 12
#define SIZE_LET 8
#define SIZE_NOMBRE 20

int utn_pruebaArray(int pResultado[],int  SIZE);
int utn_constarNumeroParticular(int pResultado[],int SIZE, int numero);
int utn_constarNumeroParticularPorReferencia (int pResultado[], int SIZE, int numeroContar,  int *numeroResultado);
int utn_constaLetraParticular (char pResultado[], char letra);
int utn_verificadorDeLeras (char pResultado[]);
int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int limite);

int main (void)
{
  setbuf (stdout, NULL);

  int numeros[SIZE_NUM] = { 3, 7, 4, 5, 2, 3, 7, 1, 7, 3, 2, 7 };
  char nombre[SIZE_LET]={'p','e','p','e','1','2','3','\0'};
  //char nombre[SIZE_LET]={'p','e','p','e','p','t','y','\0'};
  int resultado;
  char pNombre[SIZE_NOMBRE];

  printf ("\nEjercicio 01\n");
  utn_pruebaArray (&numeros, SIZE_NUM);
  printf ("\nEjercicio 02");
  utn_constarNumeroParticular (&numeros, SIZE_NUM, 5);
  printf ("\nEjercicio 03");
  utn_constarNumeroParticularPorReferencia (&numeros, SIZE_NUM, 5, &resultado);
  printf ("\nLa cantidad de veces del numero es: %d", resultado);
  printf ("\nEjercicio 04");
  utn_constaLetraParticular (&nombre, 'e');
  printf ("\nEjercicio 05");
  if(utn_verificadorDeLeras (&nombre)==0){
      printf("\nEsta dentro del rango");
  }else{
      printf("\nNO Esta dentro del rango");
  }
  printf ("\nEjercicio 06");
  utn_getNombre ("\nIngrese nombre: ", "\nEl formato del nombre es incorrecto.", pNombre, SIZE_NOMBRE);
  printf ("\nEl nombre ingresado es: %s", pNombre);

  return 0;
}




int utn_pruebaArray (int pResultado[], int SIZE)
{
  int i;
  int retorno = -1;

  if (pResultado != NULL && SIZE > 0)
    {
      retorno = 0;
      for (i = 0; i < SIZE; i++)
	{
	  printf (" %d", pResultado[i]);
	}
    }
  return retorno;
}




int utn_constarNumeroParticular (int pResultado[], int SIZE, int numero)
{

  int i;
  int retorno = -1;
  int contador = 0;

  if (pResultado != NULL && SIZE > 0)
    {
      retorno = 0;
      for (i = 0; i < SIZE; i++)
	{
	  if (pResultado[i] == numero)
	    {
	      contador++;
	    }
	}
      if (contador != 0)
	{
	  printf ("\nLa cantidad de %d que hay en el array, es de: %d", numero,contador);
	}
      else
	{
	  printf ("\nLa cantidad de %d que hay en el array es: 0", numero);
	}
    }
  return retorno;
}





int utn_constarNumeroParticularPorReferencia (int pResultado[], int SIZE, int numeroContar,  int *numeroResultado)
{

  int i;
  int retorno = -1;
  int contador = 0;

  if (pResultado != NULL && SIZE > 0)
    {
      retorno = 0;
      for (i = 0; i < SIZE; i++)
	{
	  if (pResultado[i] == numeroContar)
	    {
	      contador++;
	    }
	}
      *numeroResultado=contador;
    }
  return retorno;
}







int utn_constaLetraParticular (char pResultado[], char letra)
{

  int i;
  int retorno = -1;
  int contador = 0;

  if (pResultado != NULL && letra != ' ')
    {
      retorno = 0;
      for (i = 0; pResultado[i] != '\0'; i++)
	{
	  if (pResultado[i] == letra)
	    {
	      contador++;
	    }
	}
      if (contador != 0)
	{
	  printf ("\nLa cantidad de %c que hay en el array, es de: %d", letra,contador);
	}
      else
	{
	  printf ("\nLa cantidad de %c que hay en el array es: 0", letra);
	}
    }
  return retorno;
}




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




int utn_getNombre (char *mensaje, char *mensajeError, char *pNombre, int limite)
{

  char auxliar[limite];
  int retorno = -1;

  if (mensaje != NULL && mensajeError != NULL &&pNombre != NULL  && limite > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	  scanf ("%s", auxliar);

	  if (utn_verificadorDeLeras (auxliar) != -1)
	    {
	      strncpy (pNombre, auxliar, limite);
	      retorno = 0;
	    }
	  else
	    {
	      printf (mensajeError);

	    };
	}
      while (retorno != 0);
    }
  return retorno;
}






