#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "asociado.h"
#include "llamada.h"
#define TAM_ASOCIADO 2
#define TAM_LLAMADA 2

int main()
{
    sAsociado arrayAsociado[TAM_ASOCIADO];
    sLlamada arrayLlamada[TAM_LLAMADA];
    char bufferInt[4096];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DEL ASOCIADO\n2-MODIFICAR DATOS DEL ASOCIADO:\n3-BAJA DEL ASOCIADO:\n4-NUEVA LLAMADA:\n5-ASIGNAR AMBULANCIA:\n6-INFORMAR:\n7-Salir\n","\n ERROR!!! ",2,40);
        switch(atoi(bufferInt))
        {
        case 1://ALTA ASOCIADO
            break;
        case 2://MODI
            break;
        case 3://BAJA
            break;
        case 4://ALTA LLAMADA
            break;
        case 5:
            break;
        case 6:
            break;
        }

    }while( atoi(bufferInt) != 7);

    return 0;
}
