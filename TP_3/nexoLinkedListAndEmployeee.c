/*
 * nexoLinkedListAndEmployeee.c
 *
 *  Created on: 3 nov. 2021
 *      Author: juanm
 */

#include "nexoLinkedListAndEmployeee.h"


int PrintEmployeesWithId(LinkedList* pArrayListEmployee)
{
	int existeLaLista;
	int longitud;
	Employee* employeeAuxiliar = NULL;

	existeLaLista = 0;

	if(pArrayListEmployee != NULL)
	{
		existeLaLista = 1;
		longitud = ll_len(pArrayListEmployee);

		printf("ID     Nombre                                   Horas   Sueldo \n\n");
		for(int i=0; i<longitud; i++)
		{
			employeeAuxiliar = (Employee*)ll_get(pArrayListEmployee, i);
			employee_printWithId(employeeAuxiliar);
		}
	}

	return existeLaLista;
}

int PrintEmployeesWithPosition(LinkedList* pArrayListEmployee)
{
	int existeLaLista;
	int longitud;
	Employee* employeeAuxiliar = NULL;

	existeLaLista = 0;

	if(pArrayListEmployee != NULL)
	{
		existeLaLista = 1;
		longitud = ll_len(pArrayListEmployee);

		printf("N°     Nombre                                   Horas   Sueldo \n\n");
		for(int i=0; i<longitud; i++)
		{
			employeeAuxiliar = (Employee*)ll_get(pArrayListEmployee, i);
			printf("%-6d ",i+1);
			employee_printWithoutId(employeeAuxiliar);
		}
	}

	return existeLaLista;
}

int SortEmployees(LinkedList* pArrayListEmployee, int criterioOrdenamiento, int tipoOrdenamiento)
{
	int retorno;

	printf("Ordenando la Lista, por favor espere... \n"
			"(Tiempo estimado 10 segundos)\n");

	switch(criterioOrdenamiento)
	{
		case 1:
			retorno = ll_sort(pArrayListEmployee, employee_sortById, tipoOrdenamiento);
			break;

		case 2:
			retorno = ll_sort(pArrayListEmployee, employee_sortByName, tipoOrdenamiento);
			break;

		case 3:
			retorno = ll_sort(pArrayListEmployee, employee_sortBySalary, tipoOrdenamiento);
			break;

		case 4:
			retorno = ll_sort(pArrayListEmployee, employee_sortBySalaryAndName, tipoOrdenamiento);
			break;

		case 5:
			retorno = ll_sort(pArrayListEmployee, employee_sortByWorkTime, tipoOrdenamiento);
			break;

		case 6:
			retorno = ll_sort(pArrayListEmployee, employee_sortByWorkTimeAndName, tipoOrdenamiento);
			break;
	}

	return retorno;
}

int FindMaxId(LinkedList* pArrayListEmployee, int* maxIdRetorno)
{
	int maxId;
	int idObtenido;
	int existeAlMenosUno;
	int longitud;

	existeAlMenosUno = 0;

	if(pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
	{
		longitud = ll_len(pArrayListEmployee);
		for(int i=0; i<longitud; i++)
		{
			idObtenido = ((Employee*)ll_get(pArrayListEmployee, i))->id;
			existeAlMenosUno = 1;

			if(i == 0 || idObtenido > maxId)
			{
				maxId = idObtenido;
			}
		}

		*maxIdRetorno = maxId;
	}

	return existeAlMenosUno;
}

int CreateNewId(char* pathArchivoIds)
{
	int nuevaId;
	FILE* archivoId = fopen(pathArchivoIds, "r");

	if(archivoId != NULL)
	{
		fscanf(archivoId, "%d", &nuevaId);
		nuevaId++;
		fclose(archivoId);

		archivoId = fopen(pathArchivoIds, "w");
		fprintf(archivoId, "%d", nuevaId);
		fclose(archivoId);
	}

	return nuevaId;
}

void VaciarLista(LinkedList* pArrayListEmployee)
{
	int longitud;

	if(pArrayListEmployee)
	{
		longitud = ll_len(pArrayListEmployee);

		for(int i=0; i<longitud; i++)
		{
			employee_delete(ll_pop(pArrayListEmployee, 0));
		}
	}
}
