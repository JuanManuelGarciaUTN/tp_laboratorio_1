/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: juanm
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int VerificarCargaBinaria(Employee* pNewEmployee);


#endif /* PARSER_H_ */
