#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "validar.h"
#include "string.h"


// Funciones privadas
static int buscarProximoId (EPantalla* arrayPantallas, int longitud);
static int buscarIndiceId (EPantalla* arrayPantallas, int longitud, int id);
static int modificarPantallaPorIndice(EPantalla* arrayPantallas, int index);
//___________________


int pant_editarPantalla(EPantalla* arrayPantallas,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID de pantalla a modificar:  ","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayPantallas,len,id);
        if(index>=0)
        {
           return modificarPantallaPorIndice(arrayPantallas,index);
        }
    }
    return -1;
}


static int modificarPantallaPorIndice (EPantalla* arrayPantallas, int index)
{
    int retorno = -1;
    char bNombrePantalla[51];
    char bDireccionPantalla[51];
	char bPrecioPublicacionXdia[51];
	char bTipoPantalla[51];

    if(arrayPantallas != NULL && index >= 0)
    {
        if(val_getNombre(bNombrePantalla,"\nNOMBRE DE PANTALLA?\t","\nError:\n",3,51)==0)
        {
            if(val_getDescripcion(bDireccionPantalla,"\nDIRECCION DE LA PANTALLA?\t","\nError:\n",3,51)==0)
            {
				if(val_getFloat(bPrecioPublicacionXdia,"\nPRECIO DE LA PUBLICACION POR DIA EN ESTA PANTALLA?\t","\nError:\n",3,51)==0)
				{
					if(val_getInt(bTipoPantalla,"\nTIPO DE LA PANTALLA? INGRESE 1: LCD o 2:LED \t","\nError:\n",3,51)==0)
					{
						strncpy(arrayPantallas[index].nombrePantalla,bNombrePantalla,51);
						strncpy(arrayPantallas[index].direccionPantalla,bDireccionPantalla,51);
						arrayPantallas[index].precioPublicacionXdia=atof(bPrecioPublicacionXdia);
						if(atoi(bTipoPantalla)==1)
						{
							arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LCD;
						}
						if(atoi(bTipoPantalla)==2)
						{
							arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LED;
						}
						retorno = 0;
					}
				}

            }
        }

    }
    return retorno;
}

int pant_cargarPantalla(EPantalla* arrayPantallas, int index, int len)
{
    int retorno = -1;
    int id;
	char bNombrePantalla[51];
    char bDireccionPantalla[51];
	char bPrecioPublicacionXdia[51];
	char bTipoPantalla[51];

    if(arrayPantallas != NULL && index >= 0 && index < len)
    {
            if(val_getNombre(bNombrePantalla,"\nNOMBRE DE PANTALLA?\t","\nError:\n",3,51)==0)
            {
				if(val_getDescripcion(bDireccionPantalla,"\nDIRECCION DE LA PANTALLA?\t","\nError:\n",3,51)==0)
				{
					if(val_getFloat(bPrecioPublicacionXdia,"\nPRECIO DE LA PUBLICACION POR DIA EN ESTA PANTALLA?\t","\nError:\n",3,51)==0)
					{
						if(val_getInt(bTipoPantalla,"\nTIPO DE LA PANTALLA? INGRESE 1: LCD o 2:LED \t","\nError:\n",3,51)==0)
						{
							id = buscarProximoId(arrayPantallas,len);
							if(id != -1)
							{
								arrayPantallas[index].idPantalla=id;
								arrayPantallas[index].flagDeEstado=ESTADO_PANTALLA_OCUPADA;
								strncpy(arrayPantallas[index].nombrePantalla,bNombrePantalla,51);
								strncpy(arrayPantallas[index].direccionPantalla,bDireccionPantalla,51);
								arrayPantallas[index].precioPublicacionXdia=atof(bPrecioPublicacionXdia);
								if(atoi(bTipoPantalla)==1)
								{
									arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LCD;
								}
								if(atoi(bTipoPantalla)==2)
								{
									arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LED;
								}
								printf("EL ID DE LA PANTALLA ES %d\t",arrayPantallas[index].idPantalla);
							}
						}
					}

				}

            }

    }
    return retorno;
}

int pant_initPantalla(EPantalla* arrayPantallas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPantallas[i].flagDeEstado = ESTADO_PANTALLA_LIBRE;
        }

    }
    return retorno;
}

int pant_printPantalla(EPantalla* arrayPantallas, int longitud)
{
    int retorno = -1;
    int i;
	char auxTipoPantalla[51];
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA)
            {
				if(arrayPantallas[i].tipoPantalla==1)
				{
					strncpy(auxTipoPantalla,"LCD",51);
				}
				else
				{
					strncpy(auxTipoPantalla,"LED",51);
				}

                printf("ID: %d - NOMBRE DE LA PANTALLA: %s - DIRECCION DE LA PANTALLA: %s - TIPO DE LA PANTALLA: %s - PRECIO DE LA PUBLICACION POR DIA: %.2f \n",arrayPantallas[i].idPantalla,arrayPantallas[i].nombrePantalla,arrayPantallas[i].direccionPantalla,auxTipoPantalla, arrayPantallas[i].precioPublicacionXdia);
            }
        }

    }
    return retorno;
}


int pant_buscarIndicePantallaLibre (EPantalla* arrayPantallas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}


static int buscarProximoId(EPantalla* arrayPantallas, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA)
            {
                if(idMax < arrayPantallas[i].idPantalla)
                    idMax = arrayPantallas[i].idPantalla;
            }
        }

    }
    return idMax + 1;
}


static int buscarIndiceId(EPantalla* arrayPantallas, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayPantallas != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA)
            {
                if(id == arrayPantallas[i].idPantalla)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}


int pant_bajarPantalla(EPantalla* arrayPantallas,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID de la pantalla a dar de baja:  ","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayPantallas,len,id);
        if(index>=0)
        {
           arrayPantallas[index].flagDeEstado=ESTADO_PANTALLA_LIBRE;
           printf("EL USUARIO HA SIDO DADO DE BAJA\n");
		   retorno=0;
        }
    }

    return retorno;
}


int pant_pideId(EPantalla* arrayPantallas,int len)
{
    int retorno = -1;
    int i;
    char bidPantalla[51];
    if(arrayPantallas != NULL && len > 0)
    {
        printf("INGRESE EL ID DE LA PANTALLA:   \n");
        myFgets(bidPantalla,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayPantallas[i].idPantalla == atoi(bidPantalla) && arrayPantallas[i].flagDeEstado== ESTADO_PANTALLA_OCUPADA)
            {
                retorno =  arrayPantallas[i].idPantalla;
                break;
            }
        }

    }
    return retorno;
}
