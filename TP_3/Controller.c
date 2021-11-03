#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"
#include "informes.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int sePudoLeerElArchivo;
	FILE* pFile = fopen(path, "r");

	sePudoLeerElArchivo = -3;
	if(pArrayListEmployee != NULL && pFile != NULL)
	{
		sePudoLeerElArchivo = -2;
		if(ll_isEmpty(pArrayListEmployee))
		{
			sePudoLeerElArchivo = parser_EmployeeFromText(pFile ,  pArrayListEmployee);
		}
		fclose(pFile);
	}

    return sePudoLeerElArchivo;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int sePudoLeerElArchivo;
	FILE* pFile = fopen(path, "rb");

	sePudoLeerElArchivo = -3;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		sePudoLeerElArchivo = -2;
		if(ll_isEmpty(pArrayListEmployee))
		{
			while(!feof(pFile))
			{
				sePudoLeerElArchivo = parser_EmployeeFromBinary(pFile ,  pArrayListEmployee);
			}
		}
		fclose(pFile);
	}

    return sePudoLeerElArchivo;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int seAgregoUnEmployee;
    Employee* pNuevoEmployee = NULL;
    seAgregoUnEmployee = -1;

    if(pArrayListEmployee != NULL)
    {
    	seAgregoUnEmployee = 0;
    	pNuevoEmployee = employee_new();
    	if(pNuevoEmployee != NULL)
    	{

    		employee_setId(pNuevoEmployee, 1000); //Place HOLDER
    		employee_setHorasTrabajadas(pNuevoEmployee, 150);
    		employee_setNombre(pNuevoEmployee, "PLACER HOLDER");
    		employee_setSueldo(pNuevoEmployee, 1048596);

    		ll_add(pArrayListEmployee, pNuevoEmployee);
    		seAgregoUnEmployee = 1;
    	}
    }
    return seAgregoUnEmployee;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int existeAlMenosUno;

	existeAlMenosUno = 0;

	if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
	{
		existeAlMenosUno = 1;

		printf("ID     Nombre                                   Horas   Sueldo \n\n");
		PrintEmployeesWithId(pArrayListEmployee);

		system("pause");
		system("cls");
	}

	return existeAlMenosUno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int existeAlMenosUno;
	existeAlMenosUno = 0;
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
    {
    	existeAlMenosUno = 1;
    	printf("Ordenando la Lista, por favor espere... \n"
    			"(Tiempo estimado 10 segundos)\n");
    	ll_sort(pArrayListEmployee, employee_sortBySalaryAndName, 1);
    }
    system("cls");

    return existeAlMenosUno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile = fopen(path, "w");
	Employee* pEmployeeAuxiliar;
    int sePudoGuardar;
    int longitudLinkedList;
    int id;
    char nombre[LONGITUD_NOMBRE];
    int sueldo;
    int horasTrabajadas;

    sePudoGuardar = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	longitudLinkedList = ll_len(pArrayListEmployee);

    	for(int i=0; i<longitudLinkedList; i++)
    	{
    		if(i==0)
    		{
    			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
    		}
    		else
    		{
        		pEmployeeAuxiliar = ll_get(pArrayListEmployee, i);
        		employee_getId(pEmployeeAuxiliar, &id);
        		employee_getNombre(pEmployeeAuxiliar, nombre);
        		employee_getSueldo(pEmployeeAuxiliar, &sueldo);
        		employee_getHorasTrabajadas(pEmployeeAuxiliar, &horasTrabajadas);

        		fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
    		}
    	}

    	sePudoGuardar = 1;
    }

    return sePudoGuardar;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "wb");
    Employee* pEmployeeAuxiliar;
    int sePudoGuardar;
    int longitudLinkedList;

    sePudoGuardar = 0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
    	longitudLinkedList = ll_len(pArrayListEmployee);

    	for(int i=0; i<longitudLinkedList; i++)
    	{
    		pEmployeeAuxiliar = ll_get(pArrayListEmployee, i);
    		fwrite(pEmployeeAuxiliar, sizeof(Employee), 1, pFile);
    	}

    	sePudoGuardar = 1;
    }

    return sePudoGuardar;
}


/// @brief Le muestra al usuario el menu de opciones y le pide que ingrese la opcion deseada
///
/// @return opcion que el usuario eligió

int controller_showMenu(void)
{
	int opcionElejida;

	printf("    Menu: \n\n"
     " 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n"
     " 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).  \n"
     " 3. Alta de empleado  \n"
     " 4. Modificar datos de empleado  \n"
     " 5. Baja de empleado  \n"
     " 6. Listar empleados  \n"
     " 7. Ordenar empleados  \n"
     " 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).  \n"
     " 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).  \n"
     "10. Salir \n\n");

	PedirEnteroValidado("Ingrese la Opcion Elejida: ", "Error. Opcion Invalida\n", &opcionElejida, 1, 10);

	system("cls");

	return opcionElejida;
}


/// @brief Recibe la respuesta de las funciones de carga desde archivo
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void controller_respuestaLoad(int respuesta)
{
	switch(respuesta)
	{
		case 1:
			printf("Se Pudo Cargar la Lista de Empleados Correctamente \n\n");
			break;

		case 0:
			printf("Se Cargo PARCIALMENTE la Lista de Empleados, Archivo con DATOS corruptos o invalidos \n\n");
			break;

		case -1:
			printf("NO SE PUDO Cargar la Lista de Empleados, el Archivo esta VACIO\n\n");
			break;

		case -2:
			printf("NO SE PUDO Cargar la Lista de Empleados, ya que fue cargarda previamente\n\n");
			break;

		case -3:
			printf("ERROR. El Archivo NO Existe\n\n");
			break;
	}
}

/// @brief Recibe la respuesta de las funciones de guardado a archivo
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void controller_respuestaSave(int respuesta)
{
	switch(respuesta)
	{
		case 1:
			printf("Se Guardo la Lista de Empleados CORRECTAMENTE en el Archivo\n\n");
			break;

		case 0:
			printf("NO SE PUDO Guardar la Lista de Empleados en el Archivo\n\n");
			break;
	}
}

void controller_respuestaSort(int respuesta)
{
	switch(respuesta)
	{
		case 1:
			printf("Se Ordeno la Lista de Empleados CORRECTAMENTE\n\n");
			break;

		case 0:
			printf("NO SE PUDO Ordenar la Lista de Empleados, Ya Que Esta VACIA\n\n");
			break;
	}
}

void controller_respuestaList(int respuesta)
{
	switch(respuesta)
	{
		case 0:
			printf("NO SE PUDO Mostar la Lista de Empleados, Ya Que Esta VACIA\n\n");
			break;
	}
}


