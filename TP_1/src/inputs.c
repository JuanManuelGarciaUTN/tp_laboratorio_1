/*
 * inputs.c
 *
 *  Created on: 19 sep. 2021
 *      Author: juanm
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "determinarSiEs.h"


int PedirEnteroValidado(char mensaje[], char mensajeError[], int* pEntero, int minimo, int maximo)
{
	int retorno = 0;
	int enteroIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetInt(&enteroIngresado))
		{
			if(enteroIngresado >= minimo && enteroIngresado <= maximo)
			{

				*pEntero = enteroIngresado;
				retorno = 1;
				break;
			}
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int PedirFloat(char mensaje[], char mensajeError[], float* pFloat)
{
	int retorno = 0;
	float floatIngresado;

	while(1)
	{
		printf("%s", mensaje);
		if(MiGetFloat(&floatIngresado))
		{
			*pFloat = floatIngresado;
			retorno = 1;
			break;
		}
		printf("%s", mensajeError);
	}

	return retorno;
}

int MiGets(char cadena[], int longitud)
{
	fflush(stdin);
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		return 1;
	}
	return 0;
}

int MiGetInt(int* pEntero)
{
	int respuesta;
	char buffer[256];

	respuesta = 0;

	if(pEntero != NULL)
	{
		if(MiGets(buffer, sizeof(buffer)) && EsEntero(buffer))
		{
			*pEntero = atoi(buffer);
			respuesta = 1;
		}
	}

	return respuesta;
}

int MiGetFloat(float* flotante)
{
	int respuesta;
	char buffer[256];

	respuesta = 0;

	if(flotante != NULL)
	{
		if(MiGets(buffer, sizeof(buffer)) && EsFloat(buffer))
		{
			*flotante = atof(buffer);
			respuesta = 1;
		}
	}

	return respuesta;
}
