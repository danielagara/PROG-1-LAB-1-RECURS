#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    int idUsuario;
	char nombreProducto[51];
	float precioProducto;
	int stockProducto;
	int idProducto;
	int estadoProducto;
	int cantidadVendidaProducto;
	int calificacionDada;
}EPublicacionProducto;

#endif // PRODUCTO_H_INCLUDED
int prod_nuevaPublicacion(EPublicacionProducto* arrayPublicacionesProductos, int index, int len, int idUsuario);
int prod_buscarIndiceProductoLibre(EPublicacionProducto* arrayPublicacionesProductos, int longitud);
int prod_initProductos(EPublicacionProducto* arrayPublicacionesProductos, int longitud);
int prod_editarPublicacion(EPublicacionProducto* arrayPublicacionesProductos,int len);
void prod_listaPublicacionesPorIdUsuario(EPublicacionProducto* arrayPublicacionesProductos, int len, int idUsuario);
int prod_cancelarPublicacion(EPublicacionProducto* arrayPublicacionesProductos,int len);
int prod_comprarProducto(EPublicacionProducto* arrayPublicacionesProductos, int len);
