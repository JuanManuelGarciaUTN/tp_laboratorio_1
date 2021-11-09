#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"
#include "nexoLinkedListAndEmployeee.h"
#include "menu.h"




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
	int deseaSobrecargar;
	FILE* pFile = fopen(path, "r");

	sePudoLeerElArchivo = -3;
	if(pArrayListEmployee != NULL && pFile != NULL)
	{
		sePudoLeerElArchivo = -2;
		if(ll_isEmpty(pArrayListEmployee))
		{
			sePudoLeerElArchivo = parser_EmployeeFromText(pFile,  pArrayListEmployee);
		}
		else
		{
			deseaSobrecargar = PedirSiDeseaSobreescribirEnCarga();
			if(deseaSobrecargar == 1)
			{
				VaciarLista(pArrayListEmployee);
				sePudoLeerElArchivo = parser_EmployeeFromText(pFile,  pArrayListEmployee);
			}
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
	int deseaSobrecargar;
	FILE* pFile = fopen(path, "rb");

	sePudoLeerElArchivo = -3;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		sePudoLeerElArchivo = -2;
		if(ll_isEmpty(pArrayListEmployee))
		{
			sePudoLeerElArchivo = parser_EmployeeFromBinary(pFile ,  pArrayListEmployee);
		}
		else
		{
			deseaSobrecargar = PedirSiDeseaSobreescribirEnCarga();
			if(deseaSobrecargar == 1)
			{
				VaciarLista(pArrayListEmployee);
				sePudoLeerElArchivo = parser_EmployeeFromBinary(pFile,  pArrayListEmployee);
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
    int nuevaId;
    int horasTrabajadas;
    int sueldo;
    char nombre[LONGITUD_NOMBRE];
    Employee* pNuevoEmployee = NULL;
    seAgregoUnEmployee = -1;

    if(pArrayListEmployee != NULL)
    {
    	seAgregoUnEmployee = 0;
    	pNuevoEmployee = employee_new();
    	if(pNuevoEmployee != NULL)
    	{
    		nuevaId = CreateNewId("idMaximo.csv");
    		PedirSustantivoPropio("Ingrese el nombre del empleado: ","ERROR. Solo puede ingresar letras y espacios\n" , nombre, LONGITUD_NOMBRE);
    		PedirEnteroMayorQue("Ingrese el sueldo del empleado: ", "ERROR, debe ingresar un entero positivo\n", &sueldo , 0);
    		PedirEnteroValidado("Ingrese las horas trabajadas empleado: ", "ERROR, valor invalido\n", &horasTrabajadas , 0, 350);

    		employee_setId(pNuevoEmployee, nuevaId);
    		employee_setHorasTrabajadas(pNuevoEmployee, horasTrabajadas);
    		employee_setNombre(pNuevoEmployee, nombre);
    		employee_setSueldo(pNuevoEmployee, sueldo);

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
	int retorno;
	int cantiadEmpleados;
	int numeroBaja;
	int opcion;
	Employee* pEmployeeModificar;

	retorno = -1;

	if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
	{
		retorno = 0;

		do
		{
			PrintEmployeesWithPosition(pArrayListEmployee);
			cantiadEmpleados = ll_len(pArrayListEmployee);

			PedirEnteroValidado("Ingrese el numero del empleado a Modificar: ", "ERROR. No existe dicho empleado, vuelva a intentarlo \n", &numeroBaja, 1, cantiadEmpleados);

			printf("\nVa a dar de modificar a: \n");
			pEmployeeModificar = (Employee*)ll_get(pArrayListEmployee, numeroBaja-1);
			employee_printIdAndName(pEmployeeModificar);

			retorno = employee_edit(pEmployeeModificar) || retorno;

			printf("\n¿Desea Ingresar Otro Empleado? \n\n"
					"1. SI \n"
					"2. NO, Volver Al Menu Principal \n\n");

			PedirEnteroValidado("Ingrese Respuesta: ", "ERROR. Opcion Invalida \n", &opcion, 1, 2);

			system("cls");

		} while(opcion == 1);
	}

	return retorno;
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
	int retorno;
	int cantiadEmpleados;
	int numeroBaja;
	int opcion;
	Employee* pEmployeeBaja;

	retorno = -1;

	if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
	{
		retorno = 0;
		PrintEmployeesWithPosition(pArrayListEmployee);
		cantiadEmpleados = ll_len(pArrayListEmployee);

		do
		{
			PedirEnteroValidado("Ingrese el numero del empleado a dar de baja: ", "ERROR. No existe dicho empleado, vuelva a intentarlo \n", &numeroBaja, 1, cantiadEmpleados);

			printf("\nVa a dar de baja a: \n");
			pEmployeeBaja = (Employee*)ll_get(pArrayListEmployee, numeroBaja-1);
			employee_printIdAndName(pEmployeeBaja);

			printf("\n¿Desea Continuar? \n\n"
					"1. SI \n"
					"2. NO, Ingresar Otro Empleado \n"
					"3. NO, Volver Al Menu Principal \n\n");
			PedirEnteroValidado("Ingrese Respuesta: ", "ERROR. Opcion Invalida \n", &opcion, 1, 3);
			printf("\n");

		} while(opcion == 2);

		if(opcion == 1)
		{
			retorno = 1;
			ll_remove(pArrayListEmployee, numeroBaja-1);
			employee_delete(pEmployeeBaja);
		}
	}

	return retorno;
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
		PrintEmployeesWithId(pArrayListEmployee);
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
	int criterioOrdenamiento;
	int tipoOrdenamiento;

	existeAlMenosUno = 0;
    if(pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
    {
    	existeAlMenosUno = 1;

    	criterioOrdenamiento = PedirCriterioDeOrdenamiento();
    	tipoOrdenamiento = PedirTipoDeOrdenamiento();

    	SortEmployees(pArrayListEmployee, criterioOrdenamiento, tipoOrdenamiento);
    }

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

			pEmployeeAuxiliar = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pEmployeeAuxiliar, &id);
			employee_getNombre(pEmployeeAuxiliar, nombre);
			employee_getSueldo(pEmployeeAuxiliar, &sueldo);
			employee_getHorasTrabajadas(pEmployeeAuxiliar, &horasTrabajadas);

			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
    	}

    	sePudoGuardar = 1;
    	fclose(pFile);
    }

    return sePudoGuardar;
}


/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
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
    		pEmployeeAuxiliar = (Employee*)ll_get(pArrayListEmployee, i);
    		fwrite(pEmployeeAuxiliar, sizeof(Employee), 1, pFile);
    	}

    	sePudoGuardar = 1;
    	fclose(pFile);
    }

    return sePudoGuardar;
}


/// @brief Le muestra al usuario el menu de opciones y le pide que ingrese la opcion deseada
///
/// @return opcion que el usuario eligió
int controller_showMenu(void)
{
	int opcionElejida;

	MostrarMenuPrincipal();
	PedirEnteroValidado("Ingrese la Opcion Elejida: ", "Error. Opcion Invalida\n", &opcionElejida, 1, 10);

	system("cls");

	return opcionElejida;
}

void controller_exitProgram(LinkedList* pArrayListEmployee)
{
	int opcionElejida;

	opcionElejida = PedirGuardarAntesDeSalir();
	if(opcionElejida == 1)
	{
		controller_saveAsText("data.csv", pArrayListEmployee);
		controller_saveAsBinary("data.bin",pArrayListEmployee);
	}
}


/// @brief Le muestra al usuario la respuesta tras haber realizado una accion en el ABM.
/// 		Ej. Se cargo correctamente, lista Vacia, etc
///
/// @param respuesta int - respuesta de llamada de otra funcion controller indicando que sucedio en la misma
/// @param opcion int - indica que tipo funcion controller fue llamada
void controller_respuesta(int respuesta, int opcion)
{
	switch(opcion)
	{
		case 1: //Respuesta de Carga desde Archivo
		case 2:
			ReportLoad(respuesta);
			break;

		case 3:  //Respuesta de Agregar un Employee
			ReportAdd(respuesta);
			break;

		case 4: //Respuesta de Editar un Employee
			ReportEdit(respuesta);
			break;

		case 5: //Respuesta de Remover un Employee
			ReportRemove(respuesta);
			break;

		case 6: //Respuesta de Listar
			ReportList(respuesta);
			break;

		case 7: //Respuesta de Ordenamiento
			ReportSort(respuesta);
			break;

		case 8: //Respuesta de Guardar a un Archivo
		case 9:
			ReportSave(respuesta);
			break;
	}
}




