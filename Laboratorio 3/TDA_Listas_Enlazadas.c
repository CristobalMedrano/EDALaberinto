/**
	@file ListasEnlazadas.c
	@brief Listas Enlazadas

	TDA de listas enlazadas mediante nodos.

	@author Cristobal Medrano
	@date 19/04/2017
  
*/

#include <stdlib.h>
#include <stdio.h>
#include "Estructuras.h"
#include "TDA_Listas_Enlazadas.h"
/**
	@brief Funcion que crea un nodo.
	@param dato es el elemento a guardar en la lista.
	@returns Lista (puntero), si fue creada exitosamente.
	@returns NULL, si no fue creada.
*/
Lista* crearNodo()
{
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	//Si la asignacion de memoria es exitosa, se inicializan las variables
	if(lista!=NULL){
	    lista->dato = 0;
		lista->siguiente = NULL;
		return lista;
	}
	else{
		return NULL;
	}
}

/**
	@brief Funcion que inserta un elemento en la lista.
	@param L es una Lista de nodos.
	@param pos es la posicion en donde se insertara el elemento.
	@param dato es el dato a guardar en la lista.
	@returns Lista (puntero), con los datos actualizados.
*/
Lista* InsertarPos(Lista* L, int pos, int dato)
{
	int i;
	// Si la pos ingresada es menor a 0, retorno la lista.
	if(pos < 0)
	{
		return L;
	}
	// Si la pos ingresada es igual a 0, agrego el elemento a la lista.
	if(pos == 0)
	{
		Lista* nueva = crearNodo();
		nueva->dato = dato;
		nueva->siguiente = L;
		return nueva;
	}
	i = 0;
	Lista *indice = crearNodo();
	indice = L;
	// Muevo el puntero a la posicion - 1 que no sea nula.
	while (indice != NULL && i < pos -1)
	{
		indice = indice->siguiente;
		i++;
	}
	// si el indice no es nulo, creo el nodo y lo agrego a la lista.
	if(indice != NULL)
	{
		Lista* nueva = crearNodo();
		nueva->dato = dato;
		nueva->siguiente = indice->siguiente;
		indice->siguiente = nueva;
	}
	return L; 
}

/**
	@brief Funcion que obtiene un elemento de la lista, segun la posicion.
	@param L lista con los nodos.
	@param pos posicion del elemento a buscar.
	@returns elemento si la ejecucion fue correcta.
	@returns -1 si la posicion es invalida.
*/
int obtener(Lista* L, int pos)
{
	int i;
	if(pos < 0)
	{
		return -1;
	}
	i = 0;
	Lista* indice = L;
	while(indice != NULL && i < pos)
	{
		indice = indice->siguiente;
		i++;
	}
	if(indice == NULL)
	{
		return -1;
	}
	return indice->dato;
}
/**
	@brief Funcion que obtiene el largo de la lista.
	@param L lista con los nodos.
	@returns int con el largo de la lista.
*/
int largo(Lista* L)
{
	int i = 0;
	Lista* indice = L;
	while(indice != NULL)
	{
		indice = indice->siguiente;
		i++;
	}
	return i;
}