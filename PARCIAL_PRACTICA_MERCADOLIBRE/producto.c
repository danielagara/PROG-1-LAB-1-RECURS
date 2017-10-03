#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "validar.h"
#include <string.h>

#define ESTADO_PRODUCTO_LIBRE 0
#define ESTADO_PRODUCTO_PUBLICADO 1
#define ESTADO_PRODUCTO_VENDIDO 2
//FUNCIONES PRIVADAS
static int buscarProximoIdProducto(EPublicacionProducto* arrayPublicacionesProductos, int longitud);
static int buscarIndiceIdProducto(EPublicacionProducto* arrayPublicacionesProductos, int longitud, int id);
static int modificarPublicacionProductoPorIndice(EPublicacionProducto* arrayPublicacionesProductos, int index);
//_________________________________________________________________

static int buscarProximoIdProducto(EPublicacionProducto* arrayPublicacionesProductos, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayPublicacionesProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPublicacionesProductos[i].estadoProducto == ESTADO_PRODUCTO_PUBLICADO)
            {
                if(idMax < arrayPublicacionesProductos[i].idProducto)
                    idMax = arrayPublicacionesProductos[i].idProducto;
            }
        }

    }
    return idMax + 1;
}

static int buscarIndiceIdProducto(EPublicacionProducto* arrayPublicacionesProductos, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayPublicacionesProductos != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(id == arrayPublicacionesProductos[i].idProducto)
            {
                if(arrayPublicacionesProductos[i].estadoProducto == ESTADO_PRODUCTO_PUBLICADO)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

int prod_nuevaPublicacion(EPublicacionProducto* arrayPublicacionesProductos, int index, int len, int idUsuario)
{
    int retorno = -1;
    int id_producto;
    char bNombreProducto[51];
	char bStockProducto[51];
	char bPrecioProducto[51];


    if(arrayPublicacionesProductos != NULL && index >= 0 && index < len && idUsuario!=-1)
    {
          if(val_getNombre(bNombreProducto,"\nNOMBRE DEL PRODUCTO:  ","\nError:\n",3,51)==0)
          {
			  if(val_getInt(bStockProducto,"\nSTOCK DEL PRODUCTO:  ","\nError:\n",3,51)==0)
			  {
				  if(val_getFloat(bPrecioProducto,"\nPRECIO DEL PRODUCTO:  ","\nError:\n",3,51)==0)
				  {
					id_producto = buscarProximoIdProducto(arrayPublicacionesProductos,len);
					if(id_producto != -1)
					{
						strncpy(arrayPublicacionesProductos[index].nombreProducto,bNombreProducto,51);
						arrayPublicacionesProductos[index].idUsuario = idUsuario;
						arrayPublicacionesProductos[index].stockProducto=atoi(bStockProducto);
						arrayPublicacionesProductos[index].precioProducto=atof(bPrecioProducto);
						arrayPublicacionesProductos[index].estadoProducto = ESTADO_PRODUCTO_PUBLICADO;
						arrayPublicacionesProductos[index].idProducto = id_producto;
						arrayPublicacionesProductos[index].cantidadVendidaProducto =0;
						printf("EL ID DE SU PRODUCTO ES: %d", arrayPublicacionesProductos[index].idProducto);
						retorno = 0;
					}
				  }

			  }

           }

    }
    return retorno;
}


int prod_buscarIndiceProductoLibre(EPublicacionProducto* arrayPublicacionesProductos, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPublicacionesProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPublicacionesProductos[i].estadoProducto ==ESTADO_PRODUCTO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

int prod_initProductos(EPublicacionProducto* arrayPublicacionesProductos, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPublicacionesProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPublicacionesProductos[i].estadoProducto = ESTADO_PRODUCTO_LIBRE;
        }

    }
    return retorno;
}

int prod_editarPublicacion(EPublicacionProducto* arrayPublicacionesProductos,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID del usuario:","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceIdProducto(arrayPublicacionesProductos,len,id);
		prod_listaPublicacionesPorIdUsuario(arrayPublicacionesProductos,len,id);
        if(index>=0)
        {

           return modificarPublicacionProductoPorIndice(arrayPublicacionesProductos,index);
        }
    }
    return -1;
}


static int modificarPublicacionProductoPorIndice(EPublicacionProducto* arrayPublicacionesProductos, int index)
{
    int retorno = -1;
    char bPrecioProducto[51];
    char bStockProducto[51];

    if(arrayPublicacionesProductos != NULL && index >= 0)
    {
        if(val_getFloat(bPrecioProducto,"\nPRECIO?  ","\nError:\n",3,51)==0)
        {

            if(val_getInt(bStockProducto,"\nSTOCK?","\nError:\n",3,51)==0)
            {
                arrayPublicacionesProductos[index].stockProducto=atoi(bStockProducto);
				arrayPublicacionesProductos[index].precioProducto=atof(bPrecioProducto);
                retorno = 0;
            }
        }

    }
    return retorno;
}


void prod_listaPublicacionesPorIdUsuario(EPublicacionProducto* arrayPublicacionesProductos, int len, int idUsuario)
{
	int i;

	if(arrayPublicacionesProductos != NULL && len>0 && idUsuario!=-1)
	{
		for(i=0;i<len;i++)
		{
			if(arrayPublicacionesProductos[i].idUsuario==idUsuario && (arrayPublicacionesProductos[i].estadoProducto==ESTADO_PRODUCTO_PUBLICADO || arrayPublicacionesProductos[i].estadoProducto==ESTADO_PRODUCTO_VENDIDO))
			{
				printf("\nID DEL PRODUCTO: %d \nNOMBRE DEL PRODUCTO: %s \nPRECIO DEL PRODUCTO: %.2f \nSTOCK DEL PRODUCTO: %d \nCANTIDAD VENDIDA: %d \n __________________\n", arrayPublicacionesProductos[i].idProducto, arrayPublicacionesProductos[i].nombreProducto, arrayPublicacionesProductos[i].precioProducto, arrayPublicacionesProductos[i].stockProducto,arrayPublicacionesProductos[i].cantidadVendidaProducto);
			}
		}
	}
}


int prod_cancelarPublicacion(EPublicacionProducto* arrayPublicacionesProductos,int len)
{
	char bIdUsuario[51];
    int retorno=-1;
	char bIdProducto[51];
	int i;
    if(val_getInt(bIdUsuario, "Ingrese ID del usuario:","INCORRECTO",2,32)==0)
    {
		prod_listaPublicacionesPorIdUsuario(arrayPublicacionesProductos,len,atoi(bIdUsuario));
		if(val_getInt(bIdProducto,"Ingrese ID del procuto a borrar:  ","INCORRECTO",2,32)==0)
		{
			if(atoi(bIdProducto)!=-1)
			{
				for(i=0;i<len;i++)
				{
					if(arrayPublicacionesProductos[i].idProducto==atoi(bIdProducto))
					{
						arrayPublicacionesProductos[i].estadoProducto=ESTADO_PRODUCTO_LIBRE;
						retorno=0;
					}
				}
			}

		}

    }
    return retorno;
}

int prod_comprarProducto(EPublicacionProducto* arrayPublicacionesProductos, int len)
{
    int retorno=-1;
    int i;
    char bIdProducto[51];
    char bCalificacion[51];

    if(arrayPublicacionesProductos != NULL && len>0)
    {
        if(val_getInt(bIdProducto,"INGRESE EL ID DEL PRODUCTO A COMPRAR:  ", "ERROR ", 3, 51)==0)
        {
            for(i=0;i<len;i++)
            {
                if(arrayPublicacionesProductos[i].idProducto==atoi(bIdProducto))
                {
                    if(arrayPublicacionesProductos[i].stockProducto>0)
                    {
                        arrayPublicacionesProductos[i].stockProducto=arrayPublicacionesProductos[i].stockProducto-1;
                        val_getInt(bCalificacion,"LA COMPRA DE SE HA REALIZADO EXITOSAMENTE, CALIFIQUE A SU VENDEDOR: (1 a 5)\n","ERROR",3,51);
                        arrayPublicacionesProductos[i].calificacionDada=atoi(bCalificacion);
                        arrayPublicacionesProductos[i].cantidadVendidaProducto++;
                        arrayPublicacionesProductos[i].estadoProducto=ESTADO_PRODUCTO_VENDIDO;
                        retorno=0;
                    }
                }
            }
        }
    }

    return retorno;

}
