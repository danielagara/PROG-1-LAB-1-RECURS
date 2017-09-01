#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int imprimePorCaracter(char cadena[])
{
    int retorno=-1;
    int i=0;
/*
        while(cadena[i]!=0)
        {
            printf("%c", &cadena[i]);
            retorno=0;
            i++;
        }*/

    //FORMA PROFE
    int flagEncontroFinal=0;
    while(flagEncontroFinal==0)
    {
        char c=cadena[i];
        if(c!=0)
        {
            printf("%c", c);
        }
        else
        {
            flagEncontroFinal=-1;
        }
        i++;
    }

    return retorno;
}
