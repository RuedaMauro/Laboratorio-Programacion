/******************************************************************************
 * 
 * Rueda Mauro:
 * 
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

El programa EXCLUYE las operaciones con decimales.

*******************************************************************************/
#include <stdio_ext.h>

float sumaDeOperadores(float, float);
float restaDeOperadores(float, float);
float divisionDeOperadores(int, float);
int multiplicacionDeOperadores(int, int);
int factorialPrimerNumero(int);

int main()
{
    float primerOperadorIngresado;  
    float segundoOperadorIngresado;
    float suma;
    float resta;
    float division;
    int multiplicacion;
    int factorial;
    char respuesta;
    
    respuesta='S';
    
    while(respuesta=='S')
    {
        printf("Bienvenido, ingrese su primer operador: "); // mensaje que va a recibir el usuario para ingresar el primer operador 
        scanf("%f", &primerOperadorIngresado); // guardo el primer operador
        
        printf("Ingrese su segundo operador: "); // segundo mensaje que recibe el usuario para ingresar el segundo operador 
        scanf("%f", &segundoOperadorIngresado); // guardo el segundo operador
        
        
        if(primerOperadorIngresado ==0 || segundoOperadorIngresado ==0) // valido si el usuario ingreso 0 en algun operador
        {
            printf("No, es posible dividir por 0 \n"); // si es asi, muestro el mensaje que no es posible realizar esta operacion
        }
        else // sino es asi continua el programa normalmente
        {
            division = divisionDeOperadores(primerOperadorIngresado, segundoOperadorIngresado); // realizo la division y continuo con el programa 
        }
    
        printf("¿Desea agregar mas operadores? (S/N)"); // Preguntamos al usuario si quiere continuar usadon el programa
        __fpurge(stdin);
        scanf("%c", &respuesta);
        
    }   
        suma = sumaDeOperadores(primerOperadorIngresado, segundoOperadorIngresado); // llamada a la funcion para realizar la suma de los operadores
        printf("La suma de los dos operadores es:%.1f\n", suma);
        resta = restaDeOperadores(primerOperadorIngresado, segundoOperadorIngresado); // llamada a la funcion para realizar la resta de los operadores
        printf("La resta de los dos operadores es:%.1f\n", resta);
        printf("La division de los dos operadores es:%.2f\n", division);
        multiplicacion = multiplicacionDeOperadores(primerOperadorIngresado, segundoOperadorIngresado); // llamada a la funcion para multiplicar los operadores
        printf("La multiplicacion de los dos operadores es:%d\n", multiplicacion);
        factorial = factorialPrimerNumero(primerOperadorIngresado); // llamada a la funcion para sacar el factorial del primer operador
        printf("El factorial de el primer operador es:%d\n", factorial);
        factorial = factorialPrimerNumero(segundoOperadorIngresado); // llamada a la funcion para sacar el factorial del segundo operador
        printf("El factorial del segundo operador es:%d\n", factorial); 
        
        return 0;
     
}

float sumaDeOperadores(float primerOperador, float segundoOperador) // funcion para sumar los operadores
{
    float suma;
    suma  = primerOperador + segundoOperador;
    return suma;
}

float restaDeOperadores(float primerOperador, float segundoOperador) // funcion para restar los operadores
{
    float resta;
    resta = primerOperador - segundoOperador;
    return resta;
}

float divisionDeOperadores(int primerOperador, float segundoOperador) // funcion para dividir los operadores
{
    float division;
    division = primerOperador / segundoOperador;
    
    return division;
}

int multiplicacionDeOperadores(int primerOperador, int segundoOperador) // funcion para multiplicar los operadores
{
    int multiplicacion;
    multiplicacion = primerOperador * segundoOperador;
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
    return producto;
}
    



