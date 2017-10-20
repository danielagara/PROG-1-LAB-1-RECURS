#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"
#include "validar.h"
#include <string.h>

#define TAM_BUFFER 4096
#define TAM_PELICULAS 100
int main()
{
    char bufferInt[TAM_BUFFER];

    EPelicula arrayPeliculas[TAM_PELICULAS];
    peli_initPelicula(arrayPeliculas,TAM_PELICULAS);


    do
    {
        system("cls");
        val_getUnsignedInt(bufferInt,"\n1-AGREGAR PELICULA\n2-MODIFICAR PELICULA\n3-BORRAR PELICULA\n4-CREAR PAGINA WEB\n5-SALIR\n","\nLAS OPCIONES SON DE 1 A 4\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                peli_cargarPelicula(arrayPeliculas,peli_buscarIndicePeliculaLibre(arrayPeliculas,TAM_PELICULAS),TAM_PELICULAS);
                peli_escribeArchivo(arrayPeliculas,TAM_PELICULAS);
                break;
            case 2:
                peli_editarPelicula(arrayPeliculas,TAM_PELICULAS);
                peli_escribeArchivo(arrayPeliculas,TAM_PELICULAS);
                break;
            case 3:
                peli_bajarPelicula(arrayPeliculas,TAM_PELICULAS);
                peli_escribeArchivo(arrayPeliculas,TAM_PELICULAS);
                break;
            case 4:
                peli_generaPaginaWeb(arrayPeliculas,TAM_PELICULAS);
                break;
        }
        printf("\n");
		system("pause");

    }while( atoi(bufferInt) != 5);

    return 0;
}
