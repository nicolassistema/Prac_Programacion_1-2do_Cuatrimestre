/*
 ============================================================================
 Name        : Clase.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5


//Prototipo
int  ingresoNumeros(int* numero, int limite);

int main (void)
{


  setbuf (stdout, NULL);

  int miArray[TAM] = {1,2,3,4,5};


 int ingresoNumeros(miArray, TAM);



  return EXIT_SUCCESS;
}


int ingresoNumeros(int* miArray, int limite)
{

  int i;
//  int acumulador = 0;

/*
  for (i = 0; i < limite; i++)
      {
        printf ("\nIngresar numero: ");
        scanf ("%d", &miArray[i]);

        acumulador = acumulador + miArray[i];
      }
*/
    for (i = 0; i < limite; i++)
      {
        printf ("%d + ", miArray[i]);
      }

    //printf ("\nla suma de los numeros del array es: %d", acumulador);




  return 1;
}

