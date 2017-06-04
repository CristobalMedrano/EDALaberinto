/**
	@file Estructuras.h
	@brief Libreria que contiene las estructuras del programa.

	@author Cristobal Medrano
	@date 02/06/2017
*/

#ifndef ESTRUCTURAS
#define ESTRUCTURAS

/**
	@struct ListaTelefonos
	@brief Estructura de ListaTelefonos, contiene una lista con los 
	telefonos del usuario.
	@param telefonoUsuario, cadena de caracteres con el numero.
	@param siguiente, un puntero al siguiente telefono.
*/
typedef struct ListaTelefonos
{
	char* telefonoUsuario;
	struct ListaTelefonos *siguiente;
} ListaTelefonos;

/**
	@struct Lista
	@brief Estructura de Lista, contiene una lista con los usuarios leidos.
	@param nombreUsuario, cadena de caracteres con el nombre.
	@param listaTelefonos, Lista con los numeros del usuario.
	@param siguiente, un puntero al siguiente usuario.
*/
typedef struct Lista
{
	char* nombreUsuario;
	ListaTelefonos* listaTelefonos;
	struct Lista *siguiente;
} Lista;

/**
	@struct Arbol
	@brief Estructura de Arbol, contiene un arbol binario ordenado.
	@param nombreUsuario, cadena de caracteres con el nombre.
	@param telefonoUsuario, cadena de caracteres con el numero.
	@param hijoIzquierdo, puntero al hijo izquierdo.
	@param hijoDerecho, puntero al hijo derecho.

*/
typedef struct Arbol
{
    char* nombreUsuario;
    char* telefonoUsuario;
    struct Arbol* hijoIzquierdo;
    struct Arbol* hijoDerecho;
} Arbol;

#endif