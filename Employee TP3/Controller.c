#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int exito=0;


    pFile=(FILE*)malloc(sizeof(FILE));

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"r");

        if(pFile!=NULL)
        {
            exito=parser_EmployeeFromText(pFile , pArrayListEmployee);

        }
    }

    return exito;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    int exito=0;

   // pFile=(FILE*)malloc(sizeof(FILE));

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"rb");

        if(pFile!=NULL)
        {
            exito=parser_EmployeeFromBinary(pFile , pArrayListEmployee);


        }else
        {
            //printf("Archivo Inexistene, se creara un archivo\n");
            pFile=fopen(path,"wb");
            //fwrite(pArrayListEmployee, sizeof(LinkedList),1000,pFile);
        }
    }

    return exito;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char auxId[20];
    char auxNombre[128];
    char auxHorasTrabajadas[20];
    char auxSueldo[20];
    int exito=0;
    int len;
    int id;
    Employee* unEmpleado;

    len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        unEmpleado=employee_new();

        if(unEmpleado!=NULL)
        {
            id= len +2;
            employee_setId(unEmpleado,id);
            itoa(id,auxId,10);
            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]",auxNombre);

            printf("Ingrese sus horas realizadas: ");
            fflush(stdin);
            scanf("%[^\n]",auxHorasTrabajadas);

            printf("Ingrese su sueldo: ");
            fflush(stdin);
            scanf("%[^\n]",auxSueldo);

            unEmpleado=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);

            ll_add(pArrayListEmployee,unEmpleado);

            printf("\nEmpleado cargado exitosamente\n");
        }
        exito=1;
    }
    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int index;
    Employee* unEmpleado;
    int opcion;
    char auxNombre[20];
    int auxHorasTrabajo;
    int auxSueldo;


    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese el ID del Empleado a modificar: ");
        scanf("%d",&auxId);

      index= employee_searchIdEmployee(pArrayListEmployee,auxId);

      if(index!=-1)
      {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,index);
        printf("Que desea modificar?\n");
        printf("1.Nombre\n2.Horas trabajadas\n3.Sueldo\n");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>3)
        {
            printf("\nError, reingrese la opcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                    printf("Ingrese su nuevo nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]", auxNombre);
                    employee_setNombre(unEmpleado,auxNombre);
                    printf("\nNombre modificado con exito\n");

            break;

            case 2:
                    printf("Ingrese sus nuevas horas de trabajo: ");
                    scanf("%d", &auxHorasTrabajo);
                    employee_setHorasTrabajadas(unEmpleado,auxHorasTrabajo);
                    printf("\nHoras de Trabajo modificado con exito\n");

            break;

            case 3:
                    printf("Ingrese su nuevo sueldo: ");
                    scanf("%d", &auxSueldo);
                    employee_setSueldo(unEmpleado,auxSueldo);
                    printf("\nSueldo modificado con exito\n");

            break;

        }
      }
    }

    return index;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    Employee* auxEmpleado;
    int opcion;
    int index;



    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese el ID del Empleado a eliminar: ");
        scanf("%d",&auxId);

        printf("\nEsta seguro de eliminar al empleado %d ?\n",auxId);

        printf("1.s(Si)\n2.n(No)\n");
        printf("\nElija la opcion: ");
        scanf("%d",&opcion);

        while(opcion!=1 && opcion!=2)
        {
            printf("Error, reingrese la opcion:");
            printf("1.s(Si)\n2.n(No)\n");
            printf("\nElija la opcion: ");
            scanf("%d",&opcion);
        }

        if(opcion==1)
        {
            index=employee_searchIdEmployee(pArrayListEmployee,auxId);

            if(index!=-1)
            {
                auxEmpleado=ll_pop(pArrayListEmployee,index);
                printf("\nEmpleado eliminado correctamente\n");
                printf("%5d %10s %6d %6d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            }

        }else
        {
            printf("Eliminacion cancelada\n");
        }
    }
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int exito=0;
    int len;
    //Employee* unEmpleado;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[20];
    Employee* auxEmpleado;

    printf("\nID \t\tNOMBRE \tHORAS \tSUELDO\n\n");
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,auxNombre);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            printf("%2d %18s %7d %7d\n\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        }
        exito=1;
    }
    return exito;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;

    if(pArrayListEmployee!=NULL)
    {
        printf("\nComo le gustaria ordenar?\n");
        printf("\n1.Por Id ascendente\n2.Por Id descendente\n3.Por Nombre A->Z\n4.Por Nombre Z->A\n5.Por Sueldo ascendente\n6.Por Sueldo descendente\n7.Por Horas Trabajadas ascendente\n8.Por Horas Trabajadas descendente\n");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>8)
        {
            printf("\nError, reingrese la opcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                    ll_sort(pArrayListEmployee,employee_CompareById,1);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 2:
                    ll_sort(pArrayListEmployee,employee_CompareById,0);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 3:
                    ll_sort(pArrayListEmployee,employee_CompareByName,1);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 4:
                    ll_sort(pArrayListEmployee,employee_CompareByName,0);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 5:
                    ll_sort(pArrayListEmployee,employee_CompareBySalary,1);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 6:
                    ll_sort(pArrayListEmployee,employee_CompareBySalary,0);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 7:
                    ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,1);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;

            case 8:
                    ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,0);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;
        }
    }
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* Empleado;
    int len;
    int exito=0;
    int i;
    int auxId;
    char auxNombre[20];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<len;i++)
            {
                Empleado=(Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(Empleado,&auxId);
                employee_getNombre(Empleado,auxNombre);
                employee_getHorasTrabajadas(Empleado,&auxHorasTrabajadas);
                employee_getSueldo(Empleado,&auxSueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            }
            fclose(pFile);
        }
        exito=1;
    }

    return exito;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* Empleado;
    int len;
    int exito=0;
    int i;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0;i<len;i++)
            {
                Empleado= (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(Empleado,sizeof(Employee),1,pFile);
            }


            fclose(pFile);
        }

        exito=1;
    }

    return exito;

}

