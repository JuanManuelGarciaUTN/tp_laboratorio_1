#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include"inputs.h"


#define LONGITUD_NOMBRE 128

typedef struct
{
    int id;
    char nombre[LONGITUD_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr); //Preguntale a Ger, porque le falta sueldo
void employee_delete(Employee* this); //Le cambie los parametros

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_printWithId(Employee* this);
int employee_printWithoutId(Employee* this);

int employee_sortByName(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortById(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortBySalary(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortBySalaryAndName(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortByWorkTime(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortByWorkTimeAndName(void* pPrimerEmpleado,void* pSegundoEmpleado);


#endif // employee_H_INCLUDED
