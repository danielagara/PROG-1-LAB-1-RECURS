#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#define TAM_NOMBRE 51
#define TAM_APELLIDO 51
#define DEBUG 1
typedef struct
{
    char nombre[TAM_NOMBRE];
    char apellido[TAM_APELLIDO];
    int idSector;
}Empleado;


#endif // EMPLEADO_H_INCLUDED

Empleado* empleado_new(void);//genera un nuevo empleado, devuelve el puntero a ese Empleado
Empleado* empleado_newConstructor(char* nombre, char* apellido, int idSector);
void empleado_delete(Empleado* pEmpleado);//recibe el puntero al empleado y lo borra
int empleado_setNombre(Empleado* pEmpleado, char* nombre);//guarda el nombre en la estructura
char* empleado_getNombre(Empleado* pEmpleado);//devuelve el puntero al char que va a ser el nombre
int empleado_setApellido(Empleado* pEmpleado, char* apellido);//guarda el apellido en la estructura
char* empleado_getApellido(Empleado* pEmpleado);//devuelve el puntero al char que va a ser el apellido
int empleado_setIdSector(Empleado* pEmpleado, int idSector);
int empleado_getIdSector(Empleado* pEmpleado);//devuelver el valor en si, solo devuelve puntero en el caso de array de char
void empleado_debugShow(Empleado* pEmpleado);
