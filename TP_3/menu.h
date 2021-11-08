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

void MostrarMenuPrincipal();


int PedirCriterioDeOrdenamiento();


int PedirTipoDeOrdenamiento();

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



void ReportAdd(int respuesta);
void ReportRemove(int respuesta);
void ReportEdit(int respuesta);
void ReportSort(int respuesta);
void ReportList(int respuesta);
void PresioneEnterParaContinuar(void);

#endif /* MENU_H_ */
