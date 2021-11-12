/*
 * nexoLinkedListAndEmployeee.h
 *
 *  Created on: 3 nov. 2021
 *      Author: juanm
 */

#ifndef NEXOLINKEDLISTANDEMPLOYEEE_H_
#define NEXOLINKEDLISTANDEMPLOYEEE_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

//Posee funciones para interactuar con una LinkedList de Employees

/// @brief Muestra en pantalla todos los employees en la LinkedList
/// 		con sus datos e ID.
///
/// @param pArrayListEmployee - La LinkedList a mostrar.
/// @return 0[pArrayListEmployee es NULL] - 1[pArrayListEmployee NO es NULL]
int PrintEmployeesWithId(LinkedList* pArrayListEmployee);


/// @brief Muestra en pantalla todos los employees en la LinkedList
/// 		con su posicion en la LinkedList (1, 2, 3, etc) y sus datos
///
/// @param pArrayListEmployee - La LinkedList a mostrar.
/// @return 0[pArrayListEmployee es NULL] - 1[pArrayListEmployee NO es NULL]
int PrintEmployeesWithPosition(LinkedList* pArrayListEmployee);


/// @brief Ordena la LinkedList de employees segun el criterio y tipo de ordenamiento
///
/// @param pArrayListEmployee - La LinkedList a ordenar.
/// @param criterioOrdenamiento - criterio de ordenamiento (ej: por Nombre)
/// @param tipoOrdenamiento - tipo de ordenamiento ([1]Ascendente o [0]Descendente)
/// @return 0[Se pudo Ordenar la LinkedList] - -1[NO se pudo Ordenar la LinkedList, pArrayListEmployee es NULL]
int SortEmployees(LinkedList* pArrayListEmployee, int criterioOrdenamiento, int tipoOrdenamiento);


/// @brief Busca el valor de ID maximo en la LinkedList de employees
///
/// @param pArrayListEmployee - La LinkedList a buscar el ID maximo.
/// @param maxIdRetorno - puntero a int usado para retornar el ID maximo.
/// @return 0[pArrayListEmployee es NULL o La LinkedList esta vacía] - 1[Se encontro el ID maximo correctamente]
int FindMaxId(LinkedList* pArrayListEmployee, int* maxIdRetorno);


/// @brief Crea un nuevo ID de employee. Si la LinkedList esta vacia devuelve 1,
/// 		si no devuelve 1 más que el maximo ID actualmente en uso.
///
/// @param pArrayListEmployee - La LinkedList analizar para crear un nuevo ID
/// @return 1[La LinkedList esta vacía] - nuevo ID maximo[si existe al menos un employee, devuelve un nuevo ID]
int CreateNewId(char* pathArchivoIds);


/// @brief Vacia todos los elementos de la LinkedList y los elimina
///
/// @param pArrayListEmployee LinkedList* - puntero a linked list a vaciar
void VaciarLista(LinkedList* pArrayListEmployee);


#endif /* NEXOLINKEDLISTANDEMPLOYEEE_H_ */
