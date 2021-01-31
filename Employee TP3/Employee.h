#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int* idStr,char* nombreStr,int* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(Employee* e1, Employee* e2);

int employee_CompareBySalary(void* e1, void* e2);
int employee_CompareByHorasTrabajadas(void* e1, void* e2);
int employee_searchIdEmployee(LinkedList* pArrayListEmployee, int auxId);


#endif // employee_H_INCLUDED
