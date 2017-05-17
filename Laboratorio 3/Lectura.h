#ifndef LECTURA

#define LECTURA
//#define DEBUG

/**
	@typedef grafo
	@struct Grafo
	@brief Estructura del grafo.
	Recibe la cantidad de vertices.
	Recibe un vertice Entrada. 
	Recibe un vertice Llave.
	Recibe un vertice Salida.
	Recibe una matrizAdyacencia que contiene al grafo.

*/
typedef struct grafo 
{
	int Vertices;
	int Entrada;
	int Llave;
	int Salida;
	int** MatrizAdyacencia;
}Grafo;


int* leerArchivo(char* nombre);
char* obtenerNombreArchivo();
int** obtenerMatrizAdyacencia(int* listaGrafo);
Grafo* guardarDatos(int vertices, int entrada, int llave, int salida, int** matrizAdyacencia);
#endif