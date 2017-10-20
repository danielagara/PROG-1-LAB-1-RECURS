#include <stdio.h>
#include <stdlib.h>
#include "pelicula.h"
#include <string.h>
#include "validar.h"


// Funciones privadas
static int buscarProximoId (EPelicula* arrayPeliculas, int longitud);
static int buscarIndiceId (EPelicula* arrayPeliculas, int longitud, int id);
static int modificarPeliculaPorIndice(EPelicula* arrayPeliculas, int index);
//___________________

/** \brief peli_editarPelicula pedira el id de la pelicula a modificar, y validara que exista
 *
 * \param arrayPeliculas el array donde se buscara el dato
 * \param longitud lo que mide el array
 * \return redirige a otra funcion que modificara los datos, 0 si no se ejecuto correctamente
 *
 */

int peli_editarPelicula(EPelicula* arrayPeliculas,int longitud)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID de la pelicula a modificar:  ","INCORRECTO",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayPeliculas,longitud,id);
        if(index>=0)
        {
           return modificarPeliculaPorIndice(arrayPeliculas,index);
        }
    }
    return -1;
}

/** \brief modificarPeliculaPorIndice pedira y modificara los datos de una pantalla
 *
 * \param arrayPeliculas array a modificar el dato
 * \param indice donde se encuentra dentro del array el dato a modificar
 * \return -1 si se ejecuto incorrectamente, 0 si se pudo modificar
 *
 */

static int modificarPeliculaPorIndice(EPelicula* arrayPeliculas, int index)
{
    int retorno = -1;
	char bTitulo[51];
    char bGenero[51];
	char bDuracion[51];
	char bDescripcion[51];
	char bPuntaje[51];
	char bLinkImagen[51];

    if(arrayPeliculas != NULL && index >= 0)
    {
            if(val_getDescripcion(bTitulo,"\nTITULO DE LA PELICULA?\t","\nERROR: TITULO NO VALIDO\n",3,51)==0)
            {
				if(val_getNombre(bGenero,"\nGENERO DE LA PELICULA?\t","\nERROR: GENERO NO VALIDO\n",3,51)==0)
				{
					if(val_getInt(bDuracion,"\nDURACION DE LA PELICULA?\t","\nERROR: DURACION NO VALIDA\n",3,51)==0)
					{
						if(val_getDescripcion(bDescripcion,"\nDESCRIPCION DE LA PELICULA?\t","\nERROR: DESCRIPCION INVALIDA\n",3,51)==0)
						{
							if(val_getInt(bPuntaje,"\nPUNTAJE DE LA PELICULA?\t","\nERROR: PUNTAJE NO VALIDO, DE 1 A 5\n",3,51)==0)
							{
								if(val_getDescripcion(bLinkImagen,"\nLINK A LA IMAGEN DE LA PORTADA: \t","\nERROR: LINK INVALIDO\n",3,51)==0)
								{
									arrayPeliculas[index].flagDeEstado=ESTADO_PELICULA_OCUPADA;
									strncpy(arrayPeliculas[index].titulo,bTitulo,51);
									strncpy(arrayPeliculas[index].genero,bGenero,51);
									arrayPeliculas[index].duracion=atoi(bDuracion);
									strncpy(arrayPeliculas[index].descripcion,bDescripcion,51);
									arrayPeliculas[index].puntaje=atoi(bPuntaje);
									strncpy(arrayPeliculas[index].linkImagen,bLinkImagen,51);
									printf("LA PELICULA CON ID %d SE MODIFICO CORRECTAMENTE\t",arrayPeliculas[index].idPelicula);
								}
							}
						}
					}
				}
			}
    }
    return retorno;
}

/** \brief peli_cargarPelicula pide y carga los datos de una pelicula dentro del array
 *
 * \param arrayPeliculas el array donde se guardaran los datos
 * \param index el indice del array donde estaran esos datos especificamente
 * \param longitud lo que mide el array
 * \return -1 si no se pudo ejecutar correctamente, 0 si no hubo problemas
 *
 */

int peli_cargarPelicula(EPelicula* arrayPeliculas, int index, int longitud)
{
    int retorno = -1;
    int id;
	char bTitulo[51];
    char bGenero[51];
	char bDuracion[51];
	char bDescripcion[51];
	char bPuntaje[51];
	char bLinkImagen[51];

    if(arrayPeliculas != NULL && index >= 0 && index < longitud)
    {
            if(val_getDescripcion(bTitulo,"\nTITULO DE LA PELICULA?\t","\nERROR: TITULO NO VALIDO\n",3,51)==0)
            {
				if(val_getNombre(bGenero,"\nGENERO DE LA PELICULA?\t","\nERROR: GENERO NO VALIDO\n",3,51)==0)
				{
					if(val_getInt(bDuracion,"\nDURACION DE LA PELICULA?\t","\nERROR: DURACION NO VALIDA\n",3,51)==0)
					{
						if(val_getDescripcion(bDescripcion,"\nDESCRIPCION DE LA PELICULA?\t","\nERROR: DESCRIPCION INVALIDA\n",3,51)==0)
						{
							if(val_getInt(bPuntaje,"\nPUNTAJE DE LA PELICULA?\t","\nERROR: PUNTAJE NO VALIDO, DE 1 A 5\n",3,51)==0)
							{
								if(val_getDescripcion(bLinkImagen,"\nLINK A LA IMAGEN DE LA PORTADA: \t","\nERROR: LINK INVALIDO\n",3,51)==0)
								{
									id = buscarProximoId(arrayPeliculas,longitud);
									if(id != -1)
									{
										arrayPeliculas[index].idPelicula=id;
										arrayPeliculas[index].flagDeEstado=ESTADO_PELICULA_OCUPADA;
										strncpy(arrayPeliculas[index].titulo,bTitulo,51);
										strncpy(arrayPeliculas[index].genero,bGenero,51);
										arrayPeliculas[index].duracion=atoi(bDuracion);
										strncpy(arrayPeliculas[index].descripcion,bDescripcion,51);
										arrayPeliculas[index].puntaje=atoi(bPuntaje);
										strncpy(arrayPeliculas[index].linkImagen,bLinkImagen,51);
										printf("EL ID DE LA PELICULA ES %d\t",arrayPeliculas[index].idPelicula);
									}
								}
							}
						}
					}
				}
			}
    }
    return retorno;
}

/** \brief peli_initPelicula inicializa todos los indices del array como disponibles a ser ocupados
 *
 * \param arrayPeliculas el array a inicializar
 * \param longitud lo que mide dicho array
 * \return -1 si hubo error, 0 si no
 *
 */

int peli_initPelicula(EPelicula* arrayPeliculas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPeliculas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPeliculas[i].flagDeEstado = ESTADO_PELICULA_LIBRE;
            retorno=0;
        }

    }
    return retorno;
}


/** \brief pant_buscarIndicePeliculaLibre busca un indice dentro del array que no este ocupado con datos
 *
 * \param arrayPeliculas el array donde se buscara dicho indice
 * \param longitud lo que mide dicho array
 * \return -1 si hubo algun error, el numero del indice si se encontro
 *
 */

int peli_buscarIndicePeliculaLibre  (EPelicula* arrayPeliculas, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPeliculas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPeliculas[i].flagDeEstado == ESTADO_PELICULA_LIBRE)
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
 * \param arrayPeliculas el array donde se buscara y generara un id
 * \param longitud lo que mide dicho array
 * \return -1 en caso de error, el valor del id en caso de estar correctamente
 *
 */

static int buscarProximoId(EPelicula* arrayPeliculas, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayPeliculas != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPeliculas[i].flagDeEstado == ESTADO_PELICULA_OCUPADA)
            {
                if(idMax < arrayPeliculas[i].idPelicula)
                    idMax = arrayPeliculas[i].idPelicula;
            }
        }

    }
    return idMax + 1;
}

/** \brief buscarIndiceId busca dentro del array el indice donde se encuentra el id pasado
 *
 * \param arrayPeliculas el array donde se hara la busqueda
 * \param longitud lo que mide el array
 * \param id el id a buscar dentro del array
 * \return -1 en caso de error, el valor del indice en caso de encontrarlo
 *
 */

static int buscarIndiceId(EPelicula* arrayPeliculas, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayPeliculas != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPeliculas[i].flagDeEstado == ESTADO_PELICULA_OCUPADA)
            {
                if(id == arrayPeliculas[i].idPelicula)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}

/** \brief peli_bajarPelicula da de baja una pelicula que se encuentra cargada en el array
 *
 * \param arrayPeliculas el array donde esta dicha pelicula
 * \param longitud la longitud del array
 * \return -1 en caso de error, 0 en caso de que se ejecute correctamente
 *
 */

int peli_bajarPelicula(EPelicula* arrayPeliculas,int longitud)
{
    char idStr[32];
    int id;
    int index;
	int retorno=-1;
    if(val_getUnsignedInt(idStr, "Ingrese ID de la pelicula a dar de baja:  ","ERROR: NO SE ENCONTRO DICHO ID",2,32)==0)
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayPeliculas,longitud,id);
        if(index>=0)
        {
           arrayPeliculas[index].flagDeEstado=ESTADO_PELICULA_LIBRE;
           printf("LA PELICULA HA SIDO DADO DE BAJA\n");
		   retorno=0;
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

int peli_escribeArchivo(EPelicula* arrayPeliculas, int longitudPeliculas)
{
    FILE* pArchivo;
    int i;
    pArchivo=fopen("archivoPeliculas.bin","wb");
    int retorno=-1;
    if(pArchivo!=NULL)
    {
        for(i=0;i<longitudPeliculas;i++)
        {
            if(arrayPeliculas[i].flagDeEstado==ESTADO_PELICULA_OCUPADA)
            {
                fwrite((arrayPeliculas+i), sizeof(EPelicula),1, pArchivo);
            }
        }
        retorno=0;
        fclose(pArchivo);
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
/*
int peli_generaPaginaWeb( FILE* pArchivoAbajo, FILE* pArchivoHTML, EPelicula* arrayPeliculas, int longitudPeliculas)
{

    pArchivoArriba=fopen("parteArriba.txt", "r");
    pArchivoAbajo=fopen("parteAbajo.txt","r");
    pArchivoHTML=fopen("paginaweb.html", "w+");
    if(pArchivoArriba !=NULL && pArchivoAbajo != NULL && pArchivoHTML !=NULL)
    {
       //PRINTEO LO DE ARRIBA
       //FOR E IMPRIMO TODO LO DEL MEDIO
       //PRINTEO LO DE ABAJO
    }
}
*/

int peli_archivoHTMLarriba(void)
{
    FILE* pArchivoArriba;
    int retorno=-1;
    pArchivoArriba=fopen("parteArriba.txt", "w+");

    if(pArchivoArriba!=NULL)
    {
        fprintf(pArchivoArriba, "%s","<html lang='en'>\n");
        fprintf(pArchivoArriba, "%s","<head>\n");
        fprintf(pArchivoArriba, "%s","    <meta charset='utf-8'>\n");
        fprintf(pArchivoArriba, "%s","    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pArchivoArriba, "%s","    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pArchivoArriba, "%s","    <title>Lista peliculas</title>\n");
        fprintf(pArchivoArriba, "%s","    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pArchivoArriba, "%s","    <link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pArchivoArriba, "%s","    </head>\n");
        fprintf(pArchivoArriba, "%s","<body>\n");
        fprintf(pArchivoArriba, "%s","    <div class='container'>\n");
        retorno=0;
        fclose(pArchivoArriba);
    }
    return retorno;

}

int peli_archivoHTMLabajo(void)
{
    FILE* pArchivoAbajo;
    int retorno=-1;
    pArchivoAbajo=fopen("parteAbajo.txt", "w+");
    if(pArchivoAbajo!=NULL)
    {
        fprintf(pArchivoAbajo, "%s","		</div>\n");
        fprintf(pArchivoAbajo, "%s","    <!-- /.container -->\n");
        fprintf(pArchivoAbajo, "%s","    <!-- jQuery -->\n");
        fprintf(pArchivoAbajo, "%s","    <script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pArchivoAbajo, "%s","    <!-- Bootstrap Core JavaScript -->\n");
        fprintf(pArchivoAbajo, "%s","    <script src='js/bootstrap.min.js'></script>\n");
        fprintf(pArchivoAbajo, "%s","	<!-- IE10 viewport bug workaround -->\n");
        fprintf(pArchivoAbajo, "%s","	<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pArchivoAbajo, "%s","	<!-- Placeholder Images -->\n");
        fprintf(pArchivoAbajo, "%s","	<script src='js/holder.min.js'></script>\n");
        fprintf(pArchivoAbajo, "%s","</body>\n");
        fprintf(pArchivoAbajo, "%s","</html>\n");
        retorno=0;
        fclose(pArchivoAbajo);
    }
    return retorno;
}
