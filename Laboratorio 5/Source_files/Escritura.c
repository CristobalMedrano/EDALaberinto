/**
    @file Escritura.c
    @brief Modulo de Escritura del programa.
    
    Funciones de Escritura.

    @author Cristobal Medrano
    @date 03/06/2017
  
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Estructuras.h>
#include <TDA_LE.h>
#include <TDA_AVL.h>
#include <Escritura.h>

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
    @param arbol, arbol con los datos a escribir.
    @returns TRUE, si fue escrito correctamente.
    @returns FALSE, si existe algun error.
*/
int escribirIdentificadores(Arbol* arbol, int largo_MAX)
{
    FILE *archivoSalida;
    archivoSalida = fopen("Identificadores.out", "w");
    if (archivoSalida != NULL)
    {
        Identificadores(arbol, archivoSalida, largo_MAX);
    }
    else
    {
        printf("\n- Error de Escritura. Funcion escribirIdentificadores: El archivo no puede ser creado.\n\n");
        return FALSE;
    }
    fclose(archivoSalida);
    return TRUE;
}

/**
    @brief Funcion recursiva que escribe el identificador de cada nodo.
    @param arbol, arbol para obtener los datos del usuario.
    @param FILE*, direccion de memoria del archivo a escribir.
    @pram largo_MAX, largo del usuario con la cadena de caracteres mas larga.
*/
void Identificadores(Arbol* arbol, FILE* archivoSalida, int largo_MAX)
{
    if (arbol != NULL)
    {
        Identificadores(arbol->hijoIzquierdo, archivoSalida, largo_MAX);
        fprintf(archivoSalida, "NODO: %s", escrituraEstructurada(arbol, largo_MAX));
        fprintf(archivoSalida, "ALTURA: %d ", obtenerAltura(arbol)-1); // Altura de abajo hacia arriba.

        if (arbol->hijoIzquierdo != NULL)
        {
            fprintf(archivoSalida, "H_IZQ: %s", escrituraEstructurada(arbol->hijoIzquierdo, largo_MAX));
        }
        else
        {
            fprintf(archivoSalida, "H_IZQ: NULO%s", escrituraEstructurada(arbol->hijoIzquierdo, largo_MAX));
        }
        if (arbol->hijoDerecho != NULL)
        {
            fprintf(archivoSalida, "H_DER: %s", escrituraEstructurada(arbol->hijoDerecho, largo_MAX));
        }  
        else
        {
            fprintf(archivoSalida, "H_DER: NULO%s", escrituraEstructurada(arbol->hijoDerecho, largo_MAX));
        }
        fprintf(archivoSalida, "\n");
        Identificadores(arbol->hijoDerecho, archivoSalida, largo_MAX);
    }
    
}

/**
    @brief Funcion que permite determinar la cantidad de espacios
    a escribir en el archivo de texto, para obtener una mejor
    visualizacion de los datos obtenidos.
    @param arbol, arbol para verificar existencia del usuario.
    @pram largo_MAX, largo del usuario con la cadena de caracteres mas larga.
    @return usuarioMOdificado, con los espacios respectivos para el
    orden.
*/
char* escrituraEstructurada(Arbol* arbol, int largo_MAX)
{
    char* usuarioModificado = (char* )malloc(sizeof(char)*256);
    int largoNombre;
    if (arbol != NULL)
    {
        largoNombre = strlen(arbol->nombreUsuario);
        strcpy(usuarioModificado, arbol->nombreUsuario);
        while (largoNombre != largo_MAX+1)
        {
            strcat(usuarioModificado, " ");  
            largoNombre++;
        }
    }
    else
    {
        largoNombre = 4;
        strcpy(usuarioModificado, "");
        while (largoNombre != largo_MAX+1)
        {
            strcat(usuarioModificado, " ");  
            largoNombre++;
        }
    }
    
    return usuarioModificado;
}


