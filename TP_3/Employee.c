/*
 * Employee.c
 *
 *  Created on: 1 nov. 2021
 *      Author: juanm
 */

#include "Employee.h"

Employee* employee_new()
{
	Employee* pNewEmployee = NULL;
	pNewEmployee = (Employee*) malloc(sizeof(Employee));

	return pNewEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pNewEmployee = NULL;
	int id;
	int horasTrabajadas;
	int sueldo;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL &&
			EsEntero(idStr) && EsEntero(sueldoStr) && EsEntero(horasTrabajadasStr))
	{
		id = atoi(idStr);
		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);

		//Reservo memoria
		pNewEmployee = employee_new();


		//Asigno a los campos los valores de los parametros
		if(pNewEmployee != NULL)
		{
			employee_setId(pNewEmployee, id);
			employee_setNombre(pNewEmployee, nombreStr);
			employee_setHorasTrabajadas(pNewEmployee, horasTrabajadas);
			employee_setSueldo(pNewEmployee, sueldo);
		}
	}

	return pNewEmployee;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setId(Employee* this,int id)
{
	int sePudoSetearId;
	sePudoSetearId = 0;

	if(this != NULL)
	{
		this->id = id;
		sePudoSetearId = 1;
	}

	return sePudoSetearId;
}

int employee_getId(Employee* this,int* id)
{
	int sePudoObtenerId;
	sePudoObtenerId = 0;

	if(this != NULL)
	{
		*id = this->id;
		sePudoObtenerId = 1;
	}

	return sePudoObtenerId;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int sePudoSetearNombre;
	sePudoSetearNombre = -1;

	if(this != NULL)
	{
		sePudoSetearNombre = 0;
		if(strlen(nombre) < LONGITUD_NOMBRE)
		{
			strcpy(this->nombre, nombre);
			sePudoSetearNombre = 1;
		}
	}
	return sePudoSetearNombre;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int sePudoObtenerNombre;
	sePudoObtenerNombre = 0;

	if(this != NULL)
	{
		strncpy(nombre, this->nombre, 128);
		sePudoObtenerNombre = 1;
	}

	return sePudoObtenerNombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int sePudoSetearHorasTrabajadas;
	sePudoSetearHorasTrabajadas = 0;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		sePudoSetearHorasTrabajadas = 1;
	}
	return sePudoSetearHorasTrabajadas;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int sePudoObtenerHorasTrabajadas;
	sePudoObtenerHorasTrabajadas = 0;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		sePudoObtenerHorasTrabajadas = 1;
	}
	return sePudoObtenerHorasTrabajadas;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int sePudoSetearSueldo;
	sePudoSetearSueldo = 0;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		sePudoSetearSueldo = 1;
	}
	return sePudoSetearSueldo;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int sePudoObtenerSueldo;
	sePudoObtenerSueldo = 0;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		sePudoObtenerSueldo = 1;
	}

	return sePudoObtenerSueldo;
}

int employee_printWithId(Employee* this)
{
	int existe;
	int id;
	char nombre[LONGITUD_NOMBRE];
	int horasTrabajadas;
	int sueldo;

	existe = 0;
	if(this != NULL)
	{
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajadas);
		employee_getSueldo(this, &sueldo);
		existe = 1;
		printf("%-6d %-40s  %4d %8d \n", id, nombre, horasTrabajadas, sueldo);
	}

	return existe;
}

int employee_printWithoutId(Employee* this)
{
	int existe;
	char nombre[LONGITUD_NOMBRE];
	int horasTrabajadas;
	int sueldo;

	existe = 0;
	if(this != NULL)
	{
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horasTrabajadas);
		employee_getSueldo(this, &sueldo);
		existe = 1;
		printf("%-40s  %4d %8d \n", nombre, horasTrabajadas, sueldo);
	}

	return existe;
}


int employee_sortByName(void* pPrimerEmpleado,void* pSegundoEmpleado)
{
	int retorno;
	char nombrePrimerEmpleado[LONGITUD_NOMBRE];
	char nombreSegundoEmpleado[LONGITUD_NOMBRE];
	Employee* primerEmpleado = NULL;
	Employee* segundoEmpleado = NULL;

	if(pPrimerEmpleado != NULL && pSegundoEmpleado != NULL)
	{
		primerEmpleado = (Employee*)pPrimerEmpleado;
		segundoEmpleado = (Employee*)pSegundoEmpleado;

		employee_getNombre(primerEmpleado, nombrePrimerEmpleado);
		employee_getNombre(segundoEmpleado, nombreSegundoEmpleado);

		retorno = strcmp(nombrePrimerEmpleado, nombreSegundoEmpleado);
	}

	return retorno;
}

int employee_sortById(void* pPrimerEmpleado,void* pSegundoEmpleado)
{
	int retorno;
	int idPrimerEmpleado;
	int idSegundoEmpleado;
	Employee* primerEmpleado = NULL;
	Employee* segundoEmpleado = NULL;

	retorno = 0;

	if(pPrimerEmpleado != NULL && pSegundoEmpleado != NULL)
	{
		primerEmpleado = (Employee*)pPrimerEmpleado;
		segundoEmpleado = (Employee*)pSegundoEmpleado;

		employee_getId(primerEmpleado, &idPrimerEmpleado);
		employee_getId(segundoEmpleado, &idSegundoEmpleado);

		if(idPrimerEmpleado > idSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(idPrimerEmpleado < idSegundoEmpleado)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_sortBySalary(void* pPrimerEmpleado,void* pSegundoEmpleado)
{
	int retorno;
	int salarioPrimerEmpleado;
	int salarioSegundoEmpleado;
	Employee* primerEmpleado = NULL;
	Employee* segundoEmpleado = NULL;

	retorno = 0;

	if(pPrimerEmpleado != NULL && pSegundoEmpleado != NULL)
	{
		primerEmpleado = (Employee*)pPrimerEmpleado;
		segundoEmpleado = (Employee*)pSegundoEmpleado;

		employee_getSueldo(primerEmpleado, &salarioPrimerEmpleado);
		employee_getSueldo(segundoEmpleado, &salarioSegundoEmpleado);

		if(salarioPrimerEmpleado > salarioSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(salarioPrimerEmpleado < salarioSegundoEmpleado)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_sortByWorkTime(void* pPrimerEmpleado,void* pSegundoEmpleado)
{
	int retorno;
	int horasPrimerEmpleado;
	int horasSegundoEmpleado;
	Employee* primerEmpleado = NULL;
	Employee* segundoEmpleado = NULL;

	retorno = 0;

	if(pPrimerEmpleado != NULL && pSegundoEmpleado != NULL)
	{
		primerEmpleado = (Employee*)pPrimerEmpleado;
		segundoEmpleado = (Employee*)pSegundoEmpleado;

		employee_getHorasTrabajadas(primerEmpleado, &horasPrimerEmpleado);
		employee_getHorasTrabajadas(segundoEmpleado, &horasSegundoEmpleado);

		if(horasPrimerEmpleado > horasSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(horasPrimerEmpleado < horasSegundoEmpleado)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_sortBySalaryAndName(void* pPrimerEmpleado,void* pSegundoEmpleado)
{
	int retorno;
	int salarioPrimerEmpleado;
	int salarioSegundoEmpleado;
	char nombrePrimerEmpleado[LONGITUD_NOMBRE];
	char nombreSegundoEmpleado[LONGITUD_NOMBRE];
	Employee* primerEmpleado = NULL;
	Employee* segundoEmpleado = NULL;

	retorno = 0;

	if(pPrimerEmpleado != NULL && pSegundoEmpleado != NULL)
	{
		primerEmpleado = (Employee*)pPrimerEmpleado;
		segundoEmpleado = (Employee*)pSegundoEmpleado;

		employee_getSueldo(primerEmpleado, &salarioPrimerEmpleado);
		employee_getSueldo(segundoEmpleado, &salarioSegundoEmpleado);

		employee_getNombre(primerEmpleado, nombrePrimerEmpleado);
		employee_getNombre(segundoEmpleado, nombreSegundoEmpleado);

		if(salarioPrimerEmpleado > salarioSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(salarioPrimerEmpleado < salarioSegundoEmpleado)
			{
				retorno = -1;
			}
			else
			{
				retorno = strcmp(nombrePrimerEmpleado, nombreSegundoEmpleado);
			}
		}
	}

	return retorno;
}

int employee_sortByWorkTimeAndName(void* pPrimerEmpleado,void* pSegundoEmpleado)
{
	int retorno;
	int horasPrimerEmpleado;
	int horasSegundoEmpleado;
	char nombrePrimerEmpleado[LONGITUD_NOMBRE];
	char nombreSegundoEmpleado[LONGITUD_NOMBRE];
	Employee* primerEmpleado = NULL;
	Employee* segundoEmpleado = NULL;

	retorno = 0;

	if(pPrimerEmpleado != NULL && pSegundoEmpleado != NULL)
	{
		primerEmpleado = (Employee*)pPrimerEmpleado;
		segundoEmpleado = (Employee*)pSegundoEmpleado;

		employee_getHorasTrabajadas(primerEmpleado, &horasPrimerEmpleado);
		employee_getHorasTrabajadas(segundoEmpleado, &horasSegundoEmpleado);

		employee_getNombre(primerEmpleado, nombrePrimerEmpleado);
		employee_getNombre(segundoEmpleado, nombreSegundoEmpleado);

		if(horasPrimerEmpleado > horasSegundoEmpleado)
		{
			retorno = 1;
		}
		else
		{
			if(horasPrimerEmpleado < horasSegundoEmpleado)
			{
				retorno = -1;
			}
			else
			{
				retorno = strcmp(nombrePrimerEmpleado, nombreSegundoEmpleado);
			}
		}
	}

	return retorno;
}

