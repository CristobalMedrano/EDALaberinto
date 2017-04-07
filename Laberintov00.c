#include <stdio.h>
#include <stdlib.h>

// Bloque de define.
#define DEBUG2
#define TRUE 1
#define FALSE 0
#define LLAVE 0
#define SALIDA 1

// Bloque de estructuras.

typedef struct laberinto
{
	int N;
	int M;
	int** matrizLaberinto;
	int** matrizEntradaLlave;
	int** matrizLlaveSalida;
} Laberinto;

// Bloque de encabezados.
int** obtenerMatrizLaberinto(int N, int M, int* listmap);
Laberinto* guardarDatosLaberinto(int N, int M, int** matrizLaberinto);
int* leerArchivo(char Nombre[20], int *N, int *M);
void obtenerDatosLaberinto(int *N, int *M, int *listmap);
void recorrerLaberinto(Laberinto* L, char busqueda);
void mostrarEstadoLaberinto(Laberinto* nuevoLaberinto);
void buscarPuerta(int *datoX, int *datoY, Laberinto* L, char letra);
int** obtenerMatrizTemporal(Laberinto* L);
void direccionarLaberinto(int Pix, int Piy, int Pfx, int Pfy, int** cRecorrido,
						   Laberinto* L, int busqueda);
// Bloque de funciones.

//Funcion que recorre el laberinto
void recorrerLaberinto(Laberinto* L, char busqueda)
{
	int Ex = 0; // Entrada en X.
	int Ey = 0; // Entrada en Y.
	int Lx = 0; // Llave en X.
	int Ly = 0; // Llave en Y.
	int Sx = 0; // Salida en X.
	int Sy = 0; // Salida en Y.

	buscarPuerta(&Ex, &Ey, L, 'E');
	buscarPuerta(&Sx, &Sy, L, 'S');
	buscarPuerta(&Lx, &Ly, L, 'K');

	int Pix = 0;	// Posicion Inicial en X.
	int Piy = 0;	// Posicion Inicial en Y.
	int Pfx = 0;	// Posicion Final en X.
	int Pfy = 0;	// Posicion Final en Y.
	switch (busqueda) 
	{
		case LLAVE: Pix = Ex;
					Piy = Ey;
					Pfx = Lx;
					Pfy = Ly;
					break;
		case SALIDA:Pix = Lx;
					Piy = Ly;
					Pfx = Sx;
					Pfy = Sy;
					break;
	}
	int** cRecorrido = obtenerMatrizTemporal(L);
	direccionarLaberinto(Pix, Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	// Ubicamos la posicion de la Entrada y Salida para una mejor lectura.
	switch(busqueda)
	{
		case LLAVE: L->matrizEntradaLlave[Ex][Ey] = 'E';
					L->matrizEntradaLlave[Lx][Ly] = 'K';
					break;
		case SALIDA: L->matrizLlaveSalida[Sx][Sy] = 'S';
					 L->matrizLlaveSalida[Lx][Ly] = 'K';
					 break;
	}
}

void direccionarLaberinto(int Pix, int Piy, int Pfx, int Pfy, int** cRecorrido,
						   Laberinto* L, int busqueda)
{
	if(Pix == Pfx && Piy == Pfy)
	{
		for (int i = 0; i < L->N; ++i)
		{
			for (int j = 0; j < L->M; ++j)
			{
				switch(busqueda)
				{
					case LLAVE: L->matrizEntradaLlave[i][j] = cRecorrido[i][j];
								break;
					case SALIDA: L->matrizLlaveSalida[i][j] = cRecorrido[i][j];
								 break;
				}
				cRecorrido[i][j] = '*';
			}
		}


	}
	// ----------------------DERECHA----------------------------//
	// Caminar hacia la derecha.
	
	if (Piy <= L->M-2 && cRecorrido[Pix][Piy+1] != '*' && cRecorrido[Pix][Piy+1] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		cRecorrido[Pix][Piy+1] = 'x';

		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif

		direccionarLaberinto(Pix, Piy+1, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia la derecha (Pac-Man).
	if (Piy == L->M-1 && cRecorrido[Pix][Piy] != '*')
	{
		cRecorrido[Pix][0] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix, Piy-(L->M-1), Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------ABAJO----------------------------//
	// Caminar hacia abajo.
	if (Pix <= L->N-2 && cRecorrido[Pix+1][Piy] != '*' && cRecorrido[Pix+1][Piy] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		cRecorrido[Pix+1][Piy] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix+1, Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia abajo (Pac-Man)	
	if (Pix == L->N-1 && cRecorrido[Pix][Piy] != '*')
	{
		cRecorrido[0][Piy] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix-(L->N-1), Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}	
	// ----------------------IZQUIERDA----------------------------//
	// Caminar hacia izquierda.
	if (Piy >= 1 && cRecorrido[Pix][Piy-1] != '*' && cRecorrido[Pix][Piy-1] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		cRecorrido[Pix][Piy-1] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix, Piy-1, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia izquierda (Pac-Man)
	if (Piy == 0 && cRecorrido[Pix][Piy] != '*')
	{
		cRecorrido[Pix][L->M-1] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix, Piy+(L->M-1), Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------ARRIBA----------------------------//
	// Caminar hacia arriba.
	if (Pix >= 1 && cRecorrido[Pix-1][Piy] != '*' && cRecorrido[Pix-1][Piy] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		cRecorrido[Pix-1][Piy] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix-1, Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia arriba (Pac-Man)
	if (Pix == 0 && cRecorrido[Pix][Piy] != '*')
	{
		cRecorrido[L->N-1][Piy] = 'x';
		#ifdef DEBUG
			for (int i = 0; i < L->N; ++i)
			{
				for (int j = 0; j < L->M; ++j)
				{
					printf("%c", cRecorrido[i][j]);
				}
				printf("\n");
			}
		#endif
		direccionarLaberinto(Pix+(L->N-1), Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------DEVOLVER----------------------------//
	cRecorrido[Pix][Piy] = '.';
}

int** obtenerMatrizTemporal(Laberinto* L)
{
	int** cRecorrido = (int **)malloc(L->N * sizeof(int *));
						 for (int i = 0; i < L->N; ++i)
						 cRecorrido[i] = (int *)malloc(L->M * sizeof(int));
	
	for (int i = 0; i < L->N; ++i)
	{
		for (int j = 0; j < L->M; ++j)
		{
			cRecorrido[i][j] = L->matrizLaberinto[i][j];
			switch (cRecorrido[i][j]) 
			{
				case 'E' : cRecorrido[i][j] = '.';
				case 'K' : cRecorrido[i][j] = '.';
				case 'S' : cRecorrido[i][j] = '.';
			}
		}
	}
	return cRecorrido;
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

// Funcion que muestra el estado actual del laberinto. MODIFICAR
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

	int** inEntradaLlave = (int **)malloc(Filas * sizeof(int *));
							for (int i = 0; i < Filas; ++i)
							inEntradaLlave[i] = (int *)malloc(Columnas * sizeof(int));

	// Crear pedir memoria.
	int** inLlaveSalida = (int **)malloc(Filas * sizeof(int *));
							for (int i = 0; i < Filas; ++i)
							inLlaveSalida[i] = (int *)malloc(Columnas * sizeof(int));

	// Guardo los datos en la estructura laberinto.
	nuevolaberinto->N = Filas;
	nuevolaberinto->M = Columnas;
	nuevolaberinto->matrizLaberinto = inLaberinto;
	nuevolaberinto->matrizEntradaLlave = inEntradaLlave;
	nuevolaberinto->matrizLlaveSalida = inLlaveSalida;
	return nuevolaberinto;
}

// Funcion que lee un archivo de texto con el laberinto.
// Retorna una lista con el laberinto.
int* leerArchivo(char Nombre[20], int *N, int *M)
{
	int* listmap; // Lista del laberinto

	FILE *archivoEntrada;
	archivoEntrada = fopen(Nombre, "r");
	if(archivoEntrada == NULL)
    {
        printf("Error al abrir archivo");
    }

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
	printf("Archivo leido Correctamente.\n");
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

void escribirLaberinto(Laberinto* L)
{
	//Obtenemos el puntero del archivo a leer.
	FILE *archivoSalida;
	// Abrimos el archivo a guardar.
	archivoSalida = fopen("Salida.out", "w");
    // Notificamos error en caso de no poder abrir el archivo.
    if(archivoSalida == NULL)
    {
        printf("Error al abrir archivo");
    }
    int i;
	int j;

	// Escribimos cada posicicion de la matriz en el archivo.
	for (i = 0; i < L->N; i++)
	{
		for (j = 0; j < L->M; j++)
		{
			fprintf(archivoSalida, "%c", L->matrizEntradaLlave[i][j]);
		}
		fprintf(archivoSalida,"\n");
	}
	fprintf(archivoSalida,"\n");

	// Escribimos cada posicicion de la matriz en el archivo.
	for (i = 0; i < L->N; i++)
	{
		for (j = 0; j < L->M; j++)
		{
			fprintf(archivoSalida, "%c", L->matrizLlaveSalida[i][j]);
		}
		fprintf(archivoSalida,"\n");
	}

	printf("Archivo escrito Correctamente.\n");
    fclose(archivoSalida);
}

// Funcion main.

int main(int argc, char const *argv[])
{
	int N;
	int M;
	int* listmap;
	int** matrizLaberinto;
	printf("\n //---- Iniciando Solucionador. ----// \n");
	
	// Obtenemos los datos del laberinto:
	// Cantidad de Filas - N
	// Cantidad de Columnas - M
	// Lista del laberinto.
	// En listmap, se encuentra el nombre del archivo de entrada
	// en este caso "Entrada.in".
	obtenerDatosLaberinto(&N, &M, &listmap);
	
	// Creamos una matriz para el laberinto.
	matrizLaberinto = obtenerMatrizLaberinto(N, M, listmap);
	
	// Guardamos los datos del laberinto en una struct Laberinto.
	Laberinto* L = guardarDatosLaberinto(N, M, matrizLaberinto);
	
	// Recorremos la matriz del laberinto buscando la LLAVE.
	recorrerLaberinto(L, LLAVE);
	printf("Llave encontrada.\n");
	
	// Recorremos la matriz del laberinto buscando la SALIDA.
	recorrerLaberinto(L, SALIDA);
	printf("Salida encontrada.\n");

	// Escribimos la solucion del laberinto en un archivo. 
	// "Salida.out".
	escribirLaberinto(L);

	printf("//---- Solucionador Terminado. ----//\n");
	return TRUE;
}