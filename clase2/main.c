#include <stdio.h>
#include <stdlib.h>
#define CANT_NUMEROS 5

int main()
{
    float numeroUsuario;
    float acumuladorNumeros=0;
    float maximoNumero;
    float minimoNumero;
    float promedioNumero;
    int contador=0;
    char seguir='s';

    while(seguir!='n')
    {
        printf("Ingrese el numero: \n");
        fflush(stdin);
        scanf("%f", &numeroUsuario);
        acumuladorNumeros=acumuladorNumeros+numeroUsuario;

        if(contador==0)
        {
            minimoNumero=numeroUsuario;
            maximoNumero=numeroUsuario;
        }
        else if(contador!=0)
        {
            if(numeroUsuario<minimoNumero)
            {
                minimoNumero=numeroUsuario;
            }
            if(numeroUsuario>maximoNumero)
            {
                maximoNumero=numeroUsuario;
            }
        }
        contador++;
        printf("Desea seguir?\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    promedioNumero=acumuladorNumeros/CANT_NUMEROS;
    printf("El numero maximo es %.2f \n El numero minimo es %.2f \n El promedio de los numeros es %.2f\n", maximoNumero, minimoNumero, promedioNumero);
    return 0;
}
