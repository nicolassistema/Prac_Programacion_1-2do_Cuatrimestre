#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL); // consulta que hace
	int acumulador=0;
	int numero;
	int contador=0;
	float promedio;


	//for(numero = 0 ; numero != 999 ; numero++){

	while(1){
		printf("Ingrese un numero: ");
		fflush(stdin);
		scanf("\n %d",&numero);
		if(numero!=999){
			acumulador = acumulador + numero;
			contador++;
		}else{
			break;
		}
	}
	promedio = (float) acumulador / contador;
	printf("\n El promedio es: %.2f", promedio);

	return 0;
}
