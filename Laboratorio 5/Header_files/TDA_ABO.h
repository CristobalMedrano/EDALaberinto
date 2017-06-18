/**
	@file TDA_ABO.h
	@brief Libreria que contiene el encabezado de las funciones del TDA ABO del programa.

	@author Cristobal Medrano
	@date 28/05/2017
  
*/

#ifndef TDA_ABO
#define TDA_ABO

Arbol* crearHoja(char* nombreUsuario, char* telefonoUsuario, Arbol* arbol_izquierdo, Arbol* arbol_derecho);
Arbol* insertarUsuario_ABO(Arbol* arbol, char* nombreUsuario, char* telefonoUsuario);
Arbol* hijo_IZQUIERDO(Arbol* arbol);
Arbol* hijo_DERECHO(Arbol* arbol);
char* obtenerUsuarioArbol(Arbol* arbol);
char* obtenerTelefonoArbol(Arbol* arbol);
Arbol* buscarUsuario(Arbol* arbol, char* nombreUsuario);
Arbol* menorSiguiente(Arbol* arbol, Arbol* actual);
Arbol* obtenerMenorElemento(Arbol* arbol);
Arbol* obtenerPadre(Arbol* arbol, Arbol* elemento);
void preOrden(Arbol* arbol);
void inOrden(Arbol* arbol);
void postOrden(Arbol* arbol);

#endif