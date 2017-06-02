#include <stdlib.h>
#include <stdio.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <Lectura.h>
//#include <Lectura.h>

int main(int argc, char const *argv[])
{
	Arbol* arbol = NULL;
	//char *nombre = NULL;
	//nombre = obtenerNombreArchivo();
	// Cambiar nombre de leer archivo, por obtenerArbol
	arbol = leerArchivo("Telefonos.in");
	printf("\nin orden es: \n\n");
	inOrden(arbol);
	//MenuArboles();
	return 0;
}