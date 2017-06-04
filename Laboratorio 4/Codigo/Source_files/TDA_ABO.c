/**
	@file TDA_ABO.c
	@brief Modulo de TDA ABO del programa.
	
	Funciones del TDA Arbol Binario Ordenado.

	@author Cristobal Medrano
	@date 27/05/2017
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <string.h>
/**
	@brief Funcion que obtiene el menor elemento de un arbol
	@param arbol, Arbol a leer.
	@return indice, Arbol con el elemento menor.
*/
Arbol* obtenerMenorElemento(Arbol* arbol)
{
	Arbol* indice = arbol;
	while (hijo_IZQUIERDO(indice) != NULL)
	{
		indice = hijo_IZQUIERDO(indice);
	}
	return indice;
}

/**
	@brief Funcion que obtiene la raiz de un arbol
	@param arbol, Arbol a leer.
	@return indice, Arbol con la raiz.
*/
Arbol* obtenerRaiz(Arbol* arbol)
{
	return arbol;
}

/**
	@brief Funcion que obtiene el padre de un elemento Arbol.
	@param arbol, Arbol a leer.
	@param elemento, dato de tipo arbol a buscar.
	@return padre, Arbol con el padre del elemento.
*/
Arbol* obtenerPadre(Arbol* arbol, Arbol* elemento)
{
	Arbol* padre = NULL;
	if (arbol == NULL)
	{
		return NULL;
	}
	if (hijo_IZQUIERDO(arbol) == elemento || hijo_DERECHO(arbol) == elemento)
	{
		return arbol;
	}
	padre = obtenerPadre(hijo_IZQUIERDO(arbol), elemento);
	if (padre != NULL)
	{
		return padre;
	}
	else
	{
		return obtenerPadre(hijo_DERECHO(arbol), elemento);
	}
}

/**
	@brief Funcion que el menor elemento que sigue de un dato Arbol.
	@param arbol, Arbol a leer.
	@param actual, Arbol en la posicion actual.
	@return menorElemento que sigue al actual.
*/
Arbol* menorSiguiente(Arbol* arbol, Arbol* actual)
{
	Arbol* padre = NULL;
	if (arbol == NULL || actual == NULL)
	{
		return NULL;
	}
	if (hijo_DERECHO(actual) != NULL)
	{
		return obtenerMenorElemento(hijo_DERECHO(actual));
	}
	padre = obtenerPadre(arbol, actual);
	if (hijo_IZQUIERDO(padre) == actual)
	{
		return padre;
	}
	while (padre != NULL && hijo_DERECHO(padre) == actual)
	{
		actual = padre;
		padre = obtenerPadre(arbol, actual);
	}
	return padre;
}

/**
	@brief Funcion que busca un usuario en el arbol
	@param arbol, Arbol a leer.
	@param nombreUsuario, dato a buscar en el arbol.
	@return indice, Arbol con el nombre de usuario.
	@return NULL, si no se encontro el nombre de usuario.
*/
Arbol* buscarUsuario(Arbol* arbol, char* nombreUsuario)
{
	Arbol* indice = arbol;
	while (indice != NULL)
	{
		char* usuarioActual = obtenerDatoArbol(indice);
		if (strcmp(nombreUsuario, usuarioActual) == 0)
		{
			return indice;
		}
		if (strcmp(nombreUsuario, usuarioActual) < 0)
		{
			indice = hijo_IZQUIERDO(indice);
		}
		else
		{
			indice = hijo_DERECHO(indice);
		}
	}
	return NULL;
}

/**
	@brief Funcion que obtiene el dato del arbol
	@param arbol, Arbol a leer.
	@return nombreUsuario, si es que el arbol lo posee.
	@return NULL, si no se encuentra el dato.
*/
char* obtenerDatoArbol(Arbol* arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	else
	{
		return arbol->nombreUsuario;
	}
}

/**
	@brief Funcion que obtiene el telefono del arbol
	@param arbol, Arbol a leer.
	@return telefonoUsuario, si es que el arbol lo posee.
	@return NULL, si no se encuentra el telefono.
*/
char* obtenerTelefonoArbol(Arbol* arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	else
	{
		return arbol->telefonoUsuario;
	}
}

/**
	@brief Funcion que obtiene el hijo izquierdo de un arbol
	@param arbol, Arbol a leer.
	@return hijo izquierdo, si posee hijo izquierdo.
	@return NULL, si no posee hijo izquierdo.
*/
Arbol* hijo_IZQUIERDO(Arbol* arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	else
	{
		return arbol->hijoIzquierdo;
	}
}

/**
	@brief Funcion que obtiene el hijo derecho de un arbol
	@param arbol, Arbol a leer.
	@return hijo derecho, si posee hijo derecho.
	@return NULL, si no posee hijo derecho.
*/
Arbol* hijo_DERECHO(Arbol* arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	else
	{
		return arbol->hijoDerecho;
	}
	return arbol;
}

/**
	@brief Funcion que crear un nodo tipo Arbol.
	@param nombreUsuario, usuario a guardar en el arbol.
	@param telefonoUsuario, telefono del usuario a guardar.
	@param arbol_izquierdo, hijo izquierdo a enlazar
	@param arbol_derecho, hijo derecho a enlazar
	@return nuevaHoja, con los datos ingresados.
	@return NULL, si no fue posible asignar memoria.
*/
Arbol* crearHoja(char* nombreUsuario, char* telefonoUsuario, Arbol* arbol_izquierdo, Arbol* arbol_derecho)
{
	Arbol* nuevaHoja = (Arbol*)malloc(sizeof(Arbol)); 
	if(nuevaHoja!=NULL){ 
	    nuevaHoja->nombreUsuario = nombreUsuario;
	    nuevaHoja->telefonoUsuario = telefonoUsuario;
		nuevaHoja->hijoIzquierdo = arbol_izquierdo;
		nuevaHoja->hijoDerecho = arbol_derecho;
		return nuevaHoja;
	} 
	else{
		printf("No es posible asignar memoria para crearHoja");
		return NULL; 
	} 
} 

/**
	@brief Funcion que inserta un usuario en el arbol.
	@param arbol, Arbol a insertar el dato.
	@param nombreUsuario, nombre del usuario a insertar.
	@param telefonoUsuario, telefono del usuario a insertar.
	@return hoja, si el arbol es nulo.
	@return arbol, con el dato insertado.
*/
Arbol* insertarDato(Arbol* arbol, char* nombreUsuario, char* telefonoUsuario)
{
	Arbol* hoja = crearHoja(nombreUsuario, telefonoUsuario, NULL, NULL);
	if (arbol == NULL)
	{
		return hoja;
	}
	if (hijo_IZQUIERDO(arbol) == NULL && strcmp(obtenerDatoArbol(hoja),obtenerDatoArbol(arbol)) < 0)
	{
		arbol->hijoIzquierdo = hoja;
		return arbol;
	}
	if (hijo_DERECHO(arbol) == NULL && strcmp(nombreUsuario,obtenerDatoArbol(arbol)) >= 0)
	{
		arbol->hijoDerecho = hoja;
		return arbol;
	}
	if (strcmp(nombreUsuario,obtenerDatoArbol(arbol)) < 0)
	{
		arbol->hijoIzquierdo = insertarDato(hijo_IZQUIERDO(arbol), nombreUsuario, telefonoUsuario);
		return arbol;
	}
	else
	{
		arbol->hijoDerecho = insertarDato(hijo_DERECHO(arbol), nombreUsuario, telefonoUsuario);
		return arbol;
	}
	return arbol;
}

/**
	@brief Procedimiento que muestra el recorrido del arbol en inOrden
	@param arbol, arbol a recorrer.
*/
void inOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
	inOrden(arbol->hijoIzquierdo);
	printf("%s%s\n", arbol->nombreUsuario, arbol->telefonoUsuario);
 	inOrden(arbol->hijoDerecho);
 	}
}

/**
	@brief Procedimiento que muestra el recorrido del arbol en preOrden
	@param arbol, arbol a recorrer.
*/
void preOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
 	printf("%s%s\n", arbol->nombreUsuario, arbol->telefonoUsuario);
 	preOrden(arbol->hijoIzquierdo);
 	preOrden(arbol->hijoDerecho);
	}
}

/**
	@brief Procedimiento que muestra el recorrido del arbol en postOrden
	@param arbol, arbol a recorrer.
*/
void postOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
 	postOrden(arbol->hijoIzquierdo);
 	postOrden(arbol->hijoDerecho);
 	printf("%s%s\n", arbol->nombreUsuario, arbol->telefonoUsuario);
	}
}