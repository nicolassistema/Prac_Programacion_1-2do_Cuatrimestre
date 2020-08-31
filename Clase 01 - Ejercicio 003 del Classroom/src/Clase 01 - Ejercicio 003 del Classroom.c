/*
 ============================================================================
 - Limpie la pantalla
 - Solicite dos valores numéricos al usuario distintos de cero *
 - Asigne a las variables numero1 y numero2 los valores obtenidos
 - Realice la resta de dichas variables
 - Muestre el resultado por pantalla
 - Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
 - Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero1;
	int numero2;
	int resultado;
	int resultadoScanF;

	printf("Por favor ingrese 1er numero: ");
	fflush(stdin);
	resultadoScanF = scanf("%d", &numero1);

	while (resultadoScanF == 0) {
		fflush(stdin);
		printf("Por favor reingrese 1er numero: ");
		resultadoScanF = scanf("%d", &numero1);
	}

	printf("Por favor ingrese 2do numero: ");
	fflush(stdin);
	resultadoScanF = scanf("%d", &numero2);
	while (resultadoScanF == 0) {
		fflush(stdin);
		printf("Por favor reingrese 2do numero: ");
		resultadoScanF = scanf("%d", &numero2);
	}

	//resultado
	resultado = numero1 - numero2;

	printf("\nEl resultado de la resta es %d: ", resultado);

	if (resultado > 0) {
		printf("\nEl resultado es positivo");
	} else if (resultado < 0) {
		printf("\nEl resultado es negativo");
	} else {
		return 0;
	}

	return 0;
}
