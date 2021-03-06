/*
 * accionesCalculadora.h
 *
 *  Created on: 4 sep. 2021
 *      Author: Juan Manuel Garcia
 */

#ifndef ACCIONESCALCULADORA_H_
#define ACCIONESCALCULADORA_H_

#include <stdio.h>
#include <stdlib.h>


/// @brief Muestra el menu de la calculadora variando si se ingresaron o no los operandos Uno y Dos
///
/// @param flagIngresoOperandoUno - flag para determinar si se ingreso el operando Uno
/// @param flagIngresoOperandoDos - flag para determinar si se ingreso el operando Dos
/// @param numeroUno - el operando Uno
/// @param numeroDos - el operando Dos
void MostrarMenu(char flagIngresoOperandoUno, char flagIngresoOperandoDos, float numeroUno, float numeroDos);


/// @brief Espera que el usuario presione la tecla Enter para continuar con la ejecucion
///
void PresioneEnterParaContinuar(void);


/// @brief Verifica si se puede calcular el factorial del numero recibido
///
/// @param numero - el numero recibido a verificar
///
/// @return 1 [si se puede calcular factorial] -  0 [si no es posible calcular el factorai]
int PuedoCalcularFactorial(float numero);





#endif /* ACCIONESCALCULADORA_H_ */
