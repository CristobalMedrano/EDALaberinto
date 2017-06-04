/**
	@file TDA_ABO.h
	@brief Libreria que contiene el encabezado de las funciones del TDA ABO del programa.

	@author Cristobal Medrano
	@date 28/05/2017
  
*/

#ifndef TDA_ARBOL
#define TDA_ARBOL

#define SIN_DATO -1
Arbol* crearHoja(char* nombreUsuario, char* telefonoUsuario, Arbol* arbol_izquierdo, Arbol* arbol_derecho);
Arbol* borrarArbol(Arbol* arbol, int dato);
Arbol* obtenerRaiz(Arbol* arbol);
Arbol* mayorAnterior(Arbol* arbol, Arbol* actual);
Arbol* menorSiguiente(Arbol* arbol, Arbol* actual);
Arbol* obtenerPadre(Arbol* arbol, Arbol* elemento);
Arbol* obtenerMayorElemento(Arbol* arbol);
Arbol* obtenerMenorElemento(Arbol* arbol);
Arbol* buscarUsuario(Arbol* arbol, char* nombreUsuario);
char* obtenerDatoArbol(Arbol* arbol);
char* obtenerTelefonoArbol(Arbol* arbol);
Arbol* hijo_IZQUIERDO(Arbol* arbol);
Arbol* hijo_DERECHO(Arbol* arbol);
Arbol* insertarDato(Arbol* arbol, char* nombreUsuario, char* telefonoUsuario);
void preOrden(Arbol* arbol);
void inOrden(Arbol* arbol);
void postOrden(Arbol* arbol);
void MenuArboles();

#endif