#ifndef _VALIDAR
#define _VALIDAR

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);
int val_validarFloat(char* buffer);
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);
int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_getInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarInt(char* buffer);
void myFgets(char* buffer, int limite ,FILE* archivo);
int val_validarDescripcion(char* buffer);
int val_getLink(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
#endif
