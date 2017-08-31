#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#define CANT_EMPLEADOS 3


int main()
{
    int edad[CANT_EMPLEADOS];
    float salario[CANT_EMPLEADOS],promedio;
    int estado[CANT_EMPLEADOS];

    if(cargaEstado(estado,CANT_EMPLEADOS)!=-1)
    {
        if(obtenerDatos(edad, salario, estado, CANT_EMPLEADOS)!=-1)
        {
            mostrarDatos(edad, salario, estado, CANT_EMPLEADOS);
            calcularPromedio(edad, estado, CANT_EMPLEADOS, &promedio);
            printf("\nPROM: %.2f",promedio);
        }

        printf("\nMAX: %f",salario[calcularMaximo(salario, estado, CANT_EMPLEADOS)]);
    }



    return 0;
}
