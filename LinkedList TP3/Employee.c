#include <stdlib.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{
    Employee* pListEmployee;
    pListEmployee=(Employee*)malloc(sizeof(Employee));
    return pListEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;
    pEmployee=employee_new();

    if(pEmployee!=NULL){
        employee_setId(pEmployee,atoi(idStr));
        employee_setNombre(pEmployee,nombreStr);
        employee_setSueldo(pEmployee,atoi(horasTrabajadasStr));
        employee_setSueldo(pEmployee,atoi(sueldoStr));
    }
    return pEmployee;
}
int employee_setId(Employee* this,int id)
{
    int retorno=0;

    if(this!=NULL && id>0){
        this->id=id;
        retorno=1;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL){
        *id = this->id;
        retorno=1;
    }
    return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL){
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL){
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas > 0){
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo>0){
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}
int employee_CompareByName(void* e1, void* e2)
{
    char employee1[51];
    char employee2[51];
    int compare;
    if(e1!=NULL&&e2!=NULL){
        employee_getNombre(e1,employee1);
        employee_getNombre(e2,employee2);

        compare=strcmp(employee1,employee2);

    }
    return compare;
}
int employee_CompareById(void* e1, void* e2)
{
    Employee* employee1;
    Employee* employee2;
    int auxId1;
    int auxId2;
    int estado;

    employee1=(Employee*)e1;
    employee2=(Employee*)e2;

    if(employee1!=NULL && employee2!=NULL){
        employee_getId(e1,&auxId1);
        employee_getId(e2,&auxId2);
        if(employee1>employee2){
            estado=1;
        }else if(employee1==employee2){
            estado=0;
        }else{
            estado=-1;
        }
    }
    return estado;
}
