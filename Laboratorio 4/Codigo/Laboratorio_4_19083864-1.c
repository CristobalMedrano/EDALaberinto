#include <stdlib.h>
#include <stdio.h>
#include <Menu.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_LE.h>
#include <Lectura.h>
#include <Busqueda.h>
#include <Escritura.h>

int main(int argc, char const *argv[])
{
	Arbol* arbolDatos = NULL;
	Lista* listaBusqueda = NULL;
	Lista* listaUsuarios_Encontrados = NULL;
	int seleccion = 0;
	int escritura = FALSE;
	char *nombre = NULL;

	do
	{
		// MODULO DEL MENU	

			mostrarMenuPrincipal();
		 	if(obtenerSeleccionMenu() == SALIR)
			{
				return 0;
			}
		
		// MODULO DE LECTURA
		
			printf("\nIngrese archivo del Directorio: ");
			nombre = obtenerNombreArchivo();
			arbolDatos = crearArbol(nombre);

			printf("\nIngrese archivo de Busqueda: ");
			nombre = obtenerNombreArchivo();
			listaBusqueda = obtenerListaBusqueda(nombre);
	
		// MODULO DE BUSQUEDA

			listaUsuarios_Encontrados = buscarDatos_Usuario(arbolDatos, listaBusqueda);

		// MODULO DE ESCRITURA

			escritura = escribirArchivo(listaUsuarios_Encontrados);
			
			if (escritura == TRUE && arbolDatos != NULL && listaBusqueda != NULL)
			{
				printf("\nArchivo creado exitosamente.\n");
				seleccion = 1;
			}
			
		// REINICIO
			
			else
			{
				printf("\n- Error en la busqueda de datos. Reiniciando...\n\n");
				seleccion = 0;
			}

	} while (seleccion == 0); 
	return 0;
}