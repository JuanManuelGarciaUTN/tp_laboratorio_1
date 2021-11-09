/*
 * menu.c
 *
 *  Created on: 3 nov. 2021
 *      Author: juanm
 */

#include "menu.h"

void MostrarMenuPrincipal()
{
	printf("    Menu: \n\n"
		   " 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n"
		   " 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).  \n"
		   " 3. Alta de empleado  \n"
		   " 4. Modificar datos de empleado  \n"
		   " 5. Baja de empleado  \n"
		   " 6. Listar empleados  \n"
		   " 7. Ordenar empleados  \n"
		   " 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).  \n"
		   " 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).  \n"
		   "10. Salir \n\n");
}

int PedirCriterioDeOrdenamiento()
{
	int criterio;

	printf("    Criterios de Ordenamiento: \n\n"
		   "1. Por ID \n"
		   "2. Por Nombre \n"
		   "3. Por Salario \n"
		   "4. Por Salario y Nombre \n"
		   "5. Por Horas Trabajadas \n"
		   "6. Por Horas Trabajadas y Nombre \n\n");

	PedirEnteroValidado("Ingrese el Criterio deseado: ", "ERROR. Opcion Invalida \n", &criterio, 1, 6);

	return criterio;
}

int PedirGuardarAntesDeSalir()
{
	int criterio;

	printf("    ¿Desea Guardar Antes de Salir?: \n\n"
		   "1. SI \n"
		   "2. NO \n\n");

	PedirEnteroValidado("Ingrese Respuesta: ", "ERROR. Opcion Invalida \n", &criterio, 1, 2);

	return criterio;
}

int PedirTipoDeOrdenamiento()
{
	int tipo;

	printf("    ¿Desea Ordenar Ascendente o Descendente? \n\n"
		   "0. Descendente \n"
		   "1. Ascendente \n\n");

	PedirEnteroValidado("Ingrese la respuesta: ", "ERROR. Opcion Invalida \n", &tipo, 0, 1);

	return tipo;
}


int PedirSiDeseaSobreescribirEnCarga()
{
	int sobrecargar;

	printf("    Ya hay datos cargados \n"
			    "¿Desea Sobrescribirlos \n\n"
		   "1. SI \n"
		   "2. NO \n\n");

	PedirEnteroValidado("Ingrese la respuesta: ", "ERROR. Opcion Invalida \n", &sobrecargar, 1, 2);

	return sobrecargar;
}


void ReportLoad(int respuesta)
{
	system("cls");

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

		case -3:
			printf("ERROR. El Archivo NO Existe\n\n");
			break;
	}
}


void ReportSave(int respuesta)
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

void ReportSort(int respuesta)
{
	system("cls");
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

void ReportList(int respuesta)
{
	switch(respuesta)
	{
		case 1:
			PresioneEnterParaContinuar();
			system("cls");

			break;
		case 0:
			printf("NO SE PUDO Mostar la Lista de Empleados, Ya Que Esta VACIA\n\n");
			break;
	}
}

void ReportAdd(int respuesta)
{
	system("cls");
	switch(respuesta)
	{
		case 1:
			printf("Se AGREGO el empleado Correctamente \n\n");
			break;
	}
}

void ReportRemove(int respuesta)
{
	system("cls");
	switch(respuesta)
	{
		case 1:
			printf("Se dio BAJA al empleado Correctamente \n\n");
			break;

		case -1:
			printf("NO SE PUEDE dar Baja un empleado, Ya que la Lista esta VACIA \n\n");
			break;
	}
}

void ReportEdit(int respuesta)
{
	system("cls");
	switch(respuesta)
	{
		case -1:
			printf("NO SE PUEDE dar Modificar un empleado, Ya que la Lista esta VACIA \n\n");
			break;

		case 0:
			printf("NO se Modifico la Lista \n\n");
			break;

		case 1:
			printf("Se Modifico la Lista CORRECTAMENTE \n\n");
			break;
	}
}

void PresioneEnterParaContinuar(void)
{
	fflush(stdin);
	printf("\nPresione Enter para Continuar...\n");
	getchar();
}
