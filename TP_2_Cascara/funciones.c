#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validar.h"
#define PERSONA_LIBRE 0
#define PERSONA_OCUPADA 1
#define PERSONA_BORRADA -1

/** \brief Obtiene el indice de estado que esta libre
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \return -1 por error, indice libre
 *
 */

int perso_obtenerEspacioLibre(EPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == PERSONA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

/** \brief Busca dentro del array el dni
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \param dni a buscar
 * \return -1 error, indice de donde se encontro
 *
 */

int perso_buscarPorDni(EPersona* arrayPersona, int longitud, char* dni)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(stricmp(dni,arrayPersona[i].dni)==0)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

/** \brief Inicializa el campo estado del array para poder ser ocupado
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \return -1 error, 0 OK
 *
 */

int perso_initPersona(EPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayPersona[i].estado = PERSONA_LIBRE;
        }

    }
    return retorno;
}

/** \brief Carga el array con los datos
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \param index posicion donde se va a cargar el array
 * \return -1 error, 0 OK
 *
 */

int perso_cargarPersona(EPersona* arrayPersona, int index, int longitud)
{
    int retorno = -1;
    char bNombre[51];
    char bEdad[51];
	char bDNI[51];

    if(arrayPersona != NULL && index >= 0)
    {
		if(val_getInt(bDNI,"\nDNI?","\nError:\n",3,51)==0 && perso_buscarPorDni(arrayPersona,longitud,bDNI)==-1)
        {
            if(val_getString(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
            {
				if(val_getInt(bEdad,"\nEDAD?","\nError:\n",3,51)==0 && perso_validarEdadPersona(bEdad, "ERROR EDAD NO VALIDA\n")==0)
				{
				    strncpy(arrayPersona[index].dni,bDNI,51);
					strncpy(arrayPersona[index].nombre,bNombre,51);
					arrayPersona[index].edad=atoi(bEdad);
					arrayPersona[index].estado = PERSONA_OCUPADA;
				}

            }
        }

    }
    return retorno;
}

/** \brief Imprime las posiciones del array que se encuentren cargadas
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \return -1 error, 0 OK
 *
 */

int perso_printPersona(EPersona* arrayPersona, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayPersona[i].estado == PERSONA_OCUPADA)
            {
                printf("ID: %d - Nombre:%s - Edad:%d - DNI: %s",i,arrayPersona[i].nombre,arrayPersona[i].edad,arrayPersona[i].dni);
            }
        }

    }
    return retorno;
}

/** \brief Borra la posicion del array pedida (estado inhabilitado)
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \param mensaje a mostrarle el usuario
 * \return -1 error, 0 OK
 *
 */

int perso_borrarPersona(EPersona* arrayPersona, int longitud, char* mensaje)
{
    int retorno = -1;
	char bDNI[51];
	char respuesta='s';
	int indiceBorrar;

    if(arrayPersona != NULL && longitud > 0)
    {
		printf(mensaje);
		myFgets(bDNI,51,stdin);
		//val_validarInt(bDNI);
		if(perso_buscarPorDni(arrayPersona,longitud,bDNI) !=-1)
		{
			indiceBorrar=perso_buscarPorDni(arrayPersona,longitud,bDNI);
			printf("ESTA SEGURO QUE QUIERE BORRAR A LA PERSONA CON DNI %s ??? 's' o 'n'\n\n",bDNI);
			fflush(stdin);
			scanf(&respuesta);
			if(respuesta=='s')
			{
				arrayPersona[indiceBorrar].estado=PERSONA_BORRADA;//PREGUNTAR
				printf("PERSONA BORRADA CORRECTAMENTE");
				retorno = 0;
			}
		}
		else
		{
		    printf("NO SE ENCONTRO EL DNI\n\n");
			retorno = -1;
		}

    }
    return retorno;
}

/** \brief Ordena el array por nombre alfabeticamente
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \return -1 error, 0 OK
 *
 */

void perso_insertionSort(EPersona* arrayPersona, int longitud)
{
   int i, j;
   EPersona aux;
   for (i = 1; i < longitud; i++)
   {
       aux = arrayPersona[i];
       j = i-1;

       /* Move elements of arrayPersona[0..i-1], that are
          greater than aux, to one position ahead
          of their current position */
       while (j >= 0 && arrayPersona[j].nombre > aux.nombre)
       {
           arrayPersona[j+1] = arrayPersona[j];
           j = j-1;
       }
       arrayPersona[j+1] = aux;
   }
}

/** \brief Imprime el gráfico de edades
 *
 * \param array a utilizar de la esructura EPersona
 * \param longitud del array
 * \return -1 error, 0 OK
 *
 */

void perso_imprimirGrafico(EPersona* arrayPersona, int longitud)
{

    char grafico[longitud][3];
    int i;
    int j=longitud-1;
    int k=longitud-1;
    int l=longitud-1;

    perso_inicializaMatriz(grafico,longitud);
    if(arrayPersona != NULL && longitud > 0)
    {
        for(i=0;i<longitud;i++)
        {
            if(arrayPersona[i].estado==PERSONA_OCUPADA)
            {
                if(arrayPersona[i].edad<18)
                {
                    grafico[j][0]='*';
                    j--;
                }
                if(arrayPersona[i].edad>18 && arrayPersona[i].edad<35)
                {
                    grafico[k][1]='*';
                    k--;
                }
                if(arrayPersona[i].edad>35)
                {
                    grafico[l][2]='*';
                    l--;
                }
            }
        }

        for (i=longitud-1;i>0;i--)
        {
            for (j=0;j<3;j++)
            {
                if(grafico[i][j]=='*')
                {
                    printf("%c",grafico[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n<18 - 19-35 - >35\n");
    }

}


void perso_inicializaMatriz(char grafico[][3], int longitud)
{
    int i;
    for(i=0;i<longitud;i++)
    {
        grafico[i][0]=' ';
        grafico[i][1]=' ';
        grafico[i][2]=' ';
    }
}

/** \brief Valida que la edad este dentro de un rango razonable
 *
 * \param buffer conteniendo la edad ingresada
 * \param mensaje de error a imprimir en el caso de que falle
 * \return -1 error, 0 OK
 *
 */

int perso_validarEdadPersona(char* bufferEdad, char* mensajeError)
{
	int retorno=0;
	if(atoi(bufferEdad) <0 || atoi(bufferEdad) >200)
	{
		retorno=-1;
		printf(mensajeError);
	}
	return retorno;
}
