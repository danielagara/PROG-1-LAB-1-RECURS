#ifndef PROGRAMADOR_H_INCLUDED
#define PROGRAMADOR_H_INCLUDED

typedef struct
{
    int idProgramador;
    char nombre[51];
    char apellido[51];
    int idCategoria;
    int pagoXhora;
    int flagDeEstado;
}EProgramador;


#endif // PROGRAMADOR_H_INCLUDED
