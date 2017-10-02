#include <stdio.h>
#include <stdlib.h>
#include "alquiler.h"
#include "validar.h"
#include "cliente.h"
#include "estadisticas.h"
#include <string.h>

#define ESTADO_CLIENTE_LIBRE 0
#define ESTADO_CLIENTE_OCUPADO 1

#define ESTADO_ALQUILER_LIBRE 0
#define ESTADO_ALQUILER_ALQUILADO 1
#define ESTADO_ALQUILER_FINALIZADO 2

int est_AsociadoMaxLlamadas(ECliente* arrayClientes, int lenClientes, EAlquiler* arrayAlquileres, int lenAlquileres)
{
    int i;
    int maxAlquileres=0;
    int idClienteMAX;
    int cantidadAUX=0;

    for(i=0;i<lenClientes;i++)
    {
        if(arrayClientes[i].flagDeEstado==ESTADO_CLIENTE_OCUPADO)
        {
            cantidadAUX=alqui_cuentaAlquileres(arrayAlquileres,lenAlquileres,arrayClientes[i].idCliente);
            if(cantidadAUX>maxAlquileres)
            {
                maxAlquileres=cantidadAUX;
                idClienteMAX=arrayClientes[i].idCliente;
            }
        }
    }

    for(i=0;i<lenClientes;i++)
    {
        if(idClienteMAX==arrayClientes[i].idCliente)
        {
            printf("EL NOMBRE DE LA PERSONA CON MAS ALQUILERES ES: %s, APELLIDO: %s, Y LA CANTIDAD DE ALQUILERES ES: %d \n", arrayClientes[i].nombre, arrayClientes[i].apellido, maxAlquileres);
            break;
        }
    }
    return 0;
}
