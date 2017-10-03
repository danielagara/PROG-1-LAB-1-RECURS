#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "producto.h"
#include "validar.h"
#include "informes.h"

#define ESTADO_PRODUCTO_LIBRE 0
#define ESTADO_PRODUCTO_PUBLICADO 1
#define ESTADO_PRODUCTO_VENDIDO 2

#define ESTADO_USUARIO_OCUPADO 1
#define ESTADO_USUARIO_LIBRE 0

void info_listaPublicaciones(EPublicacionProducto* arrayPublicacionesProductos, int lenPublicaciones, EUsuario* arrayUsuarios, int lenUsuarios)
{
	int i;
	int j;

	if(arrayPublicacionesProductos != NULL && arrayUsuarios !=NULL && lenUsuarios>0 && lenPublicaciones>0)
	{
		for(i=0;i<lenPublicaciones;i++)
		{
		    for(j=0;j<lenUsuarios;j++)
            {
                if(arrayPublicacionesProductos[i].idUsuario==arrayUsuarios[j].idUsuario && (arrayPublicacionesProductos[i].estadoProducto==ESTADO_PRODUCTO_PUBLICADO || arrayPublicacionesProductos[i].estadoProducto==ESTADO_PRODUCTO_VENDIDO) && arrayUsuarios[j].flagDeEstado==ESTADO_USUARIO_OCUPADO)
                {
                    printf("\nID DEL PRODUCTO: %d \nNOMBRE DEL PRODUCTO: %s \nPRECIO DEL PRODUCTO: %.2f \nSTOCK DEL PRODUCTO: %d \nCANTIDAD VENDIDA: %d \nNOMBRE DEL USUARIO: %s \n __________________\n", arrayPublicacionesProductos[i].idProducto, arrayPublicacionesProductos[i].nombreProducto, arrayPublicacionesProductos[i].precioProducto, arrayPublicacionesProductos[i].stockProducto,arrayPublicacionesProductos[i].cantidadVendidaProducto, arrayUsuarios[j].nombreDeUsuario);
                }
            }

		}
	}
}

float info_sacaPromedioCalificaciones(EPublicacionProducto* arrayPublicacionesProductos, int len, int idUsuario)
{
    float retorno=-1;
    int i;
    int acumuladorCalificacion=0;
    int contadorProductosVendidos=0;

    for(i=0;i<len;i++)
    {
        if(arrayPublicacionesProductos[i].idUsuario== idUsuario && arrayPublicacionesProductos[i].estadoProducto==ESTADO_PRODUCTO_VENDIDO)
        {
            acumuladorCalificacion=acumuladorCalificacion+arrayPublicacionesProductos[i].calificacionDada;
            contadorProductosVendidos++;
        }
    }

    retorno=(float)acumuladorCalificacion/contadorProductosVendidos;
    return retorno;
}

void info_listaUsuarios(EPublicacionProducto* arrayPublicacionesProductos, int lenPublicaciones, EUsuario* arrayUsuarios, int lenUsuarios)
{
	int i;
	int j;

	if(arrayPublicacionesProductos != NULL && arrayUsuarios !=NULL && lenUsuarios>0 && lenPublicaciones>0)
	{
		for(i=0;i<lenPublicaciones;i++)
		{
		    for(j=0;j<lenUsuarios;j++)
            {
                if(arrayPublicacionesProductos[i].idUsuario==arrayUsuarios[j].idUsuario && arrayUsuarios[j].flagDeEstado==ESTADO_USUARIO_OCUPADO)
                {
                    printf("\nNOMBRE DEL USUARIO: %s \n PROMEDIO DE SUS CALIFICACIONES: %.2f \n __________________\n", arrayUsuarios[j].nombreDeUsuario, info_sacaPromedioCalificaciones(arrayPublicacionesProductos,lenPublicaciones,arrayUsuarios[j].idUsuario));
                }
            }

		}
	}
}
