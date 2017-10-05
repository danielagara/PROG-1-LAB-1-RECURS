#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "categoria.h"
#include "programador.h"
#include "proyecto.h"
#include "compartida.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int comp_bajaProgramadoresEnProyectos(EProgramador* arrayProgramadores, int lenProgramadores, EProyecto* arrayProyectos, int lenProyectos)
{
    int i, j;
    int retorno=-1;

    for(i=0;i<lenProgramadores;i++)
    {
        for(j=0;j<lenProyectos;j++)
        {
            if(arrayProgramadores[i].idProgramador==arrayProyectos[j].idProgramador && arrayProgramadores[i].flagDeEstado==ESTADO_PROGRAMADOR_LIBRE)
            {
                arrayProyectos[j].flagDeEstado=ESTADO_PROYECTO_LIBRE;
                retorno=0;
            }
        }
    }

    return retorno;
}

/*void comp_listadoProgramadores(EProgramador* arrayProgramadores, int lenProgramadores,
                               EProyecto* arrayProyectos, int lenProyectos, ECategoria* arrayCategorias, int lenCategorias)
{
    int i;

    for(i=0;i<lenProgramadores;i++)
    {
        if(arrayProgramadores[i].flagDeEstado == ESTADO_PROGRAMADOR_LIBRE)
        {
            printf("\n_______________________________________\n");
            prog_printProgramador(arrayProgramadores,lenProgramadores,arrayProgramadores[i].idProgramador);
            cat_imprimeDescripcionCategoria(arrayCategorias,lenCategorias,arrayProgramadores[i].idCategoria);
            proye_imprimeProyectoPorPogramador(arrayProyectos,lenProyectos,arrayProgramadores[i].idProgramador);
        }
    }

}
*/
void comp_listadoProgramadoresVersion2(EProgramador* arrayProgramadores, int lenProgramadores,
                               EProyecto* arrayProyectos, int lenProyectos, ECategoria* arrayCategorias, int lenCategorias)
{
    int i,j,k;
    float ganancia;
    for(i=0;i<lenProgramadores;i++)
    {
        for(k=0;k<lenProyectos;k++)
        {
            for(j=0;j<lenCategorias;j++)
            {
                if(arrayProgramadores[i].flagDeEstado==ESTADO_PROGRAMADOR_OCUPADO)
                {
                    printf("ID: %d - Nombre:%s - Apellido: %s \n",arrayProgramadores[i].idProgramador,arrayProgramadores[i].nombre,arrayProgramadores[i].apellido);
                    if(arrayProgramadores[i].idCategoria==arrayCategorias[j].idCategoria)
                    {
                        printf("DESCRIPCION DE LA CATEGORIA: %s\n", arrayCategorias[j].descripcionCategoria);
                        if(arrayProgramadores[i].idProgramador==arrayProyectos[k].idProgramador && arrayProyectos[k].flagDeEstado==ESTADO_PROYECTO_OCUPADO)
                        {
                            printf("NOMBRE DEL PROYECTO: %s\n", arrayProyectos[k].nombreDelProyecto);
                            ganancia=arrayCategorias[j].pagoXhora*arrayProyectos[k].horasAtrabajar;
                            printf("GANANCIA POR PROYECTO: %f\n", ganancia);
                            printf("\n_____________________________\n");
                        }
                        break;
                    }

                }

            }

        }

    }

}
