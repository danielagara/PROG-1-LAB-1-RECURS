#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED

typedef struct
{
    int idContratacion;
    int idPantalla;
    char cuitCliente[51];
    int diasQueDuraPublicacion;
    char nombreArchivoDelVideo[100];
    int flagDeEstado;
}EContratacion;

int cont_nuevaContratacion(EContratacion* arrayContrataciones, int index, int len, int idPantalla);
int cont_buscarIndiceContratacionLibre(EContratacion* arrayContrataciones, int longitud);
int cont_initProductos(EContratacion* arrayContrataciones, int longitud);
int cont_editarContratacion(EContratacion* arrayContrataciones,int len);
char cont_pideCUIT(EContratacion* arrayContrataciones,int len);
int cont_cancelarContratacion(EContratacion* arrayContrataciones,int len);
int cont_cuentaContrataciones(EContratacion* arrayContrataciones, int len, char* CUITCliente);
void cont_buscaCuitsDiferentes(EContratacion* arrayContrataciones, int lenContrataciones, int* arrayIndicesCUITS);

#endif // CONTRATACION_H_INCLUDED
#define ESTADO_CONTRATACION_LIBRE 0
#define ESTADO_CONTRATACION_OCUPADA 1
