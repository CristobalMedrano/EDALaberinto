#include <stdio.h>
#include <stdlib.h>

// Bloque de define.
#define DEBUG2
#define TRUE 1
#define FALSE 0
#define ARRIBA 0
#define ABAJO 1
#define IZQUIERDA 2
#define DERECHA 3

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
int** recorrerLaberinto(Laberinto* L, char busqueda);
void mostrarEstadoLaberinto(Laberinto* nuevoLaberinto);
void buscarPuerta(int *datoX, int *datoY, Laberinto* L, char letra);
int** obtenerMatrizTemporal(Laberinto* L);
int** direccionarLaberinto(int Ex, int Ey, int Px,
						   int Py, int N, int M, int** matrizTemporal,
						   Laberinto* L);
// Bloque de funciones.

//Funcion que recorre el laberinto
int** recorrerLaberinto(Laberinto* L, char busqueda)
{
	int Ex = 0;
	int Ey = 0;
	int Lx = 0;
	int Ly = 0;
	int Sx = 0;
	int Sy = 0;

	buscarPuerta(&Ex, &Ey, L, 'E');
	buscarPuerta(&Sx, &Sy, L, 'S');
	buscarPuerta(&Lx, &Ly, L, 'K');

	#ifdef DEBUG
	printf("Soy la ENTRADA, en la posicion %d,%d\n", Ex, Ey);
	printf("Soy la SALIDA, en la posicion %d,%d\n", Sx, Sy);
	printf("Soy la LLAVE, en la posicion %d,%d\n", Lx, Ly);
	#endif

	//Ojo aqui se viene el switch.
	int N = L->N;
	int M = L->M;

	int** matrizTemporal = obtenerMatrizTemporal(L);
	direccionarLaberinto(Lx, Ly, Sx, Sy, N, M, matrizTemporal, L);

}

int** direccionarLaberinto(int Ex, int Ey, int Px,
						   int Py, int N, int M, int** matrizTemporal,
						   Laberinto* L)
{
	printf("%d,%d\n", Ex, Ey);
	if(Ex == Px && Ey == Py)
	{
		printf("SOY LA FINAL\n");
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				printf("%c",matrizTemporal[i][j]);
			}
			printf("\n");
		}
		printf("\n Soy la Final \n");
		return matrizTemporal;
	}
	// izquierda
	else if (matrizTemporal[Ex][Ey-1] != '*' && matrizTemporal[Ex][Ey-1] == '.'
		&& matrizTemporal[Ex][Ey-1] != '+')
	{
		Ey = Ey - 1;
		matrizTemporal[Ex][Ey] = '+';
		// Cruzar hacia la izquierda.
		if (Ey == 0)
		{
			Ey = M-1;
			matrizTemporal[Ex][Ey] = '+';
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);

		} else 
		{
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);
		}

		#ifdef DEBUG2
			printf("Izquierda\n");
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", matrizTemporal[i][j]);
				}
				printf("\n");
			}
		#endif
	}
	// derecha
	else if (matrizTemporal[Ex][Ey+1] != '*' && matrizTemporal[Ex][Ey+1] == '.'
		&& matrizTemporal[Ex][Ey+1] != '+')
	{
		Ey = Ey + 1;
		matrizTemporal[Ex][Ey] = '+';
		// Cruzar hacia la derecha.
		if (Ey == M-1)
		{
			Ey = 0;
			matrizTemporal[Ex][Ey] = '+';
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);
		} else 
		{
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);
		}

		#ifdef DEBUG2
			printf("Derecha\n");
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", matrizTemporal[i][j]);
				}
				printf("\n");
			}
		#endif

	}
	// abajo
	else if ((matrizTemporal[Ex+1][Ey] != '*' && matrizTemporal[Ex+1][Ey] == '.'
		&& matrizTemporal[Ex+1][Ey] != '+') || matrizTemporal[Ex+1][Ey] == 'K')
	{
		Ex = Ex + 1;
		matrizTemporal[Ex][Ey] = '+';
		
		// Cruzar hacia abajo.
		if (Ex == N-1)
		{
			Ex = 0;
			matrizTemporal[Ex][Ey] = '+';
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);
		} 
		
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);
			

		#ifdef DEBUG2
			printf("Abajo\n");
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", matrizTemporal[i][j]);
				}
				printf("\n");
			}
		#endif

	}
	// arriba
	else if (matrizTemporal[Ex-1][Ey] != '*' && matrizTemporal[Ex-1][Ey] == '.'
		&& matrizTemporal[Ex-1][Ey] != '+')
	{
		Ex = Ex - 1;
		matrizTemporal[Ex][Ey] = '+';
		// Cruzar hacia arriba.
		if (Ex == 0)
		{
			Ex = N-1;
			matrizTemporal[Ex][Ey] = '+';
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);

		} else 
		{
			direccionarLaberinto(Ex, Ey, Px, Py, N, M, matrizTemporal, L);
		}

		#ifdef DEBUG2
			printf("Arriba\n");
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", matrizTemporal[i][j]);
				}
			printf("\n");
			}
		#endif
	}
	
	
	
	matrizTemporal[Ex][Ey] = '.';
}


int** obtenerMatrizTemporal(Laberinto* L)
{
	int** matrizTemporal = (int **)malloc(L->N * sizeof(int *));
						 for (int i = 0; i < L->N; ++i)
						 matrizTemporal[i] = (int *)malloc(L->M * sizeof(int));
	
	for (int i = 0; i < L->N; ++i)
	{
		for (int j = 0; j < L->M; ++j)
		{
			matrizTemporal[i][j] = L->matrizLaberinto[i][j];
		}
	}
	return matrizTemporal;
}


// Busco la posicion de un caracter en especifico.
void buscarPuerta(int *datoX, int *datoY, Laberinto* L, char letra)
{
	int i;
	int j;
	for (i = 0; i < L->N; i++)
	{
		for (j = 0; j < L->M; j++)
		{
			if ((L->matrizLaberinto[i][j]) == letra)
			{
				*datoX = i;
				*datoY = j;

				#ifdef DEBUG
				printf("%d,%d\n", *datoX, *datoY);
				#endif
			}
		}
	}
}

// Funcion que muestra el estado actual del laberinto.
void mostrarEstadoLaberinto(Laberinto* nuevoLaberinto)
{
	int i;
	int j;
	for (i = 0; i < nuevoLaberinto->N; i++)
	{
		printf("\n");
		for (j = 0; j < nuevoLaberinto->M; j++)
		{
			printf("%c", nuevoLaberinto->matrizLaberinto[i][j]);
		}
	}
	printf("\n");
}

//Funcion que recolecta los datos del laberinto.
void obtenerDatosLaberinto(int *N, int *M, int *listmap)
{
	*N = 0;
	*M = 0;
	*listmap = leerArchivo("Entrada.in", &*N, &*M);
}

// Funcion que obtiene los datos del laberinto.
// Retorna una struct con los datos del laberinto.
Laberinto* guardarDatosLaberinto(int Filas, int Columnas, int** inLaberinto)
{
	Laberinto* nuevolaberinto = (Laberinto*)malloc(sizeof(Laberinto));

	// Guardo los datos en la estructura laberinto.
	nuevolaberinto->N = Filas;
	nuevolaberinto->M = Columnas;
	nuevolaberinto->matrizLaberinto = inLaberinto;
	return nuevolaberinto;
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
	int valor = 0;
	listmap = (int*)malloc(sizeof(int)*Largo);

	while (i < Largo)
	{
		fscanf(archivoEntrada, " %c", &valor);
		listmap[i] = valor;

		#ifdef DEBUG
			printf("Soy valor %d\n", valor);
			printf("Soy lista %d\n", listmap[i]);
		#endif

		i++;
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
				printf("%d",matrizLaberinto[i][j]);
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
	mostrarEstadoLaberinto(nuevoLaberinto);
	// Buscamos la llave.
	recorrerLaberinto(nuevoLaberinto, 'L');
	mostrarEstadoLaberinto(nuevoLaberinto);

	// Buscamos la salida.

	return TRUE;
}