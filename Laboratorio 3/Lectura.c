#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Lectura.h"


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

Grafo* guardarDatos(int vertices, int entrada, int llave, int salida, int** matrizAdyacencia)
{
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	
	grafo->Vertices = vertices;
	grafo->Entrada = entrada;
	grafo->Llave = llave;
	grafo->Salida = salida;
	grafo->MatrizAdyacencia = matrizAdyacencia;
	return grafo;
}

int* leerArchivo(char* nombre)
{
	int* listaGrafo = (int*)malloc(sizeof(int)*256);
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");
	
	if(archivoEntrada == NULL)
    {
    	printf("\n- Error de Lectura. Verifique el archivo ingresado.\n\n");
    	return NULL;
    } else 
    {
    	int i = 0;
    	int valor;
    	char letra;
    	
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
    	#ifdef DEBUG
    	printf("Vertices: %d\n", listaGrafo[0]);
    	printf("Entrada: %d\n", listaGrafo[1]);
    	printf("Llave: %d\n", listaGrafo[2]);
    	printf("Salida: %d\n", listaGrafo[3]);
    	#endif
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
    	listaGrafo[4] = i-4;
   	    printf("Soy la cantidad de elementos %d\n", listaGrafo[4]);

    }
    fclose(archivoEntrada);
    return listaGrafo;
}

int** obtenerMatrizAdyacencia(int* listaGrafo)
{
	int i;
	int** MatrizAdyacencia = (int **)malloc(listaGrafo[0] * sizeof(int *));
							for (i = 0; i < listaGrafo[0]; ++i)
							MatrizAdyacencia[i] = (int *)malloc(listaGrafo[0] * sizeof(int));
	
	i = 0;
	while(i < listaGrafo[4])
	{
		
		i++;
	}
}

