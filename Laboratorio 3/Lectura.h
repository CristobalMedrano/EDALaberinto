#ifndef LECTURA

#define LECTURA
#define DEBUG

int* leerArchivo(char* nombre);
char* obtenerNombreArchivo();
int** obtenerMatrizAdyacencia(int* listaGrafo);
Grafo* guardarDatos(int vertices, int entrada, int llave, int salida, int** matrizAdyacencia);
#endif