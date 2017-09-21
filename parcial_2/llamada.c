#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "llamada.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int llama_initFlags(sLlamada* arrayLlamada, int longitudLlamada)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitudLlamada > 0)
    {
        for(i=0; i<longitudLlamada ; i++)
        {
            arrayLlamada[i].flagEspacio =LLAMADA_LIBRE;
        }
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int llama_buscarLlamadaLibre (sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamada[i].flagEspacio== LLAMADA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 static int llama_buscaIdLibre(sLlamada* arrayLlamada, int longitud)
{
    int retorno = -1;
    int i;
    int flagPrimerLugarOcupado=0;
    int mayorId;

    if(arrayLlamada != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamada[i].flagEspacio == LLAMADA_OCUPADA)
            {
                if(flagPrimerLugarOcupado==0)
                {
                    flagPrimerLugarOcupado=1;
                    mayorId=arrayLlamada[i].ID_Llamada;

                }
                else
                {
                    if(arrayLlamada[i].ID_Llamada>mayorId)
                    {
                        mayorId=arrayLlamada[i].ID_Llamada;
                    }
                }
            }
        }
        retorno=mayorId+1;
    }
    return retorno;
}

int llama_buscaIndice(sLlamada* arrayLlamada,int id, int longitud)
{
     int retorno = -1;
    int i;

    if(arrayLlamada != NULL && id >= 0 && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayLlamada[i].flagEspacio == LLAMADA_OCUPADA)
            {

                if(id == arrayLlamada[i].ID_Llamada)
                {
                    retorno=i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int llama_cargarLlamada(sLlamada* arrayLlamada, int index,int longitud)
{
    int retorno = -1;
    char bID_Asociado[51];
    char bMotivo[51];
    int id;

    id=llama_buscaIdLibre(arrayLlamada,longitud);

    if(arrayLlamada != NULL && index >= 0 && id != -1 && index<longitud)
    {
        if(val_getInt(bID_Asociado,"\nID ASOCIADO?","\nError:\n",3,51)==0)
        {
            if(val_getInt(bMotivo,"\nMOTIVO?","\nError:\n",3,51)==0)
			{
                arrayLlamada[index].ID_Asociado=atoi(bID_Asociado);
                arrayLlamada[index].motivo=atoi(bMotivo);
                arrayLlamada[index].estadoLlamada=LLAMADA_PENDIENTE;
                arrayLlamada[index].flagEspacio= LLAMADA_OCUPADA;
                arrayLlamada[index].ID_Llamada=id;

                retorno=0;
			}
        }

    }
    return retorno;
}

int llama_AsignaAmbulancia(sLlamada* arrayLlamada, int index,int longitud)
{
    int retorno = -1;
    char bID_Ambulancia[51];
    char btiempoInsumido[51];

    if(arrayLlamada != NULL && index >= 0 && index<longitud)
    {
        if(val_getInt(bID_Ambulancia,"\nID AMBULANCIA?","\nError:\n",3,51)==0)
        {
            if(val_getInt(btiempoInsumido,"\nTIEMPO INSUMIDO?","\nError:\n",3,51)==0)
			{
				arrayLlamada[index].ID_Ambulancia=atoi(bID_Ambulancia);
                arrayLlamada[index].tiempoInsumido=atoi(btiempoInsumido);
                arrayLlamada[index].estadoLlamada=LLAMADA_CUMPLIDA;

                retorno=0;
			}
        }

    }
    return retorno;
}

