#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "abonado.h"
#include "llamada.h"
#include "estadisticas.h"

#define TAM_ABONADOS 100
#define TAM_LLAMADAS 1000

int main()
{
    EAbonado arrayAbonados[TAM_ABONADOS];
    abo_initAbonado(arrayAbonados,TAM_ABONADOS);

    ELlamada arrayLlamadas[TAM_LLAMADAS];
    llama_initLlamadas(arrayLlamadas,TAM_LLAMADAS);

    char bufferInt[40];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DE ABONADO\n2-MODIFICAR DATOS ABONADO\n3-BAJA DE ABONADO\n4-NUEVA LLAMADA\n5-FIN DE LA LLAMADA\n6-INFORMES\n7-SALIR\n","\nSolo de 1 a 6\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                abo_cargarAbonado(arrayAbonados,abo_buscarIndicEAbonadoLibre(arrayAbonados,TAM_ABONADOS),TAM_ABONADOS);
                break;
            case 2:
                abo_editarAbonado(arrayAbonados,TAM_ABONADOS);
                break;
            case 3:
                abo_bajarAbonado(arrayAbonados,TAM_ABONADOS);
                break;
            case 4:
                llama_nuevaLlamada(arrayLlamadas,llama_buscarIndiceLlamadaLibre(arrayLlamadas,TAM_LLAMADAS),TAM_LLAMADAS,abo_pideId(arrayAbonados,TAM_ABONADOS));
                break;
            case 5:
                llama_finalizaLlamada(arrayLlamadas,TAM_LLAMADAS);
                break;
            case 6:
                printf("NOMBRE Y APELLIDO DEL ABONADO CON MAS CANTIDAD DE RECLAMOS: \n\n");
                est_AbonadoMaxLlamadas(arrayAbonados,TAM_ABONADOS,arrayLlamadas,TAM_LLAMADAS);

                printf("___________________________\n");

                printf("RECLAMO MAS REALIZADO: \n\n");
                llama_motivoMasRecurrente(arrayLlamadas,TAM_LLAMADAS);

                printf("___________________________\n");

                printf("RECLAMO QUE EN PROMEDIO DEMORA MAS EN SER RESUELTO: \n\n");
                llama_motivoTiempoPromedio(arrayLlamadas,TAM_LLAMADAS);
                break;
        }
    }while( atoi(bufferInt) != 7);

    return 0;
}
