#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

#define MAX_INPUT_BUFFER 4096

/** \brief myFgets fgets con modificacion de \0 y LF
 *
 * \param buffer puntero a char que va a ser el dato a obtener
 * \param limite el limite de caracteres que tiene dicho puntero a char
 * \param archivo puntero a archivo
 * \return VOID
 *
 */

void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/** \brief val_getNombre obtiene un dato de tipo string y valida que sean solo caracteres
 *
 * \param destino a donde se va a guardar el dato a pedir
 * \param mensaje el mensaje a imprimirle al usuario para que sepa que ingresar
 * \param mensajeError el mensaje que se le imprimira al usuario en caso de error
 * \param intentos la cantidad de intentos que puede tener este para reingresar el dato en caso de error
 * \param limite el limite de caracteres que puede tener destino
 * \return -1 en caso de error, 0 en caso de que se ingrese correctamente
 *
 */

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarNombre(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }


        }



    }
    return retorno;
}

/** \brief val_getFloat obtiene dato de tipo string y valida que sean solo caracteres aceptados de float
 *
 * \param destino el string a donde se guardara el dato pedido
 * \param mensaje el mensaje a impimirle al usuario para que ingrese el dato
 * \param mensajeError el mensaje a imprimirle al usuario en caso de error
 * \param intentos la cantidad de intentos que tiene el usuario para reingresar el dato en caso de error
 * \param limite el limite de caracteres que puede tener destino
 * \return -1 en caso de error, 0 si no hubo errores
 *
 */

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarFloat(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief val_validarNombre valida que el puntero a char que se le pasa se contenga solo de caracteres alfabeticos
 *
 * \param buffer el puntero a char a validar
 * \return -1 si hubo algun error, 0 si esta todo correcto
 *
 */

int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i]!=' ' )
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief val_validarFloat valida que todos los caracteres del puntero a char que se le pasan sean numericos, , o .
 *
 * \param buffer puntero a char a validar
 * \return -1 si hubo algun error, 0 si esta correcto
 *
 */

int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief val_validarInt valida que todos los caracteres del puntero a char que se le pasan sean numericos
 *
 * \param buffer el puntero a char a validar
 * \return -1 si hubo algun error, 0 si no hubo ninguno
 *
 */

int val_validarInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief val_getInt obtiene un dato de tipo string y valida que sean solo caracteres numericos
 *
 * \param destino a donde se guardara el string pedido
 * \param mensaje el mensaje a imprimirle al usuario para que sepa que ingresar
 * \param mensajeError el mensaje de error a imprimirle al usuario en caso de algun error
 * \param intentos el numero de veces que el usuario puede volver a intentar ingresar el dato luego de equivocarse
 * \param limite el limite de caracteres que puede tener destino
 * \return -1 si hubo algun error, 0 si la ejecucion fue correcta
 *
 */

int val_getInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief val_getUnsignedInt pide y valida un dato de tipo string que solo contenga numeros sin signo
 *
 * \param destino el puntero a char donde se va a guardar el dato pedido
 * \param mensaje el mensaje a mostrarle al usuario para que sepa que ingresar
 * \param mensajeError el mensaje a mostrarle al usuario en caso de error
 * \param intentos la cantidad de intentos que tiene el usuario de volver a ingresar el dato en caso de equivocarse
 * \param limite el limite de caracteres que tiene destino
 * \return -1 si hubo algun error, 0 si no hubo errores
 *
 */

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief val_validarUnsignedInt obtiene un dato de tipo string y valida que sean solo caracteres numericos, ., -
 *
 * \param destino a donde se guardara el string pedido
 * \param mensaje el mensaje a imprimirle al usuario para que sepa que ingresar
 * \param mensajeError el mensaje de error a imprimirle al usuario en caso de algun error
 * \param intentos el numero de veces que el usuario puede volver a intentar ingresar el dato luego de equivocarse
 * \param limite el limite de caracteres que puede tener destino
 * \return -1 si hubo algun error, 0 si la ejecucion fue correcta
 *
 */

int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief val_validarDescripcion valida que el string contenga solo caracteres alfabeticos y signos de puntuacion
 *
 * \param buffer el string a validar
 * \return -1 si hubo algun error, 0 si no hubo errores
 *
 */

int val_validarDescripcion(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != ' ' && buffer[i] != '-'  && buffer[i] != '_'  && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }

    return retorno;
}

/** \brief val_getDescripcion pide al usuario un dato de tipo string y valida su contenido
 *
 * \param destino donde se guargara el dato pedido
 * \param mensaje el mensaje a imprimirle al usuario para que sepa que ingresar
 * \param mensajeError el mensaje a imprimmirle al usuario en caso de error
 * \param intentos la cantidad de veces que el usuario puede volver a reingresar el dato en caso de equivocarse
 * \param limite la cantidad maxima de caracteres de destino
 * \return -1 si hubo algun error, 0 si no hubo errores
 *
 */

int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarDescripcion(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}

