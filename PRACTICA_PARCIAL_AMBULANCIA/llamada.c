#include <stdio.h>
#include <stdlib.h>
#include "llamada.h"
#include "validar.h"
#include <string.h>
//FUNCIONES PRIVADAS
static int buscarProximoId_llamada(ELlamadas* arrayLlamadas, int longitud);
static int buscarIndiceIdLlamada(ELlamadas* arrayLlamadas, int longitud, int id);
//_________________________________________________________________

/** \brief buscarProximoId_llamada Genera un id incremental, siempre y cuando se llegue hasta el tamaño diponible, es de tipo privada
 *
 * \param arrayLlamadas el array de estructuras a generar el id
 * \param longitud lo que mide el array
 * \return idMax+1 el id a utilizar
 *
 */


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

/** \brief buscarIndiceIdLlamada busca el indice dentro del array donde coincide el id pasado
 *
 * \param arrayLlamadas el array a analizar
 * \param longitud lo que mide el array
 * \return -1 si hubo algun error, el indice encontrado si funciono 
 *
 */


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

/** \brief llama_nuevaLlamada da alta de la llamada, pidiendo los datos al usuario, validandolos y cargandolos dentro del array
 *
 * \param arrayLlamadas el array a llenar
 * \param index el subindice en el que se van a completar los datos
 * \param len longitud del array
 * \param id_asociado el id del asociado que da de alta la llamada
 * \return -1 si hubo algun error, 0 si ejecuto correctamente
 *
 */


int llama_nuevaLlamada(ELlamadas* arrayLlamadas, int index, int len, int id_asociado)
{
    int retorno = -1;
    int id_llamada;
    char bMotivo[51];


    if(arrayLlamadas != NULL && index >= 0 && index < len && id_asociado!=-1)
    {
		if(llama_asociadoTieneLlamadaEnCurso(arrayLlamadas,len,id_asociado)==0)
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
    }
    return retorno;
}

/** \brief llama_buscarIndiceLlamadaLibre busca el indice dentro del array que no esta ocupado, es decir que tiene el flag estado como disponible
 *
 * \param arrayLlamadas el array donde se realiza la busqueda
 * \param longitud lo que mide el array
 * \return -1 si hay un error, el numero de indice si encontro un espacio libre
 *
 */


int llama_buscarIndiceLlamadaLibre(ELlamadas* arrayLlamadas, int longitud)
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

/** \brief 
 *
 * \param
 * \param
 * \return
 *
 */


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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void llama_motivoMasRecurrente(ELlamadas* arrayLlamadas, int len)
{
    int i;
    int maxMotivo=0;
    int idMotivo;
    int cantidadAUX=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_CUMPLIDO || arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_PENDIENTE)
        {
            cantidadAUX=llama_cuentaMotivos(arrayLlamadas,len,arrayLlamadas[i].motivoLlamada);
            if(cantidadAUX>maxMotivo)
            {
                maxMotivo=cantidadAUX;
                idMotivo=arrayLlamadas[i].motivoLlamada;
            }
        }
    }

    switch(idMotivo)
    {
        case MOTIVO_LLAMADA_ACV:
            printf("EL MOTIVO CON MAS LLAMADAS ES ACV, Y LA CANTIDAD DE LLAMADAS ES: %d \n", maxMotivo);
            break;
        case MOTIVO_LLAMADA_GRIPE:
            printf("EL MOTIVO CON MAS LLAMADAS ES GRIPE, Y LA CANTIDAD DE LLAMADAS ES: %d \n", maxMotivo);
            break;
        case MOTIVO_LLAMADA_INFARTO:
            printf("EL MOTIVO CON MAS LLAMADAS ES INFARTO, Y LA CANTIDAD DE LLAMADAS ES: %d \n", maxMotivo);
            break;
    }

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void llama_motivoConMayorTiempoPromedio(ELlamadas* arrayLlamadas, int len)
{
    int i;
    float maxMotivo=0;
    int idMotivo;
    float cantidadAUX=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_CUMPLIDO)
        {
            cantidadAUX=llama_sacaPromedioTiempoMotivos(arrayLlamadas,len,arrayLlamadas[i].motivoLlamada);
            if(cantidadAUX>maxMotivo)
            {
                maxMotivo=cantidadAUX;
                idMotivo=arrayLlamadas[i].motivoLlamada;
            }
        }
    }

    switch(idMotivo)
    {
        case MOTIVO_LLAMADA_ACV:
            printf("EL MOTIVO QUE EN PROMEDIO TARDA MAS EN RESOLVERSE ES ACV, CON UN PROMEDIO DE %.2f minutos", cantidadAUX);
            break;
        case MOTIVO_LLAMADA_GRIPE:
            printf("EL MOTIVO QUE EN PROMEDIO TARDA MAS EN RESOLVERSE ES GRIPE, CON UN PROMEDIO DE %.2f minutos", cantidadAUX);
            break;
        case MOTIVO_LLAMADA_INFARTO:
            printf("EL MOTIVO QUE EN PROMEDIO TARDA MAS EN RESOLVERSE ES INFARTO, CON UN PROMEDIO DE %.2f minutos", cantidadAUX);
            break;
    }

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int llama_cuentaLlamadas(ELlamadas* arrayLlamadas, int len, int id_asociado)
{
    int retorno=-1;
    int i;
    int cantidadLlamadas=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].id_asociado==id_asociado && (arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_CUMPLIDO || arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_PENDIENTE))
        {
            cantidadLlamadas++;
        }
    }
    retorno=cantidadLlamadas;
    return retorno;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int llama_cuentaMotivos(ELlamadas* arrayLlamadas, int len, int motivo)
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float llama_sacaPromedioTiempoMotivos(ELlamadas* arrayLlamadas, int len, int motivo)
{
    float retorno=-1;
    int i;
    int acumuladorTiempoMotivo=0;
    int contadorLlamada=0;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].motivoLlamada==motivo)
        {
            acumuladorTiempoMotivo=acumuladorTiempoMotivo+arrayLlamadas[i].tiempoInsumido;
            contadorLlamada++;
        }
    }

    retorno=(float)acumuladorTiempoMotivo/contadorLlamada;
    printf("EL RETORNO EN LA FUNCION CHICA ES %.2f \n", retorno);
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int llama_asociadoTieneLlamadaEnCurso(ELlamadas* arrayLlamadas, int len, int idAsociado)
{
	int retorno=0;
    int i;

    for(i=0;i<len;i++)
    {
        if(arrayLlamadas[i].id_asociado==idAsociado && arrayLlamadas[i].estadoLlamada==ESTADO_LLAMADA_PENDIENTE)
        {
            retorno=-1;
            break;
        }
    }

    return retorno;
}

