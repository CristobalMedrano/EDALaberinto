/**
	@file Laboratorio_4_19083864-1.c
	@brief Laboratorio 4 - Arboles Binarios Ordenados/Busqueda

	Programa desarrollado en C, que recibe dos archivos:

		- Telefonos.in (Directorio)
		- Buscados.in (Busqueda)

	Crea un arbol binario ordenado con los datos leidos en el
	Directorio y busca en el los datos leidos en Busqueda. Luego
	escribe los numero encontrados en un archivo de salida
	"TelefonosEncontrados.out".

	@author Cristobal Medrano
	@date 04/06/2017
  
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Menu.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_LE.h>
#include <Lectura.h>
#include <Busqueda.h>
#include <Escritura.h>

/**
	@brief Funcion main del programa.
*/
int main(int argc, char const *argv[])
{
	Arbol* arbolDatos = NULL;
	Lista* listaBusqueda = NULL;
	Lista* listaUsuarios_Encontrados = NULL;
	int seleccion = 0;
	int escritura = FALSE;
	char *archivoDirectorio = NULL;
	char *archivoBusqueda = NULL;
	clock_t lectura;
	clock_t start;

	do
	{
	// MODULO DEL MENU	

		mostrarMenuPrincipal();
	 	if(obtenerSeleccionMenu() == SALIR)
		{
			return 0;
		}
	
	// MODULO DE LECTURA
	
		// OBTENIENDO ARCHIVOS
		
		archivoDirectorio = obtenerNombreArchivo(DIRECTORIO);			
		archivoBusqueda = obtenerNombreArchivo(BUSCAR);			

		// OBTENIENDO DIRECTORIO
		
		lectura = clock();	
		printf("\n--> Iniciando Lectura. \n");
		
		start = clock();
		printf("\n-> Generando arbol de directorio (%s)...", archivoDirectorio);
		arbolDatos = crearArbol(archivoDirectorio);

		printf("\n-> Arbol generado en: %f(s)\n", ((double)clock() - start) / CLOCKS_PER_SEC);

		// OBTENIENDO LISTA DE BUSQUEDA
		
		start = clock();
		printf("\n-> Generando lista de busqueda (%s)...", archivoBusqueda);

		listaBusqueda = obtenerListaBusqueda(archivoBusqueda);
		printf("\n-> Lista de busqueda generada en: %f(s)\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
		
		printf("-> Tiempo de Lectura: %f(s)\n", ((double)clock() - lectura) / CLOCKS_PER_SEC);

	// MODULO DE BUSQUEDA

		start = clock();
		printf("\n--> Iniciando Busqueda.\n");

		listaUsuarios_Encontrados = buscarDatos_Usuario(arbolDatos, listaBusqueda);
		printf("-> Tiempo de Busqueda: %f(s)\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	// MODULO DE ESCRITURA

		start = clock();
		printf("\n--> Iniciando Escritura. \n");
		
		if (arbolDatos != NULL && listaBusqueda != NULL)
		{
			escritura = escribirArchivo(listaUsuarios_Encontrados);
			if (escritura == TRUE)
			{
				printf("\n-> Archivo creado exitosamente.\n");
			}
			seleccion = 1;
		}
		
	// REINICIO
		
		else
		{
			printf("\n- Error en la busqueda de datos. Reiniciando...\n");
			seleccion = 0;
		}

		printf("-> Tiempo de Escritura: %f(s)\n", ((double)clock() - start) / CLOCKS_PER_SEC);

	} while (seleccion == 0);

	printf("\n- Ejecucion Terminada.\n");
	return 0;
}