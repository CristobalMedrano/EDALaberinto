/**
	@file TDA_AVL.h
	@brief Libreria que contiene el encabezado de las funciones del TDA AVL del programa.

	@author Cristobal Medrano
	@date 10/06/2017
  
*/

#ifndef TDA_AVL
#define TDA_AVL

#define SIN_ALTURA 0

Arbol* insertarUsuario_AVL(Arbol* arbol, char* nombreUsuario, char* telefonoUsuario);
Arbol* EQUILIBRAR_AVL(Arbol* arbol);
int diferenciaAlturas(Arbol* arbol);
int obtenerAltura(Arbol* arbol);
Arbol* rotar_DERECHA(Arbol* arbol);
Arbol* rotar_IZQUIERDA(Arbol* arbol);

#endif