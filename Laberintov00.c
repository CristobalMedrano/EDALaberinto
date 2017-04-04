#include <stdio.h>
#include <stdlib.h>

// Bloque de define.
#define DEBUG2
#define TRUE 1
#define FALSE 0

// Bloque de estructuras.

typedef struct laberinto
{
	int N;
	int M;
	int** matrizLaberinto;
} Laberinto;

// Bloque de encabezados.
int** obtenerMatrizLaberinto(int N, int M, int* listmap);
Laberinto* guardarDatosLaberinto(int N, int M, int** matrizLaberinto);
int* leerArchivo(char Nombre[20], int *N, int *M);
void obtenerDatosLaberinto(int *N, int *M, int *listmap);

// Bloque de funciones.

//Funcion que recolecta los datos del laberinto.
void obtenerDatosLaberinto(int *N, int *M, int *listmap)
{
	*N = 0;
	*M = 0;
	*listmap = leerArchivo("Entrada.in", &*N, &*M);
}

// Funcion que obtiene los datos del laberinto.
// Retorna una struct con los datos del laberinto.
Laberinto* guardarDatosLaberinto(int N, int M, int** matrizLaberinto)
{
	Laberinto* laberinto = (Laberinto*)malloc(sizeof(int));

	// Guardo los datos en la estructura laberinto.
	laberinto->N;
	laberinto->M;
	laberinto->matrizLaberinto;
	return laberinto;
}

// Funcion que lee un archivo de texto con el laberinto.
// Retorna una lista con el laberinto.
int* leerArchivo(char Nombre[20], int *N, int *M)
{
	int* listmap; // Lista del laberinto

	FILE *archivoEntrada;
	archivoEntrada = fopen(Nombre, "r");

	fscanf(archivoEntrada,"%d",&*N);
	fscanf(archivoEntrada,"%d",&*M);

	#ifdef DEBUG
	printf("Soy n%d\n", *N);
	printf("Soy m%d\n", *M);
	#endif

	int i = 0;
	int Largo = (*N**M);
	listmap = (int*)malloc(sizeof(int)*Largo);

	while(i < Largo)
	{
        fscanf(archivoEntrada," %c",&listmap[i]);
        i++;
        
        #ifdef DEBUG
        printf("%c\n", listmap[i-1]);
        #endif
        
	}
	fclose(archivoEntrada);

	#ifdef DEBUG
	for (int i = 0; i < Largo; i++)
	{
		printf("Valor en la pos:%d dato:%c\n", i, listmap[i]);
	}
	#endif
	return listmap;
}

// Funcion que recibe como entrada la cantidad de filas,columnas y lista
// del laberinto.
// Retorna una lista de listas con el laberinto convertido.
int** obtenerMatrizLaberinto(int N, int M, int* listmap)
{
	// Asignamos memoria a la matriz.
	int **matrizLaberinto = (int **)malloc(N * sizeof(int *));
							for (int i = 0; i < N; ++i)
							matrizLaberinto[i] = (int *)malloc(M * sizeof(int));
	int i;
	int j;
	int pos = 0;
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			matrizLaberinto[i][j] = listmap[pos];
			pos++;
			#ifdef DEBUG
				printf("%c",matrizLaberinto[i][j]);
			#endif
		}
		#ifdef DEBUG
		printf("\n");
		#endif
	}

	return matrizLaberinto;
}

// Funcion main.

int main(int argc, char const *argv[])
{
	int N;
	int M;
	int* listmap;
	int** matrizLaberinto;
	obtenerDatosLaberinto(&N, &M, &listmap);

	matrizLaberinto = obtenerMatrizLaberinto(N, M, listmap);
	Laberinto* nuevoLaberinto = guardarDatosLaberinto(N, M, matrizLaberinto);

	return TRUE;
}