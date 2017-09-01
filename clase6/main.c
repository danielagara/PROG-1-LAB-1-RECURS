#include <stdio.h>
#include <stdlib.h>
#define CANT_CARACTERES 10
#include "lib.h"

int main()
{
    char cadena1[CANT_CARACTERES]={'H', 'o', 'l', 'a', '\0'};
    imprimePorCaracter(cadena1);
    return 0;
}
