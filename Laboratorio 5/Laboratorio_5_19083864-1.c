/**
	@file Laboratorio_5_19083864-1.c
	@brief Laboratorio 5 - Arboles AVL

	Programa desarrollado en C, que recibe dos archivos:

		- Telefonos.in (Directorio)
		- Buscados.in (Busqueda)

	Crea un arbol binario ordenado con los datos leidos en el
	Directorio(Telefonos.in) y busca en él, los datos leidos 
	en Busqueda(Buscados.in). Luego	escribe los numero encontrados
	con sus respectivos nombres, en un archivo de salida	
	"TelefonosEncontrados.out".

	@author Cristobal Medrano
	@date 10/06/2017
  
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Menu.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_AVL.h>
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
	int seleccion = FALSE;
	int escritura = FALSE;
	int largo_MAX = 0;
	char *archivoDirectorio = NULL;
	char *archivoBusqueda = NULL;
	clock_t time_lectura;
	clock_t time_ejecucion;
	clock_t start;

	do
	{
	// MODULO DEL MENU	

		// Mostramos el menu principal.
		mostrarMenuPrincipal();
		// Si la opcion ingresada es salir, entonces se termina la ejecucion.
	 	if(obtenerSeleccionMenu() == SALIR) return 0;

	// MODULO DE LECTURA
	
		// OBTENIENDO ARCHIVOS
		
		archivoDirectorio = obtenerNombreArchivo(DIRECTORIO);			
		archivoBusqueda = obtenerNombreArchivo(BUSCAR);			

		// OBTENIENDO DIRECTORIO
		
		// Iniciamos tiempo de ejecucion.
		time_ejecucion = clock();
		time_lectura = clock();	
		start = clock();
		printf("\n--> Iniciando Lectura. \n");
		printf("\n-> Generando arbol de directorio (%s)...", archivoDirectorio);
		
		// Se crea el arbol binario con los usuarios leidos desde el archivo de Directorio o Telefonos.
		arbolDatos = crearArbol(archivoDirectorio, &largo_MAX);

		// Si el arbol de datos no es nulo, indicamos el tiempo en generar el arbol.
		if(arbolDatos != NULL)printf("\n-> Arbol generado en: %f(s)\n", ((double)clock() - start) / CLOCKS_PER_SEC);

		// OBTENIENDO LISTA DE BUSQUEDA
		
		start = clock();
		printf("\n-> Generando lista de busqueda (%s)...", archivoBusqueda);

		// Se crea la lista de busqueda con los usuarios leidos desde el archivo Busqueda.
		listaBusqueda = obtenerListaBusqueda(archivoBusqueda);
		
		// Si la lista de busqueda no es nula, indicamos el tiempo en generarla. 
		if(listaBusqueda != NULL)printf("\n-> Lista de busqueda generada en: %f(s)\n\n", ((double)clock() - start) / CLOCKS_PER_SEC);
		
		printf("-> Tiempo de Lectura: %f(s)\n", ((double)clock() - time_lectura) / CLOCKS_PER_SEC);

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
			// Se escriben los datos obtenidos en un archivo de salida.
			escritura = escribirArchivo(listaUsuarios_Encontrados);

			// Se escriben los identificadores de los nodos en "Identificadores.out"
			escribirIdentificadores(arbolDatos, largo_MAX);
		
			if (escritura == TRUE) printf("\n-> Archivo creado exitosamente.\n");
			seleccion = TRUE;
		}
		
	// REINICIO
		
		else
		{
			printf("\n- Error en la busqueda de datos. Reiniciando...\n");
			seleccion = FALSE;
		}

		printf("-> Tiempo de Escritura: %f(s)\n", ((double)clock() - start) / CLOCKS_PER_SEC);
		printf("\n-> Tiempo de Ejecucion: %f(s)\n", ((double)clock() - time_ejecucion) / CLOCKS_PER_SEC);

	} while (seleccion == FALSE);

	printf("\n- Ejecucion Terminada.\n");
	return 0;
	return 0;
}