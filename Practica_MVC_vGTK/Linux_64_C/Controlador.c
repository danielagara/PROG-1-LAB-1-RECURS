#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Vista.h"
#include "Controlador.h"
#include "DataManager.h"


static ArrayList* nominaSocios;
static int proximoIdSocio=0;
static int getNewId();
static int setNewId(int id);
static int ultId;

void cont_init()
{
    nominaSocios = al_newArrayList();
    ultId=dm_readAll(nominaSocios);
    if(ultId!=-1)
    {
        getNewId(ultId);
    }
    else
    {
        setNewId(0);
    }
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewId(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAll(nominaSocios);
    return 0;
}

int cont_bajaSocio(int id)
{
    int retorno=-1;
    Socio* socioBaja=NULL;
    socioBaja=cont_existeSocio(id);
    if(socioBaja!=NULL)
    {
        soc_setEstado(socioBaja,SOCIO_ESTADO_INACTIVO);
        dm_saveAll(nominaSocios);
        retorno=0;
    }
    return retorno;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    int retorno=-1;
    Socio* socioModificar=NULL;
    socioModificar=cont_existeSocio(id);
    if(socioModificar!=NULL)
    {
        soc_setNombre(socioModificar,nombre);
        soc_setApellido(socioModificar,apellido);
        soc_setDni(socioModificar,dni);
        dm_saveAll(nominaSocios);
        retorno=0;
    }

    return retorno;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}

static int getNewId()
{
    return proximoIdSocio++;
}

static int setNewId(int id)
{
    proximoIdSocio = id;
    return 0;
}

void* cont_existeSocio(int id)
{
    Socio* retorno=NULL;
    if(id>=0)
    {
        if(soc_findById(nominaSocios,id)!=NULL)
        {
            retorno=soc_findById(nominaSocios,id);
        }
    }
    return retorno;
}
