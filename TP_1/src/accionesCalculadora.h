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

/// @brief Pide al usuario que ingrese un numero
///
/// @param mensaje - el mensaje que se le muestra al usuario
///
/// @return numero ingresado por el usuario
float PedirNumero(char mensaje[]);


/// @brief Pide al usuario ingresar la opcion elejida y la valida segun los parametros
///
/// @param minimo - rango minimo de las opciones posible
/// @param maximo - rango maximo de las opciones posibles
///
/// @return opcion elejida por el usuario
int PedirOpcion(int minimo, int maximo);


/// @brief Verifica si se puede calcular el factorial del numero recibido
///
/// @param numero - el numero recibido a verificar
///
/// @return 1 [si se puede calcular factorial] -  0 [si no es posible calcular el factorai]
char PuedoCalcularFactorial(float numero);



#endif /* ACCIONESCALCULADORA_H_ */
