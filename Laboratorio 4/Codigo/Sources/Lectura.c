/**
	@file Lectura.c
	@brief Modulo de Lectura del programa.
	
	Funciones de lectura.

	@author Cristobal Medrano
	@date 18/05/2017
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Estructuras.h>
#include <Lectura.h>
#include <TDA_ABO.h>



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

char* obtenerUsuario(FILE* archivoEntrada)
{
	char* usuario = (char*)malloc(sizeof(char)*256);
	if (usuario != NULL)
	{
		char primerNombre[40];
		char segundoNombre[40];
		char primerApellido[40];
		char segundoApellido[40];
		char codigoPais[10];
		int codigoNCiudad;
		char codigoCiudad[4];
		int NprimerNumero;
		char primerNumero[4];
		int NsegundoNumero;
		char segundoNumero[4];

		// Primer nombre
		fscanf(archivoEntrada, "%s", primerNombre);
		// Segundo nombre
		fscanf(archivoEntrada, "%s", segundoNombre);
		// Primer apellido
		fscanf(archivoEntrada, "%s", primerApellido);
		// Segundo apellido
		fscanf(archivoEntrada, "%s", segundoApellido);
		// Codigo Pais
		fscanf(archivoEntrada, "%s", codigoPais);
		// Codigo Ciudad
		fscanf(archivoEntrada, "%d", &codigoNCiudad);
		// Convierte el codigo numerico en string.
		sprintf(codigoCiudad, "%d", codigoNCiudad);
		// Primer Numero
		fscanf(archivoEntrada, "%d", &NprimerNumero);
		// Convierte el primer numero en string.
		sprintf(primerNumero, "%d", NprimerNumero);
		// Segundo Numero
		fscanf(archivoEntrada, "%d", &NsegundoNumero);
		// Convierte el segundo numero en string.
		sprintf(segundoNumero, "%d", NsegundoNumero);

		
		// Concatenamos el nombre del archivo.
		strcpy(usuario, primerNombre);
		strcat(usuario, " ");
		strcat(usuario, segundoNombre);
		strcat(usuario, " ");
		strcat(usuario, primerApellido);
		strcat(usuario, " ");
		strcat(usuario, segundoApellido);
		strcat(usuario, " ");
		strcat(usuario, codigoPais);
		strcat(usuario, " ");
		strcat(usuario, codigoCiudad);
		strcat(usuario, " ");
		strcat(usuario, primerNumero);
		strcat(usuario, " ");
		strcat(usuario, segundoNumero);
		return usuario;
	}
	else
	{
		printf("\n- Error de Memoria. Funcion obtenerUsuario: No se pudo asignar la memoria solicitada.\n\n");
	}
	

	return usuario;
}

/**
	@brief Funcion que lee el archivo de texto.
	@param nombre : Nombre del archivo de texto a leer.
	@returns listaGrafo con los datos del archivo de texto.
*/
Arbol* leerArchivo(char* nombre)
{
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");
	Arbol* nuevoArbol = NULL;
	// Si la lectura del archivo es correcta, inicializamos variables.
	if(archivoEntrada != NULL)
	{
		int cantidadUsuarios;
		fscanf(archivoEntrada, "%d", &cantidadUsuarios);
		char* usuario = NULL;
		int i = 0;
		while (i < cantidadUsuarios)
		{
			usuario = obtenerUsuario(archivoEntrada);
			if (usuario != NULL)
			{
				nuevoArbol = insertarDato(nuevoArbol, usuario);
			}
			i++;
		}

	} else 
	{ 
		printf("\n- Error de Lectura. Funcion leerArchivo: El archivo ingresado no existe.\n\n");
		return NULL;	
	}
	fclose(archivoEntrada);
	return nuevoArbol;
}