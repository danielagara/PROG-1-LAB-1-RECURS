#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"

int dm_dumpEmployeeList(ArrayList* list)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* pEmployees=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(list);i++)
        {
            pEmployees=al_get(list,i);
            fprintf(pFile, "%d,%s,%s,%d,%d\n", employee_getId(pEmployees),employee_getName(pEmployees), employee_getLastName(pEmployees), employee_getAge(pEmployees), employee_getType(pEmployees));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}
