/*
 * accionesCalculadora.c
 *
 *  Created on: 4 sep. 2021
 *      Author: Juan Manuel Garcia
 */


#include "accionesCalculadora.h"

float PedirNumero(char mensaje[])
{
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	printf("\n");

	return numeroIngresado;
}

int PedirOpcion(int minimo, int maximo)
{
	int opcionElejida;

	printf("Ingrese accion a realizar: ");
	scanf("%d", &opcionElejida);

	while(opcionElejida < minimo || opcionElejida > maximo)
	{
		printf("Opcion Ingresada Invalida. \n"
				"Vuelva a ingresar accion a realizar: ");
		scanf("%d", &opcionElejida);
	}

	return opcionElejida;
}

char PuedoCalcularFactorial(float numero)
{
	char bool;
	bool = 0;

	if(numero >= 0 && numero - (int)numero == 0 )
	{
		bool = 1;
	}

	return bool;
}
