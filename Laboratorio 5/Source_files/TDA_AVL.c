/**
	@file TDA_ABO.c
	@brief Modulo de TDA_AVL del programa.
	
	Funciones del TDA AVL

	@author Cristobal Medrano
	@date 10/06/2017
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_AVL.h>


// CONTENIDO(T) -> obtenerUsuarioArbol


Arbol* insertarUsuario_AVL(Arbol* arbol, char* nombreUsuario, char* telefonoUsuario)
{
	Arbol* hoja = crearHoja(nombreUsuario, telefonoUsuario, NULL, NULL);

	if (arbol == NULL)
	{
		return hoja;
	}
	if (strcmp(nombreUsuario, obtenerUsuarioArbol(arbol)) < 0)
	{
		arbol->hijoIzquierdo = insertarUsuario_AVL(hijo_IZQUIERDO(arbol), nombreUsuario, telefonoUsuario);
	}
	else
	{
		arbol->hijoDerecho = insertarUsuario_AVL(hijo_DERECHO(arbol), nombreUsuario, telefonoUsuario);
	}
	return EQUILIBRAR_AVL(arbol);
}

Arbol* EQUILIBRAR_AVL(Arbol* arbol)
{
	int diferencia = diferenciaAlturas(arbol);
	if (diferencia == 2)
	{
		if (diferenciaAlturas(hijo_IZQUIERDO(arbol)) < 0)
		{
			arbol->hijoIzquierdo = rotar_IZQUIERDA(hijo_IZQUIERDO(arbol));
		}
		return rotar_DERECHA(arbol);
	}
	if (diferencia == -2)
	{
		if (diferenciaAlturas(hijo_DERECHO(arbol)) > 0)
		{
			arbol->hijoDerecho = rotar_DERECHA(hijo_DERECHO(arbol));
		}
		return rotar_IZQUIERDA(arbol);
	}
	return arbol;
}

int diferenciaAlturas(Arbol* arbol)
{
	return obtenerAltura(hijo_IZQUIERDO(arbol)) - obtenerAltura(hijo_DERECHO(arbol));
}

int obtenerAltura(Arbol* arbol)
{
	//SIN_ALTURA == 0
	int alturaIzquierda = SIN_ALTURA;
	int alturaDerecha = SIN_ALTURA;
	if (arbol == NULL)
	{
		return SIN_ALTURA;
	}
	if (hijo_IZQUIERDO(arbol) == NULL && hijo_DERECHO(arbol) == NULL)
	{
		return 1;
	}
	alturaIzquierda = obtenerAltura(hijo_IZQUIERDO(arbol));
	alturaDerecha = obtenerAltura(hijo_DERECHO(arbol));
	if (alturaIzquierda > alturaDerecha)
	{
		return 1 + alturaIzquierda;
	}
	return 1 + alturaDerecha;
}

Arbol* rotar_DERECHA(Arbol* arbol)
{
	Arbol* raiz = hijo_IZQUIERDO(arbol);
	arbol->hijoIzquierdo = hijo_DERECHO(raiz);
	raiz->hijoDerecho = arbol;
	return raiz;
}

Arbol* rotar_IZQUIERDA(Arbol* arbol)
{
	Arbol* raiz = hijo_DERECHO(arbol);
	arbol->hijoDerecho = hijo_IZQUIERDO(raiz);
	raiz->hijoIzquierdo = arbol;
	return raiz;
}
