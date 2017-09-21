#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED
#define LLAMADA_LIBRE 0
#define LLAMADA_OCUPADA 1
#define LLAMADA_PENDIENTE 2
#define LLAMADA_CUMPLIDA 3
typedef struct
{
    int ID_Llamada;
    int ID_Asociado;
    int motivo;
    int ID_Ambulancia;
    int tiempoInsumido;
    int estadoLlamada;
    int flagEspacio;
}sLlamada;

#endif // LLAMADA_H_INCLUDED
