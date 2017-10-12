#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int edad;
}EPersona;

int cargarPersona(EPersona* pPersona);
void printPersona(EPersona* pPersona);

int main()
{
    EPersona persona;
    if(cargarPersona(&persona)==-1)
    {
        printf("ERRORRR!!\n");
    }
    else
    {
        printPersona(&persona);
    }

    return 0;
}

int cargarPersona(EPersona* pPersona)
{
    int retorno=-1;
    if(pPersona!=NULL)
    {
        printf("INGRESE NOMBRE: ");
        fgets(pPersona->nombre,19,stdin);
        printf("INGRESE EDAD: ");
        scanf("%d",&pPersona->edad);
        retorno=0;
    }
    /* con la flecha me ahorro de esto:
    EPersona aux=*pPersona;
    aux.edad=9;
    *pPersona=aux;
    o de:
    (*pPersona).edad */

    //p[i] == *(p+i)

    return retorno;
}

void printPersona(EPersona* pPersona)
{
    if(pPersona!=NULL)
    {
        printf("EL NOMBRE ES : %s Y LA EDAD ES: %d", pPersona->nombre, pPersona->edad);
    }
}
