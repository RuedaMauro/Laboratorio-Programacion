#include "libreriamascotas.h"

/** \brief Funcion para realizar el hardcodeo de la lista de mascotas del punto uno del parcial
 *
 * \param  Recibe como parametro a la estructura Elistado Mascotas para acceder a los campos de la misma  * \
 *
 */
void hardcodeoDeListadoMascotas(eListadoMascotas lista[])
{

    int legajo[5]={1,2,3,4,5};
    char nombre[5][30]={"Ybi","Godzilla","Rex","Nishi","Linu"};
    int edad[5]={6,6,5,5,1};
    char sexo[5][3]={"F","F","M","M","M"};
    char tipo[5][20]={"Siames","Doberman","Persa","Pastor Belga","Gallo"};
    int id[5]={100,101,102,103,104};
    int isEmptyM[5]={0,0,0,0,0};

    for(int i=0;i<5;i++)
    {
        lista[i].legajoDeLaMascota=legajo[i];
        lista[i].idMascota=id[i];
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].edad=edad[i];
        strcpy(lista[i].sexo,sexo[i]);
        strcpy(lista[i].tipo,tipo[i]);
        lista[i].isEmptyM=isEmptyM[i];
    }
}
/** \brief Funcion para harcodear las lista de razas punto uno del parcial
 *
 * \param Recibe como parametro a la estructura eListadoRazas para acceder a los campos de la misma
 * \return void
 *
 */
void hardcodeoListadoDeRazas(eListadoRazas lRazas[])
{
    char descripcion[5][20]={"Chico","Grande","Mediano","Grande","Chico"};
    char paisDeOrige[5][20]={"Tailandia","Alemania","Persia","Belgica","Alemania"};
    int id[5]={100,101,102,103,104};
    int isEmptyR[5] ={0,0,0,0,0};

    for(int j=0;j<5;j++)
    {
        strcpy(lRazas[j].descripcion,descripcion[j]);
        strcpy(lRazas[j].paisDeOrigen,paisDeOrige[j]);
        lRazas[j].idMascota=id[j];
        lRazas[j].isEmptyR=isEmptyR[j];
    }


}
/** \brief Funcion para mostrar la lista de mascotas y lista de raza
 *
 * \param listaMascotas[] eListadoMascotas
 * \param listaRazas[] eListadoRazas
 * \return void
 *
 */
void listaDeMascotasConDescripcion(eListadoMascotas listaMascotas[], eListadoRazas listaRazas[], int cantidad)
{
    int i;

    printf("\n***********************************************************************************************************************\n");
    printf("|                                                LISTADO DE MASCOTAS                                                  |\n");
    printf("***********************************************************************************************************************\n");
    printf("LEGAJO          NOMBRE            EDAD           SEXO          TIPO         DESCRIPCION      PAIS DE ORIGEN      ID   |\n");
    printf("***********************************************************************************************************************\n");

    for(i=0; i<cantidad;i++)
        {
            if(listaMascotas[i].isEmptyM==0 && listaRazas[i].isEmptyR==0)
            {
                printf("%d %18s %15d %15s %15s", listaMascotas[i].legajoDeLaMascota , listaMascotas[i].nombre, listaMascotas[i].edad, listaMascotas[i].sexo, listaMascotas[i].tipo);

                if(listaMascotas[i].idMascota==listaRazas[i].idMascota)
                {
                    printf("%15s  %18s   %10d\n", listaRazas[i].descripcion, listaRazas[i].paisDeOrigen, listaMascotas[i].idMascota);
                      printf("----------------------------------------------------------------------------------------------------------------------\n");
                }
            }
        }

        printf("***********************************************************************************************************************\n");

}


