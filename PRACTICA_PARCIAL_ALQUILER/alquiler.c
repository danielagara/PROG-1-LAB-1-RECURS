#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "alquiler.h"
#include "string.h"

#define ESTADO_ALQUILER_LIBRE 0
#define ESTADO_ALQUILER_ALQUILADO 1
#define ESTADO_ALQUILER_FINALIZADO 2

#define EQUIPO_AMOLADORA 1
#define EQUIPO_MEZCLADORA 2
#define EQUIPO_TALADRO 3

//FUNCIONES PRIVADAS
static int buscarProximoId_alquiler(EAlquiler* arrayAlquileres, int longitud);
static int buscarIndiceIdAlquiler(EAlquiler* arrayAlquileres, int longitud, int id);
//_________________________________________________________________

static int buscarProximoId_alquiler(EAlquiler* arrayAlquileres, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayAlquileres != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAlquileres[i].estadoAlquiler == ESTADO_ALQUILER_ALQUILADO || arrayAlquileres[i].estadoAlquiler == ESTADO_ALQUILER_FINALIZADO)
            {
                if(idMax < arrayAlquileres[i].idAlquiler)
                    idMax = arrayAlquileres[i].idAlquiler;
            }
        }

    }
    return idMax + 1;
}

static int buscarIndiceIdAlquiler(EAlquiler* arrayAlquileres, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayAlquileres != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(id == arrayAlquileres[i].idAlquiler)
            {
                if(arrayAlquileres[i].estadoAlquiler == ESTADO_ALQUILER_ALQUILADO)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

int alqui_nuevoAlquiler(EAlquiler* arrayAlquileres, int index, int len, int idCliente)
{
    int retorno = -1;
    int idAlquiler;
    char bEquipo[51];
	char btiempoEstimadoAlquiler[51];
	char bOperador[51];


    if(arrayAlquileres != NULL && index >= 0 && index < len && idCliente!=-1)
    {
          if(val_getInt(bEquipo,"\nEQUIPO A ALQUILAR? 1-AMOLADORA 2-MEZCLADORA 3-TALADRO ","\nError:\n",3,51)==0)
          {
			  if(val_getInt(btiempoEstimadoAlquiler,"\nTIEMPO ESTIMADO DEL ALQUILER? ","\nError:\n",3,51)==0)
			  {
				  if(val_getNombre(bOperador,"\nNOMBRE DEL OPERADOR? ","\nError:\n",3,51)==0)
				  {
						idAlquiler = buscarProximoId_alquiler(arrayAlquileres,len);
						if(idAlquiler != -1)
						{
							arrayAlquileres[index].idCliente = idCliente;
							arrayAlquileres[index].tipoEquipo=atoi(bEquipo);
							arrayAlquileres[index].tiempoEstimadoAlquiler= atoi(btiempoEstimadoAlquiler);
							strncpy(arrayAlquileres[index].operador,bOperador,51);
							arrayAlquileres[index].estadoAlquiler = ESTADO_ALQUILER_ALQUILADO;
							arrayAlquileres[index].idAlquiler = idAlquiler;
							printf("EL ID DE SU ALQUILER ES: %d", arrayAlquileres[index].idAlquiler);
							retorno = 0;
						}
				  }

			  }


           }

    }
    return retorno;
}


int alqui_buscarIndiceAlquilerLibre (EAlquiler* arrayAlquileres, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAlquileres != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAlquileres[i].estadoAlquiler ==ESTADO_ALQUILER_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int alqui_initAlquileres (EAlquiler* arrayAlquileres, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAlquileres != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAlquileres[i].estadoAlquiler = ESTADO_ALQUILER_LIBRE;
        }

    }
    return retorno;
}

int alqui_finalizaAlquiler(EAlquiler* arrayAlquileres, int len)
{
    int retorno = -1;
	char bIdAlquiler[51];
	char bTiempoAlquilerReal[51];
	int index;

    if(arrayAlquileres != NULL && len > 0)
    {
          if(val_getInt(bIdAlquiler,"\nINGRESE EL ID DE SU ALQUILER:  ","\nSU ALQUILER NO SE ENCONTRO:\n",3,51)==0)
          {
				if(buscarIndiceIdAlquiler(arrayAlquileres,len,atoi(bIdAlquiler))!=-1)
				{
					index=buscarIndiceIdAlquiler(arrayAlquileres,len,atoi(bIdAlquiler));

					if(val_getInt(bTiempoAlquilerReal,"\nINGRESE EL TIEMPO QUE TARDO EL ALQUILER: (EN MINUTOS)  ","\nError:\n",3,51)==0)
					{
							arrayAlquileres[index].estadoAlquiler = ESTADO_ALQUILER_FINALIZADO;
							arrayAlquileres[index].tiempoRealAlquiler=atoi(bTiempoAlquilerReal);
							retorno = 0;
					}

				}

           }


    }
    return retorno;
}

int alqui_cuentaAlquileres(EAlquiler* arrayAlquileres, int len, int idCliente)
{
    int retorno=-1;
    int i;
    int cantidadAlquileres=0;

    for(i=0;i<len;i++)
    {
        if(arrayAlquileres[i].idCliente==idCliente && (arrayAlquileres[i].estadoAlquiler==ESTADO_ALQUILER_FINALIZADO || arrayAlquileres[i].estadoAlquiler==ESTADO_ALQUILER_ALQUILADO))
        {
            cantidadAlquileres++;
        }
    }
    retorno=cantidadAlquileres;
    return retorno;
}


void alqui_equipoMasRecurrente(EAlquiler* arrayAlquileres, int len)
{
    int i;
    int maxEquipo=0;
    int idEquipo;
    int cantidadAUX=0;

    for(i=0;i<len;i++)
    {
        if(arrayAlquileres[i].estadoAlquiler==ESTADO_ALQUILER_FINALIZADO || arrayAlquileres[i].estadoAlquiler==ESTADO_ALQUILER_ALQUILADO)
        {
            cantidadAUX=alqui_cuentaEquipos(arrayAlquileres,len,arrayAlquileres[i].tipoEquipo);
            if(cantidadAUX>maxEquipo)
            {
                maxEquipo=cantidadAUX;
                idEquipo=arrayAlquileres[i].tipoEquipo;
            }
        }
    }

    switch(idEquipo)
    {
        case EQUIPO_AMOLADORA:
            printf("EL EQUIPO CON MAS ALQUILERES ES AMOLADORA, Y LA CANTIDAD DE ALQUILERES ES: %d \n", maxEquipo);
            break;
        case EQUIPO_MEZCLADORA:
            printf("EL EQUIPO CON MAS ALQUILERES ES MEZCLADORA, Y LA CANTIDAD DE ALQUILERES ES: %d \n", maxEquipo);
            break;
        case EQUIPO_TALADRO:
            printf("EL EQUIPO CON MAS ALQUILERES ES TALADRO, Y LA CANTIDAD DE ALQUILERES ES: %d \n", maxEquipo);
            break;
    }

}

int alqui_cuentaEquipos(EAlquiler* arrayAlquileres, int len, int equipo)
{
    int retorno=-1;
    int i;
    int cantidadAlquileresEquipo=0;

    for(i=0;i<len;i++)
    {
        if(arrayAlquileres[i].tipoEquipo==equipo)
        {
            cantidadAlquileresEquipo++;
        }
    }

    retorno=cantidadAlquileresEquipo;
    return retorno;
}

void alqui_equipoTiempoPromedio(EAlquiler* arrayAlquileres, int len)
{
    int i;
    float cantidadAMOLADORA=0;
	float cantidadMEZCLADORA=0;
	float cantidadTALADRO=0;

    for(i=0;i<len;i++)
    {
        if(arrayAlquileres[i].estadoAlquiler==ESTADO_ALQUILER_FINALIZADO)
        {
			switch(arrayAlquileres[i].tipoEquipo)//PREGUNTAR SI PROM DE LOS 2 TIEMPOS O ASI ESTA BIEN
			{
                case EQUIPO_AMOLADORA:
                cantidadAMOLADORA=alqui_sacaPromedioTiempoEquipos(arrayAlquileres,len,EQUIPO_AMOLADORA);
                break;

				case EQUIPO_MEZCLADORA:
				cantidadMEZCLADORA=alqui_sacaPromedioTiempoEquipos(arrayAlquileres,len,EQUIPO_MEZCLADORA);
				break;

				case EQUIPO_TALADRO:
				cantidadTALADRO=alqui_sacaPromedioTiempoEquipos(arrayAlquileres,len,EQUIPO_TALADRO);
				break;
			}

        }
    }

	printf("EL PROMEDIO EN TIEMPO REAL DE CADA EQUIPO ES DE \n AMOLADORA:  %.2f \t MEZCLADORA: %.2f \t TALADRO: %.2f\n", cantidadAMOLADORA, cantidadMEZCLADORA, cantidadTALADRO);

}

float alqui_sacaPromedioTiempoEquipos(EAlquiler* arrayAlquileres, int len, int equipo)
{
    float retorno=-1;
    int i;
    int acumuladorTiempoEquipo=0;
    int contadorAlquileres=0;

    for(i=0;i<len;i++)
    {
        if(arrayAlquileres[i].tipoEquipo==equipo)
        {
            acumuladorTiempoEquipo=acumuladorTiempoEquipo+arrayAlquileres[i].tiempoRealAlquiler;
            contadorAlquileres++;
        }
    }

    retorno=(float)acumuladorTiempoEquipo/contadorAlquileres;
    return retorno;
}
