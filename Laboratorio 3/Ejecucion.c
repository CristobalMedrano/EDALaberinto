#include <stdlib.h>
#include <stdio.h>
#include "Ejecucion.h"
#include "Lectura.h"
#include "Menu.h"

int Dijkstra()
{
	
}

int ejecucionPrincipal()
{
	//Grafo grafo = NULL;
	mostrarMenuPrincipal();
	char *nombre = NULL;
	int* listaGrafo = NULL;
	int** matrizAdyacencia = NULL;

	if (obtenerSeleccionMenu() != INGRESAR)
	{
		return 0;
	}
	
	nombre = obtenerNombreArchivo();
	listaGrafo = leerArchivo(nombre);

	if (listaGrafo != NULL)
	{
		matrizAdyacencia = obtenerMatrizAdyacencia(listaGrafo);
		Grafo* grafo = guardarDatos(listaGrafo[0], listaGrafo[1], listaGrafo[2], listaGrafo[3], matrizAdyacencia);
	}
	else
	{
		ejecucionPrincipal();
	}	
	return 0;
}


