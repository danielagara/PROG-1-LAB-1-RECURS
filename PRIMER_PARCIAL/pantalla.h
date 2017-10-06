#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int idPantalla;
    int tipoPantalla;
    int flagDeEstado;
    char nombrePantalla[51];
    char direccionPantalla[51];
    float precioPublicacionXdia;
}EPantalla;

int pant_editarPantalla(EPantalla* arrayPantallas,int len);
int pant_cargarPantalla(EPantalla* arrayPantallas, int index, int len);
int pant_initPantalla(EPantalla* arrayPantallas, int longitud);
int pant_printPantalla(EPantalla* arrayPantallas, int longitud);
int pant_buscarIndicePantallaLibre (EPantalla* arrayPantallas, int longitud);
int pant_bajarPantalla(EPantalla* arrayPantallas,int len);
int pant_pideId(EPantalla* arrayPantallas,int len);

#endif // PANTALLA_H_INCLUDED
#define TIPO_PANTALLA_LCD 1
#define TIPO_PANTALLA_LED 2

#define ESTADO_PANTALLA_LIBRE 0
#define ESTADO_PANTALLA_OCUPADA 1
