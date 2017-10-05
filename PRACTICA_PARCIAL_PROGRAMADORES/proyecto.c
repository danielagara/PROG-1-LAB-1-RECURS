#include <stdio.h>
#include <stdlib.h>
#include "proyecto.h"
#include "validar.h"
#include <string.h>

//FUNCIONES PRIVADAS
//static int buscarProximoIdProyecto(EProyecto* arrayProyectos, int len);
static int buscarIndiceIdProyecto(EProyecto* arrayProyectos, int len, int id);
//_________________________________________________________________


/** \brief buscarIndiceIdLlamada busca el indice dentro del array donde coincide el id pasado
 *
 * \param arrayProyectos el array a analizar
 * \param len lo que mide el array
 * \return -1 si hubo algun error, el indice encontrado si funciono
 *
 */


static int buscarIndiceIdProyecto(EProyecto* arrayProyectos, int len, int id)
{
    int i;
    int retorno = -1;
    if(arrayProyectos != NULL && len > 0 && id >= 0)
    {
        for(i=0; i<len ; i++)
        {
            if(id == arrayProyectos[i].idProyecto)
            {
                if(arrayProyectos[i].flagDeEstado == ESTADO_PROYECTO_OCUPADO)
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
 * \param arrayProyectos el array a llenar
 * \param index el subindice en el que se van a completar los datos
 * \param len len del array
 * \param idProgramador el id del asociado que da de alta la llamada
 * \return -1 si hubo algun error, 0 si ejecuto correctamente
 *
 */


int proye_asignaProgramadorAProyecto(EProyecto* arrayProyectos, int index, int len, int idProgramador)
{
    int retorno = -1;
    char bIdProyecto[51];
	int indexProyectoExistente;
	char bHorasAtrabajar[51];
	char bNombreProyecto[51];

    if(arrayProyectos != NULL && index >= 0 && index < len && idProgramador!=-1)
    {
			if(val_getInt(bIdProyecto,"\nINGRESE EL ID DEL PROYECTO A ASIGNAR AL PROGRAMADOR: ","\nError:\n",3,51)==0)
			{
				indexProyectoExistente=buscarIndiceIdProyecto(arrayProyectos,len,atoi(bIdProyecto));
				if(val_getInt(bHorasAtrabajar,"\nINGRESE LA CANTIDAD DE HORAS QUE DEBE TRABAJAR: ","\nError:\n",3,51)==0)
				{
					if(indexProyectoExistente!=-1)
					{
						printf("EL PROYECTO A ASIGNAR ES %s, CON EL ID %d\n",arrayProyectos[indexProyectoExistente].nombreDelProyecto, arrayProyectos[indexProyectoExistente].idProyecto);
						strncpy(arrayProyectos[index].nombreDelProyecto,arrayProyectos[indexProyectoExistente].nombreDelProyecto,51);
						arrayProyectos[index].idProyecto=arrayProyectos[indexProyectoExistente].idProyecto;
						arrayProyectos[index].idProgramador = idProgramador;
						arrayProyectos[index].flagDeEstado = ESTADO_PROYECTO_OCUPADO;
						arrayProyectos[index].horasAtrabajar=atoi(bHorasAtrabajar);
						retorno = 0;
					}
					else
					{
						if(val_getNombre(bNombreProyecto,"\nINGRESE EL NOMBRE DEL PROYECTO: ","\nError:\n",3,51)==0)
						{
							arrayProyectos[index].idProgramador = idProgramador;
							arrayProyectos[index].flagDeEstado = ESTADO_PROYECTO_OCUPADO;
							arrayProyectos[index].idProyecto = atoi(bIdProyecto);
							arrayProyectos[index].horasAtrabajar=atoi(bHorasAtrabajar);
							strncpy(arrayProyectos[index].nombreDelProyecto,bNombreProyecto,51);
							retorno=0;
						}
					}



					retorno = 0;
				}

           }
    }
    return retorno;
}

/** \brief llama_buscarIndiceLlamadaLibre busca el indice dentro del array que no esta ocupado, es decir que tiene el flag estado como disponible
 *
 * \param arrayProyectos el array donde se realiza la busqueda
 * \param len lo que mide el array
 * \return -1 si hay un error, el numero de indice si encontro un espacio libre
 *
 */


int proye_buscarIndiceProyecctoLibre(EProyecto* arrayProyectos, int len)
{
    int retorno = -1;
    int i;
    if(arrayProyectos != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            if(arrayProyectos[i].flagDeEstado ==ESTADO_PROYECTO_LIBRE)
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


int proye_initProyectos (EProyecto* arrayProyectos, int len)
{
    int retorno = -1;
    int i;
    if(arrayProyectos != NULL && len > 0)
    {
        for(i=0; i<len ; i++)
        {
            arrayProyectos[i].flagDeEstado = ESTADO_PROYECTO_LIBRE;
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

void proye_proyectoMasDemandante(EProyecto* arrayProyectos, int len)
{
    int i;
    int maxMotivo=0;
    int idProyecto;
    int cantidadAUX=0;

    for(i=0;i<len;i++)
    {
        if(arrayProyectos[i].flagDeEstado==ESTADO_PROYECTO_OCUPADO)
        {
            cantidadAUX=proye_cuentaProyectos(arrayProyectos,len,arrayProyectos[i].idProyecto);
            if(cantidadAUX>maxMotivo)
            {
                maxMotivo=cantidadAUX;
                idProyecto=arrayProyectos[i].idProyecto;
            }
        }
    }

    for(i=0;i<len;i++)
	{
		if(arrayProyectos[i].idProyecto==idProyecto)
		{
			printf("EL PROYECTO MAS DEMANDANTE ES %s CON UN TOTAL DE %d PROGRAMADORES ASIGNADOS\n", arrayProyectos[i].nombreDelProyecto, maxMotivo);
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

int proye_cuentaProyectos(EProyecto* arrayProyectos, int len, int idProyecto)
{
    int retorno=-1;
    int i;
    int cantidadProgramadoresEnProyecto=0;

    for(i=0;i<len;i++)
    {
        if(arrayProyectos[i].idProyecto==idProyecto && arrayProyectos[i].flagDeEstado==ESTADO_PROYECTO_OCUPADO)
        {
            cantidadProgramadoresEnProyecto++;
        }
    }
    retorno=cantidadProgramadoresEnProyecto;
    return retorno;
}

void proye_imprimeProyectoPorPogramador(EProyecto* arrayProyectos, int len, int idProgramador)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(arrayProyectos[i].idProgramador==idProgramador)
        {
            printf("NOMBRE DEL PROYECTO: %s\n", arrayProyectos[i].nombreDelProyecto);
        }
    }
}
