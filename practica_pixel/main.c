#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

int main()
{
    pixel* pPixel;
    pixel pixelGuardado;
    pPixel=pixel_newPixel(15);
    //ME DEVUELVE LA DIRECCION AL ARRAY, OSEA, EL PUNTERO AL PRIMER ELEMENTO

    if(pPixel==NULL)
    {
        printf("ERROR\n");
    }
    //LE PASO EL PUNTERO A PIXEL, Y EN EL INDICE LE GUARDO ESOS VALORES A CADA MIEMBRO DE LA ESTRUC
    if(pixel_setRGB(pPixel,10,1,2,3)!=-1)
    {
        pixelGuardado=pixel_getPixel(pPixel,10); //ME PASA LA ESTUCTURA DE PIXEL EN ESE INDICE
        printf("R %d - G %d - B %d \n", pixelGuardado.R, pixelGuardado.G, pixelGuardado.B);
    }//PORQUE ES UN PIXEL, NO UN PUNTERO A PIXEL

    //pixel_deletePixel(pPixel)

    return 0;
}
