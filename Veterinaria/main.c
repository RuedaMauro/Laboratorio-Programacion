/*
Soy un veterinario que necesita atender a las mascotas de sus clientes, para tener el
control vamos a tener un sistema ....el sistema debe realizar las siguientes
funcionalidades.(los datos deben ser hardcodeados).
******************************** 1era parte
#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas ​pero tengo lugar para 10.
#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de
origen)
listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica
las 5 mascotas están formadas por los siguientes datos:
a- 3 gatos
b- 2 perros
c- los demás datos deben ser hardcodeados por el alumno.
1-Se debe mostrar un listado de mascotas con sus razas y países de origen .

Punto 2:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 10
#include "libreriamascotas.h"
#include "libreriaedos.h"



int main()
{

   system("color 5f");
   printf("Parcial de Laboratorio\n");
   system("pause");


   eListadoMascotas cargaDeMascotas[TAM];
   eListadoRazas cargaDeRazas[TAM];

   hardcodeoDeListadoMascotas(cargaDeMascotas);
   hardcodeoListadoDeRazas(cargaDeRazas);

   int opcion;
   int i;
   int id=0;

   for(i=5;i<10;i++)
   {
        cargaDeMascotas[i].isEmptyM = 1;
        cargaDeRazas[i].isEmptyR = 1;
   }

   do{
        printf("\nMENU\n");
        printf("Selecciona una opcion:\n");
        printf("1.ALTA\n");
        printf("2.MOSTRAR LISTA DE MASCOTAS\n");
        printf("3.MODIFICAR DATOS DE ALGUNA MASCOTA INGRESADA.\n");
        printf("4.ELIMINAR MASCOTA.\n");
        printf("5.SALIR.\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                id++;
                cargaDeM(cargaDeMascotas,cargaDeRazas, id);
                break;
            case 2:
                listaDeMascotasConDescripcion(cargaDeMascotas, cargaDeRazas, TAM);
                break;
            case 3:
                break;
            case 4:
                EliminarMascota(cargaDeMascotas,cargaDeRazas,TAM);
                break;
        }

   }while(opcion!=5);


   return 0;
}

