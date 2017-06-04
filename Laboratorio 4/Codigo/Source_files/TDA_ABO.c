// TDA ARBOLES BINARIOS ORDENADO CON PUNTEROS

#include <stdio.h>
#include <stdlib.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <string.h>


Arbol* obtenerMenorElemento(Arbol* arbol)
{
	Arbol* indice = arbol;
	while (hijo_IZQUIERDO(indice) != NULL)
	{
		indice = hijo_IZQUIERDO(indice);
	}
	return indice;
}

Arbol* obtenerRaiz(Arbol* arbol)
{
	return arbol;
}

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

// Funcion insertar
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

void inOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
	inOrden(arbol->hijoIzquierdo);
	printf("%s%s\n", arbol->nombreUsuario, arbol->telefonoUsuario);
 	inOrden(arbol->hijoDerecho);
 	}
}

void preOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
 	printf("%s%s\n", arbol->nombreUsuario, arbol->telefonoUsuario);
 	preOrden(arbol->hijoIzquierdo);
 	preOrden(arbol->hijoDerecho);
	}
}

void postOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
 	postOrden(arbol->hijoIzquierdo);
 	postOrden(arbol->hijoDerecho);
 	printf("%s%s\n", arbol->nombreUsuario, arbol->telefonoUsuario);
	}
}