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
            // Buscamos el usuario en el arbol
        	usuarioBuscado = buscarUsuario(arbolDatos, auxiliar->nombreUsuario);
        	
        	if (usuarioBuscado != NULL)
        	{
                // Mientras exista el usuario con mas de un numero.
        		while (usuarioBuscado != NULL)
	        	{     		
                    // Obtenemos el telefono del usuario desde el arbol
	            	telefonoUsuario = obtenerTelefonoArbol(usuarioBuscado);
                    // Guardamos el telefono en una lista de telefonos pertenecientes al usuario.
	            	listaTelefonos = InsertarTelefono(listaTelefonos, 0, telefonoUsuario);
                    // Buscamos si existen mas coincidencias con el usuario.
	            	usuarioBuscado = buscarUsuario(menorSiguiente(usuarioBuscado, usuarioBuscado), auxiliar->nombreUsuario);
	        	}
        	}
        	else
        	{
                // Si el usuario no existe, indicamos que no tiene numero registrado
        		listaTelefonos = InsertarTelefono(listaTelefonos, 0, "-SIN NUMERO REGISTRADO");
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
    // Devolvemos la listaBusqueda actualizada.
	return listaBusqueda;
}