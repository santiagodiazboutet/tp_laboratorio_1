#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    char opcion='k';
    char numeroIngresado[50];
    int numeroValido=1;
    float numero1=0;
    float numero2=0;
    float resultado=0;
    int AInicializado=0;
    int BInicializado=0;
    unsigned long long int resultadoFactorial=0;
    int AyBInicializados=0;
    while(seguir=='s')
    {
        if(AInicializado==0)
        {
            printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A=%.2f)\n",numero1);
        }
       if(BInicializado==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        opcion=getche();

        switch(opcion)
        {
            case '1':

                printf("\nPor favor, ingrese el primer operando.\n");
                scanf("%s", numeroIngresado);
                printf("%s",numeroIngresado);

                numeroValido=validaNumero(numeroIngresado);
                if(numeroValido==1)
                {
                    numero1=strtof(numeroIngresado,NULL);
                    AInicializado=1;
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf("Por favor, ingrese un numero valido.");
                }
                break;
            case '2':

                printf("\nPor favor, ingrese el segundo operando.\n");
                scanf("%s", numeroIngresado);
                printf("%s",numeroIngresado);

                numeroValido=validaNumero(numeroIngresado);
                if(numeroValido==1)
                {
                    numero2=strtof(numeroIngresado,NULL);
                    BInicializado=1;
                    system("cls");
                }
                else
                {
                    system("cls");
                    printf("Por favor, ingrese un numero valido.");
                }
                break;
            case '3':
                    system("cls");
                    AyBInicializados=Inicializados(AInicializado,BInicializado);
                    if(AyBInicializados!=0)
                    {
                        resultado=suma(numero1,numero2);
                        printf("El resultado de la suma es: %.2f\n", resultado);
                    }

                break;
            case '4':
                    system("cls");
                    AyBInicializados=Inicializados(AInicializado,BInicializado);
                    if(AyBInicializados!=0)
                    {


                    resultado=resta(numero1,numero2);
                    printf("El resultado de la resta es: %.2f\n", resultado);
                    }
                break;
            case '5':
                    system("cls");
                    AyBInicializados=Inicializados(AInicializado,BInicializado);
                    if(AyBInicializados!=0)
                    {
                    if(numero2==0)
                    {

                        printf("La division no se puede realizar si el segundo operando es 0. Por favor ingrese otro numero.\n");
                        break;
                    }
                    else
                    {
                        resultado=division(numero1,numero2);
                        printf("El resultado de la division es: %.2f\n", resultado+ 0.0);

                    }
                    }
                break;
            case '6':
                    system("cls");
                    AyBInicializados=Inicializados(AInicializado,BInicializado);
                    if(AyBInicializados!=0)
                    {
                        resultado=multiplicacion(numero1,numero2);
                        printf("El resultado de la multiplicacion es: %.2f\n", resultado+ 0.0);
                    }
                break;
            case '7':
                system("cls");
                if (AInicializado==0)
                {
                    printf("Por favor, ingrese el primer operando e intente nuevamente.");
                }
                else{
                    resultadoFactorial=factorial(numero1);
                    if (resultadoFactorial==0)
                        {

                        }else
                        {
                        printf("El factorial del primer operando es: %llu\n", resultadoFactorial+ 0.0);
                        }
                    }

                break;
            case '8':
                    system("cls");
                    AyBInicializados=Inicializados(AInicializado,BInicializado);
                    if(AyBInicializados==0)
                    {
                    }
                    else
                    {
                        resultado=suma(numero1,numero2);
                        printf("El resultado de la suma es: %.2f\n\n", resultado+ 0.0);
                        resultado=resta(numero1,numero2);
                        printf("El resultado de la resta es: %.2f\n\n", resultado+ 0.0);
                        if(numero2==0)
                        {
                            printf("La division no se puede realizar si el segundo operando es 0. Por favor ingrese otro numero.\n\n");
                            break;
                        }
                        else
                        {
                            resultado=division(numero1,numero2);
                            printf("El resultado de la division es: %.2f\n\n", resultado+ 0.0);
                        }
                        resultado=multiplicacion(numero1,numero2);
                        printf("El resultado de la multiplicacion es: %.2f\n\n", resultado+ 0.0);
                        resultadoFactorial=factorial(numero1);
                        if (resultadoFactorial==0)
                        {

                        }
                        else
                        {
                            printf("El factorial del primer operando es: %llu\n\n", resultadoFactorial);
                        }

                    }

                break;
            case '9':
                seguir = 'n';
                break;
            default:
                system("cls");
                break;
        }

    }
    return 0;
}
