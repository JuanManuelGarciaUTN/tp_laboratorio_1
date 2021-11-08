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

int PrintEmployeesWithId(LinkedList* pArrayListEmployee);
int PrintEmployeesWithPosition(LinkedList* pArrayListEmployee);
int SortEmployees(LinkedList* pArrayListEmployee, int criterioOrdenamiento, int tipoOrdenamiento);
int FindMaxId(LinkedList* pArrayListEmployee, int* maxIdRetorno);
int CreateNewId(LinkedList* pArrayListEmployee);


#endif /* NEXOLINKEDLISTANDEMPLOYEEE_H_ */
