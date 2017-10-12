#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "validar.h"
#include <string.h>


//FUNCIONES PRIVADAS
static int buscarProximoIdContratacion(EContratacion* arrayContrataciones, int longitud);
static int buscarIndicePantalla(EContratacion* arrayContrataciones, int longitud, char* cuitCliente, int idPantalla);
static int modificaContratacionPorIndice(EContratacion* arrayContrataciones, int index);
//_________________________________________________________________

/** \brief buscarProximoIdContratacion genera un id autoincrementable, y lo devuelve como retorno
 *
 * \param arrayContrataciones el array al que se le genera el id
 * \param longitud lo que mide dicho array
 * \return -1 si falla, el numero de id si no hubo problemas
 *
 */

static int buscarProximoIdContratacion(EContratacion* arrayContrataciones, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayContrataciones[i].flagDeEstado == ESTADO_CONTRATACION_OCUPADA)
            {
                if(idMax < arrayContrataciones[i].idContratacion)
                    idMax = arrayContrataciones[i].idContratacion;
            }
        }

    }
    return idMax + 1;
}

/** \brief buscarIndicePantalla buscara dentro del array el valor de id de pantalla pasado como parametro
 *
 * \param arrayContrataciones el array en el que se buscara dicho id
 * \param longitud lo que mide dicho array
 * \param cuitCliente el dato cuit del cliente al que le corresponde dicho id
 * \param idPantalla el dato (id) a buscar dentro del array
 * \return -1 en caso de no haberse encontrado, el valor del indice en caso de que si
 *
 */

static int buscarIndicePantalla(EContratacion* arrayContrataciones, int longitud, char* cuitCliente, int idPantalla)
{
    int i;
    int retorno = -1;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(idPantalla == arrayContrataciones[i].idPantalla && stricmp(arrayContrataciones[i].cuitCliente,cuitCliente)==0)
            {
                if(arrayContrataciones[i].flagDeEstado == ESTADO_CONTRATACION_OCUPADA)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

/** \brief cont_nuevaContratacion genera el alta de una nueva contratacion, es decir, pide al usuario y guarda los datos dentro del array
 *
 * \param arrayContrataciones el array donde se introduciran los datos
 * \param index el indice del array donde se guardaran
 * \param len la longitud del array
 * \param idPantalla dato previo a validar antes de guardar
 * \return -1 en caso de error, 0 en caso de que se ejecute correctamente
 *
 */

int cont_nuevaContratacion(EContratacion* arrayContrataciones, int index, int len, int idPantalla)
{
    int retorno = -1;
    int idContratacion;
    char bCUITdelCliente[51];
	char bDiasQueDuraPublicacion[51];
	char bNombreArchivoDelVideo[100];


    if(arrayContrataciones != NULL && index >= 0 && index < len && idPantalla!=-1)
    {
          if(val_getInt(bCUITdelCliente,"\nCUIT DEL CLIENTE?\t","\nError:\n",3,51)==0 && strlen(bCUITdelCliente)>10)
          {
			  if(val_getInt(bDiasQueDuraPublicacion,"\nDIAS QUE DURA LA PUBLICACION?\t","\nError:\n",3,51)==0)
			  {
				  if(val_getDescripcion(bNombreArchivoDelVideo,"\nNOMBRE DEL ARCHIVO DEL VIDEO?\t","\nError:\n",3,100)==0)
				  {
					idContratacion = buscarProximoIdContratacion(arrayContrataciones,len);
					if(idContratacion != -1)
					{
						strncpy(arrayContrataciones[index].cuitCliente,bCUITdelCliente,51);
						arrayContrataciones[index].idPantalla = idPantalla;
						arrayContrataciones[index].diasQueDuraPublicacion=atoi(bDiasQueDuraPublicacion);
						strncpy(arrayContrataciones[index].nombreArchivoDelVideo,bNombreArchivoDelVideo,100);
						arrayContrataciones[index].flagDeEstado = ESTADO_CONTRATACION_OCUPADA;
						arrayContrataciones[index].idContratacion = idContratacion;
						printf("EL ID DE SU PRODUCTO ES: %d", arrayContrataciones[index].idContratacion);
						retorno = 0;
					}
				  }

			  }

           }

    }
    return retorno;
}

/** \brief cont_buscarIndiceContratacionLibre busca el indice que no tenga guardado otros datos de otra contratacion
 *
 * \param arrayContrataciones el array donde se realizara la busqueda
 * \param longitud lo que mide el array
 * \return -1 en caso de error, el numero del indice en caso de que se encuentre
 *
 */

int cont_buscarIndiceContratacionLibre(EContratacion* arrayContrataciones, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayContrataciones[i].flagDeEstado ==ESTADO_CONTRATACION_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

/** \brief cont_initProductos inicializa todos los indices del array como espacios disponibles a ocupar
 *
 * \param arrayContrataciones el array a inicializar
 * \param longitud lo que mide el array
 * \return -1 en caso de error, 0 en caso de ejecucion correcta
 *
 */

int cont_initProductos(EContratacion* arrayContrataciones, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayContrataciones != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayContrataciones[i].flagDeEstado = ESTADO_CONTRATACION_LIBRE;
            retorno=0;
        }

    }
    return retorno;
}

/** \brief cont_editarContratacion pedira el id de la pantalla a modificar, y validara que exista
 *
 * \param arrayContrataciones el array donde se buscara el dato
 * \param len lo que mide el array
 * \return redirige a otra funcion que modificara los datos, 0 si no se ejecuto correctamente
 *
 */

int cont_editarContratacion(EContratacion* arrayContrataciones,int len)
{
    char bCUITdelCliente[51];
    int index;
	char bidPantalla[51];

    if(val_getInt(bidPantalla,"INGRESE EL ID DE LA PANTALLA A MODIFICAR:\t","INCORRECTO",2,51)==0)
    {
        index = buscarIndicePantalla(arrayContrataciones,len,bCUITdelCliente,atoi(bidPantalla));
        if(index>=0)
        {

            return modificaContratacionPorIndice(arrayContrataciones,index);
        }
    }
    return 0;
}

/** \brief modificaContratacionPorIndice pedira y modificara los datos de una contratacion
 *
 * \param arrayContrataciones
 * \param index el indice donde se encuentra la contratacion a modificar
 * \return 0 si fue correctamente modificado, -1 si hubo algun error;
 *
 */

static int modificaContratacionPorIndice(EContratacion* arrayContrataciones, int index)
{
    int retorno = -1;
    char bdiasQueDuraPublicacion[51];

    if(arrayContrataciones != NULL && index >= 0)
    {
        if(val_getInt(bdiasQueDuraPublicacion,"\nCUANTOS DIAS QUIERE QUE DURE AHORA LA CONTRATACION?\t","\nError:\n",3,51)==0)
        {
            arrayContrataciones[index].diasQueDuraPublicacion=atoi(bdiasQueDuraPublicacion);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief cont_cancelarContratacion da de baja una contratacion
 *
 * \param arrayContrataciones el array donde se dara de baja el item
 * \param len la longitud del array
 * \return -1 en caso de error, 0 si fue correctamente ejecutado
 *
 */

int cont_cancelarContratacion(EContratacion* arrayContrataciones,int len)
{
    int retorno=-1;
	char bidPantalla[51];
	int i;

		if(val_getInt(bidPantalla,"Ingrese id de la pantalla a borrar:  ","INCORRECTO",2,32)==0)
		{
			if(atoi(bidPantalla)!=-1)
			{
				for(i=0;i<len;i++)
				{
					if(arrayContrataciones[i].idPantalla==atoi(bidPantalla))
					{
						arrayContrataciones[i].flagDeEstado=ESTADO_CONTRATACION_LIBRE;
						retorno=0;
					}
				}
			}

		}

    return retorno;
}


/** \brief cont_cuentaContrataciones cuenta la cantidad de contrataciones que tiene un cliente
 *
 * \param arrayContrataciones el array con la informacion sobre cada contratacion
 * \param len la longitud del array
 * \param CUITCliente el cuit de cada cliente a contar contrataciones
 * \return -1 si hubo algun error, el valor de la cantidad de contrataciones si no hubo errores
 *
 */

int cont_cuentaContrataciones(EContratacion* arrayContrataciones, int len, char* CUITCliente)
 {
     int retorno=-1;
     int i;
     int cantidadContrataciones=0;
     //char bCUITCliente[51];

     if(arrayContrataciones != NULL && len > 0 && CUITCliente != NULL)
     {
         for(i=0;i<len;i++)
        {
            if(stricmp(CUITCliente,arrayContrataciones[i].cuitCliente)==0 && arrayContrataciones[i].flagDeEstado==ESTADO_CONTRATACION_OCUPADA)
            {
                cantidadContrataciones++;
                retorno=cantidadContrataciones;
            }
        }
     }

	if(retorno!=-1)
	{
		printf("CANTIDAD DE CONTRATACIONES: %d\n", cantidadContrataciones);
	}

     return retorno;
 }
