#include <stdio.h>

typedef struct{

int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}eEmployee;


int initEmployee(eEmployee iEmployee[]);
void spaceFreeForAddEmployee(eEmployee employee[], int aumentoDeId);
eEmployee addEmployees();
int printEmployees(eEmployee listOfEmployees[], int cantidad);
int sortEmployee(eEmployee apellidosDeEmpleados[], int cant);
void findEmployeeById(eEmployee modificarEmpleado[], int cantidad);
int removeEmployee(eEmployee eliminarEmpleado[], int cantidad);
