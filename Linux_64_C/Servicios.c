#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicios.h"


Servicios* serv_new(char* descripcion, int id, int estado)
{
    Servicios* nuevoServicios = malloc(sizeof(Servicios));
    serv_setDescripcion(nuevoServicios,descripcion);
    serv_setId(nuevoServicios,id);
    serv_setEstado(nuevoServicios,estado);

    return nuevoServicios;
}


int serv_delete(Servicios* this)
{
    free(this);
    return 0;
}


int serv_setDescripcion(Servicios* this,char* descripcion)
{
    strcpy(this->descripcion,descripcion);
    return 0;
}


char* serv_getDescripcion(Servicios* this)
{
    return this->descripcion;
}

int serv_setId(Servicios* this,int id)
{

    this->id = id;
    return 0;
}

int serv_getId(Servicios* this)
{
    return this->id;
}

int serv_setEstado(Servicios* this,int estado)
{

    this->estado = estado;
    return 0;
}

int serv_getEstado(Servicios* this)
{
    return this->estado;
}


Servicios* serv_findById(ArrayList* pArrayServicios, int id)
{
    int i;
    Servicios *auxServicios;
    void* retorno=NULL;

    for(i=0;i<al_len(pArrayServicios);i++)
    {
        auxServicios = al_get(pArrayServicios,i);
        if(id == auxServicios->id)
        {
            retorno = auxServicios;
            break;
        }
    }

    return retorno;
}
