#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED
#define ASOCIADO_LIBRE 0
#define ASOCIADO_OCUPADO 1
#define ASOCIADO_INHABILITADO -1

typedef struct
{
    char nombre[51];
    char apellido[51];
    int edad;
    char DNI[11];
    int ID_Asociado;
    int flagEspacio;
}sAsociado;

#endif // ASOCIADO_H_INCLUDED

int asoc_initFlags(sAsociado* arrayAsociado, int longitudAsociado);
int asoc_buscarAsociadoLibre(sAsociado* arrayAsociado, int longitud);
static int asoc_buscaIdLibre(sAsociado* arrayAsociado, int longitud);
int asoc_buscaIndice(sAsociado* arrayAsociado,int id, int longitud);
int asoc_cargarAsociado(sAsociado* arrayAsociado, int index,int longitud);

