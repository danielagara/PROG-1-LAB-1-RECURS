#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "pantalla.h"
#include "validar.h"
#include <string.h>

/** \brief pant_printPorIdPantalla printea los elementos de una pantalla, filtrando por idPantalla
 *
 * \param arrayPantallas el array donde se buscara el idPantalla, y se imprimira
 * \param longitud lo que mide
 * \param idPantalla dato que determina que pantalla se va a imprimir
 * \return -1 en caso de error, 0 en caso de ejecucion exitosa
 *
 */

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

/** \brief listaPantallasCliente busca al cliente, y llama a pant_printPorIdPantalla para imprimir todas las pantallas que este utiliza
 *
 * \param arrayContrataciones el array que contiene los datos del cliente donde se buscara de a uno estos mismos
 * \param longitudContrataciones lo que mide el array de contrataciones
 * \param arrayPantallas el array de pantallas que contiene los datos a imprimir
 * \param longitudPantallas lo que mide el array de pantallas
 * \return
 *
 */

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
