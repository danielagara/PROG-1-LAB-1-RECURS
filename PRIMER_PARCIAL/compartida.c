#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "pantalla.h"
#include "validar.h"
#include <string.h>

/** \brief comp_listaPantallasCliente busca al cliente, y llama a pant_printPorIdPantalla para imprimir todas las pantallas que este utiliza
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

/** \brief comp_consultaFacturacion pide al usuario que ingrese el cuit, y calcula la facturacion de cada contratacion que este tiene
 *
 * \param arrayContrataciones el array donde se encontraran las contrataciones y datos del cliente
 * \param lenContrataciones longitud del array
 * \param arrayPantallas el array donde se buscara la informacion sobre las pantallas de cada contratacion
 * \param lenPantallas longitud del array
 * \return -1 en caso de error, 0 en caso de que sea correcto
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

/** \brief comp_listaContrataciones lista todas las contrataciones realizadas
 *
 * \param arrayContrataciones array que contiene la informacion de cada contratacion
 * \param lenContrataciones longitud del array
 * \param arrayPantallas el array donde se buscara la informacion sobre las pantallas de cada contratacion
 * \param lenPantallas longitud del array
 * \return VOID
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

 void comp_printFacturaciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas, char* CUIT)
 {
    int i;
    float AUXPrecioPublicacionXdia;
    float facturacion=0;

	if(arrayContrataciones != NULL && lenContrataciones>0 && arrayPantallas!=NULL && lenPantallas>0)
	{
		for(i=0;i<lenContrataciones;i++)
		{
			if(stricmp(CUIT,arrayContrataciones[i].cuitCliente)==0 && arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
			{
				AUXPrecioPublicacionXdia=pant_devuelvePrecioPublicacion(arrayPantallas,lenPantallas,arrayContrataciones[i].idPantalla);
				if(AUXPrecioPublicacionXdia!=-1)
				{
					facturacion=arrayContrataciones[i].diasQueDuraPublicacion*AUXPrecioPublicacionXdia;
					printf("\nLA FACTURACION DE LA CONTRATACION DE PANTALLA CON ID %d ES DE %.2f\n",arrayContrataciones[i].idPantalla, facturacion);
				}
			}
		}
	}
 }


/** \brief comp_listaInfoClientes imprime por cliente la cantidad de contrataciones y el total a pagar por cada una
 *
 * \param arrayContrataciones array que contiene la informacion de cada contratacion
 * \param lenContrataciones longitud del array
 * \param arrayPantallas el array donde se buscara la informacion sobre las pantallas de cada contratacion
 * \param lenPantallas longitud del array
 * \return -1 si hubo error, 0 si funciono todo OK
 *
 */

int comp_listaInfoClientes(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas)
{
    int retorno=-1;
    int i;

    if(arrayContrataciones != NULL && lenContrataciones > 0 && arrayPantallas != NULL && lenPantallas > 0)
    {
            for(i=0;i<lenContrataciones;i++)
            {
                if(arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
                {
                    cont_cuentaContrataciones(arrayContrataciones,lenContrataciones,arrayContrataciones[i].cuitCliente);
                    comp_printFacturaciones(arrayContrataciones,lenContrataciones,arrayPantallas,lenPantallas,arrayContrataciones[i].cuitCliente);
                }

            }
    }

    return retorno;
}

/** \brief comp_sumaFacturaciones suma todas las facturaciones que tiene un cliente de todas sus contrataciones
 *
 * \param arrayContrataciones array que contiene la informacion de cada contratacion
 * \param lenContrataciones longitud del array
 * \param arrayPantallas el array donde se buscara la informacion sobre las pantallas de cada contratacion
 * \param lenPantallas longitud del array
 * \param CUIT el cuit del cliente
 * \return -1 si hubo error, el valor de la suma si fue correcto
 *
 */

float comp_sumaFacturaciones(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas, char* CUIT)
{
    float retorno=-1;
    int i;
    float AUXPrecioPublicacionXdia;
    float facturacion=0;
    float facturacionTotal=0;
	if(arrayContrataciones != NULL && lenContrataciones>0 && arrayPantallas!=NULL && lenPantallas>0)
	{
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
	}


    return retorno;
}

/** \brief comp_clienteMaxFacturacion calcula cual es el cliente que tiene el maximo importe a pagar
 *
 * \param arrayContrataciones array que contiene la informacion de cada contratacion
 * \param lenContrataciones longitud del array
 * \param arrayPantallas el array donde se buscara la informacion sobre las pantallas de cada contratacion
 * \param lenPantallas longitud del array
 * \return -1 si fue incorrecta la ejecucion, 0 si no lo fue
 *
 */
int comp_clienteMaxFacturacion(EContratacion* arrayContrataciones, int lenContrataciones, EPantalla* arrayPantallas, int lenPantallas)
{
    int retorno=-1;
    int i;
    float maxFacturacion=0;
    char CUITClienteMAX[51];
    float cantidadAUX=0;

        for(i=0;i<lenContrataciones;i++)
        {
            if(arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
            {
                cantidadAUX=comp_sumaFacturaciones(arrayContrataciones, lenContrataciones,arrayPantallas,lenPantallas,arrayContrataciones[i].cuitCliente);
                if(cantidadAUX>maxFacturacion)
                {
                    maxFacturacion=cantidadAUX;
                    strncpy(CUITClienteMAX,arrayContrataciones[i].cuitCliente,51);
                    retorno=0;
                }
            }
        }


    printf("EL CLIENTE CON MAYOR FACTURACION ES %s, Y EL IMPORTE ES DE : $ %.2f  \n", CUITClienteMAX, maxFacturacion);

    return retorno;
}
