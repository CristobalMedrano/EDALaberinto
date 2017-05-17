#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Estructuras.h"
#include "Ejecucion.h"
#include "TDA_Listas_Enlazadas.h"

// Esto es lo que tengo que escribir en el archivo.
Lista* obtenerRecorrido(Casilla* camino, int vInicial, int vFinal)
{
	Lista* caminoMinimo = NULL;
	int verticeRecorrido = vFinal;
	do
	{
		caminoMinimo = InsertarPos(caminoMinimo, 0, verticeRecorrido);
		verticeRecorrido = camino[verticeRecorrido].anterior;

	}while(verticeRecorrido != vInicial);
	
	caminoMinimo = InsertarPos(caminoMinimo, 0, verticeRecorrido);
	caminoMinimo = InsertarPos(caminoMinimo, 0, camino[vFinal].costo); // El coste total es el primer Valor.
	return caminoMinimo;
}

int escribirArchivo(Lista* Entrada, Lista* Salida)
{
	int i = 0;
	int largoLista = 0;
	FILE* archivoSalida;
	archivoSalida = fopen("Salida.out", "w");
	if(archivoSalida != NULL)
	{
		fprintf(archivoSalida, "Camino entrada a llave:\n");
		fprintf(archivoSalida, "%d", obtener(Entrada, 1));
		for (i = 2; i < largo(Entrada); i++)
		{
			fprintf(archivoSalida, " - ");
			fprintf(archivoSalida, "%d", obtener(Entrada, i));
		}
		fprintf(archivoSalida, "\n");
		fprintf(archivoSalida, "Distancia recorrida: %d\n\n", obtener(Entrada, 0));

		fprintf(archivoSalida, "Camino llave a salida:\n");
		fprintf(archivoSalida, "%d", obtener(Salida, 1));
		for (i = 2; i < largo(Salida); i++)
		{
			fprintf(archivoSalida, " - ");
			fprintf(archivoSalida, "%d", obtener(Salida, i));
		}
		fprintf(archivoSalida, "\n");
		fprintf(archivoSalida, "Distancia recorrida: %d\n\n", obtener(Salida, 0));
		fclose(archivoSalida);
	}
	else
	{
		printf("\n- Error de Memoria. Funcion escribirArchivo: No se pudo asignar la memoria solicitada.\n\n");
		return FALSE;
	}

	return TRUE;
}