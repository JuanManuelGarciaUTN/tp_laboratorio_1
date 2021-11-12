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


/// @brief Asigna un nueo valor a las horas trabajadas de un Employee
///
/// @param this Employee* - Employee a modificar las horas trabajadas
/// @param horasTrabajadas int - nuevo valor de horas trabajadas
/// @return 1[Se pudo asignar] - 0[Employee puntero a NULL]
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/// @brief Obtiene las horas trabajadas de un Employee
///
/// @param this Employee* - Employee a obtener las horas trabajadas
/// @param horasTrabajadas int* - puntero para devolver el valor de horas trabajadas
/// @return 1[Se pudo devolver] - 0[Employee puntero a NULL]
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/// @brief Asigna un nueo valor al sueldo de un Employee
///
/// @param this Employee* - Employee a modificar el sueldo
/// @param sueldo int - nuevo valor de sueldo
/// @return 1[Se pudo asignar] - 0[Employee puntero a NULL]
int employee_setSueldo(Employee* this,int sueldo);


/// @brief Obtiene el sueldo de un Employee
///
/// @param this Employee* - Employee a obtener el sueldo
/// @param sueldo int* - puntero para devolver el valor del sueldo
/// @return 1[Se pudo devolver] - 0[Employee puntero a NULL]
int employee_getSueldo(Employee* this,int* sueldo);


/// @brief Muestra en pantalla todos los datos del Employee
/// 		ID - Nombre - Horas trabajadas - Sueldo
/// 		y finalmente termina en un salto de linea
///
/// @param this Employee* - employee a mostrar
/// @return 1[Se pudo mostrar] - 0[Employee puntero a NULL]
int employee_printWithId(Employee* this);


/// @brief Muestra en pantalla los datos del Employee sin el ID
/// 		Nombre - Horas trabajadas - Sueldo
/// 		y finalmente termina en un salto de linea
///
/// @param this Employee* - employee a mostrar
/// @return 1[Se pudo mostrar] - 0[Employee puntero a NULL]
int employee_printWithoutId(Employee* this);


/// @brief Muestra en pantalla el ID y Nombre del Employee
/// 		ID - Nombre
/// 		y finalmente termina en un salto de linea
///
/// @param this Employee* - employee a mostrar
/// @return 1[Se pudo mostrar] - 0[Employee puntero a NULL]
int employee_printIdAndName(Employee* this);


/// @brief Compara dos empleados segun su nombre
///
/// @param pPrimerEmpleado void* - puntero a void del primer Employee a comparar
/// @param pSegundoEmpleado void* - puntero a void del segundo Employee a comparar
/// @return -1[El segundo employee esta despues alfabeticamente que el primero] - 0[Ambos employees tienen el mismo nombre] - 1[El primer employee esta despues alfabeticamente que el segundo]
int employee_sortByName(void* pPrimerEmpleado,void* pSegundoEmpleado);


/// @brief Compara dos empleados segun su ID
///
/// @param pPrimerEmpleado void* - puntero a void del primer Employee a comparar
/// @param pSegundoEmpleado void* - puntero a void del segundo Employee a comparar
/// @return -1[segundo Employee tiene un ID mayor] - 0[Ambos ID son iguales] - 1[primer Employee tiene un ID mayor]
int employee_sortById(void* pPrimerEmpleado,void* pSegundoEmpleado);


/// @brief Compara dos empleados segun su salario
///
/// @param pPrimerEmpleado void* - puntero a void del primer Employee a comparar
/// @param pSegundoEmpleado void* - puntero a void del segundo Employee a comparar
/// @return -1[segundo Employee tiene un salario mayor] - 0[Ambos salarios son iguales] - 1[primer Employee tiene un salario mayor]
int employee_sortBySalary(void* pPrimerEmpleado,void* pSegundoEmpleado);


/// @brief Compara dos empleados segun su salario y si son iguales, los compara por nombre
///
/// @param pPrimerEmpleado void* - puntero a void del primer Employee a comparar
/// @param pSegundoEmpleado void* - puntero a void del segundo Employee a comparar
/// @return -1[segundo Employee es mayor] - 0[Ambos son iguales] - 1[primer Employee es mayor]
int employee_sortBySalaryAndName(void* pPrimerEmpleado,void* pSegundoEmpleado);


/// @brief Compara dos empleados segun las horas trabajadas
///
/// @param pPrimerEmpleado void* - puntero a void del primer Employee a comparar
/// @param pSegundoEmpleado void* - puntero a void del segundo Employee a comparar
/// @return -1[segundo Employee tiene mas horas trabajadas] - 0[Ambos son iguales] - 1[primer Employee tiene mas horas trabajadas]
int employee_sortByWorkTime(void* pPrimerEmpleado,void* pSegundoEmpleado);


/// @brief Compara dos empleados segun las horas trabajadas y si son iguales, los compara por nombre
///
/// @param pPrimerEmpleado void* - puntero a void del primer Employee a comparar
/// @param pSegundoEmpleado void* - puntero a void del segundo Employee a comparar
/// @return -1[segundo Employee es mayor] - 0[Ambos son iguales] - 1[primer Employee es mayor]
int employee_sortByWorkTimeAndName(void* pPrimerEmpleado,void* pSegundoEmpleado);


/// @brief Pregunta al usuario que campo del employee desea modificar y permite modificarlo
///
/// @param this Employee* - employee a modificar
/// @return 1[se modifico algun campo] - 0[no se modifico nada o employee apunta a NULL]
int employee_edit(Employee* this);


/// @brief Permite modificar el nombre del employee
///
/// @param this Employee* - employee a modificar
/// @return 1[se modifico] - 0[no se modifico o employee apunta a NULL]
int employee_editName(Employee* this);


/// @brief Permite modificar el salario del employee
///
/// @param this Employee* - employee a modificar
/// @return 1[se modifico] - 0[no se modifico o employee apunta a NULL]
int employee_editSalary(Employee* this);


/// @brief Permite modificar las horas trabajadas del employee
///
/// @param this Employee* - employee a modificar
/// @return 1[se modifico] - 0[no se modifico o employee apunta a NULL]
int employee_editWorkTime(Employee* this);


/// @brief Le pregunta al usuario si desea sobrescribir los datos del employee
/// 		y le pide que ingrese la respuesta
///
/// @return 1[el usuario ingreso que SI] - 2[el usuario ingreso que NO]
int PreguntarSiDeseaSobrescribir();


#endif // employee_H_INCLUDED
