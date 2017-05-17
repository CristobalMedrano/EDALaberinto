#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Estructuras.h"
#include "Lectura.h"
#include "Menu.h"
#include "Ejecucion.h"
#include "TDA_Listas_Enlazadas.h"
#include "Escritura.h"

Casilla* Dijkstra(Grafo* grafo, int vInicial)
{
	int vertices = grafo->Vertices;
	int verticeInicial = vInicial;
	int** matrizAdyacencia = grafo->MatrizAdyacencia;
	Casilla* camino = (Casilla*)malloc(sizeof(Casilla)*vertices);
	int Visitados[vertices];

	int i;
	for (i = 0; i < vertices; ++i)
	{
		camino[i].anterior = -1;
		Visitados[i] = FALSE;

		if (i != verticeInicial)
		{
			camino[i].costo = INT_MAX;
		}
		else
		{
			camino[i].costo = 0;
		}
	}
	int u = verticeInicial;
	int costoU = 0;

	while(u != -1 && costoU != INT_MAX)
	{
		Visitados[u] = TRUE;
		int v;
		for (v = 0; v < vertices; v++)
		{
			if (Visitados[v] == 0 && matrizAdyacencia[u][v] != FALSE)
			{
				if (Visitados[v] == FALSE)
				{
					int nuevoCosto = costoU + matrizAdyacencia[u][v];

					if (nuevoCosto < camino[v].costo)
					{
						camino[v].anterior = u;
						camino[v].costo = nuevoCosto;
					} 
				}
			}
		}
		costoU = INT_MAX;
		u = -1;

		for (v = 0; v < vertices; v++)
		{
			if (Visitados[v] == FALSE && camino[v].costo < costoU)
			{
				costoU = camino[v].costo;
				
				u = v;
			}
		}
	}
	return camino;
}

int ejecucionPrincipal()
{
	
	char *nombre = NULL;
	int* listaGrafo = NULL;
	int** matrizAdyacencia = NULL;
	Grafo* grafo = NULL;
	Casilla* CaminoE_L = NULL;
	Casilla* CaminoL_S = NULL;
	Lista* caminoMinimoE_L = NULL;
	Lista* caminoMinimoL_S = NULL;
	int escritura = 0;

	mostrarMenuPrincipal();
	if (obtenerSeleccionMenu() == SALIR)
	{
		return 0;
	}
	
	nombre = obtenerNombreArchivo();
	listaGrafo = leerArchivo(nombre);

	if (listaGrafo != NULL)
	{
		printf("\n- Iniciando Lectura.");
		printf("\nArchivo : %s, ingresado correctamente.\n", nombre);

		matrizAdyacencia = obtenerMatrizAdyacencia(listaGrafo);
		Grafo* grafo = guardarDatos(listaGrafo[0], listaGrafo[1], listaGrafo[2], listaGrafo[3], matrizAdyacencia);
		if (matrizAdyacencia != NULL && grafo != NULL)
		{
			printf("\n- Iniciando Solucion. \n");
			CaminoE_L = Dijkstra(grafo, grafo->Entrada);
			caminoMinimoE_L = obtenerRecorrido(CaminoE_L, listaGrafo[1], listaGrafo[2]);
			printf("\n- Desarrollando la Solucion. \n");
			
			CaminoL_S = Dijkstra(grafo, grafo->Llave);
			caminoMinimoL_S = obtenerRecorrido(CaminoL_S, listaGrafo[2], listaGrafo[3]);
			printf("\n- Solucion Terminada. \n");

			escritura = escribirArchivo(caminoMinimoE_L, caminoMinimoL_S);

			if (escritura == TRUE)
			{
				printf("\n- Ejecucion Terminada.\n");
				printf("\nArchivo : Salida.out, creado correctamente.\n");
			}
		}		
	}
	else
	{
		ejecucionPrincipal();
	}	
	return 0;
}


