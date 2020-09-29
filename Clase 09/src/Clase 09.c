#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#define TAM 2
#define LONG_NOMBRE 50
#define OCUPADO 1


/*
typedef struct
{
  int dia;
  int mes;
  int anio;
}Fecha;


typedef struct
{
  char nombre[LONG_NOMBRE];
  char apellido[LONG_NOMBRE];
  long dni;
  Fecha fechaNacimiento;
  Fecha fechaAlta;
}Alumno;

*/

typedef struct
{
    int legajo;
    char nombre[25];
} eAlumno;


void mostrarListadoDeAlumnos(eAlumno listado[], int tam);
void mostrarUnAlumno(eAlumno miAlumno);
eAlumno cargarUnAlumno(void);
void cargarListadoDeAlumnos(eAlumno listado[], int tam);
void inicializar(eAlumno listado[], int tam);



int main(void) {
	setbuf(stdout,NULL);

	//eAlumno listaAlumnos[TAM] = {100,  "Maria"};
	eAlumno listaAlumnos[TAM];

inicializar(listaAlumnos,TAM);

	cargarListadoDeAlumnos(listaAlumnos,TAM);
	mostrarListadoDeAlumnos(listaAlumnos,TAM);


	return EXIT_SUCCESS;
}











void mostrarUnAlumno(eAlumno miAlumno)
{
    printf("%8d %20s\n", miAlumno.legajo,

                                           miAlumno.nombre
                                           );
}




void mostrarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }

}




eAlumno cargarUnAlumno(void)
{
    eAlumno miAlumno;
    printf("Ingrese legajo: ");
    fflush(stdin);
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);
    return miAlumno;
}


void cargarListadoDeAlumnos(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i] = cargarUnAlumno();
    }
}




void inicializar(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        listado[i].legajo = 0;
        strcpy(listado[i].nombre,"VACIO" );
    }
}



