#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validar.h"
#define LONG_PERSONA 20

int main()
{
    char bufferInt[40];

    EPersona arrayPersona[LONG_PERSONA];

    perso_initPersona(arrayPersona,LONG_PERSONA);

    do
    {
        val_getUnsignedInt(bufferInt,"\n1- Agregar persona\n 2- Borrar persona\n 3- Imprimir lista ordenada por  nombre\n 4- Imprimir grafico de edades\n\n 5- Salir\n","\nSolo 1 y 2\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                perso_cargarPersona(arrayPersona,perso_obtenerEspacioLibre(arrayPersona,LONG_PERSONA), LONG_PERSONA);
                break;
            case 2:
                perso_borrarPersona(arrayPersona,LONG_PERSONA,"INGRESE EL DNI DE LA PERSONA A BORRAR: \n");
                break;
            case 3:
                perso_insertionSort(arrayPersona,LONG_PERSONA);
                perso_printPersona(arrayPersona, LONG_PERSONA);
                break;
            case 4:
                perso_imprimirGrafico(arrayPersona,LONG_PERSONA);
                break;
        }

    }while( atoi(bufferInt) != 5);

    return 0;
}
