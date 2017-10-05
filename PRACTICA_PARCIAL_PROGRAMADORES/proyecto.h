#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED
typedef struct
{
    int idProyecto;
    int idProgramador;
    int horasAtrabajar;
    char nombreDelProyecto[51];
    int flagDeEstado;
}EProyecto;

int proye_asignaProgramadorAProyecto(EProyecto* arrayProyectos, int index, int len, int idProgramador);
int proye_buscarIndiceProyecctoLibre(EProyecto* arrayProyectos, int len);
int proye_initProyectos (EProyecto* arrayProyectos, int len);
void proye_proyectoMasDemandante(EProyecto* arrayProyectos, int len);
int proye_cuentaProyectos(EProyecto* arrayProyectos, int len, int idProyecto);
void proye_imprimeProyectoPorPogramador(EProyecto* arrayProyectos, int len, int idProgramador);

#endif // PROYECTO_H_INCLUDED
#define ESTADO_PROYECTO_LIBRE 0
#define ESTADO_PROYECTO_OCUPADO 1
