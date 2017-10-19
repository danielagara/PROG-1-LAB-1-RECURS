#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

ArrayList* al_new(void)
{
    ArrayList* pAl;
    pAl=malloc(sizeof(ArrayList));
    if(pAl!=NULL)
    {
        pAl->r_size=INIT_SIZE;
        pAl->size=0;
        pAl->pElements =malloc(sizeof(void*)*pAl->r_size);
    }
    return pAl;
}

int al_add (ArrayList* pArray, void* element)
{
    int retorno=-1;
    if(pArray->size < pArray->r_size)
    {
        // *(pArray->pElements+pArray->size)=element; //MAÑANA PQ PUNTERO A PUNTERO
        pArray->size++;
        retorno=0;
    }
    return retorno;
}
