#include "Fcalculator.h"

float sumaDeOperadores(float primerOperador, float segundoOperador) // funcion para sumar los operadores
{
    float suma;

    suma  = primerOperador + segundoOperador;

    printf("(%.2f+%.2f=%2.f)\n", primerOperador, segundoOperador,suma);
    return suma;
}

float restaDeOperadores(float primerOperador, float segundoOperador) // funcion para restar los operadores
{
    float resta;
    resta = primerOperador - segundoOperador;

    printf("(%.2f - %.2f)=%.2f\n", primerOperador, segundoOperador, resta);

    return resta;
}

float divisionDeOperadores(int primerOperador, float segundoOperador) // funcion para dividir los operadores
{
    float division;

    if(primerOperador==0 || segundoOperador==0)
    {
        printf("No es posible dividir por 0 \n");
    }
    else
    {
        division = primerOperador / segundoOperador;

        printf("(%d/%.2f)=%.2f\n", primerOperador, segundoOperador, division);

        return division;
    }

}

int multiplicacionDeOperadores(int primerOperador, int segundoOperador) // funcion para multiplicar los operadores
{
    int multiplicacion;
    multiplicacion = primerOperador * segundoOperador;

    printf("(%d*%d)=%d\n", primerOperador, segundoOperador, multiplicacion);

    return multiplicacion;
}
int factorialPrimerNumero(int primerOperador) // funcion para obtener el factorial de los operadores
{
    int producto;

    producto=1;

    while(primerOperador >1)
    {
        producto*=primerOperador;
        primerOperador--;
    }

    printf(" es:%d \n", producto);

    return producto;
}
