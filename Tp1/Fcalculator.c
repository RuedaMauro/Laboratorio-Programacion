#include "Fcalculator.h"

float sumaDeOperadores(float primerOperador, float segundoOperador) // funcion para sumar los operadores
{
    float suma;
    
    suma  = primerOperador + segundoOperador;
    
    printf("La suma es:%.2f \n", suma);
    return suma;
}

float restaDeOperadores(float primerOperador, float segundoOperador) // funcion para restar los operadores
{
    float resta;
    resta = primerOperador - segundoOperador;
    
    printf("El resultado de la resta es:%.2f \n", resta);
    return resta;
}

float divisionDeOperadores(int primerOperador, float segundoOperador) // funcion para dividir los operadores
{
    float division;
    division = primerOperador / segundoOperador;
    
    printf("El resultado de la division es:%.2f \n", division);
    return division;
}

int multiplicacionDeOperadores(int primerOperador, int segundoOperador) // funcion para multiplicar los operadores
{
    int multiplicacion;
    multiplicacion = primerOperador * segundoOperador;
    
    printf("El resultado de la multiplicacion es:%d \n", multiplicacion);
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
    printf("El resultado del factorial es:%d \n", producto);

    return producto;
}