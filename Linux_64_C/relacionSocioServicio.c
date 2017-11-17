#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicios.h"
#include "relacionSocioServicio.h"
//relaciona entidades

SocioServicio* socserv_new(int idSocio, int idServicio, int idSocioServicio, int estado)
{
    SocioServicio* nuevoSocioServicio = malloc(sizeof(SocioServicio));
    socserv_setIdSocioServicio(nuevoSocioServicio,idSocioServicio);
    socserv_setIdServicio(nuevoSocioServicio,idServicio);
    socserv_setIdSocio(nuevoSocioServicio,idSocio);
    socserv_setEstado(nuevoSocioServicio,estado);

    return nuevoSocioServicio;
}

int socserv_delete(SocioServicio* this)
{
    free(this);
    return 0;
}

int socserv_setIdSocioServicio(SocioServicio* this,int idSocioServicio)
{

    this->idSocioServicio = idSocioServicio;
    return 0;
}

int socserv_getIdSocioServicio(SocioServicio* this)
{
    return this->idSocioServicio;
}

int socserv_setIdServicio(SocioServicio* this,int idServicio)
{

    this->idServicio = idServicio;
    return 0;
}

int socserv_getIdServicio(SocioServicio* this)
{
    return this->idServicio;
}

int socserv_setIdSocio(SocioServicio* this,int idSocio)
{

    this->idSocio = idSocio;
    return 0;
}

int socserv_getIdSocio(SocioServicio* this)
{
    return this->idSocio;
}

int socserv_setEstado(SocioServicio* this,int estado)
{

    this->estado = estado;
    return 0;
}

int socserv_getEstado(SocioServicio* this)
{
    return this->estado;
}

SocioServicio* socserv_findById(ArrayList* pArraySocioServicio, int idSocioServicio)
{
    int i;
    SocioServicio* auxSocioServicio;
    void* retorno=NULL;

    for(i=0;i<al_len(pArraySocioServicio);i++)
    {
        auxSocioServicio = al_get(pArraySocioServicio,i);
        if(idSocioServicio == auxSocioServicio->idSocioServicio)
        {
            retorno = auxSocioServicio;
            break;
        }
    }

    return retorno;
}

SocioServicio* socserv_findByIds(ArrayList* pArraySocioServicio, int idSocio, int idServicio)
{
    int i;
    SocioServicio* auxSocioServicio;
    void* retorno=NULL;

    for(i=0;i<al_len(pArraySocioServicio);i++)
    {
        auxSocioServicio = al_get(pArraySocioServicio,i);
        if(idSocio == socserv_getIdSocio(auxSocioServicio) && idServicio == socserv_getIdServicio(auxSocioServicio))
        {
            retorno = auxSocioServicio;
            break;
        }
    }

    return retorno;
}
