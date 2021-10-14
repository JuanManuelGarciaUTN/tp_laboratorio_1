/*
 * menu.h
 *
 *  Created on: 12 oct. 2021
 *      Author: juanm
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "ArrayEmployees.h"

/// @brief Muestra en pantalla el menu principal
///
void MostrarMenuPrincipal(void);

/// @brief Muestra en pantalla el sub-menu de informes
///
void MostrarSubMenuInformes(void);

/// @brief Muestra en pantalla el sub-menu de modificaciones
///
void MostrarSubMenuModificaciones(void);

/// @brief Le pide al usuario ingrese Enter para continuar la ejecucion del programa
///
void PresioneEnterParaContinuar(void);

/// @brief Toma la opcion ingresada por el usuario y realiza la accion pertinente (ALTA, BAJA, MODIFICACION, INFORMES o SALIR)
///
/// @param opcionElejida int opcion que el usuario desea realizar
/// @param listaEmployees Employee* puntero a un array de empleados
/// @param longitud int longitud del array de empleados
/// @param proximoIdNuevo int* puntero a variable tipo int que almacena el proximo nuevo ID
/// @param almenosUnEmpleadoCargado int* puntero a bandera que indica hay al menos un empleado cargado
void RealizarOpcionElejida(int opcionElejida, Employee listaEmployees[], int longitud, int* proximoIdNuevo, int* almenosUnEmpleadoCargado);



#endif /* MENU_H_ */
