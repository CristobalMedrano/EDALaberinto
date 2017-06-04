/**
	@file Menu.h
	@brief Libreria que contiene el encabezado de las funciones de Menu del programa.

	@author Cristobal Medrano
	@date 18/05/2017
  
*/
#ifndef MENU

#define MENU
#define INGRESAR 1
#define INICIAR 1
#define ARCHIVO_DIRECTORIO 2
#define ARCHIVO_BUSQUEDA 3
#define SALIR 4
#define SIN_INGRESO -1

void mostrarMenuPrincipal();
void mostrarMenuSeleccion();
int obtenerOpcionIngresada(int valMin, int valMax);
int obtenerSeleccionMenu();
#endif