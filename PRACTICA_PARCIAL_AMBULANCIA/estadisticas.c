#include <stdio.h>
#include <stdlib.h>
#include "llamada.h"
#include "validar.h"
#include "asociado.h"
#include "estadisticas.h"
#include <string.h>

int est_AsociadoMaxLlamadas(EAsociado* arrayAsociados, int lenAsociados, ELlamadas* arrayLlamadas, int lenLlamadas)
{
    int i;
    int maxLlamadas=0;
    int idAsociadoMAX;
    int cantidadAUX=0;

    for(i=0;i<lenAsociados;i++)
    {
        if(arrayAsociados[i].flagDeEstado==ESTADO_ASOCIADO_OCUPADO)
        {
            cantidadAUX=llama_cuentaLlamadas(arrayLlamadas,lenLlamadas,arrayAsociados[i].id_asociado);
            if(cantidadAUX>maxLlamadas)
            {
                maxLlamadas=cantidadAUX;
                idAsociadoMAX=arrayAsociados[i].id_asociado;
            }
        }
    }

    for(i=0;i<lenAsociados;i++)
    {
        if(idAsociadoMAX==arrayAsociados[i].id_asociado)
        {
            printf("\n SOLO NOMBRE %s \n", arrayAsociados[i].apellido);
            printf("EL NOMBRE DE LA PERSONA CON MAS LLAMADAS ES: %s, APELLIDO: %s, Y LA CANTIDAD DE LLAMADAS ES: %d \n", arrayAsociados[i].apellido, arrayAsociados[i].apellido, maxLlamadas);
            break;
        }
    }
    return 0;
}
