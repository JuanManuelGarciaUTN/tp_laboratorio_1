
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int seAgregaronCorrectamente;
	Employee* pAuxEmployee;
	char nombre[128];
	char id[20];
	char horasTrabajadas[5];
	char sueldo[20];

	seAgregaronCorrectamente = -1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

	while(!feof(pFile))
	{
		seAgregaronCorrectamente = 1 && seAgregaronCorrectamente != 0;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		pAuxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
		if(pAuxEmployee != NULL)
		{
			ll_add(pArrayListEmployee, pAuxEmployee);
		}
		else
		{
			seAgregaronCorrectamente = 0;
		}
	}

    return seAgregaronCorrectamente;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int seAgregaronCorrectamente;
	int i = 0;
	int id;
	char nombre[LONGITUD_NOMBRE];
	int sueldo;
	int horas;
	Employee* pNewEmployee;

	seAgregaronCorrectamente = -1;
	while(!feof(pFile))
	{
		i++;
		seAgregaronCorrectamente = 1 && seAgregaronCorrectamente != 0;

		pNewEmployee = employee_new();

		if(pNewEmployee != NULL)
		{
			if(fread(pNewEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				employee_getId(pNewEmployee, &id);
				employee_getNombre(pNewEmployee, nombre);
				employee_getSueldo(pNewEmployee, &sueldo);
				employee_getHorasTrabajadas(pNewEmployee, &horas);

				if(VerificarCargaBinaria(horas))
				{
					ll_add(pArrayListEmployee, pNewEmployee);
				}
				else
				{

					employee_delete(pNewEmployee);
					printf("%d\n\n", i);
					seAgregaronCorrectamente = 0;
				}
			}
		}
		else
		{
			seAgregaronCorrectamente = 0;
		}
	}

	return seAgregaronCorrectamente;
}

int VerificarCargaBinaria(int horas)
{
	int cargaCorrecta;
	cargaCorrecta = 0;

	if(horas < 500)
	{
		cargaCorrecta = 1;
	}

	return cargaCorrecta;
}
