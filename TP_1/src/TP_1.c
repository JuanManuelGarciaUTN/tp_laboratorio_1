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

	char boolIngresoOperandoUno;
	char boolIngresoOperandoDos;

	char boolCalculoResultados;
	char boolCalculoDivision;
	char boolCalculoFactorialA;
	char boolCalculoFactorialB;

	boolIngresoOperandoUno = 0;
	boolIngresoOperandoDos = 0;

	boolCalculoResultados = 0;
	boolCalculoDivision = 0;
	boolCalculoFactorialA = 0;
	boolCalculoFactorialB = 0;

	printf("Bienvenidos a la CALCULADORA \n\n");


	do
	{
		//Mostrar Menu
		printf("Opciones: \n");

		if(boolIngresoOperandoUno)
		{
			printf("1. Ingresar 1er operando (A = %.2f) \n", numeroUno);
		}
		else
		{
			printf("1. Ingresar 1er operando (A = x) \n");
		}

		if(boolIngresoOperandoDos)
		{
			printf("2. Ingresar 2do operando (B = %.2f) \n", numeroDos);
		}
		else
		{
			printf("2. Ingresar 2do operando (B = x) \n");
		}

		printf("3. Calcular: \n"
				"	-La suma A + B \n"
				"	-La resta A - B \n"
				"	-La division A / B \n"
				"	-La multiplicacion A * B \n"
				"	-El factorial A! \n"
				"	-El factorail B! \n"
				"4. Mostrar Resultados \n"
				"5. Salir del Programa \n\n");

		//Pedir que el usuario elija una opcion

		opcionElejida = PedirOpcion(1, 5);

		//continuar segun la opcion elejida por el usuario

		switch(opcionElejida)
		{
			case 1:
				system("cls");

				numeroUno = PedirNumero("Ingrese el 1er operando: ");
				boolIngresoOperandoUno = 1;
				boolCalculoResultados = 0;

				system("cls");
				printf("SE INGRESO EL 1er OPERANDO \n\n");
				break;

			case 2:
				system("cls");

				numeroDos = PedirNumero("Ingrese el 2do operando: ");
				boolIngresoOperandoDos = 1;
				boolCalculoResultados = 0;

				system("cls");
				printf("SE INGRESO EL 2do OPERANDO \n\n");
				break;

			case 3:
				system("cls");

				if(boolIngresoOperandoUno && boolIngresoOperandoDos)
				{
					resultadoSuma = Sumar(numeroUno, numeroDos);
					resultadoResta = Restar(numeroUno, numeroDos);

					if(numeroDos != 0)
					{
						resultadoDivision = Dividir(numeroUno, numeroDos);
						boolCalculoDivision = 1;
					}

					resultadoMultiplicacion = Multiplicar(numeroUno, numeroDos);

					if(PuedoCalcularFactorial(numeroUno))
					{
						factorialA = Factorial(numeroUno);
						boolCalculoFactorialA = 1;
					}

					if(PuedoCalcularFactorial(numeroDos))
					{
						factorialB = Factorial(numeroDos);
						boolCalculoFactorialB = 1;
					}

					boolCalculoResultados = 1;
					printf("SE REALIZARON LOS CALCULOS\n\n");
				}
				else
				{
					printf("ERROR. No se puede calcular sin antes ingresar operando 1 y 2\n\n");
				}
				break;

			case 4:
				system("cls");

				if(boolCalculoResultados)
				{
					printf("RESULTADOS: \n\n");
					//Resultado Suma
					printf("La suma %.2f + %.2f es: %.2f \n", numeroUno, numeroDos, resultadoSuma);

					//Resultado Resta
					printf("La resta %.2f - %.2f es: %.2f \n", numeroUno, numeroDos, resultadoResta);

					//Resultado Division
					if(boolCalculoDivision)
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
					if(boolCalculoFactorialA)
					{
						printf("El factorial %.2f es: %lu \n", numeroUno, factorialA);
					}
					else
					{
						if(numeroUno < 0)
						{
							printf("El factorial de %.2f: No se puede calcular el factorial de un numero negativo \n" , numeroUno);
						}
						else
						{
							printf("El factorial de %.2f: No se puede calcular el factorial de un numero con decimales \n" , numeroUno);
						}
					}

					//Resultado Factorial B
					if(boolCalculoFactorialB)
					{
						printf("El factorial %.2f es: %lu \n\n", numeroDos, factorialB);
					}
					else
					{
						if(numeroDos < 0)
						{
							printf("El factorial de %.2f: No se puede calcular el factorial de un numero negativo \n\n" , numeroDos);
						}
						else
						{
							printf("El factorial de %.2f: No se puede calcular el factorial de un numero con decimales \n\n" , numeroDos);
						}
					}


					//Resetear Calculadora
					boolIngresoOperandoUno = 0;
					boolIngresoOperandoDos = 0;

					boolCalculoResultados = 0;
					boolCalculoDivision = 0;
					boolCalculoFactorialA = 0;
					boolCalculoFactorialB = 0;

					//Mantener los resultados en pantalla hasta que el usuario desee
					printf("Para volver al menu principal presione ENTER");
					fflush(stdin);
					getchar();
					fflush(stdin);
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
