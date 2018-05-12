#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define OCUPADO 0
#define LIBRE 1



void ePersona_init( ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
        }
    }
    return retorno;
}

int ePersona_buscarLugarLibre(ePersona listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePersona_alta(ePersona  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int dni;
    int edad;
    int indice;


    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = ePersona_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {

                    system("cls");
                    printf("\nIngrese el nombre de la persona.\n");
                    fflush(stdin);
                    gets(nombre);
                    printf("\nIngrese la edad de la persona.\n");
                    scanf("%d",&edad);
                    printf("\nIngrese el dni de la persona.\n");
                    scanf("%d",&dni);
                    strcpy(listado[indice].nombre, nombre);
                    listado[indice].dni = dni;
                    listado[indice].edad=edad;
                    listado[indice].estado = OCUPADO;

        }
    }
    return retorno;
}

void ePersona_mostrarListado(ePersona listado[],int limite)
{

    int i;
    if(limite > 0 && listado != NULL)
    {

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                ePersona_mostrarUno(listado[i]);


            }
        }
    }
}

void ePersona_mostrarUno(ePersona parametro)
{
     printf("\n %s -dni:%d -edad: %d ",parametro.nombre,parametro.dni,parametro.edad);

}

void ePersona_ordenar(ePersona listado[],int limite)
{
    ePersona aux;
    int i;
    int j;

    for(i=0;i<limite-1;i++)
    {
        for(j=i+1;j<limite;j++)
        {   if(listado[i].estado==OCUPADO)
            {

            if(listado[j].estado==OCUPADO&&strcmp(listado[i].nombre,listado[j].nombre)>0)
            {
              aux.dni=listado[i].dni;
              listado[i].dni=listado[j].dni;
              listado[j].dni=aux.dni;
              aux.edad=listado[i].edad;
              listado[i].edad=listado[j].edad;
              listado[j].edad=aux.edad;
              strcpy(aux.nombre,listado[i].nombre);
              strcpy(listado[i].nombre,listado[j].nombre);
              strcpy(listado[j].nombre,aux.nombre);
            }
            }
        }
    }
}

void ePersona_baja(ePersona listado[] ,int limite)
{   int dni;
    int i;

    int opcion=0;
    while(opcion!=1&&opcion!=2)
    {
        ePersona_mostrarListado(listado,limite);
        printf("\nIngrese dni del componente a modificar");
        scanf("%d",&dni);
        i=ePersona_buscarPordni(listado,limite,dni);
        if(i==-2||i==-3)
        {
            printf("\nEl numero ingresado no pertenece a un dni en funcionamiento");
        }
        else
        {
            while(opcion!=1&&opcion!=2)
            {
            system("cls");
            printf("\nLa persona a dar de baja es: %s. Esta seguro que desea darla de baja?\n1-SI\n2-NO\n",listado[i].nombre);
            scanf("%d",&opcion);
            if(opcion==1)
            {
                printf("\nPersona dada de baja exitosamente\n");
                listado[i].estado=LIBRE;
                system("pause");
            }
            else if(opcion==2)
            {

            }else
                {

                printf("\nPor favor ingrese una opcion valida \n");
                }

            }
        }
    }
}
int ePersona_buscarPordni(ePersona listado[] ,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].dni == dni)
            {
                retorno = i;

                break;
            }
        }
    }
    return retorno;
}
void ePersona_grafico(ePersona lista[],int limite)
{
    int i;

    int max=0;
    int acumMayor=0;
    int acumMenor=0;
    int acumMedio=0;


    for (i=0;i<limite;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(lista[i].edad>35)
            {
                acumMayor++;
            }
            else if(lista[i].edad<18)
            {
                acumMenor++;
            }
            else
            {
                acumMedio++;
            }
        }
    }
    if(acumMayor>=acumMenor)
    {
        if(acumMayor>=acumMedio)
        {
            max=acumMayor;
        }
        else
        {
            max=acumMedio;
        }
    }
    else if(acumMenor>=acumMedio)
    {
        max=acumMenor;
    }
    else
    {
        max=acumMedio;
    }
    if(max>0)
    {

    for(;max>0;max--)
    {
        if(acumMenor==max)
        {
            printf(" * ");
            acumMenor--;
        }
        else
        {
            printf("   ");
        }
        if(acumMedio==max)
        {
            printf("  *  ");
            acumMedio--;
        }
        else
        {
            printf("     ");
        }
        if(acumMayor==max)
        {
            printf(" * \n");
            acumMayor--;
        }
        else
        {
            printf("   \n");
        }
    }
    printf("<18 19-35 >35");

    }
    else
    {
        printf("No ha ingresado suficientes personas como para realizar esta operacion.");
    }
}





