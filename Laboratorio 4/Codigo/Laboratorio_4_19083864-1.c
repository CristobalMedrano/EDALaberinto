#include <stdlib.h>
#include <stdio.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <Lectura.h>

int main(int argc, char const *argv[])
{
	char *nombre = NULL;
	nombre = obtenerNombreArchivo();
	int* listaUsuarios = leerArchivo(nombre);
	for (int i = 0; i < 17; ++i)
	{
		printf("%s\n", listaUsuarios[i]);
	}
	//MenuArboles();
	return 0;
}