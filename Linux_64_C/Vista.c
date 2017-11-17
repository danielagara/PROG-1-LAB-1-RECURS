#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "Servicios.h"
#include "relacionSocioServicio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAltaSocios();
static void opcionBajaSocios();
static void opcionModificacionSocios();
static void opcionListadoSocios();

static void opcionAltaServicios();
static void opcionBajaServicios();
static void opcionModificacionServicios();
static void opcionListadoServicios();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 12)
    {
        val_getUnsignedInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListadoSocios();
                break;
            case 2:
                opcionAltaSocios();
                break;
            case 3:
                opcionBajaSocios();
                break;
            case 4:
                opcionModificacionSocios();
                break;
            //PARTE SERVICIOS
            case 5:
                opcionListadoServicios();
                break;
            case 6:
                opcionAltaServicios();
                break;
            case 7:
                opcionBajaServicios();
                break;
            case 8:
                opcionModificacionServicios();
                break;
            //PARTE SOCIOS SERVICIOS
            case 9:
                opcionListadoSociosServicios();
                break;
            case 10:
                opcionAltaSociosServicios();
                break;
            case 11:
                opcionBajaSociosServicios();
                break;
        }
    }

    return 0;
}

//PARTE SOCIOS
void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
        {
            auxSocio=al_get(pListaSocios,i);
            if(auxSocio->estado==SOCIO_ESTADO_ACTIVO)
            {
            auxSocio = al_get(pListaSocios,i);
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",soc_getNombre(auxSocio),
                            soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
            }
        }

}


void mostrarErrorSocios(char *);

static void opcionAltaSocios()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    if(val_getString(auxNombre, "Nombre? ", "Error",2,50) ==0 && val_getString(auxApellido, "Apellido? ", "Error",2,50) == 0 && val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
    {
        cont_altaSocio(auxNombre,auxApellido,auxDni);
    }

}

static void opcionBajaSocios()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaSocio(id);
    }

}

static void opcionModificacionSocios()
{
    char auxId[10];
    int id;
    int estado;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
        {
            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
            {
                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                {
                    if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
                    {
                        estado=atoi(auxEstado);
                        if(estado == 0 || estado == 1)
                        {
                            cont_modificarSocio(auxNombre,auxApellido,auxDni,id,estado);
                        }

                    }

                }
            }

        }

    }

}

static void opcionListadoSocios()
{
    cont_listarSocios();
}

//PARTE SERVICIOS

void vista_mostrarServicios(ArrayList* pListaServicios)
{
    int i;
    Servicios* auxServicios;
    for(i=0;i<al_len(pListaServicios);i++)
        {
            auxServicios=al_get(pListaServicios,i);
            if(auxServicios->estado==SERVICIOS_ESTADO_ACTIVO)
            {
                auxServicios = al_get(pListaServicios,i);
                printf("DESCRIPCION: %s - ID: %d\n",serv_getDescripcion(auxServicios), serv_getId(auxServicios));
            }
        }
}


static void opcionAltaServicios()
{
    char auxDescripcion[60];
    if(val_getDescripcion(auxDescripcion, "Descripcion? ", "Error",2,60)==0)
    {
        printf("hola\n");
        cont_altaServicios(auxDescripcion);
    }

}

static void opcionBajaServicios()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaServicios(id);
    }

}

static void opcionModificacionServicios()
{
    char auxId[10];
    int id;
    int estado;
    char auxDescripcion[60];
    char auxEstado[5];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxDescripcion, "Descripcion? ", "Error",2,50)==0)
        {
            if(val_getUnsignedInt(auxEstado,"Estado?\nACTIVO= 0\nINACTIVO= 1", "Error",2,5)==0)
            {
                estado=atoi(auxEstado);
                if(estado == 0 || estado == 1)
                {
                    cont_modificarServicios(auxDescripcion,id,estado);
                }

            }

        }

    }

}

static void opcionListadoServicios()
{
    cont_listarServicios();
}

//PARTE SOCIOS SERVICIOS

void vista_mostrarSociosServicios(ArrayList* pListaServicios)
{
    int i;
    Servicios* auxServicios;
    for(i=0;i<al_len(pListaServicios);i++)
        {
            auxServicios=al_get(pListaServicios,i);
            if(auxServicios->estado==SERVICIOS_ESTADO_ACTIVO)
            {
                auxServicios = al_get(pListaServicios,i);
                printf("DESCRIPCION: %s - ID: %d\n",serv_getDescripcion(auxServicios), serv_getId(auxServicios));
            }
        }
}


static void opcionAltaSociosServicios()
{
    char auxDescripcion[60];
    if(val_getDescripcion(auxDescripcion, "Descripcion? ", "Error",2,60)==0)
    {
        printf("hola\n");
        cont_altaServicios(auxDescripcion);
    }

}

static void opcionBajaSociosServicios()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaServicios(id);
    }

}
