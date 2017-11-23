#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>

/** \brief crea un nuevo employee
 *
 * \param int id el id del employee
 * \param char* name array de char nombre del employee
 * \param char* lastName array de char apellido del employee
 * \param int age edad del employee
 * \param  int type tipo de trabajo del employee
 * \return Employee* un empleado cargado
 *
 */

Employee* employee_new(int id, char* name, char* lastName,int age, int type)
{
    Employee* nuevoEmployee = malloc(sizeof(Employee));
	employee_setId(nuevoEmployee,id);
    employee_setName(nuevoEmployee,name);
    employee_setLastName(nuevoEmployee,lastName);
    employee_setAge(nuevoEmployee,age);
    employee_setType(nuevoEmployee,type);

    return nuevoEmployee;
}
/** \brief borra un employee
 *
 * \param el employee a borrar
 * \return void
 *
 */


void employee_delete(Employee* this)
{
    free(this);
}
/** \brief guarda el nombre pasado en el employee que se le diga
 *
 * \param Employee* this el empleado a cargar el nombre
 * \param char* name el array de char nombre a cargar en el employee
 * \return 0 if ok
 *
 */


int employee_setName(Employee* this,char* name)
{
    strcpy(this->name,name);
    return 0;
}
/** \brief obtiene el nombre del employee pasado
 *
 * \param this el employee a obtener el nombre
 * \return char* name el nombre del employee
 *
 */


char* employee_getName(Employee* this)
{
    return this->name;
}
/** \brief guarda el apellido pasado en el employee que se le diga
 *
 * \param Employee* this el empleado a cargar el apellido
 * \param char* lastName el array de char apellido a cargar en el employee
 * \return 0 if ok
 *
 */


int employee_setLastName(Employee* this,char* lastName)
{
    strcpy(this->lastName,lastName);
    return 0;
}
/** \brief obtiene el apellido del employee pasado
 *
 * \param this el employee a obtener el apellido
 * \return char* lastName el apellido del employee
 *
 */


char* employee_getLastName(Employee* this)
{
    return this->lastName;
}

/** \brief guarda el id pasado en el employee que se le diga
 *
 * \param Employee* this el empleado a cargar el id
 * \param int id el id a cargar en el employee
 * \return 0 if ok
 *
 */


int employee_setId(Employee* this,int id)
{

    this->id = id;
    return 0;
}

/** \brief obtiene el id del employee pasado
 *
 * \param this el employee a obtener el id
 * \return int id el id del employee
 *
 */

int employee_getId(Employee* this)
{
    return this->id;
}
/** \brief guarda la edad pasada en el employee que se le diga
 *
 * \param Employee* this el empleado a cargar la edad
 * \param int age la edad a cargar en el employee
 * \return 0 if ok
 *
 */

int employee_setAge(Employee* this,int age)
{

    this->age = age;
    return 0;
}
/** \brief obtiene la edad del employee pasado
 *
 * \param this el employee a obtener la edad
 * \return int age la edad del employee
 *
 */

int employee_getAge(Employee* this)
{
    return this->age;
}
/** \brief guarda el tipo de trabajo pasado en el employee que se le diga
 *
 * \param Employee* this el empleado a cargar el tipo de trabajo
 * \param int type el tipo de trabajo a cargar en el employee
 * \return 0 if ok
 *
 */

int employee_setType(Employee* this,int type)
{

    this->type = type;
    return 0;
}
/** \brief obtiene el tipo de trabajo del employee pasado
 *
 * \param this el employee a obtener el tipo de trabajo
 * \return int type el tipo de trabajo del employee
 *
 */

int employee_getType(Employee* this)
{
    return this->type;
}
/** \brief encuentra un employee por id dentro del arraylist
 *
 * \param ArrayList* nominaEmployee la lista a buscar el employee
 * \param id el id a buscar
 * \return Employee* el employee con ese id, NULL si no se encontro
 *
 */

Employee* employee_findById(ArrayList* nominaEmployee, int id)
{
    int i;
    Employee* auxEmployee;
    void* retorno=NULL;

    for(i=0;i<al_len(nominaEmployee);i++)
    {
        auxEmployee = al_get(nominaEmployee,i);
        if(id == auxEmployee->id)
        {
            retorno = auxEmployee;
            break;
        }
    }

    return retorno;
}

/** \brief imprime el employee que se le pasa
 *
 * \param void* pEmployee el employee a imprimir
 * \return void
 *
 */

void employee_print(void* pEmployee)
{
    printf("ID: %d - NAME: %s - LAST NAME: %s - AGE: %d - TYPE: %d\n",employee_getId(pEmployee), employee_getName(pEmployee), employee_getLastName(pEmployee), employee_getAge(pEmployee), employee_getType(pEmployee));
}

/** \brief determina si el employee que se le pasa cumple el filtro
 *
 * \param void* item el employee a juzgar
 * \return 0 si no cumple el filtro, 1 si lo cumple
 *
 */

int employee_filterEmployee(void* item)
{
    int retorno=0;
    if((employee_getAge((Employee*)item))>=30 && (employee_getType((Employee*)item))== EMPLOYEE_TYPE_PROGRAMMER)
    {
        retorno=1;
    }
    else if((employee_getAge((Employee*)item))<30 && (employee_getType((Employee*)item))!= EMPLOYEE_TYPE_PROGRAMMER )
    {
        retorno=0;
    }

    return retorno;
}




