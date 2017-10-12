#ifndef COMPARTIDA_H_INCLUDED
#define COMPARTIDA_H_INCLUDED

void comp_listaPantallasCliente(EContratacion* arrayContrataciones, int longitudContrataciones,EPantalla* arrayPantallas, int longitudPantallas);
int comp_consultaFacturacion(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas);
void comp_listaContrataciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas);
int comp_listaInfoClientes(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas);
float comp_sumaFacturaciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas, char* CUIT);
int comp_clienteMaxFacturacion(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas);
void comp_printFacturaciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas, char* CUIT);
#endif // COMPARTIDA_H_INCLUDED
