/*
 * ArrayEmployees.h
 *
 *  Created on: 12 oct. 2021
 *      Author: juanm
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define UP 1
#define DOWN 0

//Estructura Empleado

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;


//Funciones Pedidas

/// @brief Para indicar que todas las posiciones dentro del array están vacías, esta
/// 		funcion pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param len int longitud del array
/// @return int Return (-1) si hubo Error[longitud invalida o puntero a NULL] - (0) si salio todo bien
int initEmployees(Employee* list, int len);


/// @brief Agrega a un array existente de employees (empleados) los valores recibidos como parametro
/// 		en la primer posicion libre.
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param len int longitud del array
/// @param id int ID del empleado
/// @param name[] char Nombre del empleado
/// @param lastName[] char Apellido del empleado
/// @param salary float Salario del empleado
/// @param sector int Numero del sector del empleado
/// @return int Return (-1) si hubo Error [longitud invalida, puntero a NULL o no habia una posicion vacía] - (0) si salio todo bien
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/// @brief Busca un empleado recibiendo como parámetro de búsqueda su ID
/// 		 y retorna su indice en dentro del array.
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param len int longitud del array
/// @param id int ID del empleado
/// @return int Return el indice de la posicion del empleado o (-1) si [longitud invalida, puntero a NULL o no se pudo encontrar el empleado]
int findEmployeeById(Employee* list, int len,int id);


/// @brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param len int longitud del array
/// @param id int ID del empleado
/// @return int Return (-1) si hubo Error [longitud invalida, puntero a NULL o no pudo encontrar el empleado] - (0) si salio todo bien
int removeEmployee(Employee* list, int len, int id);


/// @brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param len int longitud del array
/// @param order int [1] indica ascendente(UP) - [0] indica descendente(DOWN)
/// @return int Return (-1) si hubo Error[longitud invalida o puntero a NULL] - (0) si salio todo bien
int sortEmployees(Employee* list, int len, int order);


/// @brief Imprime el array de empleados de forma encolumnada
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param length int longitud del array
/// @return int Return (-1) si hubo Error[longitud invalida o puntero a NULL] - (0) si salio todo bien
int printEmployees(Employee* list, int length);


//Funciones Propias

/// @brief Imprime la suma de todos los salarios, el salario promedio y la cantidad de empleados cuyo salario es superior al promedio
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param length int longitud del array
/// @return int Return (-1) si hubo Error[longitud invalida o puntero a NULL] - (0) si salio todo bien
int reportEmployeesAverageSalary(Employee* list, int length);


/// @brief Calcula el promedio y la suma total de los salario de todos los empledos
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param length int longitud del array
/// @param average float* puntero a float para devolver el salario promedio
/// @param total float* puntero a float para devolver la suma de todos los salarios
/// @return int Return (-1) si hubo Error[longitud invalida, puntero a NULL o no hay empleados cargados] - (0) si salio todo bien
int calculateEmployeesAverageSalary(Employee* list, int length, float* average, float* total);


/// @brief Dado un salario minimo cuenta cuantos empleados tienen un salario por encima del mismo
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param length int longitud del array
/// @param minimumSalary float salario minimo sobre el que se cuenta
/// /// @param amountEmployeesAbove int* puntero a un entero para devolver la cantidad de empleados por encima de minimumSalary
/// @return int Return (-1) si hubo Error[longitud invalida, puntero a NULL o no hay empleados cargados] - (0) si salio todo bien
int countEmployeesAboveSalary(Employee* list, int length, float minimumSalary, int* amountEmployeesAbove);


/// @brief Evalúa si el array Employees esta vacía o no
///
/// @param list Employee* puntero a un array de employees (empleados)
/// @param length int longitud del array
/// @return (1) [Si el array esta vacío] - (0) [Si el arrray NO esta vacío]
int isEmployeesEmpty(Employee* list, int length);

/// @brief Imprime el encabezado del array de empleados para identificar mas facilmente los datos que se representan
/// 		(ID, Salario, Sector, Nombre y Apellido)
///
void printHeaderEmployeesArray(void);

#endif /* ARRAYEMPLOYEES_H_ */
