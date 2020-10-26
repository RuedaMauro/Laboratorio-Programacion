#include <stdio.h>

typedef struct
{
    int legajoDeLaMascota;
    int idMascota;
    char nombre[20];
    int edad;
    char sexo[3];
    char tipo[30];
    int pesoDeLaMascota;
    int isEmptyM;


}eListadoMascotas;

typedef struct
{
    int idMascota;
    char descripcion[20];
    char paisDeOrigen[20];
    int isEmptyR;

}eListadoRazas;


void hardcodeoDeListadoMascotas(eListadoMascotas lista[]);
void hardcodeoListadoDeRazas(eListadoRazas lRazas[]);
int buscarEspacioLibreMascotas(eListadoMascotas lMascotas[]);
int buscarEspacioLibreRazas(eListadoRazas lrazas[]);
eListadoMascotas altaMascota();
eListadoRazas altaRaza();
void cargaDeM(eListadoMascotas cargaM[], eListadoRazas cargaC[], int aumentoDeId); // carga de mascotas y raza, revisar
void listaDeMascotasConDescripcion(eListadoMascotas listaMascotas[], eListadoRazas listaRazas[], int cantidad);
void EliminarMascota(eListadoMascotas altaListaMascota[], eListadoRazas altaListaRazas[], int cant);
