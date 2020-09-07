/*
 ============================================================================
PEdir 2 numeros
funcion sumar
funcion restar
funcion multiplicar
funcion dividir

En caso de exito return 0, en caso de error retornar -1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Prototipo

float Suma(float numeroA, float numeroB, float *resultado);
float Resta(float numeroA, float numeroB, float *resultado);
float Multiplicar(float numeroA, float numeroB, float *resultado);
float Dividir(float numeroA, float numeroB, float *resultado);

int main(void) {


	setbuf(stdout, NULL);


	float numero1 = 6;
	float numero2 = 5;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicar;
	float resultadoDividir;
	int resultadoScanF;

	printf("Por favor ingrese 1er numero: ");
	fflush(stdin);
	resultadoScanF = scanf("%f", &numero1);

	while (resultadoScanF == 0) {
		fflush(stdin);
		printf("Por favor reingrese 1er numero: ");
		resultadoScanF = scanf("%f", &numero1);
	}


	printf("Por favor ingrese 2er numero: ");
	fflush(stdin);
	resultadoScanF = scanf("%f", &numero2);

	while (resultadoScanF == 0) {
		fflush(stdin);
		printf("Por favor reingrese 2er numero: ");
		resultadoScanF = scanf("%f", &numero2);
	}


	Suma(numero1, numero2,&resultadoSuma);
	Resta(numero1, numero2,&resultadoResta);
	Multiplicar(numero1, numero2,&resultadoMultiplicar);
	Dividir(numero1, numero2,&resultadoDividir);


//Mostrar por pantalla
printf("\nEl resultado de la suma es : %.2f", resultadoSuma );
printf("\nEl resultado de la resta es : %.2f", resultadoResta );
printf("\nEl resultado de la multiplicacion es : %.2f", resultadoMultiplicar );
printf("\nEl resultado de la division es : %.2f", resultadoDividir );



	return EXIT_SUCCESS;
}


//Implementacion

float Suma(float numeroA, float numeroB, float *resultado){
	*resultado = numeroA + numeroB;
	return 0;

}

float Multiplicar(float numeroA, float numeroB, float *resultado){
	*resultado = numeroA * numeroB;
	return 0;

}

float Resta(float numeroA, float numeroB, float *resultado){
	*resultado = numeroA - numeroB;
	return 0;

}

float Dividir(float numeroA, float numeroB, float *resultado){
	int error=-1;

	    if(numeroB!= 0.0){

	    	*resultado = numeroA / numeroB;

	    	error = 0;

	    }

		return error;
}

