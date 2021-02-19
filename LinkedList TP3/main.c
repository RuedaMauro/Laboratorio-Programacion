#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/* ***************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
**************************************************** */


int main()
{
    LinkedList* miLista;
    int opcion;
    int exito;

    miLista = ll_newLinkedList();//constructor

    do
    {
        printf("\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("10. Salir\n");
        printf("\nElija una opcion:");

        scanf("%d",&opcion);

        while(opcion<1 || opcion>10)
        {
            printf("\nError, reingrese la opcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:

                    exito=controller_loadFromText("data.csv" , miLista);

                     if(exito==1)
                    {
                        printf("\nCarga exitosa\n");

                    }else
                    {
                        printf("\nArchivo Inexistene\n");
                    }
            break;

            case 2:
                    exito=controller_loadFromBinary("data.dat" , miLista);

                     if(exito==1)
                    {
                         printf("\nCarga exitosa\n");

                    }else
                    {
                       printf("\nArchivo Inexistene, se creara un archivo\n");
                    }
            break;

            case 3:
                    controller_addEmployee(miLista);
            break;

            case 4:
                    controller_editEmployee(miLista);
            break;

            case 5:
                    controller_removeEmployee(miLista);
            break;

            case 6:
                    controller_ListEmployee(miLista);
            break;

            case 7:
                    controller_sortEmployee( miLista);
            break;

            case 8:
                    exito=controller_saveAsText("data.csv" , miLista);

                    if(exito==1)
                    {
                        printf("\nGuardado con exito\n");

                    }else
                    {
                       printf("\nNo se pudo mostrar\n");
                    }
            break;

            case 9:
                    exito=controller_saveAsBinary("data.dat" , miLista);
                    if(exito==1)
                    {
                        printf("\nGuardado con exito\n");

                    }else
                    {
                       printf("\nNo se pudo mostrar\n");
                    }

            break;

            case 10:
                    printf("\nFinalizado\n");
            break;

        }


    }while(opcion!=10);

    return 0;
}
