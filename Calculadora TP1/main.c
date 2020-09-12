/*1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/


#include <stdio.h>
#include <stdlib.h>
#include "Fcalculator.h"

int main()
{
    int opcion;
    char opcionCalculo;
    float primerOperandoIngresado;
    float segundoOperandoIngresado;
    float suma;
    float resta;
    float division;
    int multiplicacion;
    int factorial;
    int factorialNumeroDos;
    int banderaResultados;

    banderaResultados=0;

    do
    {   printf(".-------------------------------------------------.\n");
        printf("|                 CALCULADORA    (9-.-)9          |\n");
        printf(".-------------------------------------------------.\n");
        printf("°°°°°°°°°°°°°°°°°°°°°MENU°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
        printf(".-------------------------------------------------.\n");

        printf("1) Ingrese el primer operando (A=x)\n2) Ingrese el segundo operando (B=y)\n3) Calcular todas las operaciones\n4) Informar resultados\n5) Salir.\n");
        fflush(stdin);
        scanf("%d", &opcion);

        while(opcion>5 || opcion<0)
        {
          printf("Error, Seleccione una opcion valida entre (1 y 5)\n");
          fflush(stdin);
          scanf("%d", &opcion);
        }

        switch(opcion)
        {
            case 1:
                printf("Primer operador:");
                fflush(stdin);
                scanf("%f", &primerOperandoIngresado);
                printf("Listo, primer operando ingresado. :D\n");
                break;
            case 2:
                printf("Segundo operando:");
                fflush(stdin);
                scanf("%f", &segundoOperandoIngresado);
                printf("Listo, segundo operando ingresado. :D\n");
                break;
            case 3:
                printf("a) Calcular la suma (%.2f+%.2f)\nb) Calcular la resta (%.2f-%.2f)\nc) Calcular la division (%.2f/%.2f)\nd) Calcular la multiplicacion (%.2f*%.2f)\ne) Calcular el factorial (%.2f!) y (%.2f!)\n", primerOperandoIngresado, segundoOperandoIngresado, primerOperandoIngresado, segundoOperandoIngresado, primerOperandoIngresado, segundoOperandoIngresado,primerOperandoIngresado, segundoOperandoIngresado,primerOperandoIngresado, segundoOperandoIngresado);
                suma = sumaDeOperandos(primerOperandoIngresado, segundoOperandoIngresado);
                resta = restaDeOperandos(primerOperandoIngresado, segundoOperandoIngresado);
                division = divisionDeOperandos(primerOperandoIngresado, segundoOperandoIngresado);
                multiplicacion = multiplicacionDeOperandos(primerOperandoIngresado, segundoOperandoIngresado);
                factorial = factorialDelNumero(primerOperandoIngresado);
                factorialNumeroDos = factorialDelNumero(segundoOperandoIngresado);
                break;
            case 4:
                banderaResultados=1;
                break;
        }
        if(banderaResultados==1)
        {
            banderaResultados=0;

            printf("El resultado de (%.2f+%.2f) es %2.f\n", primerOperandoIngresado, segundoOperandoIngresado,suma);
            printf("El resultado de (%.2f - %.2f) es %.2f\n", primerOperandoIngresado, segundoOperandoIngresado, resta);
            printf("El resultado de (%.2f/%.2f) es %.2f\n", primerOperandoIngresado, segundoOperandoIngresado, division);
            printf("El resultado de (%.2f*%.2f) es %d\n", primerOperandoIngresado, segundoOperandoIngresado, multiplicacion);
            printf("El factorial de (%.2f) es: %d ,El factorial de (%.2f) es:%d \n", primerOperandoIngresado, factorial, segundoOperandoIngresado, factorialNumeroDos);

        }
    }while(opcion!=5);

    printf("Gracias por usar la app!!!. 6(n_n)9\n");
    return 0;
}


