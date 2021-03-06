/*
 ============================================================================
 Name        : TP_1.c
 Author      : Juan Manuel Garcia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "matematica.h"
#include "accionesCalculadora.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout, NULL);

	float numeroUno;
	float numeroDos;

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;

	unsigned long factorialA;
	unsigned long factorialB;

	int opcionElejida;

	int flagIngresoOperandoUno;
	int flagIngresoOperandoDos;

	int flagCalculoResultados;
	int flagCalculoDivision;
	int flagCalculoFactorialA;
	int flagCalculoFactorialB;

	flagIngresoOperandoUno = 0;
	flagIngresoOperandoDos = 0;

	flagCalculoResultados = 0;
	flagCalculoDivision = 0;
	flagCalculoFactorialA = 0;
	flagCalculoFactorialB = 0;

	printf("Bienvenidos a la CALCULADORA \n\n");

	do
	{
		//Mostrar Menu
		MostrarMenu(flagIngresoOperandoUno, flagIngresoOperandoDos, numeroUno, numeroDos);

		//Pedir que el usuario elija una opcion

		PedirEnteroValidado("Ingrese la opcion a realizar: ", "ERROR. ingreso invalido. \n", &opcionElejida, 1, 5);
		system("cls");

		//continuar segun la opcion elejida por el usuario

		switch(opcionElejida)
		{
			case 1:

				flagIngresoOperandoUno = PedirFloat("Ingrese el primer operando: ", "ERROR. Valor ingresado NO es un numero \n", &numeroUno);
				flagCalculoResultados = 0;

				system("cls");
				printf("SE INGRESO EL 1er OPERANDO \n\n");
				break;

			case 2:

				flagIngresoOperandoDos = PedirFloat("Ingrese el segundo operando: ", "ERROR. Valor ingresado NO es un numero \n", &numeroDos);
				flagCalculoResultados = 0;

				system("cls");
				printf("SE INGRESO EL 2do OPERANDO \n\n");
				break;

			case 3:

				if(flagIngresoOperandoUno && flagIngresoOperandoDos)
				{
					//Calculo suma
					resultadoSuma = Sumar(numeroUno, numeroDos);

					//Calculo resta
					resultadoResta = Restar(numeroUno, numeroDos);

					//Calculo division si es posible
					if(numeroDos != 0)
					{
						resultadoDivision = Dividir(numeroUno, numeroDos);
						flagCalculoDivision = 1;
					}

					//Calculo multiplicacion
					resultadoMultiplicacion = Multiplicar(numeroUno, numeroDos);

					//Calculo factorial si es posible
					if(PuedoCalcularFactorial(numeroUno))
					{
						factorialA = Factorial(numeroUno);
						flagCalculoFactorialA = 1;
					}

					if(PuedoCalcularFactorial(numeroDos))
					{
						factorialB = Factorial(numeroDos);
						flagCalculoFactorialB = 1;
					}

					flagCalculoResultados = 1;
					printf("SE REALIZARON LOS CALCULOS\n\n");
				}
				else
				{
					printf("ERROR. No se puede calcular sin antes ingresar operando 1 y 2\n\n");
				}
				break;

			case 4:

				if(flagCalculoResultados)
				{
					printf("RESULTADOS: \n\n");
					//Resultado Suma
					printf("La suma %.2f + %.2f es: %.2f \n", numeroUno, numeroDos, resultadoSuma);

					//Resultado Resta
					printf("La resta %.2f - %.2f es: %.2f \n", numeroUno, numeroDos, resultadoResta);

					//Resultado Division
					if(flagCalculoDivision)
					{
						printf("La division %.2f / %.2f es: %.2f \n", numeroUno, numeroDos, resultadoDivision);
					}
					else
					{
						printf("La division %.2f / %.2f es: No se puede dividir un numero por 0 \n" , numeroUno, numeroDos);
					}

					//Resultado Multiplicacion
					printf("La multiplicacion %.2f * %.2f es: %.2f \n", numeroUno, numeroDos, resultadoMultiplicacion);

					//Resultado Factorial A

					printf("El factorial de %.2f es: ", numeroUno);

					if(flagCalculoFactorialA)
					{
						printf("%lu \n", factorialA);
					}
					else
					{
						if(numeroUno < 0)
						{
							printf("No puede calcular el factorial de un numero negativo \n");
						}
						else
						{
							if(numeroUno - (int)numeroUno == 0)
							{
								printf("La calculadora no puede calcular el factorial de un numero mayor a 12 \n");
							}
							else
							{
								printf("No puede calcular el factorial de un numero con decimales \n");
							}
						}
					}

					//Resultado Factorial B
					printf("El factorial de %.2f es: ", numeroDos);

					if(flagCalculoFactorialB)
					{
						printf("%lu \n\n", factorialB);
					}
					else
					{
						if(numeroDos < 0)
						{
							printf("No puede calcular el factorial de un numero negativo \n");
						}
						else
						{
							if(numeroDos - (int)numeroDos == 0)
							{
								printf("La calculadora no puede calcular el factorial de un numero mayor a 12 \n");
							}
							else
							{
								printf("No puede calcular el factorial de un numero con decimales \n");
							}
						}
					}


					//Resetear Calculadora
					flagIngresoOperandoUno = 0;
					flagIngresoOperandoDos = 0;

					flagCalculoResultados = 0;
					flagCalculoDivision = 0;
					flagCalculoFactorialA = 0;
					flagCalculoFactorialB = 0;

					//Mantener los resultados en pantalla hasta que el usuario presione Enter
					PresioneEnterParaContinuar();
					system("cls");

				}
				else
				{
					printf("ERROR. No se puede mostrar resultados sin antes calcularlos \n\n");
				}
				break;

			case 5:
				printf("\nFINALIZAR EL PROGRAMA\n");
				break;
		}

	} while(opcionElejida != 5);

	return EXIT_SUCCESS;
}
