#include "libreriamascotas.h"


eListadoMascotas altaMascota()
{
    eListadoMascotas mascotas;

    mascotas.idMascota = 104;
    printf("Ingrese el legajo de la mascota (6 a 10): ");
    scanf("%d", &mascotas.legajoDeLaMascota);

    while(mascotas.legajoDeLaMascota<6 || mascotas.legajoDeLaMascota>10){
    printf("Error!!!, ingrese el legajo de la mascotas solo (6 a 10): ");
    scanf("%d", &mascotas.legajoDeLaMascota);
    }

    printf("Ingrese el nombre de la mascota: ");
    fflush(stdin);
    scanf("%[^\n]", mascotas.nombre);
    printf("Ingrese el tipo de la mascota (ej: Perro,Gato,Mono): ");
    fflush(stdin);
    scanf("%[^\n]", mascotas.tipo);
    printf("Ingrese la edad de la mascota (0 a 100): ");
    scanf("%d", &mascotas.edad);

    while(mascotas.edad<0 || mascotas.edad>10){
    printf("Error!!!, reingrese una edad válida de la mascota (0 a 100): ");
    scanf("%d", &mascotas.edad);
    }

    printf("Ingrese el sexo de la mascota (F: Femenino, M: Masculino): ");
    fflush(stdin);
    scanf("%s", mascotas.sexo);

/*    while(mascotas.sexo!="f"|| mascotas.sexo!="m"){
    printf("Error!!!, reingrese el sexo de la mascota (F: Femenino, M: Masculino): ");
    scanf("%s", mascotas.sexo);
    }
    */

    printf("Ingrese el peso de la mascota: ");
    scanf("%d", &mascotas.pesoDeLaMascota);

    mascotas.isEmptyM=0;

    return mascotas;
}

eListadoRazas altaRaza()
{
    eListadoRazas razas;

    razas.idMascota = 104;
    printf("Ingrese la descripcion de la mascota (ej: Grande, Chico, Mediano): ");
    fflush(stdin);
    scanf("%[^\n]", razas.descripcion);
    printf("Ingrese el pais de origen: ");
    fflush(stdin);
    scanf("%[^\n]", razas.paisDeOrigen);

    razas.isEmptyR=0;

    return razas;

}

/** \brief Funcion para ver si hay algun espacio libre en la lista de mascotas
 *
 * \param lMascotas[] eListadoMascotas
 * \return void
 *
 */
int buscarEspacioLibreMascotas(eListadoMascotas lMascotas[])
{
    int index2=-1;
    int j;
    for(j=5;j<10;j++)
    {
        if(lMascotas[j].isEmptyM==1)
        {
            index2 = j;
            break;
        }
    }

    return index2;
}

int buscarEspacioLibreRazas(eListadoRazas lrazas[])
{
    int index=-1;
    int i;

    for(i=5;i<10;i++)
    {
        if(lrazas[i].isEmptyR==1)
        {
            index = i;
            break;
        }
    }

    return index;
}



void cargaDeM(eListadoMascotas cargaM[], eListadoRazas cargaC[], int aumentoDeId)
{
    int i;
    int j;

    i = buscarEspacioLibreMascotas(cargaM);
    j = buscarEspacioLibreRazas(cargaC);


    if(i!=-1 && j!=-1)
    {
       cargaM[i]=altaMascota();
       cargaC[j]=altaRaza();
       cargaM[i].idMascota = cargaM[i].idMascota + aumentoDeId;
       cargaC[j].idMascota = cargaC[j].idMascota + aumentoDeId;
    }
    else
    {
        printf("No hay mas espacio\n");
    }
}

void EliminarMascota(eListadoMascotas altaListaMascota[], eListadoRazas altaListaRazas[], int cant)
{
    int legajo;

    listaDeMascotasConDescripcion(altaListaMascota, altaListaRazas, 10);

    printf("\nIngrese el legajo de la mascota a la cual desea eliminar:\n");
    scanf("%d", &legajo);

    for(int i=0;i<cant;i++)
    {
        if(altaListaMascota[i].isEmptyM == 1)
        {
            printf("\nMascota no encontrada...! :(\n");
            break;
        }else{
                if(altaListaMascota[i].legajoDeLaMascota==legajo)
                {
                    altaListaMascota[i].isEmptyM=1;
                    altaListaRazas[i].isEmptyR=1;
                    printf("\nMascota eliminada con exito...! :D\n");
                    break;
                }
        }
    }
}



void OrdenamientoDePesoMascotas()
{

}
