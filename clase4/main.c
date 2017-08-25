#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"
#include "Consola.h"

int main()
{
    int flagX=-1;
    int flagY=-1;
    float rSuma;
    float rResta;
    float rMulti;
    float rDivision;
    float y;
    float x;
    if((TomaNumero("Ingrese un numero\n","ERROR: El numero no esta dentro del rango\n", &x, 100.000, -100.000))==-1)
    {
    }
    else
    {
        flagX=0;
        if((TomaNumero("Ingrese un numero\n","ERROR: El numero no esta dentro del rango\n", &y, 100.000, -100.000))==-1)
        {
        }
        else
        {
            flagY=0;
        }
    }

    if(flagX!=-1 && flagY!=-1 )
    {
        calculadora2(&rDivision,x,y,DIVISION);
        printf("\n\n\nLa division es : %.2f",rDivision);

        calculadora2(&rSuma,x,y,SUMA);
        printf("\nLa suma es : %.2f",rSuma);

        calculadora2(&rResta, x, y, RESTA);
        printf("\nLa resta es: %.2f",rResta);

        calculadora2(&rMulti, x, y, MULTIPLICACION);
        printf("\nLa multiplicacion es %.2f", rMulti);

    }

    return 0;
}
