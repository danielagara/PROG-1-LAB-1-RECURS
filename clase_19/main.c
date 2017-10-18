#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pEmpleado;
    pEmpleado = empleado_newConstructor("JUAN","PEREZ",44);
    empleado_debugShow(pEmpleado);
    empleado_setNombre(pEmpleado, "XX");
    empleado_debugShow(pEmpleado);
    empleado_setApellido(pEmpleado, "AA");
    empleado_debugShow(pEmpleado);

    printf("\nEL NOMBRE ES : %s", empleado_getNombre(pEmpleado));




    return 0;
}
