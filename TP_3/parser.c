
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* puntero a Archivo de texto
 * \param pArrayListEmployee LinkedList* - LinkedList donde se guardaron los empleados del archivo
 * \return int -1[el Archivo esta VACIO] - 0[Se cargo PARTE de los datos, archivo corrupto] - 1[Se cargaron TODOS los datos]
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
 * \param pFile FILE* puntero a Archivo binario
 * \param pArrayListEmployee LinkedList* - LinkedList donde se guardaron los empleados del archivo
* \return int -1[el Archivo esta VACIO] - 0[Se cargo PARTE de los datos, archivo corrupto] - 1[Se cargaron TODOS los datos]
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int seAgregaronCorrectamente;
	Employee* pNewEmployee;

	seAgregaronCorrectamente = -1;

	while(!feof(pFile))
	{
		seAgregaronCorrectamente = 1 && seAgregaronCorrectamente != 0;

		pNewEmployee = employee_new();

		if(pNewEmployee != NULL)
		{
			if(fread(pNewEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				if(VerificarCargaBinaria(pNewEmployee))
				{
					ll_add(pArrayListEmployee, pNewEmployee);
				}
				else
				{

					employee_delete(pNewEmployee);
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



/** \brief Verifica que se cargara correctamente un Employee con carga Binaria desde archivo
 *
 * \param pNewEmployee Employee* puntero a un employee a verificar
* \return int 1[Datos Validos] - 0[Datos Invalidos]
 *
 */
int VerificarCargaBinaria(Employee* pNewEmployee)
{
	int cargaCorrecta;
	int horas;
	int sueldo;
	int id;
	cargaCorrecta = 0;

	if(employee_getId(pNewEmployee, &id) && employee_getHorasTrabajadas(pNewEmployee, &horas) && employee_getSueldo(pNewEmployee, &sueldo) &&
			id > 0 && horas > 0 && horas <500 && sueldo > -1)
	{
		cargaCorrecta = 1;
	}

	return cargaCorrecta;
}
