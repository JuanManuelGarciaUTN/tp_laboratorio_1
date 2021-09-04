/*
 * matematica.h
 *
 *  Created on: 4 sep. 2021
 *      Author: Juan Manuel Garcia
 */

#ifndef MATEMATICA_H_
#define MATEMATICA_H_


/// @brief Recibe dos numeros, los suma y devuelve el resultado
///
/// @param numeroUno - primer numero a sumar
/// @param numeroDos - segundo numero a sumar
/// @return el resultado de la suma de los numeros recibidos
float Sumar(float numeroUno, float numeroDos);

/// @brief Recibe dos numeros, los resta y devuelve el resultado
///
/// @param numeroUno - primer numero a restar
/// @param numeroDos - segundo numero a restar
/// @return el resultado de la resta de los numeros recibidos
float Restar(float numeroUno, float numeroDos);

/// @brief Recibe dos numeros, los multiplica y devuelve el resultado
///
/// @param numeroUno - primer numero a multiplicar
/// @param numeroDos - segundo numero a multiplicar
/// @return el resultado de la multiplicacion de los numeros recibidos
float Multiplicar(float numeroUno, float numeroDos);


/// @brief Recibe dos numeros, los divide y devuelve el resultado
///
/// @param numeroUno - dividendo
/// @param numeroDos - divisor
/// @return el resultado de la division de los numeros recibidos
float Dividir(float numeroUno, float numeroDos);


/// @brief recibe un numero, calcula su factorial y lo devuelve
///
/// @param numero - numero a calcular factorial
/// @return el factorai del numero recibido
unsigned long Factorial(float numero);

#endif /* MATEMATICA_H_ */
