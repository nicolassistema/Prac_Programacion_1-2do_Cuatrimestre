#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define TAM 40


int main(void) {

setbuf (stdout, NULL);
char pResultado[TAM];

if(utn_getNombre ("\nIngrese nombre: ", "\nEl formato del nombre es incorrecto.", pResultado,5, TAM) == -1 ){
    printf("\nSe terminaron los reintentosfallidos");
}else{
    printf("El nombre ingresado es: %s", pResultado );
}


return EXIT_SUCCESS;
}


