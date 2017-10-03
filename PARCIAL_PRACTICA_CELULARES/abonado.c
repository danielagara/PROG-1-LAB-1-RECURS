#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "abonado.h"

#define ESTADO_ABONADO_LIBRE 0
#define ESTADO_ABONADO_OCUPADO 1

// Funciones privadas
static int buscarProximoId (EAbonado* arrayAbonados, int longitud);
static int buscarIndiceId (EAbonado* arrayAbonados, int longitud, int id);
static int modificarAbonadoPorIndice(EAbonado* arrayAbonados, int index);
//___________________


int abo_editarAbonado(EAbonado* arrayAbonados,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID a modificar:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayAbonados,len,id);
        if(index>=0)
        {
           return modificarAbonadoPorIndice(arrayAbonados,index);
        }
    }
    return -1;
}


static int modificarAbonadoPorIndice (EAbonado* arrayAbonados, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];

    if(arrayAbonados != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {

            if(val_getNombre(bApellido,"\nApellido?","\nError:\n",3,51)==0)
            {
                strncpy(arrayAbonados[index].nombre,bNombre,51);
				strncpy(arrayAbonados[index].apellido,bApellido,51);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int abo_cargarAbonado(EAbonado* arrayAbonados, int index, int len)
{
    int retorno = -1;
    int idAbonado;
    char bNombre[51];
    char bApellido[51];
	char bNumeroTelefono[51];


    if(arrayAbonados != NULL && index >= 0 && index < len)
    {
        if(val_getInt(bNumeroTelefono,"\nNUMERO DE TELEFONO?","\nError:\n",3,51)==0 && abo_buscaNumTelefonoRepetido(arrayAbonados,len,bNumeroTelefono)==0)
        {
            if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
            {
				if(val_getNombre(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
				{
						idAbonado = buscarProximoId(arrayAbonados,len);
						if(idAbonado != -1)
						{
							strncpy(arrayAbonados[index].nombre,bNombre,51);
							strncpy(arrayAbonados[index].apellido,bApellido,51);
							strncpy(arrayAbonados[index].numeroTelefono,bNumeroTelefono,51);
							arrayAbonados[index].flagDeEstado=ESTADO_ABONADO_OCUPADO;
							arrayAbonados[index].idAbonado= idAbonado;
							printf("\nSU ID ES: %d\n", arrayAbonados[index].idAbonado);
							retorno = 0;
						}

				}

            }
        }

    }
    return retorno;
}

int abo_initAbonado(EAbonado* arrayAbonados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAbonados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayAbonados[i].flagDeEstado = ESTADO_ABONADO_LIBRE;
        }

    }
    return retorno;
}

int abo_printAbonado(EAbonado* arrayAbonados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAbonados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAbonados[i].flagDeEstado == ESTADO_ABONADO_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Apellido: %s - Numero de telefono: %s\n",arrayAbonados[i].idAbonado,arrayAbonados[i].nombre,arrayAbonados[i].apellido, arrayAbonados[i].numeroTelefono);
            }
        }

    }
    return retorno;
}


int abo_buscarIndicEAbonadoLibre (EAbonado* arrayAbonados, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayAbonados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAbonados[i].flagDeEstado == ESTADO_ABONADO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}


static int buscarProximoId(EAbonado* arrayAbonados, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayAbonados != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAbonados[i].flagDeEstado == ESTADO_ABONADO_OCUPADO)
            {
                if(idMax < arrayAbonados[i].idAbonado)
                    idMax = arrayAbonados[i].idAbonado;
            }
        }

    }
    return idMax + 1;
}


static int buscarIndiceId(EAbonado* arrayAbonados, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayAbonados != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayAbonados[i].flagDeEstado == ESTADO_ABONADO_OCUPADO)
            {
                if(id == arrayAbonados[i].idAbonado)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}


int abo_bajarAbonado(EAbonado* arrayAbonados,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID del abonado a dar de baja:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayAbonados,len,id);
        if(index>=0)
        {
           arrayAbonados[index].flagDeEstado=ESTADO_ABONADO_LIBRE;
		   retorno=0;
        }
    }

    return retorno;
}


int abo_pideId(EAbonado* arrayAbonados,int len)
{
    int retorno = -1;
    int i;
    char bidAbonado[51];
    if(arrayAbonados != NULL && len > 0)
    {
        printf("INGRESE SU ID:   \n");
        myFgets(bidAbonado,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayAbonados[i].idAbonado == atoi(bidAbonado) && arrayAbonados[i].flagDeEstado== ESTADO_ABONADO_OCUPADO)
            {
                retorno =  arrayAbonados[i].idAbonado;
                break;
            }
        }

    }
    return retorno;
}



int abo_buscaNumTelefonoRepetido(EAbonado* arrayAbonados, int len, char* numeroTelefono)
{
    int retorno=0;
    int i;

    for(i=0;i<len;i++)
    {
        if(strcmp(arrayAbonados[i].numeroTelefono,numeroTelefono)==0)
        {
            retorno=-1;
            break;
        }
    }

    return retorno;
}
