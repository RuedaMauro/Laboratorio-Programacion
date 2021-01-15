#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 2

int main()
{
   eEmployee cargaDeEmpleado[TAM];
   int opcion;
   int id;
   int i;
   int subMenu;

   for(i=0;i<TAM;i++)
   {
        cargaDeEmpleado[i].isEmpty = 1;
   }

   do{
        printf("\n--------------------------------------------------------------------------\n");
        printf("|************************************************************************|\n");
        printf("|************                TRABAJO PRACTICO 2               ***********|");
        printf("\n|************************************************************************|");
        printf("\n|*******************               MENU               *******************|");
        printf("\n|************************************************************************|\n");
        printf("|* Seleccione una opcion:                                               *|\n");
        printf("|*----------------------------------------------------------------------*|\n");
        printf("|* 1).DAR DE ALTA UN EMPLEADO                                           *|\n");
        printf("|* 2).MODIFICAR DATOS DE ALGUN EMPLEADO                                 *|\n");
        printf("|* 3).DAR DE BAJA UN EMPLEADO                                           *|\n");
        printf("|* 4).INFORMAR                                                          *|\n");
        printf("|* 5).SALIR                                                             *|\n");
        printf("|************************************************************************|\n");
        printf("--------------------------------------------------------------------------\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                id++;
                spaceFreeForAddEmployee(cargaDeEmpleado, id);
                break;
            case 2:
                findEmployeeById(cargaDeEmpleado, TAM);
                break;
            case 3:
                removeEmployee(cargaDeEmpleado, TAM);
                break;
            case 4:
                printf("1. LISTADO DE EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR.\n");
                printf("2. TOTAL Y PROMEDIO DE LOS SALARIOS, Y CUANTOS EMPLEADOS SUPERAN EL SALARIO PROMEDIO.\n");
                printf("3. VOLVER?.\n");
                scanf("%d", &subMenu);

                switch(subMenu)
                {
                    case 1:
                        printEmployees(cargaDeEmpleado,TAM);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;

                    default:
                        printf("Error!!!...Ingrese un opcion valida\n");
                        break;
                }
                break;
            case 5:
                break;

            default:
                printf("Error!!! Ingrese una opcion valida...");
        }

   }while(opcion!=5);



}

// promedio de sueldo 37000

// sumar salarios | promedio | empleados que superan el promedio
