/**
	@file Lectura.h
	@brief Libreria que contiene el encabezado de las funciones de Lectura del programa.

	@author Cristobal Medrano
	@date 18/05/2017
  
*/
#ifndef LECTURA

#define LECTURA
#define TRUE 1
#define FALSE 0
#define DEBUG

char* obtenerNombreArchivo();
char* leerNombre_Usuario(FILE* archivoEntrada);
char* leerTelefono_Usuario(FILE* archivoEntrada);
Arbol* crearArbol(char* nombre);
Lista* obtenerListaBusqueda(char* nombre);

#endif