#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED
typedef struct
{
    int idCategoria;
    char descripcionCategoria[51];
    float pagoXhora;
}ECategoria;

int cat_initCategoria(ECategoria* arrayCategorias, int len);
void cat_imprimeDescripcionCategoria(ECategoria* arrayCategorias, int len, int idCategoria);
#endif // CATEGORIA_H_INCLUDED
#define CATEGORIA_JUNIOR 0
#define CATEGORIA_SEMISENIOR 1
#define CATEGORIA_SENIOR 2
