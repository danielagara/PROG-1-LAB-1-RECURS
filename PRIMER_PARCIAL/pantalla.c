#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "validar.h"
#include "string.h"


// Funciones privadas
static int buscarProximoId (EPantalla* arrayPantallas, int longitud);
static int buscarIndiceId (EPantalla* arrayPantallas, int longitud, int id);
static int modificarPantallaPorIndice(EPantalla* arrayPantallas, int index);
//___________________

/** \brief pant_editarPantalla pedira el id de la pantalla a modificar, y validara que exista
 *
 * \param arrayPantallas el array donde se buscara el dato
 * \param len lo que mide el array
 * \return redirige a otra funcion que modificara los datos, 0 si no se ejecuto correctamente
 *
 */

int pant_editarPantalla(EPantalla* arrayPantallas,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID de pantalla a modificar:  ","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayPantallas,len,id);
        if(index>=0)
        {
           return modificarPantallaPorIndice(arrayPantallas,index);
        }
    }
    return -1;
}

/** \brief modificarPantallaPorIndice pedira y modificara los datos de una pantalla
 *
 * \param arrayPantallas array a modificar el dato
 * \param indice donde se encuentra dentro del array el dato a modificar
 * \return -1 si se ejecuto incorrectamente, 0 si se pudo modificar
 *
 */

static int modificarPantallaPorIndice (EPantalla* arrayPantallas, int index)
{
    int retorno = -1;
    char bNombrePantalla[51];
    char bDireccionPantalla[51];
	char bPrecioPublicacionXdia[51];
	char bTipoPantalla[51];

    if(arrayPantallas != NULL && index >= 0)
    {
        if(val_getNombre(bNombrePantalla,"\nNOMBRE DE PANTALLA?\t","\nError:\n",3,51)==0)
        {
            if(val_getDescripcion(bDireccionPantalla,"\nDIRECCION DE LA PANTALLA?\t","\nError:\n",3,51)==0)
            {
				if(val_getFloat(bPrecioPublicacionXdia,"\nPRECIO DE LA PUBLICACION POR DIA EN ESTA PANTALLA?\t","\nError:\n",3,51)==0)
				{
					if(val_getInt(bTipoPantalla,"\nTIPO DE LA PANTALLA? INGRESE 1: LCD o 2:LED \t","\nError:\n",3,51)==0)
					{
						strncpy(arrayPantallas[index].nombrePantalla,bNombrePantalla,51);
						strncpy(arrayPantallas[index].direccionPantalla,bDireccionPantalla,51);
						arrayPantallas[index].precioPublicacionXdia=atof(bPrecioPublicacionXdia);
						if(atoi(bTipoPantalla)==1)
						{
							arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LCD;
						}
						if(atoi(bTipoPantalla)==2)
						{
							arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LED;
						}
						retorno = 0;
					}
				}

            }
        }

    }
    return retorno;
}

/** \brief pant_cargarPantalla pide y carga los datos de una pantalla dentro del array
 *
 * \param arrayPantallas el array donde se guardaran los datos
 * \param index el indice del array donde estaran esos datos especificamente
 * \param len lo que mide el array
 * \return -1 si no se pudo ejecutar correctamente, 0 si no hubo problemas
 *
 */

int pant_cargarPantalla(EPantalla* arrayPantallas, int index, int len)
{
    int retorno = -1;
    int id;
	char bNombrePantalla[51];
    char bDireccionPantalla[51];
	char bPrecioPublicacionXdia[51];
	char bTipoPantalla[51];

    if(arrayPantallas != NULL && index >= 0 && index < len)
    {
            if(val_getNombre(bNombrePantalla,"\nNOMBRE DE PANTALLA?\t","\nError:\n",3,51)==0)
            {
				if(val_getDescripcion(bDireccionPantalla,"\nDIRECCION DE LA PANTALLA?\t","\nError:\n",3,51)==0)
				{
					if(val_getFloat(bPrecioPublicacionXdia,"\nPRECIO DE LA PUBLICACION POR DIA EN ESTA PANTALLA?\t","\nError:\n",3,51)==0)
					{
						if(val_getInt(bTipoPantalla,"\nTIPO DE LA PANTALLA? INGRESE 1: LCD o 2:LED \t","\nError:\n",3,51)==0)
						{
							id = buscarProximoId(arrayPantallas,len);
							if(id != -1)
							{
								arrayPantallas[index].idPantalla=id;
								arrayPantallas[index].flagDeEstado=ESTADO_PANTALLA_OCUPADA;
								strncpy(arrayPantallas[index].nombrePantalla,bNombrePantalla,51);
								strncpy(arrayPantallas[index].direccionPantalla,bDireccionPantalla,51);
								arrayPantallas[index].precioPublicacionXdia=atof(bPrecioPublicacionXdia);
								if(atoi(bTipoPantalla)==1)
								{
									arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LCD;
								}
								if(atoi(bTipoPantalla)==2)
								{
									arrayPantallas[index].tipoPantalla=TIPO_PANTALLA_LED;
								}
								printf("EL ID DE LA PANTALLA ES %d\t",arrayPantallas[index].idPantalla);
							}
						}
					}

				}

            }

    }
    return retorno;
}

/** \brief pant_initPantalla inicializa todos los indices del array como disponibles a ser ocupados
 *
 * \param arrayPantallas el array a inicializar
 * \param longitud lo que mide dicho array
 * \return -1 si hubo error, 0 si no
 *
 */

int pant_initPantalla(EPantalla* arrayPantallas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPantallas[i].flagDeEstado = ESTADO_PANTALLA_LIBRE;
            retorno=0;
        }

    }
    return retorno;
}

/** \brief pant_printPantalla imprime todas las pantallas que esten habilitadas
 *
 * \param arrayPantallas el array donde se encuentran los datos de las pantallas a imprimir
 * \param longitud lo que mide el array
 * \return -1 si hubo algun error, 0 si la ejecucion fue correcta
 *
 */

int pant_printPantalla(EPantalla* arrayPantallas, int longitud)
{
    int retorno = -1;
    int i;
	char auxTipoPantalla[51];
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA)
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

/** \brief pant_buscarIndicePantallaLibre busca un indice dentro del array que no este ocupado con datos
 *
 * \param arrayPantallas el array donde se buscara dicho indice
 * \param longitud lo que mide dicho array
 * \return -1 si hubo algun error, el numero del indice si se encontro
 *
 */

int pant_buscarIndicePantallaLibre (EPantalla* arrayPantallas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

/** \brief buscarProximoId generara y devolvera un id autoincremental
 *
 * \param arrayPantallas el array donde se buscara y generara un id
 * \param longitud lo que mide dicho array
 * \return -1 en caso de error, el valor del id en caso de estar correctamente
 *
 */

static int buscarProximoId(EPantalla* arrayPantallas, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayPantallas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA)
            {
                if(idMax < arrayPantallas[i].idPantalla)
                    idMax = arrayPantallas[i].idPantalla;
            }
        }

    }
    return idMax + 1;
}

/** \brief buscarIndiceId busca dentro del array el indice donde se encuentra el id pasado
 *
 * \param arrayPantallas el array donde se hara la busqueda
 * \param longitud lo que mide el array
 * \param id el id a buscar dentro del array
 * \return -1 en caso de error, el valor del indice en caso de encontrarlo
 *
 */

static int buscarIndiceId(EPantalla* arrayPantallas, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayPantallas != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPantallas[i].flagDeEstado == ESTADO_PANTALLA_OCUPADA)
            {
                if(id == arrayPantallas[i].idPantalla)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

/** \brief pant_bajarPantalla da de baja una pantalla que se encuentra cargada en el array
 *
 * \param arrayPantallas el array donde esta dicha pantalla
 * \param len la longitud del array
 * \return -1 en caso de error, 0 en caso de que se ejecute correctamente
 *
 */

int pant_bajarPantalla(EPantalla* arrayPantallas,int len)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID de la pantalla a dar de baja:  ","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayPantallas,len,id);
        if(index>=0)
        {
           arrayPantallas[index].flagDeEstado=ESTADO_PANTALLA_LIBRE;
           printf("EL USUARIO HA SIDO DADO DE BAJA\n");
		   retorno=0;
        }
    }

    return retorno;
}

/** \brief pant_pideId pide al usuario el dato del id y valida que este exista y ya este dado de alta en el array
 *
 * \param arrayPantallas el array donde se buscara el pasado
 * \param len la longitud del array
 * \return -1 si hubo errores, 0 si se ejecuto correctamente
 *
 */

int pant_pideId(EPantalla* arrayPantallas,int len)
{
    int retorno = -1;
    int i;
    char bidPantalla[51];
    if(arrayPantallas != NULL && len > 0)
    {
        printf("INGRESE EL ID DE LA PANTALLA:   \n");
        myFgets(bidPantalla,51,stdin);
        for(i=0; i<len ; i++)
        {
            if(arrayPantallas[i].idPantalla == atoi(bidPantalla) && arrayPantallas[i].flagDeEstado== ESTADO_PANTALLA_OCUPADA)
            {
                retorno =  arrayPantallas[i].idPantalla;
                break;
            }
        }

    }
    return retorno;
}
