/**
	@file Lectura.c
	@brief Modulo de Lectura del programa.
	
	Funciones de lectura.

	@author Cristobal Medrano
	@date 27/05/2017
  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Estructuras.h>
#include <Lectura.h>
#include <TDA_ABO.h>
#include <TDA_LE.h>

/**
	@brief Funcion que obtiene el nombre del archivo ingresado por el usuario.
	@returns nombreArchivo ingresado por el usuario.
*/
char* obtenerNombreArchivo()
{
	static char nombreArchivo[256];
	fflush(stdin); // Limpiamos buffer de entrada.
	scanf("%s", nombreArchivo);
	fflush(stdin); // Limpiamos buffer.
	return nombreArchivo;
}

/**
	@brief Funcion que lee el nombre de usuario, desde un
	archivo de texto.in
	@param archivoEntrada, archivo tipo FILE* con la direccion
	de memoria del archivo leido.
	@returns nombreUsuario, nombre del usuario.
	@returns NULL, si no fue posible leer el nombre.
*/
char* leerNombre_Usuario(FILE* archivoEntrada)
{
	char* nombreUsuario = (char*)malloc(sizeof(char)*256);
	if (nombreUsuario != NULL)
	{
		char primerNombre[64];
		char segundoNombre[64];
		char primerApellido[64];
		char segundoApellido[64];

		// Primer nombre
		fscanf(archivoEntrada, "%s", primerNombre);
		// Segundo nombre
		fscanf(archivoEntrada, "%s", segundoNombre);
		// Primer apellido
		fscanf(archivoEntrada, "%s", primerApellido);
		// Segundo apellido
		fscanf(archivoEntrada, "%s", segundoApellido);
		
		// Concatenamos el nombre del archivo.
		strcpy(nombreUsuario, primerNombre);
		strcat(nombreUsuario, " ");
		strcat(nombreUsuario, segundoNombre);
		strcat(nombreUsuario, " ");
		strcat(nombreUsuario, primerApellido);
		strcat(nombreUsuario, " ");
		strcat(nombreUsuario, segundoApellido);

		return nombreUsuario;
	}
	else
	{
		printf("\n- Error de Memoria. Funcion leerNombre_Usuario: No se pudo asignar la memoria solicitada.\n\n");
		return NULL;
	}
	

	return nombreUsuario;
}

/**
	@brief Funcion que lee el numero telefonico del usuario, desde un
	archivo de texto.in
	@param archivoEntrada, archivo tipo FILE* con la direccion
	de memoria del archivo leido.
	@returns usuario, numero telefonico del usuario.
	@returns NULL, si no fue posible leer el telefono.
*/
char* leerTelefono_Usuario(FILE* archivoEntrada)
{
	char* telefonoUsuario = (char*)malloc(sizeof(char)*256);
	if (telefonoUsuario != NULL)
	{
		char codigoPais[10];
		int codigoNCiudad;
		char codigoCiudad[4];
		int NprimerNumero;
		char primerNumero[4];
		int NsegundoNumero;
		char segundoNumero[4];

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
		strcpy(telefonoUsuario, codigoPais);
		strcat(telefonoUsuario, " ");
		strcat(telefonoUsuario, codigoCiudad);
		strcat(telefonoUsuario, " ");
		strcat(telefonoUsuario, primerNumero);
		strcat(telefonoUsuario, " ");
		strcat(telefonoUsuario, segundoNumero);
		return telefonoUsuario;
	}
	else
	{
		printf("\n- Error de Memoria. Funcion leerTelefono_Usuario: No se pudo asignar la memoria solicitada.\n\n");
		return NULL;
	}
	

	return telefonoUsuario;
}

/**
	@brief Funcion que crear un arbol binario ordenado, desde un archivo
	de texto.in.
	@param nombre : Nombre del archivo de texto a leer.
	@returns nuevoArbol, con los datos del archivo de texto.
	@returns NULL, si no fue posible leer el archivo.
*/
Arbol* crearArbol(char* nombre)
{
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");
	Arbol* nuevoArbol = NULL;
	// Si la lectura del archivo es correcta, inicializamos variables.
	if(archivoEntrada != NULL)
	{
		int cantidadUsuarios;
		fscanf(archivoEntrada, "%d", &cantidadUsuarios);
		char* nombreUsuario = NULL;
		char* telefonoUsuario = NULL;
		int i = 0;
		while (i < cantidadUsuarios)
		{
			nombreUsuario = leerNombre_Usuario(archivoEntrada);
			telefonoUsuario = leerTelefono_Usuario(archivoEntrada);

			if (nombreUsuario != NULL && telefonoUsuario != NULL)
			{
				nuevoArbol = insertarDato(nuevoArbol, nombreUsuario, telefonoUsuario);
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

/**
	@brief Funcion que obtiene la lista de usuarios a buscar.
	@param nombre del archivo a leer.
	@returns listaBusqueda, con los usuarios a leer.
	@returns NULL, si no fue posible leer el archivo.
*/
Lista* obtenerListaBusqueda(char* nombre)
{
	FILE *archivoEntrada;
	archivoEntrada = fopen(nombre, "r");
	
	Lista* listaBusqueda = NULL;
	if (archivoEntrada != NULL)
	{
		int cantidadUsuarios;
		fscanf(archivoEntrada, "%d", &cantidadUsuarios);
		int i = 0;
		char* usuario = NULL;
		while (i < cantidadUsuarios)
		{
			usuario = leerNombre_Usuario(archivoEntrada);
			listaBusqueda = InsertarFinal(listaBusqueda, usuario);
			i++;
		}
		//mostrar(listaBusqueda);
	}
	else
	{
		printf("\n- Error de Lectura. Funcion obtenerListaBusqueda: El archivo ingresado no existe.\n\n");
		return NULL;
	}
	return listaBusqueda;
}

