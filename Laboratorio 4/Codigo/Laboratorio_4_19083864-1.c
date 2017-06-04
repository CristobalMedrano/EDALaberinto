#include <stdlib.h>
#include <stdio.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_LE.h>
#include <Lectura.h>
#include <Ejecucion.h>
#include <Escritura.h>

int main(int argc, char const *argv[])
{
	Arbol* arbolDatos = NULL;
	Lista* listaBusqueda = NULL;
	Lista* listaUsuarios_Encontrados = NULL;
	int escritura = FALSE;
	char *nombre = NULL;

	// Modulo de Lectura
	
	//nombre = obtenerNombreArchivo();
	arbolDatos = crearArbol("Telefonos.in");

	//nombre = obtenerNombreArchivo();
	listaBusqueda = obtenerListaBusqueda("Buscados.in");

	// Modulo de Busqueda

	listaUsuarios_Encontrados = buscarDatos_Usuario(arbolDatos, listaBusqueda);

	// Modulo de Escritura

	escritura = escribirArchivo(listaUsuarios_Encontrados);
	
	//printf("\nin orden es: \n\n");
	//inOrden(arbolDatos);

	//MenuArboles();
	return 0;
}