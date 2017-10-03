#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "abonado.h"
#include "llamada.h"
#include "estadisticas.h"
#include "string.h"

#define ESTADO_LLAMADA_LIBRE 0
#define ESTADO_LLAMADA_EN_CURSO 1
#define ESTADO_LLAMADA_SOLUCIONADO 2
#define ESTADO_LLAMADA_NO_SOLUCIONADO 3

#define MOTIVO_FALLA_3G 1
#define MOTIVO_FALLA_LTE 2
#define MOTIVO_FALLA_EQUIPO 3

#define ESTADO_ABONADO_LIBRE 0
#define ESTADO_ABONADO_OCUPADO 1

int est_AbonadoMaxLlamadas(EAbonado* arrayAbonados, int lenAbonados, ELlamada* arrayLlamadas, int lenLlamadas)
{
    int i;
    int maxLlamadas=0;
    int idAbonadoMAX;
    int cantidadAUX=0;

    for(i=0;i<lenAbonados;i++)
    {
        if(arrayAbonados[i].flagDeEstado==ESTADO_ABONADO_OCUPADO)
        {
            cantidadAUX=llama_cuentaLlamadas(arrayLlamadas,lenLlamadas,arrayAbonados[i].idAbonado);
            if(cantidadAUX>maxLlamadas)
            {
                maxLlamadas=cantidadAUX;
                idAbonadoMAX=arrayAbonados[i].idAbonado;
            }
        }
    }

    for(i=0;i<lenAbonados;i++)
    {
        if(idAbonadoMAX==arrayAbonados[i].idAbonado)
        {
            printf("EL NOMBRE DE LA PERSONA CON MAS LLAMADAS ES: %s, APELLIDO: %s, Y LA CANTIDAD DE LLAMADAS ES: %d \n", arrayAbonados[i].nombre, arrayAbonados[i].apellido, maxLlamadas);
            break;
        }
    }
    return 0;
}
