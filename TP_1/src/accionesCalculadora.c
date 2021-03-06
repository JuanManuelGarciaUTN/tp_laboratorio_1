/*
 * accionesCalculadora.c
 *
 *  Created on: 4 sep. 2021
 *      Author: Juan Manuel Garcia
 */


#include "accionesCalculadora.h"


void MostrarMenu(char flagIngresoOperandoUno, char flagIngresoOperandoDos, float numeroUno, float numeroDos)
{
	printf("Opciones: \n");

	if(flagIngresoOperandoUno)
	{
		if(flagIngresoOperandoDos)
		{
			printf("1. Ingresar 1er operando (A = %.2f) \n"
					"2. Ingresar 2do operando (B = %.2f) \n"
					"3. Calcular: \n",numeroUno, numeroDos);
			printf("	-La suma %.2f + %.2f \n",numeroUno, numeroDos);
			printf("	-La resta %.2f - %.2f \n",numeroUno, numeroDos);
			printf("	-La division %.2f / %.2f \n",numeroUno, numeroDos);
			printf("	-La multiplicacion %.2f * %.2f \n",numeroUno, numeroDos);
			printf("	-El factorial %.2f! \n"
					"	-El factorial %.2f!\n"
					"4. Mostrar Resultados \n"
					"5. Salir del Programa \n\n",numeroUno, numeroDos);
		}
		else
		{
			printf("1. Ingresar 1er operando (A = %.2f) \n"
					"2. Ingresar 2do operando (B = y) \n"
					"3. Calcular: \n", numeroUno);
			printf("	-La suma %.2f + B \n", numeroUno);
			printf("	-La resta %.2f - B \n", numeroUno);
			printf("	-La division %.2f / B \n", numeroUno);
			printf("	-La multiplicacion %.2f * B \n", numeroUno);
			printf("	-El factorial %.2f! \n"
					"	-El factorial B!\n"
					"4. Mostrar Resultados \n"
					"5. Salir del Programa \n\n", numeroUno);
		}
	}
	else
	{
		if(flagIngresoOperandoDos)
		{
			printf("1. Ingresar 1er operando (A = x) \n"
					"2. Ingresar 2do operando (B = %.2f) \n"
					"3. Calcular: \n", numeroDos);
			printf("	-La suma A + %.2f \n", numeroDos);
			printf("	-La resta A - %.2f \n", numeroDos);
			printf("	-La division A / %.2f \n", numeroDos);
			printf("	-La multiplicacion A * %.2f \n", numeroDos);
			printf("	-El factorial A! \n"
					"	-El factorial %.f!\n"
					"4. Mostrar Resultados \n"
					"5. Salir del Programa \n\n", numeroDos);
		}
		else
		{
			printf("1. Ingresar 1er operando (A = x) \n"
					"2. Ingresar 2do operando (B = y) \n"
					"3. Calcular: \n"
					"	-La suma A + B \n"
					"	-La resta A - B \n"
					"	-La division A / B \n"
					"	-La multiplicacion A * B \n"
					"	-El factorial A! \n"
					"	-El factorail B! \n"
					"4. Mostrar Resultados \n"
					"5. Salir del Programa \n\n");
		}
	}
}


void PresioneEnterParaContinuar(void)
{
	printf("\nPresione ENTER para continuar\n");
	fflush(stdin);
	getchar();
	fflush(stdin);
}

int PuedoCalcularFactorial(float numero)
{
	int bool;
	bool = 0;

	if(numero >= 0 && numero <= 12 && numero - (int)numero == 0 )
	{
		bool = 1;
	}

	return bool;
}
