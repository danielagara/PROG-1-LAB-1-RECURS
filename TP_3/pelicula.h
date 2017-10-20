#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
typedef struct{
    char titulo[51];
    char genero[51];
    int duracion;
    char descripcion[51];
    int puntaje;
    char linkImagen[51];
    int flagDeEstado;
    int idPelicula;
}EPelicula;

int peli_bajarPelicula(EPelicula* arrayPeliculas,int longitud);
int peli_buscarIndicePeliculaLibre (EPelicula* arrayPeliculas, int longitud);
int peli_initPelicula(EPelicula* arrayPeliculas, int longitud);
int peli_cargarPelicula(EPelicula* arrayPeliculas, int index, int longitud);
int peli_editarPelicula(EPelicula* arrayPeliculas,int longitud);
int peli_escribeArchivo(EPelicula* arrayPeliculas, int longitudPeliculas);
int peli_archivoHTMLarriba(void);
int peli_archivoHTMLabajo(void);
#endif // PELICULA_H_INCLUDED

#define ESTADO_PELICULA_LIBRE 0
#define ESTADO_PELICULA_OCUPADA 1
