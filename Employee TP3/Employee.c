#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>

int employee_setId(Employee* this,int id)
{
    int setId = 0;
    if(this!=NULL && id > 0)
    {
        this->id = id;
        setId = 1;
    }

    return setId;
}
int employee_getId(Employee* this,int* id)
{
    int getId = 0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        getId = 1;
    }
    return getId;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int setNombre = 0;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        setNombre = 1;
    }
    return setNombre;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int getNombre = 0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        getNombre = 1;
    }
    return getNombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setHorasTrabajadas = 0;
    if(this!=NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        setHorasTrabajadas = 1;
    }
    return setHorasTrabajadas;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getHorasTrabajadas = 0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        getHorasTrabajadas = 1;
    }
    return getHorasTrabajadas;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int setSueldo = 0;
    if(this!=NULL && sueldo!=NULL)
    {
        this->sueldo = sueldo;
        setSueldo = 1;
    }
    return setSueldo;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int getSueldo = 0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        getSueldo = 1;
    }
    return getSueldo;
}

int employee_CompareByName(void* e1, void* e2)
{

    Employee* empleado1;
    Employee* empleado2;

    char auxNombre1[20];
    char auxNombre2[20];

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getNombre(empleado1,auxNombre1);
    employee_getNombre(empleado2,auxNombre2);

    return strcmp(auxNombre1,auxNombre2);

}
int employee_CompareById(Employee* e1, Employee* e2)
{
    int compare=0;
    Employee* empleado1;
    Employee* empleado2;
    int auxId1;
    int auxId2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getId(empleado1,&auxId1);
    employee_getId(empleado2,&auxId2);

    if(auxId1>auxId2)
    {
        compare=1;

    }else
    {
        if(auxId1<auxId2)
        {
            compare=-1;
        }
    }

    return compare;
}


int employee_CompareBySalary(void* e1, void* e2)
{
    int compare=0;
    Employee* empleado1;
    Employee* empleado2;
    int auxSueldo1;
    int auxSueldo2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getSueldo(empleado1,&auxSueldo1);
    employee_getSueldo(empleado2,&auxSueldo2);


    if(auxSueldo1>auxSueldo2)
    {
        compare=1;

    }else
    {
        if(auxSueldo1<auxSueldo2)
        {
            compare=-1;
        }
    }

    return compare;
}


int employee_CompareByHorasTrabajadas(void* e1, void* e2)
{
    int compare=0;
    Employee* empleado1;
    Employee* empleado2;
    int auxHoras1;
    int auxHoras2;

    empleado1=(Employee*)e1;
    empleado2=(Employee*)e2;

    employee_getHorasTrabajadas(empleado1,&auxHoras1);
    employee_getHorasTrabajadas(empleado2,&auxHoras2);


    if(auxHoras1>auxHoras2)
    {
        compare=1;

    }else
    {
        if(auxHoras1<auxHoras2)
        {
            compare=-1;
        }
    }

    return compare;
}


Employee* employee_new()
{
    Employee* pListEmployees;;

    pListEmployees= (Employee*) malloc(sizeof(Employee));

    return pListEmployees;

}



Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmpleado;

    pEmpleado = employee_new();

    if(pEmpleado!=NULL)
    {
        employee_setNombre(pEmpleado,nombreStr);
        employee_setHorasTrabajadas(pEmpleado,atoi(horasTrabajadasStr));
        employee_setSueldo(pEmpleado,atoi(idStr));
    }

    return pEmpleado;
}
/*
void employee_delete()
{
    Employee* aux;
    LinkedList* miLista;

    miLista = ll_newLinkedList();

    int index;

    printf("\nLISTA DE EMPLEADOS ELIMINADOS\n");

    for(int i=0;i<len;i++)
    {
        aux = (Employee*) ll_get(miLista, i);
        printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
    }

}
*/
int employee_searchIdEmployee(LinkedList* pArrayListEmployee, int auxId)
{
    int len;
    int i;
    Employee* auxEmpleado;
    int idEmpleado;
    int index=-1;

    len=ll_len(pArrayListEmployee);


    for(i=0;i<len;i++)
    {
        auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
        idEmpleado=auxEmpleado->id;
        employee_getId(auxEmpleado,&idEmpleado);

       if(auxId==idEmpleado)
       {
            index=i;
            break;

       }
    }

    return index;
}
