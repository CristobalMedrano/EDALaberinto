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
#include <TDA_AVL.h>
#include <TDA_LE.h>
#include <Escritura.h>

/**
	@brief Funcion que obtiene el nombre del archivo ingresado por el usuario.
	@param entrada, dato de tipo entero que contiene la secuencia a seguir.
	@returns nombreArchivo ingresado por el usuario.
*/
char* obtenerNombreArchivo(int entrada)
{
	char* nombreArchivo = (char*)malloc(sizeof(char)*256);
	char nombreLeido[256];
	if (entrada == DIRECTORIO)
	{
		printf("\nIngrese archivo del Directorio: ");
		fflush(stdin); // Limpiamos buffer de entrada.
		scanf("%s", nombreLeido);
		fflush(stdin); // Limpiamos buffer.
	}
	if (entrada == BUSCAR)
	{
		printf("\nIngrese archivo de Busqueda: ");
		fflush(stdin); // Limpiamos buffer de entrada.
		scanf("%s", nombreLeido);
		fflush(stdin); // Limpiamos buffer.
	}
	strcpy(nombreArchivo, nombreLeido);
	return nombreArchivo;
}

/**
	@brief Funcion que crear un arbol binario ordenado, desde un archivo
	de entrada.
	@param nombre : Nombre del archivo de texto a leer.
	@returns nuevoArbol, con los datos del archivo de texto.
	@returns NULL, si no fue posible leer el archivo.
*/
Arbol* crearArbol(char* nombre, int* largo_MAX)
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

		/*nuevoArbol = insertarUsuario_AVL(nuevoArbol, "Andrea", "+56 6 5432 1234");
		nuevoArbol = insertarUsuario_AVL(nuevoArbol, "Cristobal", "+56 6 5432 1234");
		nuevoArbol = insertarUsuario_AVL(nuevoArbol, "Diego", "+56 6 5432 1234");
		nuevoArbol = insertarUsuario_AVL(nuevoArbol, "Fernando", "+56 6 5432 1234");
		nuevoArbol = insertarUsuario_AVL(nuevoArbol, "Patricia", "+56 6 5432 1234");
		nuevoArbol = insertarUsuario_AVL(nuevoArbol, "Rodrigo", "+56 6 5432 1234");*/
		while (i < cantidadUsuarios)
		{
			nombreUsuario = leerNombre_Usuario(archivoEntrada);
			obtenerLargoNombre(nombreUsuario, largo_MAX);
			telefonoUsuario = leerTelefono_Usuario(archivoEntrada);


			if (nombreUsuario != NULL && telefonoUsuario != NULL)
			{
				nuevoArbol = insertarUsuario_AVL(nuevoArbol, nombreUsuario, telefonoUsuario);
			}
			i++;
		}
	} else 
	{ 
		printf("\n- Error de Lectura. Funcion leerArchivo: El archivo ingresado no existe.\n\n");
		return NULL;	
	}
	fclose(archivoEntrada);
	//nuevoArbol = EQUILIBRAR_AVL(nuevoArbol);
	return nuevoArbol;
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
	char* nombreUsuario = NULL;
	nombreUsuario = (char*)malloc(sizeof(char)*256);
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
	char* telefonoUsuario = NULL;
	telefonoUsuario = (char*)malloc(sizeof(char)*256);
	if (telefonoUsuario != NULL)
	{
		char codigoPais[10];
		int codigoNCiudad;
		char codigoCiudad[4];
		int num_primerNumero;
		char primerNumero[5];
		int num_segundoNumero;
		char segundoNumero[5];

		// Leemos el codigo pais y luego lo concatenamos al telefonoUsuario
		fscanf(archivoEntrada, "%s", codigoPais);
		strcpy(telefonoUsuario, codigoPais);
		strcat(telefonoUsuario, " ");
		
		// Codigo Ciudad y luego lo concatenamos al telefonoUsuario
		fscanf(archivoEntrada, "%d", &codigoNCiudad);
		// Convierte el codigo numerico en string.
		sprintf(codigoCiudad, "%d", codigoNCiudad);
		strcat(telefonoUsuario, codigoCiudad);
		strcat(telefonoUsuario, " ");
		
		// Primer Numero y luego lo concatenamos al telefonoUsuario
		fscanf(archivoEntrada, "%04d", &num_primerNumero);
		// Convierte el primer numero en string.
		sprintf(primerNumero, "%04d", num_primerNumero);
		strcat(telefonoUsuario, primerNumero);
		strcat(telefonoUsuario, " ");
		
		// Segundo Numero y luego lo concatenamos al telefonoUsuario
		fscanf(archivoEntrada, "%04d", &num_segundoNumero);
		// Convierte el segundo numero en string.
		sprintf(segundoNumero, "%04d", num_segundoNumero);
		strcat(telefonoUsuario, segundoNumero);
	}
	else
	{
		printf("\n- Error de Memoria. Funcion leerTelefono_Usuario: No se pudo asignar la memoria solicitada.\n\n");
		return NULL;
	}
	return telefonoUsuario;
}

void obtenerLargoNombre(char* nombreUsuario, int* largo_MAX)
{
	int largoNombre = 0;
	largoNombre = strlen(nombreUsuario);
	if (largoNombre > *largo_MAX)
	{
		*largo_MAX = largoNombre;
	}
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
			if (cantidadUsuarios < 10000)
			{
				listaBusqueda = InsertarFinal(listaBusqueda, usuario);
			}
			else
			{
				listaBusqueda = InsertarPos(listaBusqueda, 0, usuario);
			}	
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


