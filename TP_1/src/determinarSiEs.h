/*
 * determinarSiEs.h
 *
 *  Created on: 19 sep. 2021
 *      Author: juanm
 */

#ifndef DETERMINARSIES_H_
#define DETERMINARSIES_H_


//Funciones para validar si una cadena es de un tipo con formato Es[validacion] ej EsNumerica, EsPositivo, etc

/// @brief Recibe una cadena de texto y valida que sea un Entero
///
/// @param cadena - la cadena a validar
/// @return 1[si es entero] 0[si no es entero]
int EsEntero(char cadena[]);


/// @brief Recibe una cadena de texto y valida que sea un Flotante
///
/// @param cadena - la cadena a validar
/// @return 1[si es Flotante] 0[si no es Flotante]
int EsFloat(char cadena[]);

#endif /* DETERMINARSIES_H_ */
