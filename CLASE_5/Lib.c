#include "Lib.h"
#include <stdio.h>
#include <stdlib.h>
#define Null 0

/** \brief CARGA ARRAY ESTADO
 *
 * \param
 * \param
 * \return
 *
 */

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

/** \brief OBTIENE DATOS DEL USUARIO
 *
 * \param
 * \param
 * \return
 *
 */

int obtenerDatos (int edad[], float salario[], int estado[], int qtyMaxima)
{
    int i;
    int retorno=-1;
    float aux;
    char opcion='s';

    int espacioDisponible;
    while(opcion=='s')
    {
        for(i=0;i<qtyMaxima;i++)
        {
            if(estado[i]==-1)
            {
                espacioDisponible=i;
                break;
            }
        }
        estado[espacioDisponible]=0;
        printf("\nIngrese edad persona [%d]: ", espacioDisponible+1);
        fflush(stdin);
        scanf("%d", &edad[espacioDisponible]);

        printf("\nIngrese salario persona [%d]: ", espacioDisponible+1);
        fflush(stdin);
        scanf("%f", &aux);

        salario[espacioDisponible]=aux;

        retorno=0;
        printf("DESEA SEGUIR INGRESANDO DATOS? S o N\n");
        fflush(stdin);
        scanf("%c", &opcion);
        printf("%c", opcion);

    }
    return retorno;
}

/** \brief MUESTRA DATOS CARGADOS
 *
 * \param
 * \param
 * \return
 *
 */

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

/** \brief CALCULA PROMEDIO DE LA EDAD
 *
 * \param
 * \param
 * \return
 *
 */

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

/** \brief CALCULA SALARIO MAXIMO
 *
 * \param
 * \param
 * \return
 *
 */

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
            if(estado[i]!=-1)
            {
                if(salario[i]>salario[iMaximo])
                {
                    iMaximo = i;
                }
            }

        }
        retorno = iMaximo;
    }
    return retorno;
}
