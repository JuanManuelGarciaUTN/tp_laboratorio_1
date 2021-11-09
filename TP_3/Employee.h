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

/// @brief Constructor de Employee sin parametros
///
/// @return NULL[No pudo reservar memoria para un Employee] - Direccion de Memoria Nuevo Employee[Se pudo reservar memoria para un Employee]
Employee* employee_new();


/// @brief Constructor de Employee con parametros
///
/// @param idStr char* id del Employee
/// @param nombreStr char* nombre del Employee
/// @param horasTrabajadasStr char* horas trabajadas del Employee
/// @param sueldoStr char* sueldo del Employee
/// @return NULL[No pudo reservar memoria para un Employee] - Direccion de Memoria Nuevo Employee[Se pudo reservar memoria para un Employee]
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);



/// @brief Destructor de Employee
///
/// @param this - Employee a destruir
void employee_delete(Employee* this);


/// @brief Asigna un nuevo ID a un Employee
///
/// @param this Employee* - Employee a asignar un nuevo ID
/// @param id int - ID a asignar
/// @return 1[Se pudo asignar] - 0[Employee puntero a NULL]
int employee_setId(Employee* this,int id);


/// @brief Retorna el ID de un Employee
///
/// @param this Employee* - Employee a devolver el ID
/// @param id int* - puntero a int para devolver el ID
/// @return 1[Se pudo devolver] - 0[Employee puntero a NULL]
int employee_getId(Employee* this,int* id);


/// @brief Asigna un nuevo nombre a un Employee
///
/// @param this Employee* - Employee a asignar un nuevo nombre
/// @param nombre char* - nombre a asignar
/// @return 1[Se pudo asignar] - 0[Employee puntero a NULL]
int employee_setNombre(Employee* this,char* nombre);


/// @brief Retorna el nombre de un Employee
///
/// @param this Employee* - Employee a devolver el nombre
/// @param nombre char* - puntero a char para devolver el nombre
/// @return 1[Se pudo devolver] - 0[Employee puntero a NULL]
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_printWithId(Employee* this);
int employee_printWithoutId(Employee* this);
int employee_printIdAndName(Employee* this);

int employee_sortByName(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortById(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortBySalary(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortBySalaryAndName(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortByWorkTime(void* pPrimerEmpleado,void* pSegundoEmpleado);
int employee_sortByWorkTimeAndName(void* pPrimerEmpleado,void* pSegundoEmpleado);


int employee_edit(Employee* this);
int employee_editName(Employee* this);
int employee_editSalary(Employee* this);
int employee_editWorkTime(Employee* this);
int PreguntarSiDeseaSobrescribir();


#endif // employee_H_INCLUDED
