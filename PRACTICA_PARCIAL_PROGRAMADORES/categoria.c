#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "categoria.h"

int cat_initCategoria(ECategoria* arrayCategorias, int len)
{
    int retorno = -1;
    int i;
    if(arrayCategorias != NULL && len > 0)
    {
        arrayCategorias[0].idCategoria=CATEGORIA_JUNIOR;
        strncpy(arrayCategorias[0].descripcionCategoria,"JUNIOR",51);
        arrayCategorias[0].pagoXhora=100;

        arrayCategorias[1].idCategoria=CATEGORIA_SEMISENIOR;
        strncpy(arrayCategorias[1].descripcionCategoria,"SEMISENIOR",51);
        arrayCategorias[1].pagoXhora=200;

        arrayCategorias[2].idCategoria=CATEGORIA_SENIOR;
        strncpy(arrayCategorias[2].descripcionCategoria,"SENIOR",51);
        arrayCategorias[2].pagoXhora=300;

        retorno=0;
    }
    return retorno;
}

void cat_imprimeDescripcionCategoria(ECategoria* arrayCategorias, int len, int idCategoria)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(idCategoria==arrayCategorias[i].idCategoria)
        {
            printf("%s",arrayCategorias[i].descripcionCategoria);
        }
    }
}
