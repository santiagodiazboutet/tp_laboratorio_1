#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int construct_bFile(FILE * pFile)
{
    int code=1;
    pFile=fopen("binario.bin","wb");
    if(pFile==NULL)
    {
        code=0;
    }


    fclose(pFile);
    return code;
}


int agregarPelicula()
{   system("cls");
    FILE *pFile;
    eMovie *pelicula;
    int retorno=0;
    pelicula=(eMovie*)malloc(sizeof(eMovie));
    printf("Ingrese el titulo de la pelicula a agregar. Ingrese 0 para cancelar.\n");
    fflush(stdin);
    gets(pelicula->titulo);
    if (!strcmp(pelicula->titulo,"0"))
    {
        free(pelicula);
        system("pause");
        return retorno;

    }
    system("cls");
    printf("Ingrese el genero de la pelicula a agregar. Ingrese 0 para cancelar.\n");
    fflush(stdin);
    gets(pelicula->genero);
    if (!strcmp(pelicula->genero,"0"))
    {
        free(pelicula);
        system("pause");
        return retorno;
    }
    system("cls");
    printf("Ingrese la duracion de la pelicula a agregar. Ingrese 0 para cancelar.\n");
    scanf("%d",&pelicula->duracion);
    if (pelicula->duracion==0)
    {
        free(pelicula);
        system("pause");
        return retorno;
    }
    system("cls");
    printf("Ingrese la puntaje de la pelicula a agregar. Ingrese 0 para cancelar.\n");
    scanf("%d",&pelicula->puntaje);
    if (pelicula->puntaje==0)

    {
        free(pelicula);
        system("pause");
        return retorno;
    }
    system("cls");
    printf("Ingrese una descripcion de la pelicula a agregar. Ingrese 0 para cancelar.\n");
    fflush(stdin);
    gets(pelicula->descripcion);
    if (!strcmp(pelicula->descripcion,"0"))
    {
        free(pelicula);
        system("pause");
        return retorno;
    }
    printf("Ingrese el link de la imagen de la pelicula a agregar. Ingrese 0 para cancelar.\n");
    fflush(stdin);
    gets(pelicula->linkImagen);
    if (!strcmp(pelicula->linkImagen,"0"))
    {
        free(pelicula);
        system("pause");
        return retorno;

    }
    pFile=fopen("binario.bin","ab");
    fwrite(pelicula,sizeof(eMovie),1,pFile);
    system("cls");
    fclose(pFile);
    free(pelicula);
    retorno=1;

    return retorno;
}

int borrarPelicula()
{

    int opcion;
    int i=1;
    int j=1;
    int z=0;
    int retorno=1;
    int end=0;
    FILE *pFile;
    FILE *tempFile;
    eMovie *pelicula;
    pelicula=(eMovie*)malloc(sizeof(eMovie));
    while(i!=0)
    {system("cls");
        pFile=fopen("binario.bin","rb");
        fseek(pFile,0,SEEK_END);
        end=ftell(pFile);
        rewind(pFile);
        i=0;
        while(ftell(pFile)!=end)
        {

            fread(pelicula,sizeof(eMovie),1,pFile);
            i++;
            printf("-%d\t-Titulo: %s-\tGenero: %s\t-Duracion: %d\t-Puntaje: %d\nDescripcion: %s\n",i,pelicula->titulo,pelicula->genero,pelicula->duracion,pelicula->puntaje,pelicula->descripcion);


        }



        printf("Ingrese el numero de la pelicula que desea borrar. Ingrese 0 si quiere salir.");
        scanf("%d",&j);
        if(j!=0)
        {   rewind(pFile);
            for(z=1;z<=j;z++)
                {
                fseek(pFile,sizeof(eMovie),SEEK_CUR);
                }
            fread(pelicula,sizeof(eMovie),1,pFile);
            printf("Esta seguro de que desea borrar %s?\n1-Si\n2-No, quiero borrar otra pelicula.\n3-No, no quiero borrar ninguna",pelicula->titulo);
            z=0;
            while(z<1||z>3)
            {   scanf("%d",&z);
                    switch(z)
                    {
                        case 1:
                            system("cls");

                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            fseek(pFile,0,SEEK_SET);
                            i=1;
                            tempFile=fopen("temporario.bin","wb");

                            while(ftell(pFile)<end)
                            {
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);

                                }
                                else
                                {
                                    fseek(pFile,sizeof(eMovie),SEEK_CUR);
                                }
                                i++;

                            }
                            if(i==2)
                            {
                                retorno =0;
                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            system("pause");
                            rename("temporario.bin","binario.bin");
                            i=0;
                            break;
                        case 2:
                            i=1;
                            break;
                        case 3:
                            i=0;
                            fclose(pFile);
                            break;
                        default:
                            printf("Por favor, ingrese un numero valido");
                    }
            }


        }
        else
        {
            i=0;
            fclose(pFile);

        }
    }
    free(pelicula);

    return retorno;
}


void modificarPelicula()
{

    int opcion;
    int i=1;
    int j=1;
    int z=0;
    int retorno=1;
    FILE *pFile;
    FILE *tempFile;
    eMovie *pelicula;
    char auxChar1[20];
    char auxChar2[100];
    int auxInt;
    int end;
    pelicula=(eMovie*)malloc(sizeof(eMovie));

    while(i!=0)
    {system("cls");
        pFile=fopen("binario.bin","rb");
        fseek(pFile,0,SEEK_END);
        end=ftell(pFile);
        rewind(pFile);
        i=0;
        while(ftell(pFile)!=end)
        {

            fread(pelicula,sizeof(eMovie),1,pFile);
            i++;
            printf("-%d\t-Titulo: %s-\tGenero: %s\t-Duracion: %d\t-Puntaje: %d\nDescripcion: %s\n",i,pelicula->titulo,pelicula->genero,pelicula->duracion,pelicula->puntaje,pelicula->descripcion);


        }


        printf("Ingrese el numero de la pelicula que desea modificar. Ingrese 0 si quiere salir.");
        scanf("%d",&j);
        if(j!=0)
        {
            for(z=0;z<=j;z++)
                {
                fseek(pFile,(sizeof(eMovie)),SEEK_SET);
                }
            fread(pelicula,sizeof(eMovie),1,pFile);
            printf("-Titulo: %s-\tGenero: %s\t-Duracion: %d\t-Puntaje: %d\nDescripcion: %s\nLink imagen:%s\n",pelicula->titulo,pelicula->genero,pelicula->duracion,pelicula->puntaje,pelicula->descripcion,pelicula->linkImagen);
            printf("Seleccione el campo que desea modificar \n1-Titulo\n2-Genero\n3-Duracion\n4-Puntaje\n5-Descripcion\n6-Link imagen\n7-Modificar otra pelicula\n8-Salir\n",pelicula->titulo,pelicula->genero,pelicula->duracion,pelicula->puntaje,pelicula->descripcion,pelicula->linkImagen);
            z=0;
            while(z<1||z>8)
            {   scanf("%d",&z);
                    switch(z)
                    {
                        case 1:
                            printf("\nIngrese el nuevo titulo de la pelicula\n");
                            fflush(stdin);
                            gets(auxChar1);
                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            rewind(pFile);
                            tempFile=fopen("temporario.bin","wb");
                            i=1;
                            while(ftell(pFile)!=end)
                            {
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);

                                }
                                else
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    strcpy(pelicula->titulo,auxChar1);
                                    printf("%s",pelicula->titulo);
                                    printf("%s",pelicula->titulo);
                                    system("pause");
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }

                                i++;

                            }
                            /*fclose(pFile);
                            fclose(tempFile);
                            pFile=(eMovie*)fopen("binario.bin","wb");
                            tempFile=(eMovie*)fopen("temporario.bin","rb");
                            while(fgets(pelicula,sizeof(eMovie),tempFile)!=NULL)
                            {free(pelicula);
                            pelicula=(eMovie*)malloc(sizeof(eMovie));
                            fread(pelicula,sizeof(eMovie),1,tempFile);
                            fwrite(pelicula,sizeof(eMovie),1,pFile);
                            }*/
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea seguir modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d",&i);
                            if(i==2)
                            {
                                i=0;
                            }
                            break;
                        case 2:
                            printf("Ingrese el nuevo genero de la pelicula\n");
                            fflush(stdin);
                            gets(auxChar1);
                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            rewind(pFile);
                            tempFile=fopen("temporario.bin","wb");
                            i=1;


                            while(ftell(pFile)!=end)
                            {
                                free(pelicula);
                                pelicula=(eMovie*)malloc(sizeof(eMovie));
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }
                                else
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    strcpy(pelicula->genero,auxChar1);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }
                                i++;

                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea seguir modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d",&i);
                            if(i==2)
                            {
                                i=0;
                            }
                            break;
                        case 3:
                            printf("\nIngrese la nueva duracion de la pelicula\n");
                            fflush(stdin);
                            scanf("%d",&auxInt);
                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            rewind(pFile);
                            tempFile=fopen("temporario.bin","wb");
                            i=1;
                            while(ftell(pFile)!=end)
                            {
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);

                                }
                                else
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    pelicula->duracion=auxInt;
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }
                                i++;

                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea seguir modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d",&i);
                            if(i==2)
                            {
                                i=0;
                            }
                            break;
                        case 4:
                            printf("\nIngrese el nuevo puntaje de la pelicula\n");
                            fflush(stdin);
                            scanf("%d",&auxInt);
                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            rewind(pFile);
                            tempFile=fopen("temporario.bin","wb");
                            i=1;
                            while(ftell(pFile)!=end)
                            {
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);

                                }
                                else
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    pelicula->puntaje=auxInt;
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }
                                i++;

                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea seguir modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d",&i);
                            if(i==2)
                            {
                                i=0;
                            }
                            break;
                        case 5:
                            printf("\nIngrese la nueva descripcion de la pelicula\n");
                            fflush(stdin);
                            gets(auxChar2);
                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            rewind(pFile);
                            tempFile=fopen("temporario.bin","wb");
                            i=1;
                            while(ftell(pFile)!=end)
                            {
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);

                                }
                                else
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    strcpy(pelicula->descripcion,auxChar2);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }
                                i++;

                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea seguir modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d",&i);
                            if(i==2)
                            {
                                i=0;
                            }
                            break;
                        case 6:
                            printf("\nIngrese el nuevo link para la imagen de la pelicula\n");
                            fflush(stdin);
                            gets(auxChar2);
                            fseek(pFile,0,SEEK_END);
                            end=ftell(pFile);
                            rewind(pFile);
                            tempFile=fopen("temporario.bin","wb");
                            i=1;
                            while(ftell(pFile)!=end)
                            {
                                if(i!=j)
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);

                                }
                                else
                                {
                                    fread(pelicula,sizeof(eMovie),1,pFile);
                                    strcpy(pelicula->linkImagen,auxChar2);
                                    fwrite(pelicula,sizeof(eMovie),1,tempFile);
                                }
                                i++;

                            }

                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea seguir modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d",&i);
                            if(i==2)
                            {
                                i=0;
                            }
                            break;
                        case 7:
                            i=1;
                            break;
                        case 8:
                            i=0;
                            break;
                        default:
                            printf("\nPor favor, ingrese un numero valido\n");
                    }
            }


        }
        else
        {
            i=0;
        }
    }
    free(pelicula);
}
void generarPagina()
{
    FILE *pFile;
    FILE *htmlFile;
    eMovie *pelicula;
    int end;
    pFile=fopen("binario.bin","rb");
    pelicula=(eMovie*)malloc(sizeof(eMovie));
    htmlFile=fopen("index.html","w");

    fseek(pFile,0,SEEK_END);
    end=ftell(pFile);
    rewind(pFile);
    fprintf(htmlFile,"<!DOCTYPE html>"
"<!-- Template by Quackit.com -->"
"<html lang='en'>"
"<head>"
  "  <meta charset='utf-8'>"
  "  <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
  "  <meta name='viewport' content='width=device-width, initial-scale=1'>"
  "  <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
  "  <title>Lista peliculas</title>"
  "  <!-- Bootstrap Core CSS -->"
  "  <link href='css/bootstrap.min.css' rel='stylesheet'>"
  "  <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
   " <link href='css/custom.css' rel='stylesheet'>"
  "  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
  "  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
  "  <!--[if lt IE 9]>"
       " <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
       "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
    "<![endif]-->"
"</head>"
"<body>"
    "<div class='container'>"
        "<div class='row'>");


    while(ftell(pFile)!=end)
    {

        fread(pelicula,sizeof(eMovie),1,pFile);
        fprintf(htmlFile,"<!-- Repetir esto para cada pelicula -->\n");
        fprintf(htmlFile,"<article class='col-md-4 article-intro'>\n<a href='#'>\n");
        fprintf(htmlFile,"<img class='img-responsive img-rounded' src='%s' alt=''>\n </a>\n  <h3>\n  <a href='#'>%s</a>\n  </h3>\n<ul>\n",pelicula->linkImagen,pelicula->titulo);
        fprintf(htmlFile,"<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d min</li>\n</ul>\n",pelicula->genero,pelicula->puntaje,pelicula->duracion);
        fprintf(htmlFile,"<p>%s</p>\n </article>\n<!-- Repetir esto para cada pelicula -->",pelicula->descripcion);
        system("pause");
    }
       fprintf(htmlFile,"</div>"
        "<!-- /.row -->"
    "</div>"
    "<!-- /.container -->"
    "<!-- jQuery -->"
    "<script src='js/jquery-1.11.3.min.js'></script>"
    "<!-- Bootstrap Core JavaScript -->"
    "<script src='js/bootstrap.min.js'></script>"
	"<!-- IE10 viewport bug workaround -->"
	"<script src='js/ie10-viewport-bug-workaround.js'></script>"
	"<!-- Placeholder Images -->"
	"<script src='js/holder.min.js'></script>"
"</body>"
"</html>");
    fclose(pFile);
    fclose(htmlFile);

}

