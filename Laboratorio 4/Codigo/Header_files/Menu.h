/**
	@file Menu.h
	@brief Libreria que contiene el encabezado de las funciones de Menu del programa.

	@author Cristobal Medrano
	@date 04/06/2017
  
*/
#ifndef MENU
#define MENU

#define INGRESAR 1
#define INICIAR 1
#define SALIR 2
#define SIN_INGRESO -1

void mostrarMenuPrincipal();
void mostrarMenuSeleccion();
int obtenerOpcionIngresada(int valMin, int valMax);
int obtenerSeleccionMenu();
#endif