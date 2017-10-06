#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "pantalla.h"
#include "validar.h"
#include <string.h>

int pant_printPorIdPantalla(EPantalla* arrayPantallas, int longitud, int idPantalla)
{
    int retorno = -1;
    int i;
	char auxTipoPantalla[51];
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA && idPantalla == arrayPantallas[i].idPantalla)
            {
				if(arrayPantallas[i].tipoPantalla==1)
				{
					strncpy(auxTipoPantalla,"LCD",51);
				}
				else
				{
					strncpy(auxTipoPantalla,"LED",51);
				}

                printf("ID: %d - NOMBRE DE LA PANTALLA: %s - DIRECCION DE LA PANTALLA: %s - TIPO DE LA PANTALLA: %s - PRECIO DE LA PUBLICACION POR DIA: %.2f \n",arrayPantallas[i].idPantalla,arrayPantallas[i].nombrePantalla,arrayPantallas[i].direccionPantalla,auxTipoPantalla, arrayPantallas[i].precioPublicacionXdia);
            }
        }

    }
    return retorno;
}

void listaPantallasCliente(EContratacion* arrayContrataciones, int longitudContrataciones,EPantalla* arrayPantallas, int longitudPantallas)
{
    char bCuitCliente[51];
    int j;
	if(val_getInt(bCuitCliente,"\nINGRESE SU CUIT\t","\nError:\n",3,51)==0)
    {
		for(j=0;j<longitudContrataciones;j++)
		{
			if(stricmp(bCuitCliente,arrayContrataciones[j].cuitCliente)==0 && arrayContrataciones[j].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
			{
				pant_printPorIdPantalla(arrayPantallas,longitudPantallas,arrayContrataciones[j].idPantalla);
			}
		}

	}
}


/*
void listaContrataciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas)
{
    int i;
    for(i=0;i<lenContrataciones;i++)
    {
        for(j=0;j<lenContrataciones;j++)

    }
}
*/
