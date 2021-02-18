#include <stdlib.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

}

int employee_setId(Employee* this,int id)
{
    if(this!=NULL && id>0){
    this->id=id;
    }
}
int employee_getId(Employee* this,int* id)
{
    int getId = 0;

    if(this!=NULL && id!=NULL){
        *id = this->id;
        getId = 1;
    }
    return getId;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL){
        strcpy(this->nombre,nombre);
    }
}
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL && nombre!=NULL){
        strcpy(nombre,this->nombre);
    }
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL && horasTrabajadas > 0){
        this->horasTrabajadas=horasTrabajadas;
    }
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL && horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
    }
}
int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL && sueldo>0){
        this->sueldo = sueldo;
    }
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this!=NULL && sueldo!=NULL){
        *sueldo=this->sueldo;
    }
}
int employee_CompareByName(Employee* e1, Employee* e2)
{

}
int employee_CompareById(Employee* e1, Employee* e2)
{

}
