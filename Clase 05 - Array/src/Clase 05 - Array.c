/*
 ============================================================================
 Name        : Clase.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int
main (void)
{
  setbuf (stdout, NULL);

  int numeros[TAM];
  int i;
  int acumulador = 0;

  for (i = 0; i < TAM; i++)
    {
      printf ("\nIngresar numero: ");
      scanf ("%d", &numeros[i]);

      acumulador = acumulador + numeros[i];
    }

  for (i = 0; i < TAM; i++)
    {
      printf ("%d + ", numeros[i]);
    }

  printf ("\nla suma de los numeros del array es: %d", acumulador);



  return EXIT_SUCCESS;
}
