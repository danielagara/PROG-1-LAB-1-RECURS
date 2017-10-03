#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "producto.h"
#include "validar.h"
#include "informes.h"

#define TAM_USUARIOS 100
#define TAM_PUBLICACIONES_PRODUCTOS 1000
int main()
{
    EUsuario arrayUsuarios[TAM_USUARIOS];
    usu_initUsuario(arrayUsuarios,TAM_USUARIOS);

    EPublicacionProducto arrayPublicacionesProductos[TAM_PUBLICACIONES_PRODUCTOS];
    prod_initProductos(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS);

   char bufferInt[40];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DE USUARIO\n2-MODIFICAR DATOS USUARIO\n3-BAJA DE USUARIO\n4-PUBLICAR PRODUCTO\n5-MODIFICAR PRODUCTO\n6-CANCELAR PRODUCTO\n7-COMPRAR PRODUCTO\n8-PUBLICACIONES POR USUARIO\n9-TODAS LAS PUBLICACIONES\n10-USUARIOS Y PROMEDIO CALIFICACIONES\n11-SALIR\n","\nSolo de 1 a 6\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                usu_cargarUsuario(arrayUsuarios,usu_buscarIndiceUsuarioLibre(arrayUsuarios,TAM_USUARIOS),TAM_USUARIOS);
                break;
            case 2:
                usu_editarUsuario(arrayUsuarios,TAM_USUARIOS);
                break;
            case 3:
                usu_bajarUsuario(arrayUsuarios,TAM_USUARIOS);
                break;
            case 4:
                prod_nuevaPublicacion(arrayPublicacionesProductos,prod_buscarIndiceProductoLibre(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS),TAM_PUBLICACIONES_PRODUCTOS,usu_pideId(arrayUsuarios,TAM_USUARIOS));
                break;
            case 5:
                prod_editarPublicacion(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS);
                break;
            case 6:
                prod_cancelarPublicacion(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS);
                break;
            case 7:
                prod_comprarProducto(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS);
                break;
            case 8:
                prod_listaPublicacionesPorIdUsuario(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS,usu_pideId(arrayUsuarios,TAM_USUARIOS));
                break;
            case 9:
                info_listaPublicaciones(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS,arrayUsuarios,TAM_USUARIOS);
                break;
            case 10:
                info_listaUsuarios(arrayPublicacionesProductos,TAM_PUBLICACIONES_PRODUCTOS,arrayUsuarios, TAM_USUARIOS);
                break;
        }

    }while( atoi(bufferInt) != 11);

    return 0;
}
