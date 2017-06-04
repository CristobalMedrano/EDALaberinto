#include <stdio.h>
#include <stdlib.h>
#include <Estructuras.h>
#include <TDA_ABO.h>
#include <TDA_LE.h>
#include <Ejecucion.h>

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
        		listaTelefonos = InsertarTelefono(listaTelefonos, "-SIN NUMERO");
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