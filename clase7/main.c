#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char auxiliar[51];
    strncpy(auxiliar,"Hello world!\n", 51);//respeta el limite que le pase, usar esta
    auxiliar[50]='\0';//se usa por las dudas, le fuerzo el contrabarra 0
    printf("%s", auxiliar);
    char auxiliar2[51];
    strncpy(auxiliar2,"hello world!\n", 51);
    printf("%d",strcmpi(auxiliar2, auxiliar));
    //printf(auxiliar); TAMBIEN SE USA

    return 0;

}
