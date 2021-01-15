#include "ArrayEmployees.h"
#include <string.h>
#define TAM 2

int initEmployee(eEmployee iEmployee[])
{
    int index=-1;
    int i;

    for(i=0;i<TAM;i++)
    {
        if(iEmployee[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }

    return index;
}

void spaceFreeForAddEmployee(eEmployee employee[], int aumentoDeId)
{
    int i;
    i = initEmployee(employee);

    if(i!=-1)
    {
       employee[i] = addEmployees();
       employee[i].id = employee[i].id + aumentoDeId;

       printf("\nEmpleado agregadado con exito...!!!\n");
    }
    else
    {
        printf("\nNo hay mas espacio para agregar otro empleado!!!... :(\n");
    }
}

eEmployee addEmployees()
{
   eEmployee empleado;

    empleado.id = -1;
    printf("Ingrese el nombre del empleado: ");
    fflush(stdin);
    scanf("%[^\n]", empleado.name);
    printf("Ingrese el apellido del empleado: ");
    fflush(stdin);
    scanf("%[^\n]", empleado.lastName);
    printf("Ingrese el salario del empleado: ");
    scanf("%f", &empleado.salary);
    printf("Ingrese el sector del empleado: ");
    scanf("%d", &empleado.sector);

    empleado.isEmpty=0;

    return empleado;

}


void findEmployeeById(eEmployee modificarEmpleado[], int cantidad)
{
    int i;
    for(i=0; i<cantidad;i++)
    {
        if(modificarEmpleado[i].isEmpty == 0)
        {
            printEmployees(modificarEmpleado, cantidad);

            int respuesta, dato;

            printf("\nIngrese el numero de id para modificar los datos del empleado: ");
            scanf("%d", &respuesta);

            for(i=0; i<cantidad;i++)
            {
                if(respuesta == modificarEmpleado[i].id)
                {
                    printf("Seleccione el dato que desea modificar: \n");
                    printf("1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n5.VOLVER?\n");
                    scanf("%d", &dato);

                    switch(dato)
                    {
                        case 1:
                            printf("Ingrese el nuevo nombre del empleado: ");
                            fflush(stdin);
                            scanf("%[^\n]", modificarEmpleado[i].name);
                            printf("\nExito!!!...nombre modificado.\n");
                            break;
                        case 2:
                            printf("Ingrese el nuevo apellido del empleado: ");
                            fflush(stdin);
                            scanf("%[^\n]", modificarEmpleado[i].lastName);
                            printf("\nExito!!!...apellido modificado.\n");
                            break;
                        case 3:
                            printf("ingrese el nuevo salario del empleado: ");
                            scanf("%f", &modificarEmpleado[i].salary);
                            printf("\nExito!!!...salario del  empleado modificado.\n");
                            break;
                        case 4:
                            printf("ingrese el nuevo sector del empleado: ");
                            fflush(stdin);
                            scanf("%d", &modificarEmpleado[i].sector);
                            printf("\nExito!!!...sector del empleado modificado.\n");
                            break;
                        case 5:
                            break;

                        default:
                            printf("\nError 404 not found!!! :(\nIngrese una opcion valida...");
                            scanf("%d", &dato);
                    }
                }
            }
        }else{
            printf("\nError!!!...Aun no se han cargado empleados.\n");
            break;
        }
    }
}

int removeEmployee(eEmployee eliminarEmpleado[], int cantidad)
{
    int id;

    for(int i=0;i<cantidad;i++)
    {
        if(eliminarEmpleado[i].isEmpty==0)
        {
            printEmployees(eliminarEmpleado, cantidad);

            printf("\nIngrese el ID del empleado al cual desea eliminar:\n");
            scanf("%d", &id);


            if(eliminarEmpleado[i].isEmpty == 1)
            {
                printf("\nEmpleado no encontrado...! :(\n");
                break;
            }else{
                    if(eliminarEmpleado[i].id==id)
                    {
                        eliminarEmpleado[i].isEmpty=1;
                        printf("\nEmpleado eliminado con exito...! :D\n");
                        break;
                    }
            }
        }else{
                printf("\nError!!!...Aun no se han cargado empleados.\n");
                printf("\n");
                break;
        }
    }
    return 0;
}


int sortEmployee(eEmployee apellidosDeEmpleados[], int cant)
{
    eEmployee auxApellidosDeEmpleados;

    int i,j;

    for(i=0;i<cant;i++)
    {
        for(j=i;j<cant;j++)
        {
            if(apellidosDeEmpleados[i].isEmpty == 0 && apellidosDeEmpleados[j].isEmpty==0)
            {
                if(strcmp(apellidosDeEmpleados[i].lastName, apellidosDeEmpleados[j].lastName)>0)
                {
                    auxApellidosDeEmpleados = apellidosDeEmpleados[j];
                    apellidosDeEmpleados[j] = apellidosDeEmpleados[i];
                    apellidosDeEmpleados[i] = auxApellidosDeEmpleados;
                }
            }
        }

    }
    return 0;
}

int printEmployees(eEmployee listOfEmployees[], int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(listOfEmployees[i].isEmpty==0)
        {
            sortEmployee(listOfEmployees, cantidad);

            printf("\n*******************************************************\n");
            printf("|                  LISTA DE EMPLEADOS                 |\n");
            printf("*******************************************************\n");
            printf("|  NOMBRE  |  APELLIDO  |  SALARIO  |  SECTOR  |  ID  |\n");
            printf("*******************************************************\n");

            for(i=0; i<cantidad;i++)
                {
                    if(listOfEmployees[i].isEmpty==0)
                    {
                        printf("|%7s %11s %14.2f %7d %8d  |\n", listOfEmployees[i].name , listOfEmployees[i].lastName, listOfEmployees[i].salary, listOfEmployees[i].sector, listOfEmployees[i].id);
                              printf("-------------------------------------------------------\n");
                    }
                }
                printf("*******************************************************\n");

        }else{
            printf("\nError!!!...Aun no se han cargado empleados.\n");
            printf("\n");
            break;

        }
    }
    return 0;
}


