#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "pantalla.h"
#include "validar.h"
#include <string.h>

/** \brief listaPantallasCliente busca al cliente, y llama a pant_printPorIdPantalla para imprimir todas las pantallas que este utiliza
 *
 * \param arrayContrataciones el array que contiene los datos del cliente donde se buscara de a uno estos mismos
 * \param longitudContrataciones lo que mide el array de contrataciones
 * \param arrayPantallas el array de pantallas que contiene los datos a imprimir
 * \param longitudPantallas lo que mide el array de pantallas
 * \return
 *
 */

void comp_listaPantallasCliente(EContratacion* arrayContrataciones, int longitudContrataciones,EPantalla* arrayPantallas, int longitudPantallas)
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

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int comp_consultaFacturacion(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas)
{
    int retorno=-1;
    int i;
    float AUXPrecioPublicacionXdia;
    float facturacionTotal;
    char bCuitCliente[51];
    if(val_getInt(bCuitCliente,"\nINGRESE SU CUIT\t","\nError:\n",3,51)==0)
    {
		for(i=0;i<lenContrataciones;i++)
		{
			if(stricmp(bCuitCliente,arrayContrataciones[i].cuitCliente)==0 && arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
			{
				AUXPrecioPublicacionXdia=pant_devuelvePrecioPublicacion(arrayPantallas,lenPantallas,arrayContrataciones[i].idPantalla);
				if(AUXPrecioPublicacionXdia!=-1)
                {
                    facturacionTotal=arrayContrataciones[i].diasQueDuraPublicacion*AUXPrecioPublicacionXdia;
                    printf("LA FACTURACION TOTAL POR LA PANTALLA %d ES DE %.2f\n", arrayContrataciones[i].idPantalla, facturacionTotal);
                    retorno=0;
                }

			}
		}

	}

	return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void comp_listaContrataciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas)
{
    int i;

    if(arrayContrataciones != NULL && lenContrataciones > 0 && arrayPantallas != NULL && lenPantallas > 0)
    {
        for(i=0;i<lenContrataciones;i++)
        {
            if(arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
            {
                pant_printNombrePantalla(arrayPantallas,lenPantallas,arrayContrataciones[i].idPantalla);
                printf("CUIT DEL CLIENTE: %s\nNOMBRE DEL ARCHIVO DE VIDEO: %s\nCANTIDAD DE DIAS QUE DURA LA PUBLICACION: %d\n", arrayContrataciones[i].cuitCliente, arrayContrataciones[i].nombreArchivoDelVideo, arrayContrataciones[i].diasQueDuraPublicacion);
            }
        }

    }
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int comp_listaInfoClientes(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas)
{
    int retorno=-1;
    int i;
    float AUXPrecioPublicacionXdia;
    float facturacionTotal;
    int cantidadContrataciones=0;


    if(arrayContrataciones != NULL && lenContrataciones > 0 && arrayPantallas != NULL && lenPantallas > 0)
    {
            for(i=0;i<lenContrataciones;i++)
            {
                if(arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
                {
                    cantidadContrataciones=cont_cuentaContrataciones(arrayContrataciones,lenContrataciones,arrayContrataciones[i].cuitCliente);
                    printf("CANTIDAD DE CONTRATACIONES: %d\n", cantidadContrataciones);
                    AUXPrecioPublicacionXdia=pant_devuelvePrecioPublicacion(arrayPantallas,lenPantallas,arrayContrataciones[i].idPantalla);
                    if(AUXPrecioPublicacionXdia!=-1)
                    {
                        facturacionTotal=arrayContrataciones[i].diasQueDuraPublicacion*AUXPrecioPublicacionXdia;
                        printf("LA FACTURACION TOTAL POR LA PANTALLA %d ES DE %.2f\n", arrayContrataciones[i].idPantalla, facturacionTotal);
                        retorno=0;
                    }
                }

            }
    }

    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float comp_sumaFacturaciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas, char* CUIT)
{
    float retorno=-1;
    int i;
    float AUXPrecioPublicacionXdia;
    float facturacion=0;
    float facturacionTotal=0;

    for(i=0;i<lenContrataciones;i++)
    {
        if(stricmp(CUIT,arrayContrataciones[i].cuitCliente)==0 && arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
        {
            AUXPrecioPublicacionXdia=pant_devuelvePrecioPublicacion(arrayPantallas,lenPantallas,arrayContrataciones[i].idPantalla);
            if(AUXPrecioPublicacionXdia!=-1)
            {
                facturacion=arrayContrataciones[i].diasQueDuraPublicacion*AUXPrecioPublicacionXdia;
                facturacionTotal=facturacionTotal+facturacion;
                retorno=facturacionTotal;
            }
        }
    }

    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int comp_clienteMaxFacturacion(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas)
{
    int i;
    float maxFacturacion=0;
    char CUITClienteMAX[51];
    float cantidadAUX=0;
    char bCuitCliente[51];

        for(i=0;i<lenContrataciones;i++)
        {
            if(arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
            {
                cantidadAUX=comp_sumaFacturaciones(arrayContrataciones, lenContrataciones,arrayPantallas,lenPantallas,arrayContrataciones[i].cuitCliente);
                if(cantidadAUX>maxFacturacion)
                {
                    maxFacturacion=cantidadAUX;
                    strncpy(CUITClienteMAX,arrayContrataciones[i].cuitCliente,51);
                }
            }
        }


    printf("EL CLIENTE CON MAYOR FACTURACION ES %s, Y EL IMPORTE ES DE : $ %.2f  \n", CUITClienteMAX, maxFacturacion);

    return 0;
}

