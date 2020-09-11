/*
 *
 * 1) agregarle al codigo del martes (usuario que ingresa numeros y se guarda en array)
la funcion de ordenar
2) hacer la funcion para imprimir el array
3) imprimir el array antes de ordenar y despues.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje, char* mensajeError, int pResultado[],int reintentos,int maximo,int minimo);
void ordenarArray(int miArray[], int tam);
void imprimirArray(int miArray[],int tam);



int main(void) {
  setbuf (stdout, NULL);



int miArray[8] = {9,5,7,4,5,8,6,2};
int i;


/*
for (i = 0; i < 8; i++) {
//getInt("Ingrese un numero: ", "El numero es incorrecto.", miArray[i],5,10000,1);
    printf("Ingrese un numero: ");
    scanf("%d",miArray[i]);

}
*/

printf("\narray sin ordenar: ");
imprimirArray(miArray, 8);


printf("\narray ordenado: ");
ordenarArray( miArray, 8);
imprimirArray(miArray, 8);







	return EXIT_SUCCESS;
}



int getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d" , &bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



void imprimirArray(int miArray[],int tam){

  int i;
  for (i = 0; i < tam; ++i) {


      printf("[%d] ", miArray[i]);

  }


}





void ordenarArray (int  miArray[], int tam)
{
  int flagEstadoDesordenado = 1;
  int i;
  int aux;
  while (flagEstadoDesordenado == 1) // no esta ordenado
    {
      flagEstadoDesordenado = 0;
      // la pasadita
      for (i = 0; i < (tam - 1); i++)
	{
	  if (miArray[i] > miArray[i + 1])
	    {
	      // intercambiar (swap)
	      aux = miArray[i];
	      miArray[i] = miArray[i + 1];
	      miArray[i + 1] = aux;
	      flagEstadoDesordenado = 1;
	    }
	}
  }
}



