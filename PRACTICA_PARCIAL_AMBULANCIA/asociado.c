#include <stdio.h>
#include <stdlib.h>
#include "asociado.h"
#include "validar.h"
#include <string.h>

// Funciones privadas
static int buscarProximoId (EAsociado* arrayAsociados, int longitud);
static int buscarIndiceId (EAsociado* arrayAsociados, int longitud, int id);
static int modificarAsociadoPorIndice(EAsociado* arrayAsociados, int index);
//___________________


int asoc_editarAsociado(EAsociado* arrayAsociados,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID a modificar:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayAsociados,len,id);
        if(index>=0)
        {
           return modificarAsociadoPorIndice(arrayAsociados,index);
        }
    }
    return -1;
}


static int modificarAsociadoPorIndice (EAsociado* arrayAsociados, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];

    if(arrayAsociados != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {

            if(val_getNombre(bApellido,"\nApellido?","\nError:\n",3,51)==0)
            {
                strncpy(arrayAsociados[index].nombre,bNombre,51);
				strncpy(arrayAsociados[index].apellido,bApellido,51);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int asoc_cargarAsociado(EAsociado* arrayAsociados, int index, int len)
{
    int retorno = -1;
    int id;
    char bNombre[51];
    char bApellido[51];
	char bDNI[51];
	char bEdad[51];


    if(arrayAsociados != NULL && index >= 0 && index < len)
    {
        if(val_getInt(bDNI,"\nDNI?","\nError:\n",3,20)==0 && asoc_buscaDNIrepetido(arrayAsociados,len,bDNI)==0)
        {
            if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
            {
				if(val_getNombre(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
				{
					if(val_getInt(bEdad,"\nEDAD?","\nError:\n",3,51)==0)
					{
						id = buscarProximoId(arrayAsociados,len);
						if(id != -1)
						{
							strncpy(arrayAsociados[index].nombre,bNombre,51);
							strncpy(arrayAsociados[index].apellido,bApellido,51);
							strncpy(arrayAsociados[index].DNI,bDNI,20);
							arrayAsociados[index].edad = atoi(bEdad);
							arrayAsociados[index].flagDeEstado = ESTADO_ASOCIADO_OCUPADO;
							arrayAsociados[index].id_asociado= id;
							printf("\nSU ID ES: %d\n", arrayAsociados[index].id_asociado);
							retorno = 0;
						}
					}

				}

            }
        }

    }
    return retorno;
}

int asoc_initAsociado (EAsociado* arrayAsociados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAsociados[i].flagDeEstado = ESTADO_ASOCIADO_LIBRE;
        }

    }
    return retorno;
}

int asoc_printAsociado(EAsociado* arrayAsociados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociados[i].flagDeEstado == ESTADO_ASOCIADO_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Apellido: %.s - DNI:%s - Edad:%d\n",arrayAsociados[i].id_asociado,arrayAsociados[i].nombre,arrayAsociados[i].apellido, arrayAsociados[i].DNI, arrayAsociados[i].edad);
            }
        }

    }
    return retorno;
}


int asoc_buscarIndiceAsociadoLibre (EAsociado* arrayAsociados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociados[i].flagDeEstado == ESTADO_ASOCIADO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}


static int buscarProximoId(EAsociado* arrayAsociados, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayAsociados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociados[i].flagDeEstado == ESTADO_ASOCIADO_OCUPADO)
            {
                if(idMax < arrayAsociados[i].id_asociado)
                    idMax = arrayAsociados[i].id_asociado;
            }
        }

    }
    return idMax + 1;
}


static int buscarIndiceId(EAsociado* arrayAsociados, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayAsociados != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAsociados[i].flagDeEstado == ESTADO_ASOCIADO_OCUPADO)
            {
                if(id == arrayAsociados[i].id_asociado)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}


int asoc_bajarAsociado(EAsociado* arrayAsociados,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID del asociado a dar de baja:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayAsociados,len,id);
        if(index>=0)
        {
           arrayAsociados[index].flagDeEstado=ESTADO_ASOCIADO_LIBRE;
		   retorno=0;
        }
    }

    return retorno;
}


int asoc_pideId(EAsociado* arrayAsociados,int len)
{
    int retorno = -1;
    int i;
    char bId_asociado[51];
    if(arrayAsociados != NULL && len > 0)
    {
        printf("INGRESE SU ID:   \n");
        myFgets(bId_asociado,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayAsociados[i].id_asociado == atoi(bId_asociado) && arrayAsociados[i].flagDeEstado== ESTADO_ASOCIADO_OCUPADO)
            {
                retorno =  arrayAsociados[i].id_asociado;
                break;
            }
        }

    }
    return retorno;
}



int asoc_buscaDNIrepetido(EAsociado* arrayAsociados, int len, char* DNI)
{
    int retorno=0;
    int i;

    for(i=0;i<len;i++)
    {
        if(strcmp(arrayAsociados[i].DNI,DNI)==0)
        {
            retorno=-1;
            break;
        }
    }

    return retorno;
}
