/*
 * inputs.h
 *
 *  Created on: 19 sep. 2021
 *      Author: juanm
 */

#ifndef INPUTS_H_
#define INPUTS_H_


/// @brief Le pide al usuario que ingrese un Entero y si se encuentra dentro de un rango lo asigna a una posicion de memoria
///
/// @param mensaje - el mensaje que se le muestra al usuario
/// @param mensajeError - el mensaje que se le muestra al usuario si ingresa un dato invalido
/// @param pEntero - la direccion de memoria donde se guardara el dato una vez validado
/// @param minimo - rango minimo de validacion
/// @param maximo - rango maximo de validacion
/// @return 1[se devolvio un dato validado] 0[si hubo algun error]
int PedirEnteroValidado(char mensaje[], char mensajeError[], int* pEntero, int minimo, int maximo);


/// @brief Le pide al usuario que ingrese un Float y valida que sea flotante
///
/// @param mensaje - el mensaje que se le muestra al usuario
/// @param mensajeError - el mensaje que se le muestra al usuario si ingresa un dato invalido
/// @param pFloat - la direccion de memoria donde se guardara el flotante
/// @return 1[se devolvio un float] 0[si hubo algun error]
int PedirFloat(char mensaje[], char mensajeError[], float* pFloat);

/// @brief Permite al usuario ingresar un dato como cadena char
///
/// @param cadena - vector tipo char donde se guarda la cadena ingresada
/// @param longitud - la longitud del vector donde se guarla la cadena ingresada
/// @return 0[si no hubo ningun error] -1[si hubo un error]
int MiGets(char cadena[], int longitud);

/// @brief Permite ingresar un entero como cadena de texto y valida que sea un entero
///
/// @param entero - Puntero donde se guarda el entero ingresado
/// @return 1[si el usuario ingreso un entero] 0[si el usuario no ingreso un entero]
int MiGetInt(int* entero);

/// @brief Permite ingresar un entero como cadena de texto y valida que sea un float
///
/// @param flotante - Puntero donde se guarda el float ingresado
/// @return 1[si el usuario ingreso un float] 0[si el usuario no ingreso un float]
int MiGetFloat(float* flotante);

#endif /* INPUTS_H_ */
