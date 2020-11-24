/*
 ============================================================================
 Name        : Practica.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void func(int* a,int b );

void mostrar(char a,char *b);

int main(void) {

	setbuf(stdout, NULL);

/*

char cadena[50]= "1234567890abcdefghijkmnlopqrst";
char *p;
p = cadena;

printf("\n%c",cadena[10]);
printf("\n%c",*(p+10));
*/




char a= 'M';
int b = 14;
void(pFuncion)(char,int *);
pFuncion = mostrar;
pFuncion(a,&b);






/*
int num1= 65;
int num2= 50;
*/

//func(&num1, &num2);
//printf("%d %d", num1, num2);
//mostrar(&cadena);

/*
int * num1;
int num2;
int num3;


num2=15;
num1=&num2;
num3=*num1;
*/

/*
printf("\nNUM1: %p",num1);
printf("\nNUM2: %d",num2);
printf("\nNUM3: %d",num3);
*/







	return EXIT_SUCCESS;
}



void func(int* a,int b )
{
	*a +=43;
	b+= 18;
}


void mostrar(char a,char *b)
{
	printf("A: %c - B: %d \n",a,*b);
}


/*
void mostrar(char * cadena)
{

	while(*cadena != '\0')
	{
		printf("\n %c \n", *cadena);
		cadena ++;
	}
}
*/




