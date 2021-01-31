#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
   Employee* oneEmployee;
    char auxId[10];
    char auxNombre[128];
    char auxHorasTrabajadas[10];
    char auxSueldo[10];
    int leidos;
    int entro=0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        while(!feof(pFile))
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            if(leidos==4)
            {
                oneEmployee=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                ll_add(pArrayListEmployee, oneEmployee);
                entro=1;
            }
            if(feof(pFile))
            {
                break;
            }

        }

        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
        entro=1;
    }

    return entro;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    int bandera;
    int entro=0;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {

        while(!feof(pFile))
        {
            oneEmployee=employee_new();
            bandera=fread(oneEmployee,sizeof(Employee),1,pFile);
            if(bandera==1)
            {
                ll_add(pArrayListEmployee,oneEmployee);
            }

        }
        entro=1;
        fclose(pFile);
    }

    return entro;
}
