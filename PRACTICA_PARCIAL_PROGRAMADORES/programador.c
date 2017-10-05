#include <stdio.h>
#include <stdlib.h>
#include "programador.h"
#include "validar.h"
#include <string.h>

// Funciones privadas
static int buscarProximoId (EProgramador* arrayProgramadores, int len);
static int buscarIndiceId (EProgramador* arrayProgramadores, int len, int id);
static int modificarProgramadorPorIndice(EProgramador* arrayProgramadores, int index);
//___________________

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int prog_editarProgramador(EProgramador* arrayProgramadores,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID a modificar:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayProgramadores,len,id);
        if(index>=0)
        {
           return modificarProgramadorPorIndice(arrayProgramadores,index);
        }
    }
    return -1;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


static int modificarProgramadorPorIndice (EProgramador* arrayProgramadores, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];
	char bCategoria[51];

    if(arrayProgramadores != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {

            if(val_getNombre(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
            {
				if(val_getInt(bCategoria,"\nCATEGORIA? 0-JUNIOR  1-SEMI-SENIOR  2-SENIOR","\nError:\n",3,51)==0)
				{
					strncpy(arrayProgramadores[index].nombre,bNombre,51);
					strncpy(arrayProgramadores[index].apellido,bApellido,51);
					arrayProgramadores[index].idCategoria=atoi(bCategoria);
					retorno = 0;
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


int prog_cargarProgramador(EProgramador* arrayProgramadores, int index, int len)
{
    int retorno = -1;
    int id;
    char bNombre[51];
    char bApellido[51];
	char bCategoria[51];


    if(arrayProgramadores != NULL && index >= 0 && index < len)
    {
         if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
         {
			if(val_getNombre(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
			{
				if(val_getInt(bCategoria,"\nCATEGORIA? 0-JUNIOR  1-SEMI-SENIOR  2-SENIOR","\nError:\n",3,51)==0)
				{
					id = buscarProximoId(arrayProgramadores,len);
					if(id != -1)
					{
						strncpy(arrayProgramadores[index].nombre,bNombre,51);
						strncpy(arrayProgramadores[index].apellido,bApellido,51);
						arrayProgramadores[index].idCategoria = atoi(bCategoria);
						arrayProgramadores[index].flagDeEstado = ESTADO_PROGRAMADOR_OCUPADO;
						arrayProgramadores[index].idProgramador= id;
						printf("\nSU ID ES: %d\n", arrayProgramadores[index].idProgramador);
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


int prog_initProgrmador (EProgramador* arrayProgramadores, int len)
{
    int retorno = -1;
    int i;
    if(arrayProgramadores != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            arrayProgramadores[i].flagDeEstado = ESTADO_PROGRAMADOR_LIBRE;
			retorno=0;
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


int prog_printProgramadores(EProgramador* arrayProgramadores, int len)
{
    int retorno = -1;
    int i;
    if(arrayProgramadores != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayProgramadores[i].flagDeEstado == ESTADO_PROGRAMADOR_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Apellido: %s \n",arrayProgramadores[i].idProgramador,arrayProgramadores[i].nombre,arrayProgramadores[i].apellido);
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

void prog_printProgramador(EProgramador* arrayProgramadores, int len, int idProgramador)
{
    int i;
    if(arrayProgramadores != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayProgramadores[i].idProgramador == idProgramador)
            {
                printf("ID: %d - Nombre:%s - Apellido: %s \n",arrayProgramadores[i].idProgramador,arrayProgramadores[i].nombre,arrayProgramadores[i].apellido);
            }
        }

    }
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int prog_buscarIndiceProgramadorLibre (EProgramador* arrayProgramadores, int len)
{
    int retorno = -1;
    int i;
    if(arrayProgramadores != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayProgramadores[i].flagDeEstado == ESTADO_PROGRAMADOR_LIBRE)
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

static int buscarProximoId(EProgramador* arrayProgramadores, int len)
{
    int i;
    int idMax = -1;
    if(arrayProgramadores != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayProgramadores[i].flagDeEstado == ESTADO_PROGRAMADOR_OCUPADO)
            {
                if(idMax < arrayProgramadores[i].idProgramador)
                    idMax = arrayProgramadores[i].idProgramador;
            }
        }

    }
    return idMax + 1;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


static int buscarIndiceId(EProgramador* arrayProgramadores, int len, int id)
{
    int i;
    int retorno = -1;
    if(arrayProgramadores != NULL && len > 0 && id >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayProgramadores[i].flagDeEstado == ESTADO_PROGRAMADOR_OCUPADO)
            {
                if(id == arrayProgramadores[i].idProgramador)
                {
                    retorno = i;
                    break;
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


int prog_bajarProgramador(EProgramador* arrayProgramadores,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID del programador a dar de baja:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayProgramadores,len,id);
        if(index>=0)
        {
           arrayProgramadores[index].flagDeEstado=ESTADO_PROGRAMADOR_LIBRE;
           printf("EL PROGRAMADOR CON ID %d HA SIDO DADO DE BAJA CORRECTAMENTE\n\n",id);
		   retorno=0;
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


int prog_pideId(EProgramador* arrayProgramadores,int len)
{
    int retorno = -1;
    int i;
    char bidProgramador[51];
    if(arrayProgramadores != NULL && len > 0)
    {
        printf("INGRESE SU ID:   \n");
        myFgets(bidProgramador,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayProgramadores[i].idProgramador == atoi(bidProgramador) && arrayProgramadores[i].flagDeEstado== ESTADO_PROGRAMADOR_OCUPADO)
            {
                retorno =  arrayProgramadores[i].idProgramador;
                break;
            }
        }

    }
    return retorno;
}
