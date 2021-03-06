#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

    int option;
    int respuesta;
    LinkedList* listaEmpleados = NULL;
    listaEmpleados = ll_newLinkedList();

    do{

    	option = controller_showMenu();

        switch(option)
        {
            case 1:
            	respuesta = controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
            	respuesta = controller_loadFromBinary("data.bin",listaEmpleados);
                break;

            case 3:
            	respuesta = controller_addEmployee(listaEmpleados);
                break;

            case 4:
            	respuesta = controller_editEmployee(listaEmpleados);
                break;

            case 5:
            	respuesta = controller_removeEmployee(listaEmpleados);
                break;

            case 6:
            	respuesta = controller_ListEmployee(listaEmpleados);
                break;

            case 7:
            	respuesta = controller_sortEmployee(listaEmpleados);
                break;

            case 8:
            	respuesta = controller_saveAsText("data.csv", listaEmpleados);
                break;

            case 9:
            	respuesta = controller_saveAsBinary("data.bin",listaEmpleados);
                break;

            case 10:
            	controller_exitProgram(listaEmpleados);
                break;
        }

        controller_respuesta(respuesta, option);

    }while(option != 10);

    return 0;
}

