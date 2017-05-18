#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Estructuras.h"
#include "Lectura.h"


/**
	@brief Funcion que obtiene el nombre del archivo ingresado por el usuario.
	@returns el nombre ingresado por el usuario.
*/
char* obtenerNombreArchivo()
{
	static char leerNombre[256];
	fflush(stdin); // Limpiamos buffer de entrada.
	printf("Ingrese nombre del archivo: \n");
	if (scanf("%s", &leerNombre) != 0)
	{
	    fflush(stdin); // Limpiamos buffer.
	}
	return leerNombre;
}

/**
	@brief Funcion que lee el archivo de texto.
	@param nombre : Nombre del archivo de texto a leer.
	@returns listaGrafo con los datos del archivo de texto.
*/
int* leerArchivo(char* nombre)
{
	int* listaGrafo = NULL;
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");

	// Si la lectura del archivo es correcta, inicializamos variables.
	if(archivoEntrada != NULL)
    {
    	int i = 0;
    	int valor;
    	char letra;
    	listaGrafo = (int*)malloc(sizeof(int)*(214748364));
    	// Si la asignacion de memoria es correcta, iniciamos la lectura.
    	if (listaGrafo != NULL)
    	{
    		fscanf(archivoEntrada, "%d", &listaGrafo[i]);
	    	while(i < 3)
	    	{
	    		i++;
	    		fscanf(archivoEntrada, " %c", &letra);
		    	switch(letra)
		    	{
		    		case 'E':fscanf(archivoEntrada, "%d", &listaGrafo[i]);
		    				break;
		    		case 'K':fscanf(archivoEntrada, "%d", &listaGrafo[i]);
		    				break;
		    		case 'S':fscanf(archivoEntrada, "%d", &listaGrafo[i]);
		    				break;
		    	}
	    	}
	    	i++;
	    	listaGrafo[i] = 0;
	    	i++;
	    	while (feof(archivoEntrada) == 0)
	    	{
	    		fscanf(archivoEntrada, "%d", &valor);
	    		if (feof(archivoEntrada) == 0) 
	    		{
		    		listaGrafo[i] = valor;
		    		i++;
	    		}
	    		
	    	}
	    	printf("hola\n");
	    	listaGrafo[4] = i-5;
	    	listaGrafo = (int*)realloc(listaGrafo, sizeof(int)*(listaGrafo[4]+5));
    	}
    	else 
    	{
    		printf("\n- Error de Memoria. Funcion leerArchivo: No se pudo asignar la memoria solicitada.\n\n");
    		return NULL;
    	}
    } else 
    { 
    	printf("\n- Error de Lectura. Funcion leerArchivo: Verifique el archivo ingresado.\n\n");
    	return NULL;	
    }
    fclose(archivoEntrada);
    return listaGrafo;
}

/**
	@brief Funcion que obtiene una matriz de adyacencia
	@param listaGrafo : Lista con los datos del archivo leido.
	@returns MatrizAdyacendia del grafo leido.
*/
int** obtenerMatrizAdyacencia(int* listaGrafo)
{
	int Vertices = listaGrafo[0]; //Vertices del Grafo
	int cantidadElementos = listaGrafo[4]; //Cantidad de elementos a leer.
	int i;
	int j;
	int puntoInicio;
	int puntoFin;
	int longitud;
	int** MatrizAdyacencia = (int **)calloc(Vertices+1, sizeof(int *));
							for (i = 1; i < Vertices+1; ++i)
							MatrizAdyacencia[i] = (int *)calloc(Vertices+1, sizeof(int));
	// Si la asignacion de memoria es correcta, continuamos la ejecucion.
	if (MatrizAdyacencia != NULL)
	{
		i = 0;
		while(i < cantidadElementos)
		{
			puntoInicio = listaGrafo[i+5];
			puntoFin = listaGrafo[i+6];
			longitud = listaGrafo[i+7];

			MatrizAdyacencia[puntoInicio][puntoFin] = longitud; 
			MatrizAdyacencia[puntoFin][puntoInicio] = longitud;
			i = i + 3;
		}
	}
	else
	{
		printf("\n- Error de Memoria. Funcion obtenerMatrizAdyacencia: No se pudo asignar la memoria solicitada.\n\n");
		return NULL;
	}
	return MatrizAdyacencia;
}

/**
	@brief Funcion que guarda los datos obtenidos en una estructura Grafo.
	@param vertices : Vertices del grafo.
	@param entrada : Posicion del Vertice de Entrada.
	@param llave : Posicion del Vertice de Llave.
	@param salida : Posicion del Vertice de Salida.
	@param matrizAdyacencia : Matriz de Adyacencia con los datos del grafo.
	@returns un puntero a la estructura Grafo con los datos.
*/
Grafo* guardarDatos(int vertices, int entrada, int llave, int salida, int** matrizAdyacencia)
{
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));

	// Si la asignacion de memoria es correcta, guardamos los datos.
	if(grafo != NULL)
	{
		grafo->Vertices = vertices;
		grafo->Entrada = entrada;
		grafo->Llave = llave;
		grafo->Salida = salida;
		grafo->MatrizAdyacencia = matrizAdyacencia;
	}
	else 
	{
		return NULL;
		printf("\n- Error de Memoria. Funcion guardarDatos: No se pudo asignar la memoria solicitada.\n\n");
	}
	
	
	return grafo;
}