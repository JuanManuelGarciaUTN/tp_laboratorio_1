/*
 ============================================================================
 Name        : TP_2.c
 Author      : Juan Manuel Garcia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define ELEMENTS_MAX 1000

int main(void) {

	Employee listaEmpleados[ELEMENTS_MAX];
	int proximoIdNuevo;
	int opcionElejida;
	int almenosUnEmpleadoCargado;

	proximoIdNuevo = 1;
	almenosUnEmpleadoCargado = FALSE;

	initEmployees(listaEmpleados, ELEMENTS_MAX);

	do
	{
		MostrarMenuPrincipal();
		PedirEnteroValidado("Ingrese una Opcion: ", "ERROR, opcion Invalida \n", &opcionElejida, 1, 5);
		RealizarOpcionElejida(opcionElejida, listaEmpleados, ELEMENTS_MAX, &proximoIdNuevo, &almenosUnEmpleadoCargado);

	} while(opcionElejida != 5);


	return EXIT_SUCCESS;
}
