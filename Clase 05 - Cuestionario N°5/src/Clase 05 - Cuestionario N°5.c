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

int
main (void)
{


  setbuf (stdout, NULL);

  int array[5];
  int mayor;

  for (int i = 0; i < 5; i++)
    {
      printf ("ingrese: %d", i);
      scanf ("%d", &array[i]);

    }

  for (int i = 5; i > 0; i--)
    {
      if (array[i] > mayor)
	{
	  mayor=array[i];
	}
    }

  printf("el mayor es %d",mayor);

  return EXIT_SUCCESS;
}
