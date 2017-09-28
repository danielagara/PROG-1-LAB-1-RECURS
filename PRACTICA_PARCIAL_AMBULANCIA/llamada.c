#include <stdio.h>
#include <stdlib.h>
#include "llamada.h"
#include "validar.h"
#include <string.h>
//FUNCIONES PRIVADAS
static int buscarProximoId_llamada(ELlamadas* arrayLlamadas, int longitud);
static int buscarIndiceIdLlamada(ELlamadas* arrayLlamadas, int longitud, int id);
//_________________________________________________________________

static int buscarProximoId_llamada(ELlamadas* arrayLlamadas, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayLlamadas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_PENDIENTE || arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_CUMPLIDO)
            {
                if(idMax < arrayLlamadas[i].id_llamada)
                    idMax = arrayLlamadas[i].id_llamada;
            }
        }

    }
    return idMax + 1;
}

static int buscarIndiceIdLlamada(ELlamadas* arrayLlamadas, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayLlamadas != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(id == arrayLlamadas[i].id_llamada)
            {
                if(arrayLlamadas[i].estadoLlamada == ESTADO_LLAMADA_PENDIENTE)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

int llama_nuevaLlamada(ELlamadas* arrayLlamadas, int index, int len, int id_asociado)
{
    int retorno = -1;
    int id_llamada;
    char bMotivo[51];


    if(arrayLlamadas != NULL && index >= 0 && index < len && id_asociado!=-1)
    {
          if(val_getInt(bMotivo,"\nMOTIVO DE LA LLAMADA?  1=ACV - 2=INFARTO - 3=GRIPE","\nError:\n",3,51)==0)
          {
				id_llamada = buscarProximoId_llamada(arrayLlamadas,len);
				if(id_llamada != -1)
				{
					arrayLlamadas[index].id_asociado = id_asociado;
					arrayLlamadas[index].motivoLlamada= atoi(bMotivo);
					arrayLlamadas[index].estadoLlamada = ESTADO_LLAMADA_PENDIENTE;
					arrayLlamadas[index].id_llamada = id_llamada;
					printf("EL ID DE SU LLAMADA ES: %d", arrayLlamadas[index].id_llamada);
					retorno = 0;
				}

           }

    }
    return retorno;
}


int llama_buscarIndiceLlamadaLibre (ELlamadas* arrayLlamadas, int longitud)
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

int llama_initLlamadas (ELlamadas* arrayLlamadas, int longitud)
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

int llama_asignaAmbualncia(ELlamadas* arrayLlamadas, int len)
{
    int retorno = -1;
    char bId_llamada[51];
	char bId_ambulancia[51];
	char bTiempoInsumido[51];
	int index;

    if(arrayLlamadas != NULL && len > 0)
    {
          if(val_getInt(bId_llamada,"\nINGRESE EL ID DE SU LLAMADA:  ","\nSU LLAMADA NO SE ENCONTRO:\n",3,51)==0)
          {
				if(buscarIndiceIdLlamada(arrayLlamadas,len,atoi(bId_llamada))!=-1)
				{
					index=buscarIndiceIdLlamada(arrayLlamadas,len,atoi(bId_llamada));

					if(val_getInt(bId_ambulancia,"\nINGRESE EL ID DE LA AMBULANCIA:  ","\nError:\n",3,51)==0)
					{
						if(val_getInt(bTiempoInsumido,"\nTIEMPO INSUMIDO EN MINUTOS:  ","\nError:\n",3,51)==0)
						{
							arrayLlamadas[index].estadoLlamada = ESTADO_LLAMADA_CUMPLIDO;
							arrayLlamadas[index].id_ambulancia=atoi(bId_ambulancia);
							arrayLlamadas[index].tiempoInsumido=atoi(bTiempoInsumido);
							retorno = 0;
						}
					}

				}

           }


    }
    return retorno;
}


void llama_motivoMasRecurrente(ELlamadas* arrayLlamadas, int len)
{
    int i;
    int retorno=-1;
    int contadorACV=0;
    int contadorINFARTO=0;
    int contadorGRIPE=0;
    int mayor=-1;
    char nombreMotivo[51];

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].motivoLlamada==MOTIVO_LLAMADA_ACV)
        {
            contadorACV++;
        }

        if(arrayLlamadas[i].motivoLlamada==MOTIVO_LLAMADA_INFARTO)
        {
            contadorINFARTO++;
        }

        if(arrayLlamadas[i].motivoLlamada==MOTIVO_LLAMADA_GRIPE)
        {
            contadorGRIPE++;
        }
    }

    if(contadorACV>contadorINFARTO && contadorACV>contadorGRIPE)
    {
        mayor=contadorACV;
        strncpy(nombreMotivo,"ACV",51);
    }
    if(contadorINFARTO>contadorGRIPE && contadorINFARTO>contadorACV)
    {
        mayor=contadorINFARTO;
        strncpy(nombreMotivo,"INFARTO",51);
    }
    if(contadorGRIPE>contadorACV && contadorGRIPE>contadorINFARTO)
    {
        mayor=contadorGRIPE;
        strncpy(nombreMotivo,"GRIPE",51);
    }

    if(mayor!=-1)
    {
         printf("\nEL MOTIVO MAS RECURRENTE ES: %s Y LA CANTIDAD DE VECES QUE FUE SOLICITADO: %d", nombreMotivo, mayor);
    }

}
