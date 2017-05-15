#ifndef LECTURA

#define LECTURA
#define DEBUG

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
Grafo* guardarDatos(int vertices, int entrada, int llave, int salida, int** matrizAdyacencia);
#endif