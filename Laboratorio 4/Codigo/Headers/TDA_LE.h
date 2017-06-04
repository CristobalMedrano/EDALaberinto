/**
	@file TDA_Listas_Enlazadas.h
	@brief Libreria que contiene el encabezado de las funciones de listas enlazadas del programa.

	@author Cristobal Medrano
	@date 18/05/2017
  
*/

#ifndef LISTAS_ENLAZADAS
#define LISTAS_ENLAZADAS

Lista* crearNodo();
ListaTelefonos* crearNodoTelefono();
Lista* InsertarPos(Lista* L, int pos, char* nombreUsuario);
Lista* InsertarFinal(Lista* L, char* nombreUsuario);
ListaTelefonos* InsertarTelefono(ListaTelefonos* L, char* telefonoUsuario);
char* obtener(Lista* L, int pos);
int largo(Lista* L);
void mostrar(Lista * L);
void mostrarNumero(ListaTelefonos * L);

#endif