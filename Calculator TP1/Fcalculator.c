#include "Fcalculator.h"

float sumaDeOperandos(float primerOperando, float segundoOperando) // funcion para sumar los operadores
{
    float suma;

    suma  = primerOperando + segundoOperando;
    return suma;
}
float restaDeOperandos(float primerOperando, float segundoOperando) // funcion para restar los operadores
{
    float resta;
    resta = primerOperando - segundoOperando;

    return resta;
}
float divisionDeOperandos(int primerOperando, float segundoOperando) // funcion para dividir los operadores
{
    float division;

    if(primerOperando==0 || segundoOperando==0)
    {
        printf("No se puede dividir por 0\n");
    }
    else
    {
        division = primerOperando / segundoOperando;

        return division;
    }

}

int multiplicacionDeOperandos(int primerOperando, int segundoOperando) // funcion para multiplicar los operadores
{
    int multiplicacion;
    multiplicacion = primerOperando * segundoOperando;

    return multiplicacion;
}
int factorialDelNumero(int primerOperando) // funcion para obtener el factorial de los operadores
{
    int producto;

    producto=1;

    while(primerOperando >1)
    {
        producto*=primerOperando;

        primerOperando--;

    }
    return producto;
}
