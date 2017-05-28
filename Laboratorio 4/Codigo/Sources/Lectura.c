/**
	@file Lectura.c
	@brief Modulo de Lectura del programa.
	
	Funciones de lectura.

	@author Cristobal Medrano
	@date 18/05/2017
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <Estructuras.h>
#include <Lectura.h>


/**
	@brief Funcion que obtiene el nombre del archivo ingresado por el usuario.
	@returns el nombre ingresado por el usuario.
*/
char* obtenerNombreArchivo()
{
	static char leerNombre[256];
	fflush(stdin); // Limpiamos buffer de entrada.
	printf("Ingrese nombre del archivo: \n");
	scanf("%s", leerNombre);
	fflush(stdin); // Limpiamos buffer.
	return leerNombre;
}

/**
	@brief Funcion que lee el archivo de texto.
	@param nombre : Nombre del archivo de texto a leer.
	@returns listaGrafo con los datos del archivo de texto.
*/
int* leerArchivo(char* nombre)
{
	int* listaUsuarios = NULL;
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");

	// Si la lectura del archivo es correcta, inicializamos variables.
	if(archivoEntrada != NULL)
    {
    	int i = 0;
    	char usuario[256];
    	int cantidadUsuarios;

    	fscanf(archivoEntrada, "%d", &cantidadUsuarios);
    	
    	listaUsuarios = (int*)malloc(sizeof(int)*(5*cantidadUsuarios));
    	// Si la asignacion de memoria es correcta, iniciamos la lectura.
    	if (listaUsuarios != NULL)
    	{
    		
    		listaUsuarios[i] = cantidadUsuarios;
	    	while(i+1 < cantidadUsuarios)
	    	{
	    		fscanf(archivoEntrada, " %c", &listaUsuarios);
		    	i++;
	    	}
    	}
    	else 
    	{
    		printf("\n- Error de Memoria. Funcion leerArchivo: No se pudo asignar la memoria solicitada.\n\n");
    		return NULL;
    	}
    } else 
    { 
    	printf("\n- Error de Lectura. Funcion leerArchivo: El archivo ingresado no existe.\n\n");
    	return NULL;	
    }
    fclose(archivoEntrada);
    return listaUsuarios;
}