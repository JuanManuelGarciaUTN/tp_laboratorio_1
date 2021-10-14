/*
 * ArrayEmployees.c
 *
 *  Created on: 12 oct. 2021
 *      Author: juanm
 */

#include"ArrayEmployees.h"

//Funciones Pedidas
int initEmployees(Employee* list, int len)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;
		}
	}

	return retorno;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				retorno = 0;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = FALSE;

				break;
			}
		}
	}

	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	int indiceEmployee;

	retorno = -1;

	indiceEmployee = findEmployeeById(list, len, id);

	if(indiceEmployee != -1)
	{
		retorno = 0;
		list[indiceEmployee].isEmpty = TRUE;
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int retorno;
	Employee auxiliar;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 0;
		switch(order)
		{
			case UP:
				for(int i=0; i<len-1; i++)
				{
					if(list[i].isEmpty == FALSE)
					{
						for(int j=i; j<len; j++)
						{
							if(list[j].isEmpty == FALSE)
							{
								if((strcmp(list[i].lastName, list[j].lastName) > 0) || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
							}
						}
					}
				}
				break;

			case DOWN:
				for(int i=0; i<len-1; i++)
				{
					if(list[i].isEmpty == FALSE)
					{
						for(int j=i; j<len; j++)
						{
							if(list[j].isEmpty == FALSE)
							{
								if((strcmp(list[i].lastName, list[j].lastName) < 0) || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))
								{
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
							}
						}
					}
				}
				break;
		}
	}

	return retorno;
}

int printEmployees(Employee* list, int length)
{
	int retorno;
	int flagArrayVacio;
	char nombreYApellido[102];

	retorno = -1;
	flagArrayVacio = TRUE;

	if(list != NULL && length > 0)
	{
		for(int i=0; i<length; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				strcpy(nombreYApellido, list[i].name);
				strcat(nombreYApellido, " ");
				strcat(nombreYApellido, list[i].lastName);
				if(flagArrayVacio == TRUE)
				{
					printHeaderEmployeesArray();
				}
				flagArrayVacio = FALSE;
				printf("%-4d %-30s %10.2f      %-3d\n", list[i].id, nombreYApellido, list[i].salary, list[i].sector);
			}
		}
	}

	if(flagArrayVacio == TRUE)
	{
		printf("La lista de empleados esta vacia\n");
	}

	return retorno;
}


//Funciones Propias
int reportEmployeesAverageSalary(Employee* list, int length)
{
	int retorno;

	float sumaTotalSalarios;
	float salarioPromedio;
	int cantidadEmpleadosArribaDelPromedio;

	retorno = -1;

	if(list != NULL && length > 0)
	{
		retorno = calculateEmployeesAverageSalary(list, length, &salarioPromedio, &sumaTotalSalarios);
		countEmployeesAboveSalary(list, length, salarioPromedio, &cantidadEmpleadosArribaDelPromedio);
	}

	if(retorno != -1)
	{
		printf("La suma total de todos los salarios es: %.2f \n"
				"El salario promedio es: %.2f \n"
				"La cantidad de empleados arriba del salario promedio es: %d \n\n", sumaTotalSalarios, salarioPromedio, cantidadEmpleadosArribaDelPromedio);
	}

	return retorno;
}

int calculateEmployeesAverageSalary(Employee* list, int length, float* average, float* total)
{
	int retorno;
	float sumaTotalSalarios;
	int cantidadEmpleados;

	retorno = -1;
	sumaTotalSalarios = 0;
	cantidadEmpleados = 0;

	if(list != NULL && length > 0)
	{
		for(int i=0; i<length; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				retorno = 0;
				cantidadEmpleados ++;
				sumaTotalSalarios += list[i].salary;
			}
		}
		if(retorno == 0)
		{
			*average = sumaTotalSalarios / cantidadEmpleados;
			*total = sumaTotalSalarios;
		}
	}

	return retorno;
}

int countEmployeesAboveSalary(Employee* list, int length, float minimumSalary, int* amountEmployeesAbove)
{
	int retorno;
	int cantidadEmpleados;

	retorno = -1;
	cantidadEmpleados = 0;

	if(list != NULL && length > 0)
	{
		for(int i=0; i<length; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > minimumSalary)
			{
				retorno = 0;
				cantidadEmpleados ++;
			}
		}

		*amountEmployeesAbove = cantidadEmpleados;
	}

	return retorno;
}

int isEmployeesEmpty(Employee* list, int length)
{
	int retorno;
	retorno = 1;

	if(list != NULL && length > 0)
	{
		for(int i=0; i<length; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

void printHeaderEmployeesArray(void)
{
	printf("ID   Nombre y Apellido                 SALARIO      SECTOR\n\n");
}
