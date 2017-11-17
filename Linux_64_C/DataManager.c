
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Socio.h"
#include "Servicios.h"
#include "DataManager.h"

int dm_saveAllSocios(ArrayList* pArraySocios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArraySocios);i++)
        {
            pSocio=al_get(pArraySocios,i);
            fwrite(pSocio,sizeof(Socio),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);
    return retorno;
}

int dm_readAllSocios(ArrayList* pArraySocios)
{
    int retorno=-1;
    Socio auxSocio;
    int maxId=0;
    Socio* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxSocio,sizeof(Socio),1,pArchivoSocios)==1)
            {
                pSocio=soc_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(pArraySocios,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
    return retorno;
}


//PARTE SERVICIOS

int dm_saveAllServicios(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pServicios=NULL;
    if(pArchivoServicios!=NULL)
    {
        for(i=0;i<al_len(pArrayServicios);i++)
        {
            pServicios=al_get(pArrayServicios,i);
            fwrite(pServicios,sizeof(Servicios),1,pArchivoServicios);
            retorno=0;
        }

    }
    fclose(pArchivoServicios);
    return retorno;
}

int dm_readAllServicios(ArrayList* pArrayServicios)
{
    int retorno=-1;
    Servicios auxServicios;
    int maxId=0;
    Servicios* pServicios=NULL;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pArchivoServicios!=NULL)
    {
        do{
            if(fread(&auxServicios,sizeof(Servicios),1,pArchivoServicios)==1)
            {
                pServicios=serv_new(auxServicios.descripcion,auxServicios.id,auxServicios.estado);
                al_add(pArrayServicios,pServicios);
                if(auxServicios.id>maxId)
                {
                    maxId=auxServicios.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoServicios));
        fclose(pArchivoServicios);
    }
    return retorno;
}
