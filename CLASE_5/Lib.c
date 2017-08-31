#include "Lib.h"
#include <stdio.h>
#include <stdlib.h>
#define Null 0

int cargaEstado(int estado[], int qtyMaxima)
{
    int i;
    int retorno=-1;
    if(qtyMaxima>0 && estado!=Null)
    {
        retorno=0;
        for(i=0;i<qtyMaxima;i++)
        {
            estado[i]=-1;
        }
    }

    return retorno;

}

int obtenerDatos (int edad[], float salario[], int estado[], int qtyMaxima)
{
    int i;
    int retorno=-1;
    float aux;

    for(i = 0; i < qtyMaxima ; i++)
    {
        if(estado[i]==-1)
        {
            estado[i]=0;
            printf("\nIngrese edad persona [%d]: ", i+1);
            fflush(stdin);
            scanf("%d", &edad[i]);

            printf("\nIngrese salario persona [%d]: ", i+1);
            fflush(stdin);
            scanf("%f", &aux);

            salario[i]=aux;

            retorno=0;
        }
        /*else
        {
            printf("NO SE PUEDEN INGRESAR MAS EDADES DE USUARIOS\n");
        }*/
    }

    return retorno;

}

int mostrarDatos(int edad[], float salario[], int estado[], int qtyMaxima)
{
    int i;
    int retorno=-1;

    printf("\nEDAD\t\tSALARIO");
    for(i = 0; i < qtyMaxima; i++)
    {
        if(estado[i]!=-1)
        {
            printf("\n%d\t\t%.2f\n", edad[i], salario[i]);
            retorno=0;
        }
    }
    return retorno;
}

int calcularPromedio(int edad[], int estado[], int qtyMaxima, float* promedio)
{
    int i;
    int retorno = -1;
    int acumulador = 0;
    int contadorValidos=0;


    if(qtyMaxima > 0 && edad != Null && promedio != Null)
    {
        retorno = 0;
        for(i = 0; i < qtyMaxima; i++)
        {
            if(estado[i]!= -1)
            {
                acumulador = acumulador  + edad[i];
                contadorValidos++;
            }

        }
        *promedio = (float)acumulador/contadorValidos;
    }
    return retorno;
}


int calcularMaximo(float salario[], int estado[], int qtyMaxima)
{
    int i;
    int retorno=-1;
    int iMaximo;

    if(qtyMaxima > 0 && salario != Null)
    {
        iMaximo = 0;
        for(i = 1; i < qtyMaxima; i++)
        {
                if(salario[i]>salario[iMaximo])
                {
                    iMaximo = i;
                }
        }
        retorno = iMaximo;
    }
    return retorno;
}
