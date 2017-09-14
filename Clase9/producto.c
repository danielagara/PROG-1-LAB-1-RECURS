#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "validar.h"

int prod_cargarProducto (sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[LIMITE_CARACTERES];
    char bPrecio[LIMITE_CARACTERES];
    char bDescripcion[LIMITE_CARACTERES];

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",LIMITE_INTENTOS,LIMITE_CARACTERES)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",LIMITE_INTENTOS,LIMITE_CARACTERES)==0)
            {
                if(val_getDescripcion(bDescripcion,"\nDescripcion?\n","\nError:\n",LIMITE_INTENTOS,LIMITE_CARACTERES)==0)
                {
                    strncpy(arrayProducto[index].nombre,bNombre,LIMITE_CARACTERES);
                    arrayProducto[index].precio = atof(bPrecio);
                    strncpy(arrayProducto[index].desc, bDescripcion, LIMITE_CARACTERES);
                    arrayProducto[index].estado = PRODUCTO_OCUPADO;

                }
                //printf("Float ok");

            }
        }

    }
    return retorno;
}

int prod_initProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProducto[i].estado = PRODUCTO_LIBRE;
        }

    }
    return retorno;
}

int prod_printProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                printf("ID: %d - Nombre: %s - Precio: %.2f - Descripcion: %s\n",i,arrayProducto[i].nombre,arrayProducto[i].precio, arrayProducto[i].desc);
            }
        }

    }
    return retorno;
}

int prod_indexDisponible(sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
