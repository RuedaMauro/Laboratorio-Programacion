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
    int setId=0;

    if(this!=NULL && id>0){
    this->id=id;
    setId=1;
    }
    return setId;
}
int employee_getId(Employee* this,int* id)
{
    int getId=0;

    if(this!=NULL && id!=NULL){
        *id = this->id;
        getId=1;
    }
    return getId;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int setNombre=0;

    if(this!=NULL){
        strcpy(this->nombre,nombre);
        setNombre=1;
    }
    return setNombre;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int getNombre=0;

    if(this!=NULL && nombre!=NULL){
        strcpy(nombre,this->nombre);
        getNombre=1;
    }
    return getNombre;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int setHorasTrabajadas=0;

    if(this!=NULL && horasTrabajadas > 0){
        this->horasTrabajadas=horasTrabajadas;
        setHorasTrabajadas=1;
    }
    return setHorasTrabajadas;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int getHorasTrabajadas=0;

    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        getHorasTrabajadas=1;
    }
    return getHorasTrabajadas;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int setSueldo=0;

    if(this!=NULL && sueldo>0){
        this->sueldo = sueldo;
        setSueldo=1;
    }
    return setSueldo;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int getSueldo=0;

    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
        getSueldo=1;
    }
    return getSueldo;
}
int employee_CompareByName(Employee* e1, Employee* e2)
{

}
int employee_CompareById(Employee* e1, Employee* e2)
{

}
