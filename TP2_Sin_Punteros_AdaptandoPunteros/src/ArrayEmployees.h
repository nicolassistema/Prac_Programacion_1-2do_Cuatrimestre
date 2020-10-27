/*
 ============================================================================
 Name        : TP2.c
 Author      : Nicolas Letticugna - 1H
 ============================================================================
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TRUE 1
#define FALSE 0
#define LONG_NAME_EMPLOYE 51
#define QTY_EMPLOYE 1000

struct
{
int id;
char name[LONG_NAME_EMPLOYE];
char lastName[LONG_NAME_EMPLOYE];
float salary;
int sector;
int isEmpty;
}typedef Employee;



//FUNCIONES QUE SOLICITA EL TP
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char* name,char* lastName,float salary,int sector);
int findEmployeeById (Employee *list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);


//FUNCIONES QUE SOLICITA EL TP  PERO CON PUNTEROS
int p_InitEmployees(Employee* list[], int len);
Employee* p_Employee_newConParametros(int id, char* name,char* lastName,float salary,int sector);
int p_PrintEmployees(Employee* list[], int len);
int p_FindEmployeeById (Employee *list[], int len, int id);
void cliente_delete(Employee* aux);
int p_RemoveEmployee(Employee* list[], int len, int id);


//FUNCIONES COMPLEMENTARIAS A LA BIBLIOTECA
int chargeEmployee (Employee* list, int len);
int utn_searchFree (Employee* list, int len);
int updateEmployee (Employee* list, int len);
int  bufferToArray (Employee* list, Employee *auxEmployee, int len, int id);
int printForId  (Employee *list, int len, int id);
int arrayToBuffer(Employee *list,Employee *listBuffer, int len, int id);
void printForId2  (Employee* auxEmployee);
int deleteEmployee (Employee* list, int len);
float sumaTotal(Employee* list, int len);
float promedio(Employee* list, int len);
int cantidadSuperiorAlPromedio(Employee* list, int len);
int flagLimite(Employee* list, int len);
int prepareForDelete (Employee *list, int len);
int isEmpty(Employee* list, int limit, int index);




#endif /* ARRAYEMPLOYEES_H_ */
