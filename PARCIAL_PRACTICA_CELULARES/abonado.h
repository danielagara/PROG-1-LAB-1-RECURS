#ifndef ABONADO_H_INCLUDED
#define ABONADO_H_INCLUDED

typedef struct
{
    int idAbonado;
    char numeroTelefono[51];
    char nombre[51];
    char apellido[51];
    int flagDeEstado;
}EAbonado;


#endif // ABONADO_H_INCLUDED
int abo_editarAbonado(EAbonado* arrayAbonados,int len);
int abo_cargarAbonado(EAbonado* arrayAbonados, int index, int len);
int abo_initAbonado(EAbonado* arrayAbonados, int longitud);
int abo_printAbonado(EAbonado* arrayAbonados, int longitud);
int abo_buscarIndicEAbonadoLibre (EAbonado* arrayAbonados, int longitud);
int abo_bajarAbonado(EAbonado* arrayAbonados,int len);
int abo_pideId(EAbonado* arrayAbonados,int len);
int abo_buscaNumTelefonoRepetido(EAbonado* arrayAbonados, int len, char* numeroTelefono);
