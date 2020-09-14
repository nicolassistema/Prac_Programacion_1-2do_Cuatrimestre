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
int ordenarArray(int miArray[], int tam);
void imprimirArray(int miArray[],int tam);



int main(void) {
  setbuf (stdout, NULL);



int miArray[8] = {99,20,77,50,41,100,58,33};
int contadorArrayOrdenado;



printf("\narray sin ordenar: ");
imprimirArray(miArray, 8);


printf("\narray ordenado: ");
contadorArrayOrdenado = ordenarArray( miArray, 8);
imprimirArray(miArray, 8);

printf("\nCantidad de veces que itero: %d", contadorArrayOrdenado);





//dsdsdsd



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





int ordenarArray (int miArray[], int SIZE)
{
  int flagSwap;
  int i;
  int contador = 0;
  int retorno = -1;
  int buffer;
  int nuevoLimite;

  if (miArray != NULL && SIZE >= 0)
    {
      nuevoLimite = SIZE - 1;
      do
	{
	  flagSwap = 0;
	  for (i = 0; i < nuevoLimite; i++)
	    {
	      contador++;
	      if (miArray[i] < miArray[i + 1])
		{
		  flagSwap = 1;
		  buffer = miArray[i];
		  miArray[i] = miArray[i + 1];
		  miArray[i + 1] = buffer;
		}
	    }
	  nuevoLimite--;
	}
      while (flagSwap);
      retorno = contador;
    }
  return retorno;
}



