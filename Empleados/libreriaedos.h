#include <stdio.h>

int buscarEspacioLibreMascotas(eListadoMascotas lMascotas[]);
eListadoMascotas altaMascota();
eListadoRazas altaRaza();
void cargaDeM(eListadoMascotas cargaM[], eListadoRazas cargaC[], int aumentoDeId); // carga de mascotas y raza, revisar
void mostrarLista(eListadoMascotas altaListaMascota[], eListadoRazas altaListaRazas[], int cant); // muestra lista de mascotas ingresandos solo por el usuario
void listaDeMascotasConDescripcion(eListadoMascotas listaMascotas[], eListadoRazas listaRazas[], int cantidad);

void EliminarMascota(eListadoMascotas altaListaMascota[], eListadoRazas altaListaRazas[], int cant);
