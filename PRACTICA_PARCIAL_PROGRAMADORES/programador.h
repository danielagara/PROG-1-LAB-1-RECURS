#ifndef PROGRAMADOR_H_INCLUDED
#define PROGRAMADOR_H_INCLUDED

typedef struct
{
    int idProgramador;
    char nombre[51];
    char apellido[51];
    int idCategoria;
    int flagDeEstado;
}EProgramador;

int prog_editarProgramador(EProgramador* arrayProgramadores,int len);
int prog_cargarProgramador(EProgramador* arrayProgramadores, int index, int len);
int prog_initProgrmador (EProgramador* arrayProgramadores, int len);
int prog_printProgramadores(EProgramador* arrayProgramadores, int len);
int prog_buscarIndiceProgramadorLibre (EProgramador* arrayProgramadores, int len);
int prog_bajarProgramador(EProgramador* arrayProgramadores,int len);
int prog_pideId(EProgramador* arrayProgramadores,int len);
void prog_printProgramador(EProgramador* arrayProgramadores, int len, int idProgramador);

#endif // PROGRAMADOR_H_INCLUDED
#define ESTADO_PROGRAMADOR_LIBRE 0
#define ESTADO_PROGRAMADOR_OCUPADO 1
