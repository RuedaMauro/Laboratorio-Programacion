#include <stdio.h>
#include "Fcalculator.h"

int main()
{
    int opcion;
    float primerOperadorIngresado;
    float segundoOperadorIngresado;
    float suma;
    float resta;
    float division;
    int multiplicacion;
    int factorial;

    do
    {

        printf("Hola! elija la operacion que desea realizar: \n");
        printf("1) Sumar \n2) Restar \n3) Multiplicar \n4) Dividir\n5) Factorial\n6)Salir.\n");
        scanf("%d", &opcion);

        if(opcion!=6)
        {
            printf("Ingrese el primer operador: ");
            scanf("%f", &primerOperadorIngresado);

            printf("Ingrese el segundo operador: ");
            scanf("%f", &segundoOperadorIngresado);
        }

        switch(opcion)
        {
            case 1:
                suma = sumaDeOperadores(primerOperadorIngresado, segundoOperadorIngresado);
            break;
            case 2:
                resta = restaDeOperadores(primerOperadorIngresado, segundoOperadorIngresado);
            break;
            case 3:
                multiplicacion = multiplicacionDeOperadores(primerOperadorIngresado, segundoOperadorIngresado);
            break;
            case 4:
                division = divisionDeOperadores(primerOperadorIngresado, segundoOperadorIngresado);
            break;
            case 5:
                printf("El factorial de A)%2.f", primerOperadorIngresado);
                factorial = factorialPrimerNumero(primerOperadorIngresado);
                printf("El factorial de B)%2.f", segundoOperadorIngresado);
                factorial = factorialPrimerNumero(segundoOperadorIngresado);
                break;
            case 6:
                printf("Gracias por usar la app!");
                break;

        }

    }while(opcion!=6);


    return 0;

}
