#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "asociado.h"


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int asoc_initFlags(sAsociado* arrayAsociado, int longitudAsociado)
{
    int retorno = -1;
    int i;
    if(arrayAsociado != NULL && longitudAsociado > 0)
    {
        for(i=0; i<longitudAsociado ; i++)
        {
            arrayAsociado[i].flagEspacio = ASOCIADO_LIBRE;
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


int asoc_buscarAsociadoLibre (sAsociado* arrayAsociado, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].flagEspacio == ASOCIADO_LIBRE)
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

 static int asoc_buscaIdLibre(sAsociado* arrayAsociado, int longitud)
{
    int retorno = -1;
    int i;
    int flagPrimerLugarOcupado=0;
    int mayorId;

    if(arrayAsociado != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].flagEspacio == ASOCIADO_OCUPADO)
            {
                if(flagPrimerLugarOcupado==0)
                {
                    flagPrimerLugarOcupado=1;
                    mayorId=arrayAsociado[i].ID_Asociado;

                }
                else
                {
                    if(arrayAsociado[i].ID_Asociado>mayorId)
                    {
                        mayorId=arrayAsociado[i].ID_Asociado;
                    }
                }
            }
        }
        retorno=mayorId+1;
    }
    return retorno;
}

int asoc_buscaIndice(sAsociado* arrayAsociado,int id, int longitud)
{
     int retorno = -1;
    int i;

    if(arrayAsociado != NULL && id >= 0 && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociado[i].flagEspacio == ASOCIADO_OCUPADO)
            {

                if(id == arrayAsociado[i].ID_Asociado)
                {
                    retorno=i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int asoc_cargarAsociado (sAsociado* arrayAsociado, int index,int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
	char bEdad[51];
	char bDNI[51];
    int id;

    id=asoc_buscaIdLibre(arrayAsociado,longitud);

    if(arrayAsociado != NULL && index >= 0 && id != -1 && index<longitud)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            if(val_getNombre(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
			{
				if(val_getInt(bEdad,"\nEDAD?","\nError:\n",3,51)==0)
				{
					if(val_getNombre(bDNI,"\nDNI?","\nError:\n",3,51)==0)
					{
						strncpy(arrayAsociado[index].nombre,bNombre,51);
						strncpy(arrayAsociado[index].apellido,bApellido,51);
						arrayAsociado[index].edad=atoi(bEdad);
						strncpy(arrayAsociado[index].DNI,bDNI,51);
						arrayAsociado[index].ID_Asociado=id;
						arrayAsociado[index].flagEspacio =ASOCIADO_OCUPADO;
						retorno=0;
					}
				}
			}
        }

    }
    return retorno;
}

//FALTA BAJA Y MODI
