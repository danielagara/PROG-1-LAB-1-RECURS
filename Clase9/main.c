#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#define LIMITE_PRODUCTOS 200

int main()
{
    sProducto arrayProductos[LIMITE_PRODUCTOS];
    char seguir='s';
    char opcion;
    int index;

    while(seguir=='s')
    {
        printf("\nA- Cargar un producto\n");
        printf("B- Imprimir lista de productos\n");
        printf("C- Salir\n");

        gets(&opcion);

        switch(opcion)
        {
            case 'A':
                prod_initProducto(arrayProductos,LIMITE_PRODUCTOS);
                //prod_cargarProducto (arrayProductos, 1);
                index=prod_indexDisponible(arrayProductos,LIMITE_PRODUCTOS);
                fflush(stdin);
                prod_cargarProducto(arrayProductos, index);
				break;
			case 'B':
			    prod_printProducto(arrayProductos,LIMITE_PRODUCTOS);
				break;
            case 'C':
                seguir = 'n';
                break;
        }
    }


    return 0;
}
