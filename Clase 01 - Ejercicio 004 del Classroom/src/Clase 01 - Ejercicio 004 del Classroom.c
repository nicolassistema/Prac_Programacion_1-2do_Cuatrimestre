/*
 ============================================================================
 - Solicite al usuario 10 números
 - Calcule cuántos son negativos y cuantos son positivos
 - Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int respuestaScanf;
	int i;
	int negativos = 0;
	int positivos = 0;

	for (i = 0; i < 10; i++) {

		printf("\nPor favor ingresar el numero: ");
		fflush(stdin);
		respuestaScanf = scanf("%d", &numero);


		while (respuestaScanf == 0) {
			printf("\nPor favor reingresar el numero: ");
			fflush(stdin);
			respuestaScanf = scanf("%d", &numero);

		}

		if (numero < 0) {
			negativos++;
		} else if (numero > 0) {
			positivos++;
		} else {

		}

		if(i < 9){
		printf("\nQuedan ingresar (%d) numeros\n", (9 - i));
		}
	}

//Mensaje*****************************************************************
	if (negativos == 0) {
		printf("\nNo hay numeros negativos");
	} else {
		printf("\nLa cantidad de numeros negativos es: %d",  negativos);
	}

	if (positivos == 0) {
		printf("\nNo hay numeros positivos");
	}
	printf("\nLa cantidad de nuemros positivos es: %d" , positivos);
//************************************************************************

	return 0;
}
