#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int flagPelicula=0;
    int opcion=0;
    int error;
    FILE * bFile;
    error=construct_bFile(bFile);
    if (error==0)
    {
        printf("No se pudo crear archivo binario. Por favor contacte a su administrador de sistema");
    }
    else
    {
        while(seguir=='s')
        {
            system("cls");
            printf("1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Generar pagina web\n");
            printf("5- Salir\n");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    flagPelicula= agregarPelicula();
                    break;
                case 2:
                    if(flagPelicula!=1)
                    {
                        printf("Debe ingresar una pelicula para poder borrarla.\n");
                        system("pause");
                    }else{
                    flagPelicula=borrarPelicula();
                    }
                    break;
                case 3:
                    if(flagPelicula!=1)
                    {
                        printf("Debe ingresar una pelicula para poder modificarla.\n");
                        system("pause");
                    }else{
                    modificarPelicula();
                    }
                    break;
                case 4:
                    if(flagPelicula!=1)
                    {
                        printf("Debe ingresar una pelicula para poder generar una pagina.\n");
                        system("pause");
                    }else{
                    generarPagina();
                    }
                    break;
                case 5:
                    seguir = 'n';
                    break;
            }
        }
    }
    return 0;
}
