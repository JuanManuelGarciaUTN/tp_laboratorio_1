/*
 * determinarSiEs.c
 *
 *  Created on: 19 sep. 2021
 *      Author: juanm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funciones para validar si una cadena es de un tipo formato Es[validacio] ej EsNumerica, EsPositivo, etc
int EsEntero(char cadena[])
{
	int i;
	int esNumerica;

	i = 0;
	esNumerica = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				esNumerica = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		esNumerica = 0;
	}

	return esNumerica;
}

int EsFloat(char cadena[])
{
	int i;
	int esFlotante;
	int flagPrimerComa;

	i = 0;
	flagPrimerComa = 0;
	esFlotante = 1;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if(cadena[i] == '.' && flagPrimerComa == 0)
			{
				flagPrimerComa = 1;
			}
			else
			{
				if(cadena[i] == ',' && flagPrimerComa == 0)
				{
					flagPrimerComa = 1;
					cadena[i] = '.';
				}
				else
				{
					if(cadena[i] < '0' || cadena[i] > '9')
					{
						esFlotante = 0;
						break;
					}
				}
			}
			i++;
		}
	}
	else
	{
		esFlotante = 0;
	}

	return esFlotante;
}
