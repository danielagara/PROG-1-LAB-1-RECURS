#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"
//static pixel arrayPixel[1024];


pixel* pixel_getRGB(pixel* pPixel, int index)
{
    return pPixel+index;
}

int pixel_setRGB(pixel* pPixel, int index, int R, int G, int B)
{
    int retorno=-1;
    if(pPixel!=NULL && index>=0)
    {
        (pPixel+index)->R=R;
        (pPixel+index)->G=G;
        (pPixel+index)->B=B;
        retorno = 0;
    }
    return retorno;
}

pixel* pixel_newPixel(int qty)
{
    pixel* arrayPixel = NULL;
    arrayPixel=malloc(sizeof(pixel)*qty);
    return arrayPixel;//devuelve el puntero al array que tengo como static
}

pixel pixel_getPixel(pixel* pPixel, int index)
{
    return *(pPixel+index); // //el CONTENIDO del item en arrayPixel, es decir la estructura completa
}

void pixel_deletePixel(pixel* pPixel)
{
    if(pPixel!=NULL)
    {
        free(pPixel);
    }
}

pixel* pixel_resize(pixel* pPixel, int newQty)
{
    pixel* pAuxPixel;
    if(pPixel != NULL)
    {
        pAuxPixel=realloc(pPixel,newQty);
        if(pAuxPixel==NULL)//parte mia
        {
            printf("NO HAY MAS LUGAR");
            return pAuxPixel;
        }
        else
        {
            printf("HAY LUGAR\n");
            return pAuxPixel;
        }
    }
}
