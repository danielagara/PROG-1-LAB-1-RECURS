#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "validar.h"
#include <string.h>


//FUNCIONES PRIVADAS
static int buscarProximoIdContratacion(EContratacion* arrayContrataciones, int longitud);
static int buscarIndicePantalla(EContratacion* arrayContrataciones, int longitud, char* cuitCliente, int idPantalla);
static int modificaContratacionPorIndice(EContratacion* arrayContrataciones, int index);
//_________________________________________________________________

static int buscarProximoIdContratacion(EContratacion* arrayContrataciones, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayContrataciones[i].flagDeEstado == ESTADO_CONTRATACION_OCUPADA)
            {
                if(idMax < arrayContrataciones[i].idContratacion)
                    idMax = arrayContrataciones[i].idContratacion;
            }
        }

    }
    return idMax + 1;
}

static int buscarIndicePantalla(EContratacion* arrayContrataciones, int longitud, char* cuitCliente, int idPantalla)
{
    int i;
    int retorno = -1;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(idPantalla == arrayContrataciones[i].idPantalla && stricmp(arrayContrataciones[i].cuitCliente,cuitCliente)==0)
            {
                if(arrayContrataciones[i].flagDeEstado == ESTADO_CONTRATACION_OCUPADA)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

int cont_nuevaContratacion(EContratacion* arrayContrataciones, int index, int len, int idPantalla)
{
    int retorno = -1;
    int idContratacion;
    char bCUITdelCliente[51];
	char bDiasQueDuraPublicacion[51];
	char bNombreArchivoDelVideo[100];


    if(arrayContrataciones != NULL && index >= 0 && index < len && idPantalla!=-1)
    {
          if(val_getInt(bCUITdelCliente,"\nCUIT DEL CLIENTE?\t","\nError:\n",3,51)==0)
          {
			  if(val_getInt(bDiasQueDuraPublicacion,"\nDIAS QUE DURA LA PUBLICACION?\t","\nError:\n",3,51)==0)
			  {
				  if(val_getDescripcion(bNombreArchivoDelVideo,"\nNOMBRE DEL ARCHIVO DEL VIDEO?\t","\nError:\n",3,100)==0)
				  {
					idContratacion = buscarProximoIdContratacion(arrayContrataciones,len);
					if(idContratacion != -1)
					{
						strncpy(arrayContrataciones[index].cuitCliente,bCUITdelCliente,51);
						arrayContrataciones[index].idPantalla = idPantalla;
						arrayContrataciones[index].diasQueDuraPublicacion=atoi(bDiasQueDuraPublicacion);
						strncpy(arrayContrataciones[index].nombreArchivoDelVideo,bNombreArchivoDelVideo,100);
						arrayContrataciones[index].flagDeEstado = ESTADO_CONTRATACION_OCUPADA;
						arrayContrataciones[index].idContratacion = idContratacion;
						printf("EL ID DE SU PRODUCTO ES: %d", arrayContrataciones[index].idContratacion);
						retorno = 0;
					}
				  }

			  }

           }

    }
    return retorno;
}

int cont_buscarIndiceContratacionLibre(EContratacion* arrayContrataciones, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayContrataciones[i].flagDeEstado ==ESTADO_CONTRATACION_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int cont_initProductos(EContratacion* arrayContrataciones, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayContrataciones[i].flagDeEstado = ESTADO_CONTRATACION_LIBRE;
        }

    }
    return retorno;
}

int cont_editarContratacion(EContratacion* arrayContrataciones,int len)
{
    char bCUITdelCliente[51];
    int index;
	char bidPantalla[51];
    if(val_getInt(bidPantalla,"INGRESE EL ID DE LA PANTALLA A MODIFICAR:\t","INCORRECTO",2,51)==0)
    {
        index = buscarIndicePantalla(arrayContrataciones,len,bCUITdelCliente,atoi(bidPantalla));
        if(index>=0)
        {

            return modificaContratacionPorIndice(arrayContrataciones,index);
        }
    }
    return 0;
}


static int modificaContratacionPorIndice(EContratacion* arrayContrataciones, int index)
{
    int retorno = -1;
    char bdiasQueDuraPublicacion[51];

    if(arrayContrataciones != NULL && index >= 0)
    {
        if(val_getInt(bdiasQueDuraPublicacion,"\nCUANTOS DIAS QUIERE QUE DURE AHORA LA CONTRATACION?\t","\nError:\n",3,51)==0)
        {
            arrayContrataciones[index].diasQueDuraPublicacion=atoi(bdiasQueDuraPublicacion);
            retorno = 0;
        }
    }
    return retorno;
}


int cont_cancelarContratacion(EContratacion* arrayContrataciones,int len)
{
    int retorno=-1;
	char bidPantalla[51];
	int i;

		if(val_getInt(bidPantalla,"Ingrese id de la pantalla a borrar:  ","INCORRECTO",2,32)==0)
		{
			if(atoi(bidPantalla)!=-1)
			{
				for(i=0;i<len;i++)
				{
					if(arrayContrataciones[i].idPantalla==atoi(bidPantalla))
					{
						arrayContrataciones[i].flagDeEstado=ESTADO_CONTRATACION_LIBRE;
						retorno=0;
					}
				}
			}

		}

    return retorno;
}

