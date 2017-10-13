#include <stdio.h>
#include <stdlib.h>
#define TAM_ITERACIONES 100
int main()
{
    FILE* pArchivo;
    int i;
    pArchivo=fopen("archivo.txt","w");
    if(pArchivo==NULL)
    {
        printf("ERROR\n");
        exit(1);
    }
    else
    {
        for(i=1;i<=TAM_ITERACIONES;i++)
        {
            fprintf(pArchivo,"%d\n",i);
        }
    }
    fclose(pArchivo);

    char texto[50];
    pArchivo=fopen("archivo.txt","r");
    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            //fread(texto,sizeof(char),50,pArchivo);
            if(fgets(texto,50,pArchivo)!=NULL)
            printf("%s", texto);
        }
    }
    return 0;
}
