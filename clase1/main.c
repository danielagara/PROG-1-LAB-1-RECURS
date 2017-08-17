#include <stdio.h>
#include <stdlib.h>

#define NUM_ITERACION 10

int main()
{
    int numerosUsuario;
    int contadorNegativos=0;
    int cantidadPositivos;
    float acumuladorPositivos=0;
    float acumuladorNegativos=0;
    float promedioPositivos;
    float promedioNegativos;
    //int contadorPositivos=0;
    int i;

    for(i=0;i<NUM_ITERACION;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &numerosUsuario);
        if(numerosUsuario<0)
        {
            contadorNegativos++;
            acumuladorNegativos=acumuladorNegativos+numerosUsuario;
        }
        else
        {
            acumuladorPositivos=acumuladorPositivos+numerosUsuario;
        }

        /*else if(numerosUsuario>=0)
        {
            contadorPositivos++;
        }*/
    }
    cantidadPositivos=NUM_ITERACION-contadorNegativos;
    if(contadorNegativos!=0)
    {
        promedioNegativos=acumuladorNegativos/contadorNegativos;
    }
    if(cantidadPositivos!=0)
    {
        promedioPositivos=acumuladorPositivos/cantidadPositivos;
    }

    printf("La cantidad de numeros positivos es: %d y la de negativos es: %d\n", cantidadPositivos, contadorNegativos);
    if(promedioNegativos!=0 && promedioPositivos!=0)
    {
        printf("El promedio de los numeros positivos ingresados es %.2f y el de los numeros negativos es %.2f", promedioPositivos, promedioNegativos);
    }

    return 0;
}
