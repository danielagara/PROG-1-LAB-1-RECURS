#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int idAbonado;
    int idLlamada;
    int motivoLlamada;
    int estadoLlamada;
    int tiempoSolucion;
}ELlamada;

#endif // LLAMADA_H_INCLUDED

int llama_nuevaLlamada(ELlamada* arrayLlamadas, int index, int len, int idAbonado);
int llama_buscarIndiceLlamadaLibre (ELlamada* arrayLlamadas, int longitud);
int llama_initLlamadas(ELlamada* arrayLlamadas, int longitud);
int llama_finalizaLlamada(ELlamada* arrayLlamadas, int len);
int llama_cuentaLlamadas(ELlamada* arrayLlamadas, int len, int idAbonado);
void llama_motivoMasRecurrente(ELlamada* arrayLlamadas, int len);
int llama_cuentaMotivos(ELlamada* arrayLlamadas, int len, int equipo);
float llama_sacaPromedioTiempoMotivos(ELlamada* arrayLlamadas, int len, int motivo);
void llama_motivoTiempoPromedio(ELlamada* arrayLlamadas, int len);

