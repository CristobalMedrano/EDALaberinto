/**
    @file Escritura.c
    @brief Modulo de Escritura del programa.
    
    Funciones de Escritura.

    @author Cristobal Medrano
    @date 03/06/2017
  
*/

#include <stdlib.h>
#include <stdio.h>
#include <Estructuras.h>
#include <TDA_LE.h>
#include <Escritura.h>
/**
    @brief Procedimiento que escribe los datos de la listaBusqueda.
    @param archivoSalida, donde guardar los datos.
    @param listaBusqueda, con los datos a leer.
*/
void escribirDatos(FILE* archivoSalida, Lista* listaBusqueda)
{
	int contador = 0;
    Lista *auxiliar = crearNodo();
    ListaTelefonos *auxiliarTelefonos = crearNodoTelefono();
    auxiliar=listaBusqueda;
    while(auxiliar != NULL)
    {
    	contador = 0;
    	auxiliarTelefonos=auxiliar->listaTelefonos;
    	fprintf(archivoSalida, "%s", auxiliar->nombreUsuario);
    	while(auxiliarTelefonos != NULL)
    	{
    		if (contador < 1)
    		{
    			fprintf(archivoSalida, " %s", auxiliarTelefonos->telefonoUsuario);
    			contador++;
    			auxiliarTelefonos = auxiliarTelefonos->siguiente;
    		}
    		else
    		{
    			fprintf(archivoSalida, " - %s", auxiliarTelefonos->telefonoUsuario);
    			contador++;
    			auxiliarTelefonos = auxiliarTelefonos->siguiente;
    		}
    		
    	}
    	fprintf(archivoSalida, "\n");
    	auxiliar = auxiliar->siguiente;
    }
}
/**
    @brief Funcion que escribe los datos en el archivo de salida.
    @param listaBusqueda, lista que contiene los elementos a escribir.
    @returns TRUE, si fue escrito correctamente.
    @returns FALSE, si existe algun error.
*/
int escribirArchivo(Lista* listaBusqueda)
{
	FILE *archivoSalida;
	archivoSalida = fopen("TelefonosEncontrados.out", "w");
	if (archivoSalida != NULL && listaBusqueda != NULL)
	{
		escribirDatos(archivoSalida, listaBusqueda);
	}
	else
	{
		printf("\n- Error de Escritura. Funcion escribirArchivo: El archivo no puede ser creado.\n\n");
		return FALSE;	
	}
	fclose(archivoSalida);
	return TRUE;
}