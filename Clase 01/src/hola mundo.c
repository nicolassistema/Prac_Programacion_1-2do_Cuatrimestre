#include <stdio.h>
#include <stdlib.h>

int main(void) {

//Pedir 5 numeros enteros y mostrar el promedio
	setbuf(stdout, NULL); // consulta que hace

	int numero;
	int acumulador = 0;
	float promedio;
	int respuestaScan;
	int i;




	printf("\n Ingrese un numero: ");
			fflush(stdin);
			respuestaScan  = scanf("%d",&numero);
		//	printf("\n Ingrese un numero: %d", respuestaScan);

			for (i = 0; i < 5; i++) {

				printf("\n Ingrese un numero: ");
				fflush(stdin);
				respuestaScan  = scanf("%d",&numero);
				while (respuestaScan == 0){
					printf("Error, reingrese un numero: ");
					fflush(stdin);
					respuestaScan = scanf("%d",&numero);
				}
				acumulador +=numero;
			}

			promedio=(float)acumulador / i;
			printf("\n El priomedio es: %.2f", promedio);

	return EXIT_SUCCESS;
}
