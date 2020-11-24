/*
 ============================================================================
 Name        : Probando_Trabajar_Con_Archivos.c
 Author      : Nicolas Letticugna - 1H
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "biblioteca.h"



int main(void) {
	setbuf(stdout,NULL);


FILE * sarasa;
int a = 998;
char * lala= "hola";
//float i;

//fp = fopen("archivo.txt","wb");
//sarasa = fopen("archivo.dat","wb");
sarasa = fopen("archivo.dat","wb");
if(sarasa!=NULL)
{

//	Alumno a;
//	a.id = 9;
//	a.altura = 1.75;
//	sprintf(a.nombre,"Nicolas Ezequiel");
//	i = 12345678;
//	fprintf(fp,"%f",i);
//fprintf(fp,"HOLA\n");




//fwrite(&a,sizeof(Alumno),1,fp);//escribe en el archivo binario

	fwrite(&lala,sizeof(char*),2,sarasa);//escribe en el archivo binario
//	fprintf(sarasa,"%d",a);



//fread(&a,sizeof(Alumno),1,fp);//Leo el archivo binario
//printf("id: %d  nombre: %s  altura: %.2f", a.id, a.nombre, a.altura); // muestro lo leido por temrinal




	fclose(sarasa);
}
else
{
	printf("HUBO UN PROBELMA CON EL ARCHIVO");
}









	return EXIT_SUCCESS;
}
