#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int pasarStringAEntero(char datoAPasar[])
{
    int datoPasado;
    int retorno=-1;
    datoPasado=atoi(datoAPasar);
    retorno=datoPasado;
    return retorno;

}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int tomarNombre(char nombre[], int cantidadMaxima)
{
    int retorno=-1;
    printf("INGRESE EL NOMBRE\n");
    fflush(stdin);
    fgets(nombre, cantidadMaxima, stdin);
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int tomarEdad(char edad[], int cantidadMaxima)
{
    int retorno=-1;
    int edadPasada;

    printf("INGRESE  LA EDAD\n");
    fflush(stdin);
    fgets(edad, cantidadMaxima, stdin);
    edadPasada=pasarStringAEntero(edad);
    printf("%d\n", edadPasada);
    return retorno;
}
