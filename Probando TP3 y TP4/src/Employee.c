/*
 * Employee.c
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"

#define LEN_AUX 128

static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);

/**
 * \brief Crea un espacio de memoria para un empleado
 * \param Void No recibe par�metros
 * \return Retorna un puntero al espacio de memoria donde ser� guardado el empleado
 *
 */

Employee* envio_new(void)
{
	Employee* auxiliarP = NULL;
	auxiliarP = (Employee*) malloc(sizeof(Employee));
	return auxiliarP;
}

/**
 * \brief Crea un empleado conociendo sus par�metros
 * \param idStr char* Puntero id
 * \param nombreStr char* Puntero al nombre
 * \param horasTrabajadasStr char* Puntero a horasTrabajadas
 * \param sueldo char* Puntero a sueldo
 * \return Retorna un puntero al espacio de memoria donde ser� guardado el empleado
 *
 */

Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
	Employee* this = NULL;
	this = envio_new();
	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
	{
		if(	employee_setNombre(this,nombreStr) == -1 ||
			employee_setIdTxt(this,idStr) == -1 ||
			employee_setHorasTrabajadasTxt(this,horasTrabajadasStr) == -1 ||
			employee_setSueldoTxt(this,sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}

/**
 * \brief Crea un empleado conociendo sus par�metros reales
 * \param id int Id con el que se cargar� el empleado
 * \param nombre char* Puntero al nombre
 * \param horasTrabajadasStr int  HorasTrabajadas con las que se cargar� el empleado
 * \param sueldo int Sueldo con el que se cargar� el empleado
 * \return Retorna un puntero al espacio de memoria donde ser� guardado el empleado
 *
 */

Employee* employee_newParametros(int id, char* nombre,int horasTrabajadasStr, int sueldo)
{
	Employee* this = NULL;
	this = envio_new();
	if(this != NULL && nombre != NULL && horasTrabajadasStr > 0 && sueldo > 0)

	{
		if(	employee_setId(this, id) == -1 ||
			employee_setNombre(this,nombre) == -1 ||
			employee_setHorasTrabajadas(this, horasTrabajadasStr) == -1 ||
			employee_setSueldo(this, sueldo) == -1)
		{
			employee_delete(this);
			this = NULL;
		}
	}
	return this;
}


/**
 * \brief Elimina el empleado pasado por par�metro
 * \param this Employee* Puntero al empleado a eliminar
 * \return void
 */


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/**
 * \brief Cambia el nombre del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado a modificar
 * \param nombre char* Puntero al nombre que se cambiar�
 * \return int (-1) ERROR y (0) OK
 */

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

/**
 * \brief Se obtiene el nombre del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

/**
 * \brief Se cambiar� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id int ID que se cargar� al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}

/**
 * \brief Se cambiar� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se cargar� al empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		if(esNumerica(id,10))
		{
			retorno = 0;
			this->id = atoi(id);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int envio_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}


/**
 * \brief Se obtendr� el id del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param id char* Puntero al ID que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_getIdTxt(Employee* this,char* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);
	}
	return retorno;
}

/**
 * \brief Se cambiar�n las horas trabajadas del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int Cantidad de horas trabajadas que se cargar� en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas >= 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}


/**
 * \brief Se cambiar�n las horas trabajadas del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas char* Puntero a la cantidad de horas trabajadas que se cargar� en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		if(esNumerica(horasTrabajadas,10))
		{
			retorno = 0;
			this->horasTrabajadas = atoi(horasTrabajadas);
		}
	}
	return retorno;
}

/**
 * \brief Se obtendr�n las horas trabajadas del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int* Puntero a la cantidad de horas trabajadas que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/**
 * \brief Se obtendr�n las horas trabajadas del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas char* Puntero a la cantidad de horas trabajadas que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */


int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		sprintf(horasTrabajadas,"%d",this->horasTrabajadas);
	}
	return retorno;
}


/**
 * \brief Se cambiar� el sueldo del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param sueldo int Sueldo que se cargar� en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}


/**
 * \brief Se cambiar� el sueldo del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param sueldo char* Puntero al sueldo que se cargar� en el empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_setSueldoTxt(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		if(esNumerica(sueldo,100000))
		{
			retorno = 0;
			this->sueldo = atoi(sueldo);
		}
	}
	return retorno;
}


/**
 * \brief Se obtendr� el sueldo del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param sueldo int* Puntero al sueldo que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}


/**
 * \brief Se obtendr� el sueldo del empleado pasado por par�metro
 * \param this Employee* Puntero al empleado
 * \param sueldo char* Puntero al sueldo que se obtendr� del empleado mencionado
 * \return int (-1) ERROR y (0) OK
 */

int employee_getSueldoTxt(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		sprintf(sueldo,"%d",this->sueldo);
	}
	return retorno;
}
/**********************************************************************/

/**
 * \brief Verifica si la cadena ingresada es un nombre valido, teniendo en cuenta guines y espacios
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '-' && cadena[i] != ' ' &&(cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int employee_imprimir(Employee* this)
{
	int retorno=-1;
	char idAux[LEN_AUX];
	char hsTrabajadas[LEN_AUX];
	char sueldoAux[LEN_AUX];
	char nombreAux[NOMBRE_LEN];

	if(this != NULL)
	{
		retorno = 0;
		employee_getIdTxt(this,idAux);
		employee_getNombre(this,nombreAux);
		employee_getSueldoTxt(this,sueldoAux);
		employee_getHorasTrabajadasTxt(this,hsTrabajadas);

		printf("ID: %10s - %10s - Hs.Trabajadas: %10s - Sueldo %10s\n",idAux
																	   ,nombreAux
																	   ,hsTrabajadas
																	   ,sueldoAux);
		retorno = 0;
	}
	return retorno;
}



/**
 * \brief Imprime los datos de un Empleado
 * \param pElemento Puntero al Empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int employee_imprimirGral(void* this)
{
	int retorno=-1;
	Employee* auxElemento = (Employee*) this;
	char idAux[LEN_AUX];
	char hsTrabajadas[LEN_AUX];
	char sueldoAux[LEN_AUX];
	char nombreAux[NOMBRE_LEN];

	if(this != NULL)
	{
		retorno = 0;
		employee_getIdTxt(auxElemento,idAux);
		employee_getNombre(auxElemento,nombreAux);
		employee_getSueldoTxt(auxElemento,sueldoAux);
		employee_getHorasTrabajadasTxt(auxElemento,hsTrabajadas);

		printf("ID: %10s - %10s - Hs.Trabajadas: %10s - Sueldo %10s\n",idAux
																	   ,nombreAux
																	   ,hsTrabajadas
																	   ,sueldoAux);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Ordena por nombre
 * \param EmpUno void* Puntero al Empleado que se busca ordenar
 * \param EmpDos void* Puntero al Empleado que se busca ordenar
 * \return int Retorna 0 (Si ambos par�metros son iguales)
 * 					   1 (Si EmpDos es mayor)
 * 					   -1 (Si EmpUno es mayor)
 */


int employee_ordenarNombre(void* EmpUno, void* EmpDos)
{
	int retorno = 0;
	char auxNombre[NOMBRE_LEN];
	char auxNombreDos[NOMBRE_LEN];
	Employee* auxUno;
	Employee* auxDos;

		auxUno = (Employee*)EmpUno;
		auxDos = (Employee*)EmpDos;
		if(auxUno != NULL && auxDos != NULL)
		{

			if(employee_getNombre(auxUno,auxNombre)== 0 &&
				employee_getNombre(auxDos,auxNombreDos)== 0)
			{
				 if(strncmp(auxNombre,auxNombreDos,NOMBRE_LEN)>0)
				 {
					 retorno = -1;
				 }
				 else if(strncmp(auxNombre,auxNombreDos,NOMBRE_LEN) < 0)
				{
					retorno = 1;
				}
			}
		}
	return retorno;
}


/**
 * \brief Ordena por ID
 * \param EmpUno void* Puntero al Empleado que se busca ordenar
 * \param EmpDos void* Puntero al Empleado que se busca ordenar
 * \return int Retorna 0 (Si ambos par�metros son iguales)
 * 					   -1 (Si auxDos es mayor)
 * 					   1 (Si auxUno es mayor)
 */


int employee_ordenarID(void* auxUno, void* auxDos)
{
	int retorno = 0;
	int auxIntUno;
	int auxIntDos;

	Employee* auxiliarEmpl;
	Employee* auxEmple;

	auxiliarEmpl = (Employee*) auxUno;
	auxEmple = (Employee*) auxDos;

	envio_getId(auxiliarEmpl,&auxIntUno);
	envio_getId(auxEmple,&auxIntDos);

	if(auxIntUno>auxIntDos)
	{
		retorno = 1;
	}
	else if(auxIntUno<auxIntDos)
	{
		retorno = -1;
	}
	return retorno;
}

/**
 * \brief Calcula Total
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    1(OK)
 */

int calcularEmpleadosLiquidacion(void* auxElemento)
{
	int retorno = -1;
	Employee* auxiliarElemento = (Employee*)auxElemento;
	int auxSueldo;

	if(auxiliarElemento != NULL && !employee_getSueldo(auxiliarElemento,&auxSueldo))
	{
		retorno = auxSueldo;
	}

	return retorno;
}


/**
 * \brief Informa horas bajo criterio
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    1(OK CRITERO)
 * 					    0(NO CRITERIO)
 */


int calcularElementosHsMayoresA(void* auxElemento)
{
	int retorno = -1;
	Employee* auxiliarElemento = (Employee*)auxElemento;
	int hsTrab;

	if(auxElemento != NULL)
	{
		employee_getHorasTrabajadas(auxiliarElemento,&hsTrab);
		if(hsTrab >= 300)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}


/**
 * \brief Compara sueldos Total
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    auxValor(OK)
 */

int compararSueldoPorValor(void* auxElemento, int valor,int index)
{
	Employee* auxiliarElemento = (Employee*)auxElemento;
	int auxSueldo;

	if(auxiliarElemento != NULL && valor >= 0 && index >= 0)
	{
		employee_getSueldo(auxiliarElemento,&auxSueldo);
		if(index==0)
		{
			valor = auxSueldo;
		}
		else if (auxSueldo > valor)
		{
			valor = auxSueldo;
		}
	}
	return valor;
}


/**
 * \brief Informa horas bajo criterio
 * \param EmpUno void* Puntero al elemento que se busca clasificar
 * \return int Retorna -1 (ERROR)
 * 					    1(OK CRITERO)
 * 					    0(NO CRITERIO)
 */


int calcularElementos(void* auxElemento)
{
	int retorno = -1;

	if(auxElemento != NULL)
	{
		retorno = 1;
	}	else
	{
		retorno = 0;
	}
	return retorno;
}
