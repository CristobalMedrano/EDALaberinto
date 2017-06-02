// TDA ARBOLES BINARIOS ORDENADO CON PUNTEROS

#include <stdio.h>
#include <stdlib.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <string.h>


// Funcion crear

/*
Arbol* borrarArbol(Arbol* arbol, int dato)
{
	Arbol* posicion = buscarDato(arbol, dato);
	Arbol* padre = obtenerPadre(arbol, posicion);

	if (posicion == NULL)
	{
		return arbol;
	}
	if (hijo_IZQUIERDO(posicion) == NULL && hijo_DERECHO(posicion) == NULL)
	{
		if (obtenerRaiz(arbol) == posicion)
		{
			free(arbol);
			return NULL;
		}
		else if (posicion == hijo_IZQUIERDO(padre))
		{
			padre->hijoIzquierdo = NULL;
		}
		else
		{
			padre->hijoDerecho = NULL;
		}
		free(posicion);
		posicion = NULL;
		return arbol;
	}
	
	if (hijo_DERECHO(posicion) == NULL)
	{
		
		if (posicion == obtenerRaiz(arbol))
		{
			arbol = posicion->hijoIzquierdo;
		}
		else if (hijo_IZQUIERDO(padre) == posicion)
		{
			padre->hijoIzquierdo = posicion->hijoIzquierdo;
		}
		else
		{
			padre->hijoDerecho = posicion->hijoIzquierdo;
		}
		free(posicion);
		posicion = NULL;
		return arbol;
	}
	Arbol* reemplazo = menorSiguiente(arbol, posicion);
	int valorReemplazo = obtenerDatoArbol(reemplazo);
	reemplazo->dato = posicion->dato;
	posicion->dato = valorReemplazo;
	posicion->hijoDerecho = borrarArbol(hijo_DERECHO(posicion), dato);
	return arbol;
}*/

/*Arbol* obtenerRaiz(Arbol* arbol)
{
	return arbol;
}

Arbol* mayorAnterior(Arbol* arbol, Arbol* actual)
{
	Arbol* padre = NULL;
	if (arbol == NULL || actual == NULL)
	{
		return NULL;
	}
	if (hijo_IZQUIERDO(actual) != NULL)
	{
		return obtenerMayorElemento(hijo_IZQUIERDO(actual));
	}
	padre = obtenerPadre(arbol, actual);
	if (hijo_DERECHO(padre) == actual)
	{
		return padre;
	}
	while (padre != NULL && hijo_IZQUIERDO(padre) == actual)
	{
		actual = padre;
		padre = obtenerPadre(arbol, actual);
	}
	return padre;
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

Arbol* obtenerMayorElemento(Arbol* arbol)
{
	Arbol* indice = arbol;
	while (hijo_DERECHO(indice) != NULL)
	{
		indice = hijo_DERECHO(indice);
	}
	return indice;
}

Arbol* obtenerMenorElemento(Arbol* arbol)
{
	Arbol* indice = arbol;
	while (hijo_IZQUIERDO(indice) != NULL)
	{
		indice = hijo_IZQUIERDO(indice);
	}
	return indice;
}

Arbol* buscarDato(Arbol* arbol, int dato)
{
	Arbol* indice = arbol;
	while (indice != NULL)
	{
		int datoActual = obtenerDatoArbol(indice);
		if (datoActual == dato)
		{
			return indice;
		}
		if (dato < datoActual)
		{
			indice = hijo_IZQUIERDO(indice);
		}
		else
		{
			indice = hijo_DERECHO(indice);
		}
	}
	return NULL;
}*/

char* obtenerDatoArbol(Arbol* arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	else
	{
		return arbol->usuario;
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
Arbol* crearHoja(char* usuario, Arbol* arbol_izquierdo, Arbol* arbol_derecho)
{
	Arbol* nuevaHoja = (Arbol*)malloc(sizeof(Arbol)); 
	if(nuevaHoja!=NULL){ 
	    nuevaHoja->usuario = usuario; 
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
Arbol* insertarDato(Arbol* arbol, char* usuario)
{
	Arbol* hoja = crearHoja(usuario, NULL, NULL);
	if (arbol == NULL)
	{
		return hoja;
	}
	if (hijo_IZQUIERDO(arbol) == NULL && strcmp(obtenerDatoArbol(hoja),obtenerDatoArbol(arbol)) < 0)
	{
		arbol->hijoIzquierdo = hoja;
		return arbol;
	}
	if (hijo_DERECHO(arbol) == NULL && strcmp(usuario,obtenerDatoArbol(arbol)) >= 0)
	{
		arbol->hijoDerecho = hoja;
		return arbol;
	}
	if (strcmp(usuario,obtenerDatoArbol(arbol)) < 0)
	{
		arbol->hijoIzquierdo = insertarDato(hijo_IZQUIERDO(arbol), usuario);
		return arbol;
	}
	else
	{
		arbol->hijoDerecho = insertarDato(hijo_DERECHO(arbol), usuario);
		return arbol;
	}
	return arbol;
}

void inOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
	inOrden(arbol->hijoIzquierdo);
 	printf("%s\n", arbol->usuario);
 	inOrden(arbol->hijoDerecho);
 	}
}

void preOrden(Arbol* arbol)
{
	if (arbol != NULL)
	{ 
 	printf("%s\n", arbol->usuario);
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
 	printf("%s\n", arbol->usuario);
	}
}

/*void MenuArboles()
{
	Arbol* arbol = NULL;
	int opcion = 0;
	int dato = 0;

	do
	{
		printf("\nIngrese una opcion:\n");
		printf("(0) insertar\n");
		printf("(1) mayor elemento\n");
		printf("(2) menor elemento\n");
		printf("(3) borrar\n");
		printf("(-1) salir\n");
		scanf("%d", &opcion);
		switch (opcion)
		{
			case 0 :
					printf("Ingrese dato: \n");
					scanf("%d", &dato);
					arbol= insertarDato(arbol, dato);
					printf("\ninOrden: ");
		        	inOrden(arbol);
		        	printf("\npreOrden: ");
		        	preOrden(arbol);
		        	printf("\npostOrden: ");
		        	postOrden(arbol);
					 break;
			case 1 :
					printf("mayor: %d\n", obtenerMayorElemento(arbol)->dato);
					 break;
			case 2 :
					printf("menor: %d\n", obtenerMenorElemento(arbol)->dato);
					break;
			case 3 :printf("Ingrese dato: \n");
					scanf("%d", &dato);
					arbol = borrarArbol(arbol, dato);
					printf("\ninOrden: ");
		        	inOrden(arbol);
		        	printf("\npreOrden: ");
		        	preOrden(arbol);
		        	printf("\npostOrden: ");
		        	postOrden(arbol);
		    case -1:printf("Saliendo...\n");
		}
		
	} while (opcion != -1);
}*/
