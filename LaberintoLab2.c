/**
	@file LaberintoLab2.c
	@brief Programa que resuelve laberintos.

	Programa que hace uso de listas enlazadas
	Busca el camino minimo dentro del laberinto

	@author Cristobal Medrano Alvarado - 19083864-1
	@date 27/04/2017
*/

#include <stdio.h>
#include <stdlib.h>

// Bloque de define.
#define DEBUG2
#define TRUE 1
#define FALSE 0
#define LLAVE 0
#define SALIDA 1

#define ARRIBA 0
#define ABAJO 1
#define IZQUIERDA 2
#define DERECHA 3

// Bloque de estructuras.
/**
	@typedef Lista
	@struct Lista
	@brief Estructura de Lista, recibe un dato(int) y un puntero a la
	siguiente Lista.
*/
typedef struct Lista
{
	int dato;
	struct Lista *siguiente;
} Lista;

/**
	@typedef Laberinto
	@struct Lista
	@brief Estructura del laberinto.
	Recibe la cantidad de filas y columnas (N y M respectivamente)
	Recibe una matriz que contiene el laberinto inicial
	Recibe una matriz que contiene el laberinto desarrollado desde la entrada hasta la llave.
	Recibe una matriz que contiene el laberinto desarrollado desde la llave a la salida.
	Recibe un contador del camino minimo
	Recibe un contador del camino minimo desde la entrada a la llave
	Recibe un contador del camino minimo desde la llave a la salida 
*/
typedef struct laberinto
{
	int N; // Filas
	int M; // Columnas
	int** matrizLaberinto;
	int** matrizEntradaLlave;
	int** matrizLlaveSalida;
	int contCaminoMinimo;
	int contCaminoMinimoLlave;
	int contCaminoMinimoSalida;
} Laberinto;

// Bloque de encabezados.
int* leerArchivo(char Nombre[20], int *N, int *M);
int** obtenerMatrizLaberinto(int N, int M, int* listmap);
Laberinto* guardarDatosLaberinto(int N, int M, int** matrizLaberinto);
void recorrerLaberinto(Laberinto* L, char busqueda);
void buscarPuerta(int *datoX, int *datoY, Laberinto* L, char letra);
int** obtenerMatrizTemporal(Laberinto* L);
void direccionarLaberinto(int Pix, int Piy, int Pfx, int Pfy, int** cRecorrido,
						   Laberinto* L, int busqueda);
int conCamino(Laberinto* L, int** cRecorrido);
void guardarCaminoMin(Laberinto* L, int** cRecorrido, int caminoMin, int busqueda);
Lista* crearNodo();
Lista* InsertarFinal(Lista* L, int dato);
int obtener(Lista* L, int pos);
int largo(Lista* L);
Lista* buscarPosiciones(Laberinto* Lab, int busqueda);
Lista* guardarDireccion(Laberinto* Lab, Lista* L, int i, int j, int busqueda);



Lista* guardarDireccion(Laberinto* Lab, Lista* L, int i, int j, int busqueda);
// Bloque de funciones.

/**
	@brief Funcion que lee el archivo
	@param Nombre del archivo
	@param N cantidad de filas
	@param M cantidad de columnas
	@returns listmap, que contiene el laberinto leido.
	@returns -1 si no fue posible leer el archivo.
*/
int* leerArchivo(char Nombre[20], int *N, int *M)
{
	int* listmap; // Lista del laberinto

	FILE *archivoEntrada;
	archivoEntrada = fopen(Nombre, "r");
	if(archivoEntrada == NULL)
    {
        printf("Error al abrir archivo");
        return NULL;
    }

	fscanf(archivoEntrada,"%d",&*N);
	fscanf(archivoEntrada,"%d",&*M);

	int i = 0;
	int Largo = (*N**M);
	int valor = 0;
	listmap = (int*)malloc(sizeof(int)*Largo);

	while (i < Largo)
	{
		fscanf(archivoEntrada, " %c", &valor);
		listmap[i] = valor;
		i++;
	}
	fclose(archivoEntrada);
	printf("Archivo leido Correctamente.\n");
	return listmap;
}

/**
	@brief Funcion que convierte la lista del laberinto en una matriz.
	@param N cantidad de filas
	@param M cantidad de columnas
	@param listmap un puntero a la lista del laberinto.
	@returns matrizLaberinto, la cual contiene el laberinto.
*/
int** obtenerMatrizLaberinto(int N, int M, int* listmap)
{
	// Asignamos memoria a la matriz.
	int k;
	int **matrizLaberinto = (int **)malloc(N * sizeof(int *));
							for (k = 0; k < N; k++)
							matrizLaberinto[k] = (int *)malloc(M * sizeof(int));
	int i;
	int j;
	int pos = 0;
	for(i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			matrizLaberinto[i][j] = listmap[pos];
			pos++;
		}
	}

	return matrizLaberinto;
}
/**
	@brief Funcion que guarda en la estructura laberinto, los datos del laberinto.
	@param Filas cantidad de filas
	@param Columnas cantidad de columnas
	@param inLaberinto matriz con laberinto inicial.
	@returns nuevolaberinto, del tipo Laberinto*.
*/
Laberinto* guardarDatosLaberinto(int Filas, int Columnas, int** inLaberinto)
{
	Laberinto* nuevolaberinto = (Laberinto*)malloc(sizeof(Laberinto));

	int i;
	int** inEntradaLlave = (int **)malloc(Filas * sizeof(int *));
							for (i = 0; i < Filas; ++i)
							inEntradaLlave[i] = (int *)malloc(Columnas * sizeof(int));

	// Crear pedir memoria.
	int** inLlaveSalida = (int **)malloc(Filas * sizeof(int *));
							for (i = 0; i < Filas; ++i)
							inLlaveSalida[i] = (int *)malloc(Columnas * sizeof(int));

	// Guardo los datos en la estructura laberinto.
	nuevolaberinto->N = Filas;
	nuevolaberinto->M = Columnas;
	nuevolaberinto->matrizLaberinto = inLaberinto;
	nuevolaberinto->matrizEntradaLlave = inEntradaLlave;
	nuevolaberinto->matrizLlaveSalida = inLlaveSalida;
	return nuevolaberinto;
}
/**
	@brief Procedimiento que obtiene los datos inciales para recorrer.
	@param L es el puntero de la estructura Laberinto
	@param busqueda es el elemento a buscar en el laberinto.
*/
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
/**
	@brief Procedimiento que busca las coordenadas de un caracter en especifico.
	@param datoX posicion del dato en X.
	@param datoY posicion del dato en Y.
	@param L puntero a la estructura Laberinto, para obtener datos en el.
	@param letra caracter a buscar.
*/
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
			}
		}
	}
}
/**
	@brief Funcion que genera una matriz temporal sin caracteres de entrada, llave o salida en ella.
	@param L, puntero a la estructura Laberinto con el fin de obtener el laberinto principal.
	@return cRecorrido, matriz temporal solo con caracteres * y .
*/
int** obtenerMatrizTemporal(Laberinto* L)
{
	int i;
	int j;
	int** cRecorrido = (int **)malloc(L->N * sizeof(int *));
						 for (i = 0; i < L->N; ++i)
						 cRecorrido[i] = (int *)malloc(L->M * sizeof(int));
	
	for (i = 0; i < L->N; ++i)
	{
		for (j = 0; j < L->M; ++j)
		{
			cRecorrido[i][j] = L->matrizLaberinto[i][j];
			switch (cRecorrido[i][j]) 
			{
				case 'E' : cRecorrido[i][j] = '.';
						   break;
				case 'K' : cRecorrido[i][j] = '.';
						   break;
				case 'S' : cRecorrido[i][j] = '.';
						   break;
			}
		}
	}
	return cRecorrido;
}
/**
	@brief Procedimiento que busca todas las soluciones del laberinto.
	@param Pix Posicion de entrada en x.
	@param Piy Posicion de entrada en y.
	@param Pfx Posicion de salida en x.
	@param Pfy Posicion de salida en y.
	@param cRecorrido matriz temporal que guarda el recorrido.
	@param L puntero a la estructura Laberinto, para obtener y guardar datos en el.
	@param busqueda elemento a buscar en el laberinto.

*/
void direccionarLaberinto(int Pix, int Piy, int Pfx, int Pfy, int** cRecorrido,
						   Laberinto* L, int busqueda)
{
	if(Pix == Pfx && Piy == Pfy)
	{
		// Contamos la cantidad de pasos a recorrer.
		int caminoMin = conCamino(L, cRecorrido);
		// Comparamos la cantidad de pasos obtenida y seleccionamos la mas corta.
		guardarCaminoMin(L, cRecorrido, caminoMin, busqueda);
		// Guardamos las direcciones 
		
	}
	// ----------------------DERECHA----------------------------//
	// Caminar hacia la derecha.
	
	if (Piy <= L->M-2 && cRecorrido[Pix][Piy+1] != '*' && cRecorrido[Pix][Piy+1] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		direccionarLaberinto(Pix, Piy+1, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia la derecha (Pac-Man).
	if (Piy == L->M-1 && cRecorrido[Pix][Piy] != '*' && cRecorrido[Pix][Piy] != 'x')
	{	
		cRecorrido[Pix][L->M-1] = 'x';
		cRecorrido[Pix][0] = 'x';
		direccionarLaberinto(Pix, Piy-(L->M-1), Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------ABAJO----------------------------//
	// Caminar hacia abajo.
	if (Pix <= L->N-2 && cRecorrido[Pix+1][Piy] != '*' && cRecorrido[Pix+1][Piy] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		direccionarLaberinto(Pix+1, Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}	
	// Cruzar hacia abajo (Pac-Man)	
	if (Pix == L->N-1 && cRecorrido[Pix][Piy] != '*' && cRecorrido[Pix][Piy] != 'x')
	{
		cRecorrido[L->N-1][Piy] = 'x';
		cRecorrido[0][Piy] = 'x';
		direccionarLaberinto(Pix-(L->N-1), Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------IZQUIERDA----------------------------//
	// Caminar hacia izquierda.
	if (Piy >= 1 && cRecorrido[Pix][Piy-1] != '*' && cRecorrido[Pix][Piy-1] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		direccionarLaberinto(Pix, Piy-1, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia izquierda (Pac-Man)
	if (Piy == 0 && cRecorrido[Pix][Piy] != '*' && cRecorrido[Pix][Piy] != 'x')
	{
		cRecorrido[Pix][0] = 'x';
		cRecorrido[Pix][L->M-1] = 'x';
		direccionarLaberinto(Pix, Piy+(L->M-1), Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------ARRIBA----------------------------//
	// Caminar hacia arriba.
	if (Pix >= 1 && cRecorrido[Pix-1][Piy] != '*' && cRecorrido[Pix-1][Piy] != 'x')
	{
		cRecorrido[Pix][Piy] = 'x';
		direccionarLaberinto(Pix-1, Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// Cruzar hacia arriba (Pac-Man)
	if (Pix == 0 && cRecorrido[Pix][Piy] != '*' && cRecorrido[Pix][Piy] != 'x')
	{
		cRecorrido[0][Piy] = 'x';
		cRecorrido[L->N-1][Piy] = 'x';
		direccionarLaberinto(Pix+(L->N-1), Piy, Pfx, Pfy, cRecorrido, L, busqueda);
	}
	// ----------------------DEVOLVER----------------------------//
	cRecorrido[Pix][Piy] = '.';
}
/**
	@brief Funcion que lee la cantidad de camino recorrido.
	@param L puntero a la estructura Laberinto, para obtener datos.
	@param cRecorrido matriz temporal que aloja el recorrido del laberinto.
	@returns caminoMin, que contiene la cantidad total de pasos a recorrer.
*/
int conCamino(Laberinto* L, int** cRecorrido)
{
	int caminoMin = 0;
	for (int i = 0; i < L->N; ++i)
	{
		for (int j = 0; j < L->M; ++j)
		{
			if(cRecorrido[i][j] == 'x')
			{
				caminoMin++;
			}		
		}
	}
	return caminoMin;
}
/**
	@brief Procedimiento que guarda el camino minimo en la estructura Laberinto.
	@param L contiene los datos de la estructura Laberinto.
	@param caminoMin contiene la cantidad de camino a recorrer.
	@param busqueda caracter a buscar en la funcion, sirve para diferenciar donde guardar los datos. 
*/
void guardarCaminoMin(Laberinto* L, int** cRecorrido, int caminoMin, int busqueda)
{
	// Guardamos el camino minimo.
	for (int i = 0; i < L->N; ++i)
	{
		for (int j = 0; j < L->M; ++j)
		{
			if(L->contCaminoMinimo >= caminoMin)
			{
				L->contCaminoMinimo = caminoMin;
				switch(busqueda)
 				{
 					case LLAVE: L->contCaminoMinimoLlave = L->contCaminoMinimo;
 								L->matrizEntradaLlave[i][j] = cRecorrido[i][j];
 								break;
 					case SALIDA: L->contCaminoMinimoSalida = L->contCaminoMinimo;
 								 L->matrizLlaveSalida[i][j] = cRecorrido[i][j];
 								 break;
 				}
			}
		}
	}
}
// Funcion que encuentra las posiciones con letras.
/**
	@brief Funcion que encuentra las posiciones de las letras.
	@param Lab, puntero a la estructura Laberinto.
	@param busqueda, elemento a buscar en la matriz.
	@returns L, Lista enlazada que contiene el camino a recorrer en palabras.
*/
Lista* buscarPosiciones(Laberinto* Lab, int busqueda)
{
	int Ex = 0; // Entrada en X.
	int Ey = 0; // Entrada en Y.
	int Lx = 0; // Llave en X.
	int Ly = 0; // Llave en Y.
	int Sx = 0; // Salida en X.
	int Sy = 0; // Salida en Y.

	buscarPuerta(&Ex, &Ey, Lab, 'E');
	buscarPuerta(&Sx, &Sy, Lab, 'S');
	buscarPuerta(&Lx, &Ly, Lab, 'K');

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

	Lista * L = NULL;
	int i= Pix;
	int j= Piy;
	L = guardarDireccion(Lab, L, i, j, busqueda);
	return L;
}

/**
	@brief Funcion que guarda la direccion a caminar en la lista enlazada.
	@param Lab, puntero a la estructura laberinto para obtener datos de ella.
	@param L, puntero a la Lista enlazada que contendra los pasos.
	@param i, posicion inicial en x.
	@param j, posicion inicial en y.
	@param busqueda, filtro de busqueda.
	@returns L con el paso a paso para recorrer el laberinto.
*/
Lista* guardarDireccion(Laberinto* Lab, Lista* L, int i, int j, int busqueda)
{
	int cont= 0;
	if(busqueda == LLAVE)
	{
		while(cont < Lab->contCaminoMinimoLlave-1){
			// Arriba
			if(Lab->matrizEntradaLlave[i-1][j] == 'x')
			{
				L = InsertarFinal(L, ARRIBA);
				i--;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
			// Cruzar Arriba
			if(i == 0)
			{
				i = Lab->N-1;
				L = InsertarFinal(L, ARRIBA);
				Lab->matrizEntradaLlave[i][j] = '*';
				cont++;
				L = InsertarFinal(L, ARRIBA);
				i--;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
			// Abajo
			if(Lab->matrizEntradaLlave[i+1][j] == 'x')
			{
				L = InsertarFinal(L, ABAJO);
				i++;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
				
			}
			// Cruzar abajo
			if(i == Lab->N-1)
			{
				i = 0;
				L = InsertarFinal(L, ABAJO);
				Lab->matrizEntradaLlave[i][j] = '*';
				cont++;
				L = InsertarFinal(L, ABAJO);
				i++;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
			// Izquierda
			if(Lab->matrizEntradaLlave[i][j-1] == 'x')
			{
				L = InsertarFinal(L, IZQUIERDA);
				j--;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
			// Cruzar Izquierda
			if(j == 0)
			{
				j = Lab->M-1;
				L = InsertarFinal(L, IZQUIERDA);
				Lab->matrizEntradaLlave[i][j] = '*';
				cont++;
				L = InsertarFinal(L, IZQUIERDA);
				j--;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
			// Derecha
			if(Lab->matrizEntradaLlave[i][j+1] == 'x')
			{
				L = InsertarFinal(L, DERECHA);
				j++;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
			// Cruzar Derecha
			if(j == Lab->M-1)
			{
				j = 0;
				L = InsertarFinal(L, DERECHA);
				Lab->matrizEntradaLlave[i][j] = '*';
				cont++;
				L = InsertarFinal(L, DERECHA);
				j++;
				cont++;
				Lab->matrizEntradaLlave[i][j] = '*';
			}
		}
	}
	if(busqueda == SALIDA)
	{
		while(cont < Lab->contCaminoMinimoSalida-1){
			// Arriba
			if(Lab->matrizLlaveSalida[i-1][j] == 'x')
			{
				L = InsertarFinal(L, ARRIBA);
				i--;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
			// Cruzar Arriba
			if(i == 0)
			{
				i = Lab->N-1;
				L = InsertarFinal(L, ARRIBA);
				Lab->matrizLlaveSalida[i][j] = '*';
				cont++;
				L = InsertarFinal(L, ARRIBA);
				i--;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
			// Abajo
			if(Lab->matrizLlaveSalida[i+1][j] == 'x')
			{
				L = InsertarFinal(L, ABAJO);
				i++;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
				
			}
			// Cruzar abajo
			if(i == Lab->N-1)
			{
				i = 0;
				L = InsertarFinal(L, ABAJO);
				Lab->matrizLlaveSalida[i][j] = '*';
				cont++;
				L = InsertarFinal(L, ABAJO);
				i++;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
			// Izquierda
			if(Lab->matrizLlaveSalida[i][j-1] == 'x')
			{
				L = InsertarFinal(L, IZQUIERDA);
				j--;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
			// Cruzar Izquierda
			if(j == 0)
			{
				j = Lab->M-1;
				L = InsertarFinal(L, IZQUIERDA);
				Lab->matrizLlaveSalida[i][j] = '*';
				cont++;
				L = InsertarFinal(L, IZQUIERDA);
				j--;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
			// Derecha
			if(Lab->matrizLlaveSalida[i][j+1] == 'x')
			{
				L = InsertarFinal(L, DERECHA);
				j++;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
			// Cruzar Derecha
			if(j == Lab->M-1)
			{
				j = 0;
				L = InsertarFinal(L, DERECHA);
				Lab->matrizLlaveSalida[i][j] = '*';
				cont++;
				L = InsertarFinal(L, DERECHA);
				j++;
				cont++;
				Lab->matrizLlaveSalida[i][j] = '*';
			}
		}
	}
	return L;	
}

/**
	@brief Procedimiento que escribe la solucion del laberinto en un archivo.
	@param L, puntero a la estructura Laberinto que contiene los datos a guardar.
*/
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

	// Escribimos cada posicicion de la matrizEntradaLlave en el archivo.
	for (i = 0; i < L->N; i++)
	{
		for (j = 0; j < L->M; j++)
		{
			fprintf(archivoSalida, "%c", L->matrizEntradaLlave[i][j]);
		}
		fprintf(archivoSalida,"\n");
	}
	// Escribimos los pasos a recorrer desde la entrada a la llave.
	fprintf(archivoSalida, "\n");
	escribirPasos(archivoSalida, LLAVE, L);
	fprintf(archivoSalida, "\n");

	// Escribimos cada posicicion de la matrizLlaveSalida en el archivo.
	for (i = 0; i < L->N; i++)
	{
		for (j = 0; j < L->M; j++)
		{
			fprintf(archivoSalida, "%c", L->matrizLlaveSalida[i][j]);
		}
		fprintf(archivoSalida,"\n");
	}
	// Escribimos los pasos a recorrer desde la llave a la salida.
	fprintf(archivoSalida, "\n");
	escribirPasos(archivoSalida, SALIDA, L);

	printf("Archivo escrito Correctamente.\n");
    fclose(archivoSalida);
}
/**
	@brief Procedimiento que escribe el paso a paso en el archivo de salida.
	@param archivoSalida, puntero al archivo de salida
	@param busqueda, filtro para diferenciar el tipo de dato a guardar.
	@param L, puntero a la estructura laberinto que contiene los datos a guardar.
*/
void escribirPasos(FILE* archivoSalida, int busqueda, Laberinto* L)
{
	Lista* lista = buscarPosiciones(L, busqueda);
	int i;
	for (i = 0; i < largo(lista); i++)
	{

		switch(busqueda)
		{
			case LLAVE: if (obtener(lista,i) == ARRIBA)
						{
							fprintf(archivoSalida, "Arriba\n");
						}
						if (obtener(lista,i) == ABAJO)
						{
							fprintf(archivoSalida, "Abajo\n");
						}
						if (obtener(lista,i) == IZQUIERDA)
						{
							fprintf(archivoSalida, "Izquierda\n");
						}
						if (obtener(lista,i) == DERECHA)
						{
							fprintf(archivoSalida, "Derecha\n");
						}

						break;
			case SALIDA:if (obtener(lista,i) == ARRIBA)
						{
							fprintf(archivoSalida, "Arriba\n");
						}
						if (obtener(lista,i) == ABAJO)
						{
							fprintf(archivoSalida, "Abajo\n");
						}
						if (obtener(lista,i) == IZQUIERDA)
						{
							fprintf(archivoSalida, "Izquierda\n");
						}
						if (obtener(lista,i) == DERECHA)
						{
							fprintf(archivoSalida, "Derecha\n");
						}
						break;
		}
	}	
}
/**
	@brief Funcion que crea un nodo.
	@param dato es el elemento a guardar en la lista.
	@returns Lista (puntero), si fue creada exitosamente.
	@returns NULL, si no fue creada.
*/
Lista* crearNodo()
{
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	//Si la asignacion de memoria es exitosa, se inicializan las variables
	if(lista!=NULL){
	    lista->dato = 0;
		lista->siguiente = NULL;
		return lista;
	}
	else{
		return NULL;
	}
}
/**
	@brief Funcion que inserta un elemento al final de la lista.
	@param L es una Lista de nodos.
	@param dato es el elemento a guardar en la lista.
	@returns Lista (puntero), con los datos actualizados.
*/
Lista* InsertarFinal(Lista* L, int dato)
{
	//Se crea una nueva lista
	Lista *nuevo = crearNodo();
	Lista *aux = crearNodo();
	//Se comprueba si se realiza con exito
	//Si la lista es creada con exito
	if(nuevo!=NULL){
        //Se ve si L esta vacia
        if (L==NULL){
            //En ese caso, L sera igual a la nueva lista que creamos
        	L = nuevo;
            nuevo->dato = dato;
            nuevo->siguiente = NULL;
            return L;
        }
        else
        { 
        	// Aux sera igual a L.
        	aux = L;
        	// Ubicamos el puntero en el ultimo nodo.
        	while(aux->siguiente != NULL)
        	{
        		aux = aux->siguiente;
        	}
        	// Asignamos la ultima posicion al nuevo nodo.
        	aux->siguiente = nuevo;
        	nuevo->dato = dato;
        	nuevo->siguiente = NULL;
        	// Retornamos la lista.
        	return L;
        }

	}
	//En caso que la asignacion de memoria falle, se avisa del error y se retorna la lista L
	else{
        printf("Error en la asignacion de memoria\n");
        return L;
    }
}
/**
	@brief Funcion que obtiene un elemento de la lista, segun la posicion.
	@param L lista con los nodos.
	@param pos posicion del elemento a buscar.
	@returns elemento si la ejecucion fue correcta.
	@returns -1 si la posicion es invalida.
*/
int obtener(Lista* L, int pos)
{
	int i;
	if(pos < 0)
	{
		return -1;
	}
	i = 0;
	Lista* indice = L;
	while(indice != NULL && i < pos)
	{
		indice = indice->siguiente;
		i++;
	}
	if(indice == NULL)
	{
		return -1;
	}
	return indice->dato;
}
/**
	@brief Funcion que obtiene el largo de la lista.
	@param L lista con los nodos.
	@returns int con el largo de la lista.
*/
int largo(Lista* L)
{
	int i = 0;
	Lista* indice = L;
	while(indice != NULL)
	{
		indice = indice->siguiente;
		i++;
	}
	return i;
}


 /**
	@brief Funcion main que ejecuta cada una de las funciones.
	@returns 0 si su ejecucion fue correcta.
 */

int main(int argc, char const *argv[])
{
	int N;
	int M;
	int* listmap = leerArchivo("Entrada.in", &N, &M);
	if(listmap != NULL)
	{
		int** matrizLaberinto;
		printf("\n //---- Iniciando Solucionador. ----// \n");
		
		// Creamos una matriz para el laberinto.
		matrizLaberinto = obtenerMatrizLaberinto(N, M, listmap);
		
		// Guardamos los datos del laberinto en una struct Laberinto.
		Laberinto* L = guardarDatosLaberinto(N, M, matrizLaberinto);
			
		// Recorremos la matriz del laberinto buscando la LLAVE.
		L->contCaminoMinimo = N*M;
		recorrerLaberinto(L, LLAVE);
		printf("--- Llave encontrada. ---\n");
		
		// Recorremos la matriz del laberinto buscando la SALIDA.
		L->contCaminoMinimo = N*M;
		recorrerLaberinto(L, SALIDA);
		printf("Salida encontrada.\n");

		// Escribimos la solucion del laberinto en un archivo. 
		// "Salida.out".
		escribirLaberinto(L);
	}
	printf("//---- Solucionador Terminado. ----//\n");
	return TRUE;
}
