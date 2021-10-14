/*
 * menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: juanm
 */


#include "menu.h"

void MostrarMenuPrincipal(void)
{
	printf("Menu de Opciones: \n"
			"	1 -> ALTA de Empleado \n"
			"	2 -> MODIFICAR un Empleado \n"
			"	3 -> BAJA de Empleado \n"
			"	4 -> INFORMES \n"
			"	5 -> SALIR del Programa \n\n");
}

void MostrarSubMenuInformes(void)
{
	printf("Menu de Informes: \n"
			"	1 -> Mostrar Listado de Empleados Ordenado\n"
			"	2 -> Mostar Total, Promedio de Salarios, y Cantidad de Empleados por Encima del Salario Minimo \n"
			"	3 -> Volver al Menu Principal \n\n");
}

void MostrarSubMenuModificaciones(void)
{
	printf("Menu de Modificarciones: \n"
			"	1 -> Modificar NOMBRE\n"
			"	2 -> Modificar APELLIDO\n"
			"	3 -> Modificar SALARIO\n"
			"	4 -> Modificar SECTOR\n"
			"	5 -> Volver al Menu Principal \n\n");
}

void PresioneEnterParaContinuar(void)
{
	printf("\nPresione enter para continuar: ");
	getchar();
}


void RealizarOpcionElejida(int opcionElejida, Employee listaEmployees[], int longitud, int* proximoIdNuevo, int* almenosUnEmpleadoCargado)
{
	int idAuxiliar;
	char nameIngresado[51];
	char lastNameIngresado[51];
	float salaryIngresado;
	int sectorIngresado;
	int indexAuxiliar;

	system("cls");

	switch(opcionElejida)
	{
		case 1:

			PedirSustantivoPropio("Ingrese el Nombre del Empleado: ", "ERROR. Debe ingresar un Nombre \n", nameIngresado, 51);
			PedirSustantivoPropio("Ingrese el Apellido del Empleado: ", "ERROR. Debe ingresar un Nombre \n", lastNameIngresado, 51);
			PedirFloatMayorQue("Ingrese el Salario del Empleado: ", "ERROR. Valor Invalido \n", &salaryIngresado, 0);
			PedirEnteroMayorQue("Ingrese el Sector del Empleado: ", "ERROR. Valor Invalido \n", &sectorIngresado, 0);
			if(addEmployee(listaEmployees, longitud, *proximoIdNuevo, nameIngresado, lastNameIngresado, salaryIngresado, sectorIngresado) == -1)
			{
				system("cls");
				printf("No se Pudo Cargar Un Empleado Porque La Lista Esta Llena \n\n");
			}
			else
			{
				*proximoIdNuevo += 1;
				*almenosUnEmpleadoCargado = TRUE;
				system("cls");
				printf("Se Cargo Un Empleado Correctamente \n\n");
			}
			break;

		case 2:
			if(*almenosUnEmpleadoCargado == FALSE)
			{
				printf("ERROR. Primero Debe Cargar Al Menos un Empleado Para Modificar la Lista\n\n");
			}
			else
			{
				printEmployees(listaEmployees, longitud);
				while(1)
				{
					PedirEntero("\nIngrese el ID del Empleado a Modificar: ", "ERROR. Ingrese un numero Entero", &idAuxiliar);
					indexAuxiliar = findEmployeeById(listaEmployees, longitud, idAuxiliar);
					if(indexAuxiliar != -1)
					{
						MostrarSubMenuModificaciones();
						PedirEnteroValidado("Ingrese Opcion a realizar: ", "ERROR. Opcion ingresada inexistente\n", &opcionElejida, 1, 5);

						switch(opcionElejida)
						{
							case 1:
								PedirSustantivoPropio("Ingrese el Nombre del Empleado: ", "ERROR. Debe ingresar un Nombre \n", listaEmployees[indexAuxiliar].name, 51);
								break;

							case 2:
								PedirSustantivoPropio("Ingrese el Apellido del Empleado: ", "ERROR. Debe ingresar un Nombre \n", listaEmployees[indexAuxiliar].lastName, 51);
								break;

							case 3:
								PedirFloatMayorQue("Ingrese el Salario del Empleado: ", "ERROR. Valor Invalido \n", &listaEmployees[indexAuxiliar].salary, 0);
								break;

							case 4:
								PedirEnteroMayorQue("Ingrese el Sector del Empleado: ", "ERROR. Valor Invalido \n", &listaEmployees[indexAuxiliar].sector, 0);
								break;

							case 5:
								break;
						}
						system("cls");
						if(opcionElejida != 5)
						{
							printf("Se Modifico el Empleado Correctamente \n\n");
						}
						break;
					}

					printf("No existe un empleado con el ID ingresado \n"
							"	1 -> Para volver a intentarlo \n"
							"	2 -> Para volver al Menu Principal \n\n");
					PedirEnteroValidado("Ingrese opcion: ", "ERROR. Opcion ingresada inexistente\n", &opcionElejida, 1, 2);

					if(opcionElejida == 2)
					{
						system("cls");
						break;
					}
				}
			}
			break;

		case 3:
			if(*almenosUnEmpleadoCargado == FALSE)
			{
				printf("ERROR. Primero Debe Cargar Al Menos un Empleado Para dar BAJA a un Empleado de la Lista\n\n");
			}
			else
			{
				printEmployees(listaEmployees, longitud);
				do
				{
					PedirEntero("\nIngrese el ID del Empleado a Dar de Baja: ", "ERROR. Ingrese un numero Entero", &idAuxiliar);
					if(removeEmployee(listaEmployees, longitud, idAuxiliar) == 0)
					{
						if(isEmployeesEmpty(listaEmployees, longitud))
						{
							*almenosUnEmpleadoCargado = FALSE;
						}
						system("cls");
						printf("Se Dio de Baja al Empleado Correctamente \n\n");
						break;
					}
					printf("No existe un empleado con el ID ingresado \n"
							"	-> Ingrese 1 para volver a intentarlo \n"
							"	-> Ingrese 2 para volver al Menu Principal \n");
					PedirEnteroValidado("", "ERROR. Opcion ingresada inexistente\n", &opcionElejida, 1, 2);

				} while(opcionElejida != 2);
			}
			break;

		case 4:
			if(*almenosUnEmpleadoCargado == FALSE)
			{
				printf("ERROR. Primero Debe Cargar Al Menos un Empleado Para Mostrar Informes sobre Lista\n\n");
			}
			else
			{
				MostrarSubMenuInformes();
				PedirEnteroValidado("Ingrese Accion a Realizar: ", "ERROR. opcion ingresada inexistente\n", &opcionElejida, 1, 3);

				switch(opcionElejida)
				{
					case 1:

						printf("\n¿Como desea que se muestre la lista? \n"
								"	0 -> Ordenada Descendentemente \n"
								"	1 -> Ordenada Ascendentemente \n");
						PedirEnteroValidado("Ingrese Tipo de Ordenamiento: ", "ERROR. opcion ingresada inexistente\n", &opcionElejida, 0, 1);

						sortEmployees(listaEmployees, longitud, opcionElejida);
						system("cls");
						printf("La Lista de Empleados Ordenada es: \n\n");
						printEmployees(listaEmployees, longitud);
						PresioneEnterParaContinuar();
						system("cls");
						break;

					case 2:
						system("cls");
						reportEmployeesAverageSalary(listaEmployees, longitud);
						PresioneEnterParaContinuar();
						system("cls");
						break;

					case 3:
						system("cls");
						break;
				}
			}
			break;

		case 5:
			system("cls");
			printf("Gracias, Vuelva Pronto \n\n");
			PresioneEnterParaContinuar();
			break;
	}
}
