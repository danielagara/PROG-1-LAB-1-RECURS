#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char DNI[20];
    int flagDeEstado;
}ECliente;

#endif // CLIENTE_H_INCLUDED
int cli_editarCliente(ECliente* arrayClientes,int len);
int cli_cargarCliente(ECliente* arrayClientes, int index, int len);
int cli_initCliente (ECliente* arrayClientes, int longitud);
int cli_printCliente(ECliente* arrayClientes, int longitud);
int cli_buscarIndiceClienteLibre (ECliente* arrayClientes, int longitud);
int cli_bajarCliente(ECliente* arrayClientes,int len);
int cli_pideId(ECliente* arrayClientes,int len);
int cli_buscaDNIrepetido(ECliente* arrayClientes, int len, char* DNI);
