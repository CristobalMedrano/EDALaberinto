/**
    @file Busqueda.c
    @brief Modulo de Busqueda del programa.
    
    Funciones de Busqueda.

    @author Cristobal Medrano
    @date 02/06/2017
  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_LE.h>
#include <Busqueda.h>
/**
    @brief Funcion que busca los datos del usuario en el directorio.
    @param arbolDatos, dato de tipo Arbol con los usuarios.
    @param listaBusqueda, dato de tipo Lista con los usuarios a buscar.
    @returns listaBusqueda, Lista actualizada con los telefonos del usuario.
*/
Lista* buscarDatos_Usuario(Arbol* arbolDatos, Lista* listaBusqueda)
{	
    Arbol* usuarioBuscado = NULL;
	char* telefonoUsuario = NULL;
	ListaTelefonos* listaTelefonos = NULL;
	
	if(listaBusqueda!=NULL)
	{
        Lista *auxiliar = crearNodo();
        auxiliar=listaBusqueda;
        while(auxiliar!=NULL)
        {
        	usuarioBuscado = buscarUsuario(arbolDatos, auxiliar->nombreUsuario);
        	
        	if (usuarioBuscado != NULL)
        	{
        		while (usuarioBuscado != NULL)
	        	{     		
	            	telefonoUsuario = obtenerTelefonoArbol(usuarioBuscado);
	            	listaTelefonos = InsertarTelefono(listaTelefonos, telefonoUsuario);
	            	usuarioBuscado = buscarUsuario(menorSiguiente(usuarioBuscado, usuarioBuscado), auxiliar->nombreUsuario);
	        	}
        	}
        	else
        	{
        		listaTelefonos = InsertarTelefono(listaTelefonos, "-SIN NUMERO REGISTRADO");
        	}
        	auxiliar->listaTelefonos = listaTelefonos;
        	listaTelefonos = NULL;
        	auxiliar = auxiliar->siguiente;
        }
	}
	else
	{
		return NULL;
	}
	return listaBusqueda;
}