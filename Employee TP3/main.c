#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int main()
{
    Employee* listaDeEmpleados;
    int respuesta;
    int exito;

    system("color 5f");
    printf("Parcial de programacion\n");
    system("pause");

    listaDeEmpleados = ll_newLinkedList();

    do{
         printf("Menu:\n");
         printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
         printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
         printf("3. Alta de empleado\n");
         printf("4. Modificar datos de empleado\n");
         printf("5. Baja de empleado\n");
         printf("6. Listar empleados\n");
         printf("7. Ordenar empleados\n");
         printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
         printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
         scanf("%d", &respuesta);

         switch(respuesta)
            {
                case 1:
                    exito=controller_loadFromText("data.csv" , listaDeEmpleados);

                     if(exito==1)
                    {
                        printf("\nCarga exitosa\n");

                    }else
                    {
                        printf("\nArchivo Inexistene\n");
                    }
                    break;
                case 2:
                    exito=controller_loadFromBinary("data.dat" , listaDeEmpleados);

                     if(exito==1)
                    {
                         printf("\nCarga exitosa\n");

                    }else
                    {
                       printf("\nArchivo Inexistene, se creara un archivo\n");
                    }
                    break;
                case 3:
                    controller_addEmployee(listaDeEmpleados);
                    break;
                case 4:
                    controller_editEmployee(listaDeEmpleados);
                    break;
                case 5:
                    controller_removeEmployee(listaDeEmpleados);
                    break;
                case 6:
                    controller_ListEmployee(listaDeEmpleados);
                    break;
                case 7:
                    controller_sortEmployee(listaDeEmpleados);
                    break;
                case 8:
                    exito=controller_saveAsText("data.csv" , listaDeEmpleados);

                    if(exito==1)
                    {
                        printf("\nGuardado con exito\n");

                    }else
                    {
                       printf("\nNo se pudo mostrar\n");
                    }
                    break;
                case 9:
                     exito=controller_saveAsBinary("data.dat" , listaDeEmpleados);
                    if(exito==1)
                    {
                        printf("\nGuardado con exito\n");

                    }else
                    {
                       printf("\nNo se pudo mostrar\n");
                    }
                    break;
                case 10:
                    printf("Operacion realizada.\n");
                    break;
            }

    }while(respuesta!=10);
    return 0;
}
/*
    LinkedList* miLista;
    int len;

    miLista = ll_newLinkedList();

    Employee* aux;

    len = ll_len(miLista);

    printf("Cantidad: %d\n", len);


    Employee* e1;
    e1 = (Employee*) malloc (sizeof(Employee));
    e1->id=8;
    strcpy(e1->nombre,"Juan");
    e1->sueldo=500;
    e1->horasTrabajadas=10;
    printf("Cantidad: %d\n", len);

    Employee* e2;
    e2 = (Employee*) malloc (sizeof(Employee));
    e2->id=8;
    strcpy(e2->nombre,"Armando");
    e2->sueldo=500;
    e2->horasTrabajadas=10;
    printf("");

    ll_add(miLista,e1);
    ll_add(miLista,e2);
    len = ll_len(miLista);

    printf("Cantidad: %d\n", len);

    for(int i=0;i<len;i++)
    {
        aux = (Employee*) ll_get(miLista, i);
        printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
    }


    //----remove---

/* ll_remove(miLista,index -1);

    len = ll_len(miLista);
*/

    //----------------INDEXOF-------------------

/*    index = ll_indexOf(miLista, e1);
    printf("Indexof e1:%d\n", index);

    index = ll_indexOf(miLista, e2);
    printf("Indexof e2:%d\n", index);


    //---------------SET----------------

    ll_set(miLista,2,e2);

    len = ll_len(miLista);

    printf("LISTA REMPLAZANDO AL ULTIMO\n");

    for(int i=0;i<len;i++)
    {
        aux = (Employee*) ll_get(miLista, i);
        printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
    }


    //----------------------POP-----------------

    ll_pop(miLista, 3);


    len = ll_len(miLista);

    printf("Se elimino de la lista: %d) %4d %15s %4d %4d\n", aux->id, aux->nombre, aux->horasTrabajadas);

    for(int i=0;i<len;i++)
    {
        aux = (Employee*) ll_get(miLista, i);
        printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
    }

    //----------------------------SORT------------------------

        ll_sort(miLista, employee_CompareByName,1);

        printf("LISTA ORDENADA POR NOMBRE");

        len = ll_len(miLista);

      for(int i=0;i<len;i++)
        {
            aux = (Employee*) ll_get(miLista, i);
            printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
        }

        //-----------------PUSH-----------------

    ll_push(miLista,2,e2);

    len = ll_len(miLista);

      for(int i=0;i<len;i++)
        {
            aux = (Employee*) ll_get(miLista, i);
            printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
        }

 // -------------------------ADD-------------

        ll_add(miLista,e2);

        printf("LISTA REPETIDA POR NOMBRE");

        len = ll_len(miLista);

      for(int i=0;i<len;i++)
        {
            aux = (Employee*) ll_get(miLista, i);
            printf("%d) %4d %15s %4d %4d\n", i+1, aux->id, aux->nombre, aux->horasTrabajadas);
        }

    // --------------------------
    return 0;
}
*/
