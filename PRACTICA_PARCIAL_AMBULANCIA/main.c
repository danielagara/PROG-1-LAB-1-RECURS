#include <stdio.h>
#include <stdlib.h>
#include "asociado.h"
#include "llamada.h"
#include "validar.h"
#include "estadisticas.h"
#define TAM_ASOCIADOS 20
#define TAM_LLAMADAS 100

int main()
{
    EAsociado arrayAsociados[TAM_ASOCIADOS];
    asoc_initAsociado(arrayAsociados,TAM_ASOCIADOS);

    ELlamadas arrayLlamadas[TAM_LLAMADAS];
    llama_initLlamadas(arrayLlamadas,TAM_LLAMADAS);

    char bufferInt[40];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DE ASOCIADO\n2-MODIFICAR DATOS ASOCIADO\n3-BAJA DE ASOCIADO\n4-NUEVA LLAMADA\n5-ASIGNAR AMBULANCIA\n6-INFORMES\n7-SALIR\n","\nSolo de 1 a 6\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                asoc_cargarAsociado(arrayAsociados,asoc_buscarIndiceAsociadoLibre(arrayAsociados,TAM_ASOCIADOS),TAM_ASOCIADOS);
                break;
            case 2:
                asoc_editarAsociado(arrayAsociados,TAM_ASOCIADOS);
                break;
            case 3:
                asoc_bajarAsociado(arrayAsociados,TAM_ASOCIADOS);
                break;
            case 4:
                llama_nuevaLlamada(arrayLlamadas,llama_buscarIndiceLlamadaLibre(arrayLlamadas,TAM_LLAMADAS), TAM_LLAMADAS,asoc_pideId(arrayAsociados,TAM_ASOCIADOS));
                break;
            case 5:
                llama_asignaAmbualncia(arrayLlamadas,TAM_LLAMADAS);
                break;

            case 6:
                //1: FALTA
                printf("\n  -El nombre y apellido del asociado con mas llamados: \n");
                est_AsociadoMaxLlamadas(arrayAsociados,TAM_ASOCIADOS, arrayLlamadas,TAM_LLAMADAS);
                //2:
                printf("\n -El o los motivo/s mas recurrente/s y su cantidad: \n");
                llama_motivoMasRecurrente(arrayLlamadas,TAM_LLAMADAS);
                //3: FALTA
                printf("\n-El motivo que en promedio mas demora en ser resuelto: \n");
                llama_motivoConMayorTiempoPromedio(arrayLlamadas,TAM_LLAMADAS);
                break;
        }

    }while( atoi(bufferInt) != 7);

    return 0;
}

