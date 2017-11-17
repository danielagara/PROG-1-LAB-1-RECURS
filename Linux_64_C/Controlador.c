#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicios.h"
#include "relacionSocioServicio.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaSocios;
static ArrayList* nominaServicios;
static ArrayList* nominaSociosServicios;
static int proximoIdSocio=0;
static int getNewIdSocios();
static int setNewIdSocios(int id);
static int proximoIdServicios=0;
static int getNewIdServicios();
static int setNewIdServicios(int id);
static int proximoIdSociosServicios=0;
static int getNewIdSociosServicios();
static int setNewIdSociosServicios(int id);

void cont_init()
{
    nominaSocios = al_newArrayList();
    nominaServicios = al_newArrayList();
    setNewIdSocios(dm_readAllSocios(nominaSocios) + 1);
    setNewIdServicios(dm_readAllServicios(nominaServicios) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaSocio (char* nombre,char* apellido,char* dni)
{
    Socio* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewIdSocios(),SOCIO_ESTADO_ACTIVO);
    al_add(nominaSocios,auxSocio);
    dm_saveAllSocios(nominaSocios);
    return 0;
}

int cont_bajaSocio (int id)
{
    Socio* auxSocio;
    auxSocio=soc_findById(nominaSocios,id);
    if(auxSocio!=NULL)
    {
        soc_setEstado(auxSocio,SOCIO_ESTADO_INACTIVO);
        dm_saveAllSocios(nominaSocios);
    }

    return 0;
}


int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado)
{
    Socio* auxSocio;

    auxSocio=soc_findById(nominaSocios,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);
        soc_setEstado(auxSocio,estado);
        dm_saveAllSocios(nominaSocios);
    }

    return 0;
}

int cont_listarSocios ()
{
    vista_mostrarSocios(nominaSocios);
    return 0;
}


static int getNewIdSocios()
{
    return proximoIdSocio++;
}

static int setNewIdSocios(int id)
{
    proximoIdSocio = id;
    return 0;
}

//PARTE SERVICIOS


int cont_altaServicios (char* descripcion)
{
    Servicios* auxServicios;
    auxServicios = serv_new(descripcion,getNewIdServicios(),SERVICIOS_ESTADO_ACTIVO);
    al_add(nominaServicios,auxServicios);
    dm_saveAllServicios(nominaServicios);
    return 0;
}

int cont_bajaServicios (int id)
{
    Servicios* auxServicios;
    auxServicios=serv_findById(nominaServicios,id);
    if(auxServicios!=NULL)
    {
        serv_setEstado(auxServicios,SERVICIOS_ESTADO_INACTIVO);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}


int cont_modificarServicios (char* descripcion, int id, int estado)
{
    Servicios* auxServicios;

    auxServicios=serv_findById(nominaServicios,id);

    if(auxServicios!=NULL)
    {
        serv_setDescripcion(auxServicios,descripcion);
        serv_setEstado(auxServicios,estado);
        dm_saveAllServicios(nominaServicios);
    }

    return 0;
}

int cont_listarServicios ()
{
    vista_mostrarServicios(nominaServicios);
    return 0;
}


static int getNewIdServicios()
{
    return proximoIdServicios++;
}

static int setNewIdServicios(int id)
{
    proximoIdServicios = id;
    return 0;
}

//PARTE SOCIOS SERVICIOS
static int getNewIdSociosServicios()
{
    return proximoIdSociosServicios++;
}

static int setNewIdSociosServicios(int id)
{
    proximoIdSociosServicios = id;
    return 0;
}

int cont_altaSociosServicios (int idSocio, int idServicio)
{
    SocioServicio* auxSociosServicios;
    if(socserv_findByIds(nominaSociosServicios, idSocio, idServicio)==NULL)
    {
        auxSociosServicios=socserv_new(idSocio, idServicio, getNewIdSociosServicios(),SOCIOS_SERVICIOS_ESTADO_ACTIVO);
        al_add(nominaSociosServicios, auxSociosServicios);
        dm_saveAllSociosServicios(nominaSociosServicios);
    }
    return 0;
}
