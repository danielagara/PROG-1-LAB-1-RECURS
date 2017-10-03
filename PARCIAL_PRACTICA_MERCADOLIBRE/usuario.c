#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "validar.h"
#include "string.h"

#define ESTADO_USUARIO_OCUPADO 1
#define ESTADO_USUARIO_LIBRE 0

// Funciones privadas
static int buscarProximoId (EUsuario* arrayUsuarios, int longitud);
static int buscarIndiceId (EUsuario* arrayUsuarios, int longitud, int id);
static int modificarUsuarioPorIndice(EUsuario* arrayUsuarios, int index);
//___________________


int usu_editarUsuario(EUsuario* arrayUsuarios,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID a modificar:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayUsuarios,len,id);
        if(index>=0)
        {
           return modificarUsuarioPorIndice(arrayUsuarios,index);
        }
    }
    return -1;
}


static int modificarUsuarioPorIndice (EUsuario* arrayUsuarios, int index)
{
    int retorno = -1;
    char bNombreUsuario[51];
    char bPassword[51];

    if(arrayUsuarios != NULL && index >= 0)
    {
        if(val_getNombre(bNombreUsuario,"\nNOMBRE DE USUARIO?","\nError:\n",3,51)==0)
        {

            if(val_getNombre(bPassword,"\nPASSWORD?","\nError:\n",3,51)==0)
            {
                strncpy(arrayUsuarios[index].nombreDeUsuario,bNombreUsuario,51);
				strncpy(arrayUsuarios[index].password,bPassword,51);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int usu_cargarUsuario(EUsuario* arrayUsuarios, int index, int len)
{
    int retorno = -1;
    int id;
    char bNombreUsuario[51];
    char bPassword[51];

    if(arrayUsuarios != NULL && index >= 0 && index < len)
    {
            if(val_getNombre(bNombreUsuario,"\nNOMBRE DE USUARIO?  ","\nError:\n",3,51)==0 && usu_buscaNombreUsuarioRepetido(arrayUsuarios,len,bNombreUsuario)==0)
            {
				if(val_getNombre(bPassword,"\nPASSWORD?  ","\nError:\n",3,51)==0)
				{
						id = buscarProximoId(arrayUsuarios,len);
						if(id != -1)
						{
							strncpy(arrayUsuarios[index].nombreDeUsuario,bNombreUsuario,51);
							strncpy(arrayUsuarios[index].password,bPassword,51);
							arrayUsuarios[index].flagDeEstado = ESTADO_USUARIO_OCUPADO;
							arrayUsuarios[index].idUsuario= id;
							printf("\nSU ID ES: %d\n", arrayUsuarios[index].idUsuario);
							retorno = 0;
						}

				}

            }

    }
    return retorno;
}

int usu_initUsuario(EUsuario* arrayUsuarios, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayUsuarios != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayUsuarios[i].flagDeEstado = ESTADO_USUARIO_LIBRE;
        }

    }
    return retorno;
}

/*int usu_printUsuario(EUsuario* arrayUsuarios, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayUsuarios != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayUsuarios[i].flagDeEstado == ESTADO_USUARIO_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Apellido: %.s - DNI:%s - Edad:%d\n",arrayUsuarios[i].nombreDeUsuario,arrayUsuarios[i].nombre,arrayUsuarios[i].apellido, arrayUsuarios[i].DNI, arrayUsuarios[i].edad);
            }
        }

    }
    return retorno;
}*/


int usu_buscarIndiceUsuarioLibre (EUsuario* arrayUsuarios, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayUsuarios != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayUsuarios[i].flagDeEstado == ESTADO_USUARIO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}


static int buscarProximoId(EUsuario* arrayUsuarios, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayUsuarios != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayUsuarios[i].flagDeEstado == ESTADO_USUARIO_OCUPADO)
            {
                if(idMax < arrayUsuarios[i].idUsuario)
                    idMax = arrayUsuarios[i].idUsuario;
            }
        }

    }
    return idMax + 1;
}


static int buscarIndiceId(EUsuario* arrayUsuarios, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayUsuarios != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayUsuarios[i].flagDeEstado == ESTADO_USUARIO_OCUPADO)
            {
                if(id == arrayUsuarios[i].idUsuario)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}


int usu_bajarUsuario(EUsuario* arrayUsuarios,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID del asociado a dar de baja:  ","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayUsuarios,len,id);
        if(index>=0)
        {
           arrayUsuarios[index].flagDeEstado=ESTADO_USUARIO_LIBRE;
           printf("EL USUARIO HA SIDO DADO DE BAJA\n");
		   retorno=0;
        }
    }

    return retorno;
}


int usu_pideId(EUsuario* arrayUsuarios,int len)
{
    int retorno = -1;
    int i;
    char bidUsuario[51];
    if(arrayUsuarios != NULL && len > 0)
    {
        printf("INGRESE SU ID:   \n");
        myFgets(bidUsuario,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayUsuarios[i].idUsuario == atoi(bidUsuario) && arrayUsuarios[i].flagDeEstado== ESTADO_USUARIO_OCUPADO)
            {
                retorno =  arrayUsuarios[i].idUsuario;
                break;
            }
        }

    }
    return retorno;
}



int usu_buscaNombreUsuarioRepetido(EUsuario* arrayUsuarios, int len, char* nombreDeUsuario)
{
    int retorno=0;
    int i;

    for(i=0;i<len;i++)
    {
        if(strcmp(arrayUsuarios[i].nombreDeUsuario,nombreDeUsuario)==0)
        {
            retorno=-1;
            break;
        }
    }

    return retorno;
}
