#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn_input.h"
#include "Controller.h"
#include <string.h>
#define LEN_AUX 128

static int idMaximoEncontrado(LinkedList* pArrayListEmployee, int* idMaximo);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListEmployee != NULL)
	{

		pArch = fopen(path, "rw");
		if(pArch != NULL && parser_EmployeeFromText(pArch,pArrayListEmployee)==0)
		{
			printf("El archivo se cargo exitosamente\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}
	return retorno;
}







/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE *pArch;
	if(path != NULL && pArrayListEmployee != NULL)
	{

		pArch = fopen(path, "rb");
		if(pArch != NULL && parser_EmployeeFromBinary(pArch,pArrayListEmployee)==0)
		{
			printf("El archivo se cargo con exito\n");
			retorno = 0;
			fclose(pArch);
		}
		else

			printf("El archivo no puede abrirse\n");
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pAuxiliarEmpleado;
	char auxNombre[LEN_AUX];
	int auxHsTrabajadas;
	int sueldo;
	int idAux;

	if(pArrayListEmployee != NULL)
	{
		if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre: \n", "Valor incorrecto\n",2)) &&
		   !(utn_getNumero(&auxHsTrabajadas,"Ingrese horas trabajadas: \n", "Valor incorrecto\n",1, 1000,2)) &&
		   !(utn_getNumero(&sueldo,"Ingrese sueldo: \n", "Valor incorrecto\n",1, 1000000,2)))
		{
			if(ll_len(pArrayListEmployee) == 0)
			{
				idAux = 0;
			}
			else
			{
				idMaximoEncontrado(pArrayListEmployee, &idAux);
				idAux = idAux + 1;
			}
			if(employee_newParametros(idAux,auxNombre,auxHsTrabajadas,sueldo) >= 0)
			{
				pAuxiliarEmpleado = (Employee*)employee_newParametros(idAux,auxNombre,auxHsTrabajadas,sueldo);
				ll_add(pArrayListEmployee,pAuxiliarEmpleado);

				retorno = 0;
				printf("Empleado creado correctamente en la ubicaci�n %d\n", idAux);
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmployee;
	int index;
	int auxID;
	int opcionAux;
	char auxNombre[LEN_AUX];
	int auxHsTrabajadas;
	int sueldo;


	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&auxID,"Ingrese el ID del empleado\n","ID inv�lido\n",0,ll_len(pArrayListEmployee), 2))
		{
			index = controller_buscarPorIdArray(pArrayListEmployee, auxID);
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,index);
			if(auxEmployee != NULL)
			{
				employee_imprimir(auxEmployee);


				if(!utn_getNumero(&opcionAux,"Confirma modificar el empleado? [0-NO/1-SI]\n","Opci�n inv�lida\n",0,1,2) && opcionAux == 1)
				{
					if(!(utn_getNombre(auxNombre, LEN_AUX,"Ingrese nombre\n", "Valor incorrecto\n",2)) &&
					   !(utn_getNumero(&auxHsTrabajadas,"Ingrese horas trabajadas\n", "Valor incorrecto\n",1, 1000,2)) &&
					   !(utn_getNumero(&sueldo,"Ingrese sueldo\n", "Valor incorrecto\n",1, 1000000,2)))
					{
					retorno = 0;
					employee_setNombre(auxEmployee, auxNombre);
					employee_setHorasTrabajadas(auxEmployee, auxHsTrabajadas);
					employee_setSueldo(auxEmployee,sueldo);
					}
				}
			}
		}
	}
	return retorno;
}
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxID;
	int opcionAux;
	int index;
	Employee* auxEmployee;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(!utn_getNumero(&auxID,"Ingrese el ID que desea eliminar\n","ID inv�lido\n",0,ll_len(pArrayListEmployee), 2))
		{
			index = controller_buscarPorIdArray(pArrayListEmployee, auxID);
			auxEmployee = (Employee*)ll_get(pArrayListEmployee,index);
			if(auxEmployee != NULL)
			{
				employee_imprimir(auxEmployee);

				if(!utn_getNumero(&opcionAux,"Confirma eliminar el empleado? [0-NO/1-SI]\n","Opci�n inv�lida\n",0,1,2) && opcionAux == 1)
				{
					retorno = 0;
					ll_remove(pArrayListEmployee,index);
					employee_delete(auxEmployee);
					printf("Empleado eliminado exitosamente\n");
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	Employee* bufferpEmployee;
	bufferpEmployee = employee_new();

	if(pArrayListEmployee != NULL)
	{
		retorno=0;

		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			bufferpEmployee = ll_get(pArrayListEmployee,i);
			employee_imprimir(bufferpEmployee);
		}
	}
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
		int retorno = -1;
		int opcion;
	 	int (*employee_pFordenarNombre)(void*, void*) = employee_ordenarNombre;


		if(pArrayListEmployee != NULL)
		{
			retorno=0;
			if(!utn_getNumero(&opcion,"Ingrese �rden [1-ascendente / 0-descendente]\n","Valor inv�lido\n",0,1,2))
			{
				printf("Espere, se est� cargando la lista\n");
				if(ll_sort(pArrayListEmployee,employee_pFordenarNombre,opcion)==0)
				{
					printf("Fue ordenado correctamente\n");
					retorno = 0;
					controller_ListEmployee(pArrayListEmployee);
				}
			}
		}

		return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	int auxiliarId;
	char auxiliarNombre[NOMBRE_LEN];
	int auxiliarHsTrab;
	int auxSueldo;
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL && path != NULL)
	{

		fpArchivo = fopen(path,"w");
		if(fpArchivo != NULL)
		{
			retorno=0;
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
				if(auxEmpleado != NULL)
				{
					if(!employee_getId(auxEmpleado,&auxiliarId) &&
					   !employee_getNombre(auxEmpleado,auxiliarNombre) &&
					   !employee_getHorasTrabajadas(auxEmpleado,&auxiliarHsTrab) &&
					   !employee_getSueldo(auxEmpleado,&auxSueldo))
					{
						fprintf(fpArchivo,"%d,%s,%d,%d\n",auxiliarId,auxiliarNombre,auxiliarHsTrab,auxSueldo);
					}
				}

			}
			fclose(fpArchivo);
			printf("Archivo guardado correctamente\n");

		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
		int i;
		FILE* fpArchivo;
		Employee* auxEmpleado;
		int contadorEmployee = 0;
		int len;

		if(pArrayListEmployee != NULL && path != NULL)
		{
			len = ll_len(pArrayListEmployee);

			fpArchivo = fopen(path,"wb");
			if(fpArchivo != NULL)
			{
				retorno=0;
				for(i=0;i<len;i++)
				{
					auxEmpleado = ll_get(pArrayListEmployee, i);
					if(fwrite(auxEmpleado, sizeof(Employee),1,fpArchivo)==1)
					{
						contadorEmployee++;
					}
				}
				fclose(fpArchivo);
				printf("Archivo cargado correctamente\n");
				printf("Se guardaron %d empleados\n",contadorEmployee);
			}
		}
		return retorno;
}

/**
 * \brief Busca un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista que ser� evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

static int idMaximoEncontrado(LinkedList* pArrayListEmployee, int* idMaximo)
{
	int retorno = -1;
	int i;
	int flag = 0;
	int idAuxMaximo;
	int idAuxiliar;
	Employee* auxiliarEmployee;
	Employee* auxEmplo;

	if(pArrayListEmployee != NULL && idMaximo != NULL)
	{
		retorno=0;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmplo = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmplo,&idAuxiliar);
			if(!flag)
			{
				auxiliarEmployee = ll_get(pArrayListEmployee,i);
				employee_getId(auxiliarEmployee,&idAuxMaximo);
				flag = 1;
			}
			else if(idAuxiliar > idAuxMaximo)
			{
				idAuxMaximo = idAuxiliar;
			}

		}
		*idMaximo = idAuxMaximo;

	}
	return retorno;
}



/**
 * \brief Busca un empleado por ID
 * \param pArrayListEmployee LinkedList* Puntero a la lista que ser� evaluada
 * \return int Devuelve la ubicacion donde se encuentra el ID(OK), (-1)ERROR, (-2)ID NO ENCONTRADO
 */

int controller_buscarPorIdArray(LinkedList* pArrayListEmployee, int id)
{
	int retorno=-1;
	int i;
	int idAux;
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL && id >= 0)
	{
		retorno = -2;
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee,i);
			employee_getId(auxEmpleado, &idAux);

			if( idAux == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
