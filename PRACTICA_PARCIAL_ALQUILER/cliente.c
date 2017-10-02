#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "cliente.h"
#include "string.h"

#define ESTADO_CLIENTE_LIBRE 0
#define ESTADO_CLIENTE_OCUPADO 1

// Funciones privadas
static int buscarProximoId (ECliente* arrayClientes, int longitud);
static int buscarIndiceId (ECliente* arrayClientes, int longitud, int id);
static int modificarClientePorIndice(ECliente* arrayClientes, int index);
//___________________


int cli_editarCliente(ECliente* arrayClientes,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID a modificar:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayClientes,len,id);
        if(index>=0)
        {
           return modificarClientePorIndice(arrayClientes,index);
        }
    }
    return -1;
}


static int modificarClientePorIndice (ECliente* arrayClientes, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bApellido[51];

    if(arrayClientes != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {

            if(val_getNombre(bApellido,"\nApellido?","\nError:\n",3,51)==0)
            {
                strncpy(arrayClientes[index].nombre,bNombre,51);
				strncpy(arrayClientes[index].apellido,bApellido,51);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int cli_cargarCliente(ECliente* arrayClientes, int index, int len)
{
    int retorno = -1;
    int idCliente;
    char bNombre[51];
    char bApellido[51];
	char bDNI[51];


    if(arrayClientes != NULL && index >= 0 && index < len)
    {
        if(val_getInt(bDNI,"\nDNI?","\nError:\n",3,20)==0 && cli_buscaDNIrepetido(arrayClientes,len,bDNI)==0)
        {
            if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
            {
				if(val_getNombre(bApellido,"\nAPELLIDO?","\nError:\n",3,51)==0)
				{
						idCliente = buscarProximoId(arrayClientes,len);
						if(idCliente != -1)
						{
							strncpy(arrayClientes[index].nombre,bNombre,51);
							strncpy(arrayClientes[index].apellido,bApellido,51);
							strncpy(arrayClientes[index].DNI,bDNI,20);
							arrayClientes[index].flagDeEstado = ESTADO_CLIENTE_OCUPADO;
							arrayClientes[index].idCliente= idCliente;
							printf("\nSU ID ES: %d\n", arrayClientes[index].idCliente);
							retorno = 0;
						}

				}

            }
        }

    }
    return retorno;
}

int cli_initCliente (ECliente* arrayClientes, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayClientes != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayClientes[i].flagDeEstado = ESTADO_CLIENTE_LIBRE;
        }

    }
    return retorno;
}

int cli_printCliente(ECliente* arrayClientes, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayClientes != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayClientes[i].flagDeEstado == ESTADO_CLIENTE_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Apellido: %.s - DNI:%s\n",arrayClientes[i].idCliente,arrayClientes[i].nombre,arrayClientes[i].apellido, arrayClientes[i].DNI);
            }
        }

    }
    return retorno;
}


int cli_buscarIndiceClienteLibre (ECliente* arrayClientes, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayClientes != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayClientes[i].flagDeEstado == ESTADO_CLIENTE_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}


static int buscarProximoId(ECliente* arrayClientes, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayClientes != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayClientes[i].flagDeEstado == ESTADO_CLIENTE_OCUPADO)
            {
                if(idMax < arrayClientes[i].idCliente)
                    idMax = arrayClientes[i].idCliente;
            }
        }

    }
    return idMax + 1;
}


static int buscarIndiceId(ECliente* arrayClientes, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayClientes != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayClientes[i].flagDeEstado == ESTADO_CLIENTE_OCUPADO)
            {
                if(id == arrayClientes[i].idCliente)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}


int cli_bajarCliente(ECliente* arrayClientes,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID del asociado a dar de baja:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayClientes,len,id);
        if(index>=0)
        {
           arrayClientes[index].flagDeEstado=ESTADO_CLIENTE_LIBRE;
		   retorno=0;
        }
    }

    return retorno;
}


int cli_pideId(ECliente* arrayClientes,int len)
{
    int retorno = -1;
    int i;
    char bId_cliente[51];
    if(arrayClientes != NULL && len > 0)
    {
        printf("INGRESE SU ID:   \n");
        myFgets(bId_cliente,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayClientes[i].idCliente == atoi(bId_cliente) && arrayClientes[i].flagDeEstado== ESTADO_CLIENTE_OCUPADO)
            {
                retorno =  arrayClientes[i].idCliente;
                break;
            }
        }

    }
    return retorno;
}



int cli_buscaDNIrepetido(ECliente* arrayClientes, int len, char* DNI)
{
    int retorno=0;
    int i;

    for(i=0;i<len;i++)
    {
        if(strcmp(arrayClientes[i].DNI,DNI)==0)
        {
            retorno=-1;
            break;
        }
    }

    return retorno;
}
