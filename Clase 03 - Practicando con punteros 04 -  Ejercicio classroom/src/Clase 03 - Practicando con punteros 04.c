/*
 ============================================================================
Crear una función que permita ingresar un numero al usuario y lo retorne.
Crear una función que reciba el radio de un círculo y retorne su área.
Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule el área de un círculo cuyo radio es ingresado por el usuario.
 Documentar las funciones al estilo Doxygen.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Prototipo
int utn_Getfloat(char* mensaje1, char* mensaje2, float* pNumero, int reintentos);
float Area(int numero);



int main(void) {
	setbuf(stdout,NULL);

float numero1;
//int numero2;
//int resultado;
//reintentosint reintentos = 4;



if(utn_Getfloat("\nIngresar un numero: ", "El numero es incorrecto, ingresar numero: ", &numero1,3) == 0 ){
	printf("\nEl numero ingresao es: %.2f", numero1);
	printf("\nEl area del circulo es: %.2f", Area(numero1));
}else{

	printf("\nLA cantidad de reintentos supero el maximo permitido");
}





	return EXIT_SUCCESS;
}



int utn_Getfloat(char* mensaje, char* mensajeError, float* pNumero, int reintentos)
{
	float numero;
	int resultado;
	int retorno = -1;


	printf("\n%s", mensaje);
	fflush(stdin);
	resultado= scanf("%f", &numero);



	while(resultado == 0 && reintentos > 0)
		{
			reintentos--;
			printf("\n%s", mensajeError);
			fflush(stdin);
			resultado= scanf("%f", &numero);
		}

	if(resultado != 0)
		{
			*pNumero = numero;
			retorno = 0;
			return retorno;
		}
	return retorno;
}



float Area(int numero){

	float pi = 3.14;
	float resultado;

	resultado = pi*(numero * numero);

	return resultado;

}




