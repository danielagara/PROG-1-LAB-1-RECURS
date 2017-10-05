#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "categoria.h"
#include "programador.h"
#include "proyecto.h"
#include "compartida.h"

#define TAM_CATEGORIA 3
#define TAM_PROGRAMADORES 100
#define TAM_PROYECTOS 1000
int main()
{
    ECategoria arrayCategorias[TAM_CATEGORIA];
    cat_initCategoria(arrayCategorias, TAM_CATEGORIA);

    EProgramador arrayProgramadores[TAM_PROGRAMADORES];
    prog_initProgrmador(arrayProgramadores,TAM_PROGRAMADORES);

    EProyecto arrayProyectos[TAM_PROYECTOS];
    proye_initProyectos(arrayProyectos,TAM_PROYECTOS);

    char bufferInt[40];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DE PROGRAMADOR\n2-MODIFICAR DATOS PROGRAMADOR\n3-BAJA DE PROGRAMADOR\n4-ASIGNAR PROGRAMADOR A PROYECTO\n5-\n6-\7-\n8-PROYECTO MAS DEMANDANTE\n9-SALIR\n","\nSolo de 1 a 7\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                prog_cargarProgramador(arrayProgramadores,prog_buscarIndiceProgramadorLibre(arrayProgramadores,TAM_PROGRAMADORES),TAM_PROGRAMADORES);
                break;
            case 2:
                prog_editarProgramador(arrayProgramadores,TAM_PROGRAMADORES);
                break;
            case 3:
                prog_bajarProgramador(arrayProgramadores,TAM_PROGRAMADORES);
                comp_bajaProgramadoresEnProyectos(arrayProgramadores,TAM_PROGRAMADORES,arrayProyectos,TAM_PROYECTOS);
                break;
            case 4:
                prog_printProgramadores(arrayProgramadores,TAM_CATEGORIA);
                proye_asignaProgramadorAProyecto(arrayProyectos,proye_buscarIndiceProyecctoLibre(arrayProyectos,TAM_PROYECTOS),TAM_PROYECTOS,prog_pideId(arrayProgramadores,TAM_PROGRAMADORES));
                break;
            case 5:
                comp_listadoProgramadoresVersion2(arrayProgramadores,TAM_PROGRAMADORES,arrayProyectos,TAM_PROYECTOS,arrayCategorias,TAM_CATEGORIA);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                proye_proyectoMasDemandante(arrayProyectos,TAM_PROYECTOS);
                break;
        }

    }while( atoi(bufferInt) != 9);

    return 0;
}
