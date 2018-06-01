#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[100];
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(void);

/**
 *  Borra una pelicula del archivo binario
 *  @return retorna 1 o 0 de acuerdo a si quedan peliculas por eliminar o no
 */
int borrarPelicula(void);

/**
 *  Modifica una pelicula del archivo binario
 */
void modificarPelicula(void);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina();

/**
 *  Genera un archivo binario para utilizar en el trabajo.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @return 1 si puede crear el archivo y 0 si no puede.
 */
int construct_bFile(FILE *);

#endif // FUNCIONES_H_INCLUDED
