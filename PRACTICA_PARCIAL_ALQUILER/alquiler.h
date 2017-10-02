#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct
{
    int idCliente;
    int idAlquiler;
    int tipoEquipo;
    int tiempoEstimadoAlquiler;
    int tiempoRealAlquiler;
    int estadoAlquiler;
    char operador[51];
}EAlquiler;

#endif // ALQUILER_H_INCLUDED

int alqui_nuevoAlquiler(EAlquiler* arrayAlquileres, int index, int len, int idCliente);
int alqui_buscarIndiceAlquilerLibre (EAlquiler* arrayAlquileres, int longitud);
int alqui_initAlquileres (EAlquiler* arrayAlquileres, int longitud);
int alqui_finalizaAlquiler(EAlquiler* arrayAlquileres, int len);
int alqui_cuentaAlquileres(EAlquiler* arrayAlquileres, int len, int idCliente);
void alqui_equipoMasRecurrente(EAlquiler* arrayAlquileres, int len);
int alqui_cuentaEquipos(EAlquiler* arrayAlquileres, int len, int equipo);
void alqui_equipoTiempoPromedio(EAlquiler* arrayAlquileres, int len);
float alqui_sacaPromedioTiempoEquipos(EAlquiler* arrayAlquileres, int len, int equipo);
