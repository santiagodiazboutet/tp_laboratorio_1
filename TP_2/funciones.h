#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Inicia la variable estado de todos los miembros del array en LIBRE
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 * @return codigo de control de error
 */
int ePersona_init(ePersona[],int limite);
/**
 * Permite al usuario ingresar datos al array
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 * @return codigo de control de error
 */
int ePersona_alta(ePersona[],int limite);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 * @return el primer indice disponible
 */
int ePersona_buscarLugarLibre(ePersona[],int);
/**
 * Imprime los valores de una estructura
 * @param parametro a imprimir
 */
void ePersona_mostrarUno(ePersona);
/**
 * Imprime todos los miembros del array de la estructura
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 */
void ePersona_mostrarListado(ePersona[],int);
/**
 * Ordena alfabeticamente el array de una estructura
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 */
void ePersona_ordenar(ePersona[],int);

/**
 * Modifica el estado de el elmento que elija el usuario a LIBRE
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 */
void ePersona_baja(ePersona listado[] ,int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int ePersona_buscarPordni(ePersona listado[] ,int limite, int dni);
/**
 * Imprime grafico de las edades que tine la estructura
 * @param lista el array se pasa como parametro.
 * @param tamaño maximo del array
 * @return codigo de control de error
 */
void ePersona_grafico(ePersona lista[],int limite);




#endif // FUNCIONES_H_INCLUDED
