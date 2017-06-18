/**
	@file Escritura.h
	@brief Libreria que contiene el encabezado de las funciones de Escritura del programa.

	@author Cristobal Medrano
	@date 03/06/2017
  
*/

#ifndef ESCRITURA
#define ESCRITURA

#define FALSE 0
#define TRUE 1
int escribirArchivo(Lista* listaBusqueda);
void escribirDatos(FILE* archivoSalida, Lista* listaBusqueda);
int escribirIdentificadores(Arbol* arbol, int largo_MAX);
void Identificadores(Arbol* arbol, FILE* archivoSalida, int largo_MAX);
char* escrituraEstructurada(Arbol* arbol, int largo_MAX);
#endif