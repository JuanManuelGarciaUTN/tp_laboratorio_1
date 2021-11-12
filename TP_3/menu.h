/*
 * menu.h
 *
 *  Created on: 3 nov. 2021
 *      Author: juanm
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

/// @brief Le muestra al usuario el Menu Principal
///
void MostrarMenuPrincipal();


/// @brief Le muestra al usuario los distintos Criterios de ordenamiento
/// 		y le pide que ingrese el que desea usar
///
/// @return int - criterio de ordenamiento ingresado
int PedirCriterioDeOrdenamiento();


/// @brief Le muestra al usuario el tipo de Ordenamiento Ascendente o Descendente
/// 		y le pide que ingrese el que desea usar
///
/// @return int - 0[Descendente] - 1[Ascendente]
int PedirTipoDeOrdenamiento();


/// @brief Le pregunta al usuario si desea sobrescribir los datos, cuando ya fueron cargados previamente
/// 		y le pide que ingrese la respuesta
///
/// @return 1[el usuario ingreso que SI] - 2[el usuario ingreso que NO]
int PedirSiDeseaSobreescribirEnCarga();


/// @brief Le pregunta al usuario si desea guardar antes de salir del programa
/// 		y le pide que ingrese la respuesta
///
/// @return 1[el usuario ingreso que SI] - 2[el usuario ingreso que NO]
int PedirGuardarAntesDeSalir();

/// @brief Recibe la respuesta de las funciones de carga desde archivo
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportLoad(int respuesta);


/// @brief Recibe la respuesta de las funciones de guardado a archivo
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportSave(int respuesta);


/// @brief Recibe la respuesta de las funciones de agregar employee
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportAdd(int respuesta);


/// @brief Recibe la respuesta de las funciones de baja de employee
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportRemove(int respuesta);


/// @brief Recibe la respuesta de las funciones de Editar employee
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportEdit(int respuesta);


/// @brief Recibe la respuesta de las funciones de Ordenar employees
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportSort(int respuesta);



/// @brief Recibe la respuesta de las funciones de Listar employees
/// 		y muestra el mensaje correspondiente al usuario.
///
/// @param respuesta que se debe mostrar al usuario
void ReportList(int respuesta);


/// @brief Espera que el usuario ingrese ENTER para continuar
/// 		con la ejecucion del programa.
void PresioneEnterParaContinuar(void);

#endif /* MENU_H_ */
