#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMPERS 20

int main()
{
    char seguir='s';
    int opcion=0;
    ePersona listaPersonas[TAMPERS];
    ePersona_init(listaPersonas,TAMPERS);
    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ePersona_alta(listaPersonas, TAMPERS);
                break;
            case 2:
                ePersona_baja(listaPersonas,TAMPERS);
                break;
            case 3:
                ePersona_ordenar(listaPersonas,TAMPERS);
                ePersona_mostrarListado(listaPersonas,TAMPERS);
                break;
            case 4:
                ePersona_grafico(listaPersonas,TAMPERS);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
