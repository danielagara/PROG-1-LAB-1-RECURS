#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



typedef struct{

    char nombre[50];
    int edad;
    int estado;
    char dni[51];

}EPersona;

int perso_obtenerEspacioLibre(EPersona* arrayPersona, int longitud);

int perso_buscarPorDni(EPersona* arrayPersona, int longitud, char* dni);

int perso_initPersona(EPersona* arrayPersona, int longitud);

int perso_cargarPersona(EPersona* arrayPersona, int index, int longitud);

int perso_printPersona(EPersona* arrayPersona, int longitud);

int perso_borrarPersona(EPersona* arrayPersona, int longitud, char* mensaje);

void perso_insertionSort(EPersona* arrayPersona, int longitud);

void perso_imprimirGrafico(EPersona* arrayPersona, int longitud);

int perso_validarEdadPersona(char* bufferEdad, char* mensajeError);

void perso_inicializaMatriz(char grafico[][3], int longitud);

#endif // FUNCIONES_H_INCLUDED
