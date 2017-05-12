#include <stdlib.h>
#include <stdio.h>
//#include "LeerArchivo.h"

void leerArchivo(char* nombre);
char* obtenerNombreArchivo();


char* obtenerNombreArchivo()
{
	static char leerNombre[256];
	fflush(stdin); // Limpiamos buffer de entrada.
	printf("Ingrese nombre del archivo: \n");
	if (scanf("%s", &leerNombre) != 0)
	{
		// Obtenemos el contenido del buffer que sea distinto a salto de linea.
	    while (getchar() != '\n');
	    fflush(stdin); // Limpiamos buffer.
	}
	return leerNombre;
}

void leerArchivo(char* nombre)
{
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");
	
	if(archivoEntrada != NULL)
    {
        printf("Leemos los datos.\n");
    } else 
    {
    	printf("No se pudo leer el archivo.\n");
    }
}

int main(int argc, char const *argv[])
{
	char *nombre = obtenerNombreArchivo();
	printf("Opcion Leida = %s\n", nombre);
	leerArchivo(nombre);

	return 0;
}