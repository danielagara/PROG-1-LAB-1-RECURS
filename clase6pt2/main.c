#include <stdio.h>
#include <stdlib.h>
#define CANT_ELEMENTOS 5
#include "lib.h"

int main()//ALCORITMO DE ORDENAMIENTO MEJORADO 2.0
{
    int a[CANT_ELEMENTOS]={1,2,5,7,8};
    int i;

    ordenaArray (a,CANT_ELEMENTOS);

    for(i=0;i<CANT_ELEMENTOS;i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}
