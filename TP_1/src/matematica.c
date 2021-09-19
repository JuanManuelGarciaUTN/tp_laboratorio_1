/*
 * matematica.c
 *
 *  Created on: 4 sep. 2021
 *      Author: Juan Manuel Garcia
 */


#include <stdio.h>
#include <stdlib.h>

#include "matematica.h"

float Sumar(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

float Restar(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

float Dividir(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
}

float Multiplicar(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

unsigned long Factorial(float numero)
{
	unsigned long resultado;
	resultado = 1;

	while(numero > 1)
	{
		resultado *= numero;
		numero--;
	}

	return resultado;
}
