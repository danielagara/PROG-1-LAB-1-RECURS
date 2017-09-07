#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANTIDAD_USUARIOS 5
int main()
{
    char nombre[CANTIDAD_USUARIOS][51];
    char edad[CANTIDAD_USUARIOS][54545];
    int i;

    for(i=0;i<CANTIDAD_USUARIOS;i++)
    {
        strncpy(nombre,tomarNombre(*nombre,51), 51);
        strncpy(edad,tomarEdad(edad,54545), 51);
    }




    return 0;
}
