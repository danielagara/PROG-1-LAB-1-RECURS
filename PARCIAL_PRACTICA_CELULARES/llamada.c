#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "llamada.h"

#define ESTADO_LLAMADA_LIBRE 0
#define ESTADO_LLAMADA_EN_CURSO 1
#define ESTADO_LLAMADA_SOLUCIONADO 2
#define ESTADO_LLAMADA_NO_SOLUCIONADO 3

#define MOTIVO_FALLA_3G 1
#define MOTIVO_FALLA_LTE 2
#define MOTIVO_FALLA_EQUIPO 3

//FUNCIONES PRIVADAS
static int buscarProximoId_llamada(ELlamada* arrayLlamadas, int longitud);
static int buscarIndiceIdLlamada(ELlamada* arrayLlamadas, int longitud, int id);
//_________________________________________________________________

static int buscarProximoId_llamada(ELlamada* arrayLlamadas, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayLlamadas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_EN_CURSO || arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_SOLUCIONADO || arrayLlamadas[i].estadoLlamada ==ESTADO_LLAMADA_NO_SOLUCIONADO)
            {
                if(idMax < arrayLlamadas[i].idLlamada)
                    idMax = arrayLlamadas[i].idLlamada;
            }
        }

    }
    return idMax + 1;
}

static int buscarIndiceIdLlamada(ELlamada* arrayLlamadas, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayLlamadas != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(id == arrayLlamadas[i].idLlamada)
            {
                if(arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_SOLUCIONADO ||  arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_NO_SOLUCIONADO || arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_EN_CURSO)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

int llama_nuevaLlamada(ELlamada* arrayLlamadas, int index, int len, int idAbonado)
{
    int retorno = -1;
    int idLlamada;
    char bMotivo[51];


    if(arrayLlamadas != NULL && index >= 0 && index < len && idAbonado!=-1)
    {
		 if(val_getInt(bMotivo,"\nMOTIVO LLAMADA? 1-FALLA 3G 2-FALLA LTE 3-FALLA EQUIPO ","\nError:\n",3,51)==0)
		 {
			idLlamada = buscarProximoId_llamada(arrayLlamadas,len);
			if(idLlamada != -1)
			{
				arrayLlamadas[index].motivoLlamada=atoi(bMotivo);
				arrayLlamadas[index].idAbonado= idAbonado;
				arrayLlamadas[index].estadoLlamada = ESTADO_LLAMADA_EN_CURSO;
				arrayLlamadas[index].idLlamada = idLlamada;
				printf("EL ID DE SU LLAMADA ES: %d", arrayLlamadas[index].idLlamada);
				retorno = 0;
			}
		 }



    }
    return retorno;
}


int llama_buscarIndiceLlamadaLibre (ELlamada* arrayLlamadas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamadas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamadas[i].estadoLlamada ==ESTADO_LLAMADA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int llama_initLlamadas(ELlamada* arrayLlamadas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamadas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayLlamadas[i].estadoLlamada = ESTADO_LLAMADA_LIBRE;
        }

    }
    return retorno;
}

int llama_finalizaLlamada(ELlamada* arrayLlamadas, int len)
{
    int retorno = -1;
	char bIdLlamada[51];
	char btiempoSolucion[51];
	char bEstadoLlamada[51];
	int index;

    if(arrayLlamadas != NULL && len > 0)
    {
          if(val_getInt(bIdLlamada,"\nINGRESE EL ID DE SU LLAMADA:  ","\nSU LLAMADA NO SE ENCONTRO:\n",3,51)==0)
          {
				if(buscarIndiceIdLlamada(arrayLlamadas,len,atoi(bIdLlamada))!=-1)
				{
					index=buscarIndiceIdLlamada(arrayLlamadas,len,atoi(bIdLlamada));

					if(val_getInt(btiempoSolucion,"\nINGRESE EL TIEMPO QUE TARDO EN ESTA LLAMADA: (EN MINUTOS)  ","\nError:\n",3,51)==0)
					{
						if(val_getInt(bEstadoLlamada,"\n SU PROBLEMA FUE RESUELTO? : 2-SI 3-NO  ","\nError:\n",3,51)==0)
						{
							if(atoi(bEstadoLlamada)==ESTADO_LLAMADA_SOLUCIONADO)
							{
								arrayLlamadas[index].estadoLlamada = ESTADO_LLAMADA_SOLUCIONADO;
							}
							if(atoi(bEstadoLlamada)==ESTADO_LLAMADA_NO_SOLUCIONADO)
							{
								arrayLlamadas[index].estadoLlamada = ESTADO_LLAMADA_NO_SOLUCIONADO;
							}
							arrayLlamadas[index].tiempoSolucion=atoi(btiempoSolucion);
							retorno = 0;
						}

					}

				}


           }


    }
    return retorno;
}

int llama_cuentaLlamadas(ELlamada* arrayLlamadas, int len, int idAbonado)
{
    int retorno=-1;
    int i;
    int cantidadLlamadas=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].idAbonado==idAbonado && (arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_NO_SOLUCIONADO || arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_SOLUCIONADO || arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_EN_CURSO))
        {
            cantidadLlamadas++;
        }
    }
    retorno=cantidadLlamadas;
    return retorno;
}

void llama_motivoMasRecurrente(ELlamada* arrayLlamadas, int len)
{
    int i;
    int maxMotivo=0;
    int motivo;
    int cantidadAUX=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_EN_CURSO || arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_SOLUCIONADO || arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_NO_SOLUCIONADO)
        {
            cantidadAUX=llama_cuentaMotivos(arrayLlamadas,len,arrayLlamadas[i].motivoLlamada);
            if(cantidadAUX>maxMotivo)
            {
                maxMotivo=cantidadAUX;
                motivo=arrayLlamadas[i].motivoLlamada;
            }
        }
    }

    switch(motivo)
    {
        case MOTIVO_FALLA_3G:
            printf("EL MOTIVO CON MAS LLAMADAS ES FALLA 3G, Y LA CANTIDAD DE LLAMADAS ES: %d \n", maxMotivo);
            break;
        case MOTIVO_FALLA_LTE:
            printf("EL MOTIVO CON MAS LLAMADAS ES FALLA LTE, Y LA CANTIDAD DE LLAMADAS ES: %d \n", maxMotivo);
            break;
        case MOTIVO_FALLA_EQUIPO:
            printf("EL MOTIVO CON MAS LLAMADAS ES FALLA EQUIPO, Y LA CANTIDAD DE LLAMADAS ES: %d \n", maxMotivo);
            break;
    }

}

int llama_cuentaMotivos(ELlamada* arrayLlamadas, int len, int motivo)
{
    int retorno=-1;
    int i;
    int cantidadLlamadasMotivo=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].motivoLlamada==motivo)
        {
            cantidadLlamadasMotivo++;
        }
    }

    retorno=cantidadLlamadasMotivo;
    return retorno;
}


void llama_motivoTiempoPromedio(ELlamada* arrayLlamadas, int len)
{
    int i;
    float cantidadFalla3G=0;
	float cantidadFallaLTE=0;
	float cantidadFallaEQUIPO=0;
	float maxMotivoTiempo=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_SOLUCIONADO)
        {
			switch(arrayLlamadas[i].motivoLlamada)
			{
			    case MOTIVO_FALLA_3G:
                cantidadFalla3G=llama_sacaPromedioTiempoMotivos(arrayLlamadas,len,MOTIVO_FALLA_3G);
				maxMotivoTiempo=cantidadFalla3G;
                break;

				case MOTIVO_FALLA_LTE:
				cantidadFallaLTE=llama_sacaPromedioTiempoMotivos(arrayLlamadas,len,MOTIVO_FALLA_LTE);
				break;

				case MOTIVO_FALLA_EQUIPO:
				cantidadFallaEQUIPO=llama_sacaPromedioTiempoMotivos(arrayLlamadas,len,MOTIVO_FALLA_EQUIPO);
				break;
			}

        }
    }

	if(maxMotivoTiempo<MOTIVO_FALLA_LTE)
	{
		maxMotivoTiempo=MOTIVO_FALLA_LTE;
	}
	if(maxMotivoTiempo<MOTIVO_FALLA_EQUIPO)
	{
		maxMotivoTiempo=MOTIVO_FALLA_EQUIPO;
	}
//NO HICE EL SWITCH POR QUE SON FLOATS
	if(maxMotivoTiempo==cantidadFalla3G)
    {
        printf("EL RECLAMO QUE EN PROMEDIO MAS TARDA EN SER RESUELTO ES FALLA 3G, CON UN PROMEDIO DE: %.2f", maxMotivoTiempo);
    }

    if(maxMotivoTiempo==cantidadFallaLTE)
    {
        printf("EL RECLAMO QUE EN PROMEDIO MAS TARDA EN SER RESUELTO ES FALLA LTE, CON UN PROMEDIO DE: %.2f", maxMotivoTiempo);
    }

    if(maxMotivoTiempo==cantidadFallaEQUIPO)
    {
        printf("EL RECLAMO QUE EN PROMEDIO MAS TARDA EN SER RESUELTO ES FALLA EQUIPO, CON UN PROMEDIO DE: %.2f", maxMotivoTiempo);
    }


	//printf("EL PROMEDIO EN TIEMPO REAL DE CADA EQUIPO ES DE \n AMOLADORA:  %.2f \t MEZCLADORA: %.2f \t TALADRO: %.2f\n", cantidadFalla3G, cantidadFallaLTE, cantidadFallaEQUIPO);
}

float llama_sacaPromedioTiempoMotivos(ELlamada* arrayLlamadas, int len, int motivo)
{
    float retorno=-1;
    int i;
    int acumuladorTiempomotivo=0;
    int contadorLlamadas=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].motivoLlamada==motivo)
        {
            acumuladorTiempomotivo=acumuladorTiempomotivo+arrayLlamadas[i].tiempoSolucion;
            contadorLlamadas++;
        }
    }

    retorno=(float)acumuladorTiempomotivo/contadorLlamadas;
    return retorno;
}
