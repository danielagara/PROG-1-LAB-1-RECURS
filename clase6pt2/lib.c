#include "lib.h"
int ordenaArray (int a[], int qtymaxima)
{
    int aux;
    int i, flagCambioAlgo;
    do{
        flagCambioAlgo=0;
        for(i=0;i<qtymaxima-1;i++)
        {
            if(a[i]>a[i+1])
            {
                flagCambioAlgo=1;
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
            }
        }

    }while(flagCambioAlgo);
}
