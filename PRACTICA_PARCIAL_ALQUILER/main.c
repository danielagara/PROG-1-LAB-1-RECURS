#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "cliente.h"
#include "alquiler.h"
#include "estadisticas.h"

#define TAM_CLIENTES 100
#define TAM_ALQUILERES 1000

int main()
{
    ECliente arrayClientes[TAM_CLIENTES];
    cli_initCliente (arrayClientes,TAM_CLIENTES);

    EAlquiler arrayAlquileres[TAM_ALQUILERES];
    alqui_initAlquileres(arrayAlquileres,TAM_ALQUILERES);

    char bufferInt[40];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DE CLIENTE\n2-MODIFICAR DATOS CLIENTE\n3-BAJA DE CLIENTE\n4-NUEVO ALQUILER\n5-FIN DE ALQUILER\n6-INFORMES\n7-SALIR\n","\nSolo de 1 a 6\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                cli_cargarCliente(arrayClientes,cli_buscarIndiceClienteLibre(arrayClientes,TAM_CLIENTES),TAM_CLIENTES);
                break;
            case 2:
                cli_editarCliente(arrayClientes,TAM_CLIENTES);
                break;
            case 3:
                cli_bajarCliente(arrayClientes,TAM_CLIENTES);
                break;
            case 4:
                alqui_nuevoAlquiler(arrayAlquileres,alqui_buscarIndiceAlquilerLibre(arrayAlquileres,TAM_ALQUILERES),TAM_ALQUILERES,cli_pideId(arrayClientes,TAM_CLIENTES));
                break;
            case 5:
                alqui_finalizaAlquiler(arrayAlquileres,TAM_ALQUILERES);
                break;
            case 6:
                est_AsociadoMaxLlamadas(arrayClientes,TAM_CLIENTES,arrayAlquileres,TAM_ALQUILERES);

                alqui_equipoMasRecurrente(arrayAlquileres,TAM_ALQUILERES);

                alqui_equipoTiempoPromedio(arrayAlquileres,TAM_ALQUILERES);
                break;
        }
    }while( atoi(bufferInt) != 7);
    return 0;
}
