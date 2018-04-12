#include<stdio.h>
#include<ctype.h>
#include"funciones.h"
#include <string.h>


float suma (float numero1, float numero2)
{
    float resultado;

    resultado=numero1+numero2;
    return resultado;
}
float resta (float numero1, float numero2)
{
    float resultado;
    resultado=numero1-numero2;
    return resultado;
}
float multiplicacion (float numero1, float numero2)
{
    float resultado;

    resultado=numero1*numero2;
    return resultado;
}
float division (float numero1,float numero2)
{
    float resultado;
    if ( numero2==0)
    {

        resultado=0;
    }
    else
    {
        resultado=numero1/numero2;

    }
    return resultado;
}
unsigned long long int factorial (float numero)
{   unsigned long long int acumulador=numero;
    long long int contador=numero-1;
    int numeroEntero=(int)numero;
    float decimal=numero-numeroEntero;
    if (numero<0)
    {
        printf("No se puede realizar el factorial de un numero negativo. Por favor, ingrese otro numero e intente nuevamente.");
        acumulador =0;
    }
    else if(numero==0)
    {
        acumulador=1;
    }
    else if(decimal>0)
    {
        printf("No se puede realizar el factorial de un numero decimal. Por favor, ingrese otro numero e intente nuevamente.");
        acumulador =0;
    }
    else
    {
        while(contador>0)
        {
        acumulador=acumulador*contador;
        contador--;
        }
    }

    return acumulador;
}
int Inicializados(int AInicializado,int BInicializado)
    {   int Inicializados=0;
        if(AInicializado==0||BInicializado==0)
        {
            printf("No ha ingresado los numeros necesarios para realizar esta operacion. Ingreselos e intente nuevamente.\n");

        }
        else
        {
            Inicializados=1;
        }
        return Inicializados;
    }
int validaNumero(char numeroIngresado[])
{   int esNumero=1;
    int numeroString;
    int acumuladorInvalidos=0;
    int acumuladorPunto=0;
    int acumuladorNegativo=0;
    for (numeroString=0;numeroIngresado[numeroString];numeroString++)
    {
       if (isdigit(numeroIngresado[numeroString])!= 1)
       {
            if(numeroIngresado[numeroString]=='.')
        {
                acumuladorPunto++;
        }
            else if((numeroIngresado[numeroString]=='-'))
        {
                acumuladorNegativo++;
                if (numeroString>0)
                {
                    acumuladorInvalidos++;
                }
        }
            else
        {
            acumuladorInvalidos++;
        }
       }
    }
    if (acumuladorInvalidos>0)
    {
        esNumero=0;
    }
    else if(acumuladorPunto>1)
    {
        esNumero=0;
    }
    else if(acumuladorNegativo>1)
    {
        esNumero=0;
    }
    return esNumero;
}
