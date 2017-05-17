#ifndef ESTRUCTURAS

#define ESTRUCTURAS

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

typedef struct casilla
{
	int anterior;
	int costo;
} Casilla;

/**
	@typedef lista
	@struct Lista
	@brief Estructura de Lista, recibe un dato(int) y un puntero a la
	siguiente Lista.
*/
typedef struct lista
{
	int dato;
	struct lista *siguiente;
} Lista;

#endif