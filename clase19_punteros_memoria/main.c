#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pEmpleado;
    pEmpleado=empleado_newConstructor("JUAN", "PEREZ", 1);
    empleado_debugShow(pEmpleado);
    empleado_setNombre(pEmpleado,"ANA"); //LE CAMBIE EL NOMBRE
    empleado_debugShow(pEmpleado);
    printf("\nEL NOMBRE ES : %s", empleado_getNombre(pEmpleado));
    return 0;
}
