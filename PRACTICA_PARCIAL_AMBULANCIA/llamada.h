#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
	int id_llamada;
	int id_asociado;
	int estadoLlamada;
	int motivoLlamada;
	int id_ambulancia;
	int tiempoInsumido;
}ELlamadas;

#endif // LLAMADA_H_INCLUDED

#define ESTADO_LLAMADA_LIBRE -1
#define ESTADO_LLAMADA_PENDIENTE 0
#define ESTADO_LLAMADA_CUMPLIDO 1

#define MOTIVO_LLAMADA_ACV 1
#define MOTIVO_LLAMADA_INFARTO 2
#define MOTIVO_LLAMADA_GRIPE 3

int llama_nuevaLlamada(ELlamadas* arrayLlamadas, int index, int len, int id_asociado);
int llama_buscarIndiceLlamadaLibre (ELlamadas* arrayLlamadas, int longitud);
int llama_initLlamadas (ELlamadas* arrayLlamadas, int longitud);
int llama_asignaAmbualncia(ELlamadas* arrayLlamadas, int len);
void llama_motivoMasRecurrente(ELlamadas* arrayLlamadas, int len);
int llama_cuentaLlamadas(ELlamadas* arrayLlamadas, int len, int id_asociado);
int llama_cuentaMotivos(ELlamadas* arrayLlamadas, int len, int motivo);
float llama_sacaPromedioTiempoMotivos(ELlamadas* arrayLlamadas, int len, int motivo);
void llama_motivoConMayorTiempoPromedio(ELlamadas* arrayLlamadas, int len);
int llama_asociadoTieneLlamadaEnCurso(ELlamadas* arrayLlamadas, int len, int idAsociado);
