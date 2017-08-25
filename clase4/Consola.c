#include <stdio.h>
#include <stdlib.h>
#include "Consola.h"

/** \brief TOMA NUMERO
 *
 * \param mensaje El mensaje a imprimir
 * \param numero El numero a ingresar
 * \param max El maximo del numero a ingresar
 * \param min El minimo del numero a ingresar
 * \return
 *
 */

int TomaNumero(char mensajeInicial[],char mensajeError[], float* numero, float max, float min)
{
    float auxNumero;

    printf("%s", mensajeInicial);
    scanf("%f", &auxNumero);
    if(auxNumero<min || auxNumero>max)
    {
        printf("%s", mensajeError);
        return -1;
    }
    else
    {
        *numero=auxNumero;
        return 0;
    }
}
