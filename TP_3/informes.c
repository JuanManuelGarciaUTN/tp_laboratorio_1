/*
 * informes.c
 *
 *  Created on: 2 nov. 2021
 *      Author: juanm
 */

#include "informes.h"
void PrintEmployeesWithId(LinkedList* pArrayListEmployee)
{
	int longitud;
	Employee* employeeAuxiliar = NULL;

	longitud = ll_len(pArrayListEmployee);
	for(int i=0; i<longitud; i++)
	{
		employeeAuxiliar = (Employee*)ll_get(pArrayListEmployee, i);
		employee_printWithId(employeeAuxiliar);
	}
}

void PrintEmployeesWithoutId(LinkedList* pArrayListEmployee)
{
	int longitud;
	Employee* employeeAuxiliar = NULL;

	longitud = ll_len(pArrayListEmployee);
	for(int i=0; i<longitud; i++)
	{
		employeeAuxiliar = (Employee*)ll_get(pArrayListEmployee, i);
		employee_printWithoutId(employeeAuxiliar);
	}
}


