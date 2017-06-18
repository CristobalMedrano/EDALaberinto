/**
	@file Lectura.h
	@brief Libreria que contiene el encabezado de las funciones de Lectura del programa.

	@author Cristobal Medrano
	@date 01/06/2017
  
*/
#ifndef LECTURA
#define LECTURA

#define TRUE 1
#define FALSE 0
#define DIRECTORIO 0
#define BUSCAR 1
#define DEBUG

char* obtenerNombreArchivo(int entrada);
Arbol* crearArbol(char* nombre, int* largo_MAX);
char* leerNombre_Usuario(FILE* archivoEntrada);
char* leerTelefono_Usuario(FILE* archivoEntrada);
void obtenerLargoNombre(char* nombreUsuario, int* largo_MAX);
Lista* obtenerListaBusqueda(char* nombre);

#endif