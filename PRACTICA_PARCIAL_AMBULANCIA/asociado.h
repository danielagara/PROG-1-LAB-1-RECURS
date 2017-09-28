#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

#define ESTADO_ASOCIADO_LIBRE 0
#define ESTADO_ASOCIADO_OCUPADO 1

typedef struct
{
	int id_asociado;
	char DNI[20];
	char nombre[51];
	char apellido[51];
	int edad;
	int flagDeEstado;
}EAsociado;

#endif // ASOCIADO_H_INCLUDED


int asoc_editarAsociado (EAsociado* arrayAsociados, int len);
int asoc_cargarAsociado (EAsociado* arrayAsociados, int index, int len);
int asoc_printAsociado (EAsociado* arrayAsociados, int longitud);
int asoc_initAsociado (EAsociado* arrayAsociados, int longitud);
int asoc_buscarIndiceAsociadoLibre (EAsociado* arrayAsociados, int longitud);
int asoc_editarAsociado(EAsociado* arrayAsociados,int len);
int asoc_bajarAsociado(EAsociado* arrayAsociados,int len);
int asoc_pideId(EAsociado* arrayAsociados,int len);
