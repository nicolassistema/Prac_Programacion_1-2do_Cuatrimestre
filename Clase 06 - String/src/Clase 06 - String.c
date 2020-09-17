
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "utn.h"
//
  int main(void) {
    setbuf (stdout, NULL);


   int pResultado;

/*
  char nombre[11]="juan";
  char apellido[15]="gomez";
  char aux[30];
  int salida;


  printf("Imprimiendo nombre: %s", nombre);
  salida=strnlen(nombre, sizeof(nombre)); //cuenta la cantidad de caracteres hasta el \0 y devuelve ese cantidad en la salida
  strncpy(aux, nombre, sizeof(aux));

  printf("\n Imprimiendo aux: %s", aux);
  printf("\n Imprimiendo salida de strnlen : %d", salida);

  strncat(nombre," Lala", sizeof(nombre));//concatena conviertiendo todo en un string
  printf("\n Imprimiendo nombre: %s", nombre);


  snprintf(aux, sizeof(aux), "%s dfdfdf %s", nombre, apellido );

*/


/*
    char str[] = "CompuTer ScienCe PoRTAl fOr geeKS";

    printf("Given string is: %s\n", str);

    printf("\nstring after converting to the uppercase is: %s", strupr(str));

*/
  while (1)
    {
      if (utn_getNumero ("\nIngrese un nuemro: ", "\nError al ingresar numero",
			 &pResultado, 5, 1000000, -2) == 0)
	{
	  printf ("\nEl numero es: %d", pResultado);
	}
    }







  	return EXIT_SUCCESS;
  }






























