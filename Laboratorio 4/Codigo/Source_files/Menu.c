/**
	@file Menu.c
	@brief Menu del Programa.
	
	Modulo encargado de la interaccion con el usuario a traves de un menu grafico.

	@author Cristobal Medrano
	@date 18/05/2017
  
*/
#include <stdlib.h>
#include <stdio.h>
#include <Menu.h>

/**
	@brief Procedimiento que muestra el menu principal.
*/
void mostrarMenuPrincipal()
{
	printf("*************************************\n");
	printf("*                                   *\n");
	printf("*          Laboratorio N.4          *\n");
	printf("*          Arboles Binarios         *\n");
	printf("*                                   *\n");
	printf("*        Cristobal Medrano A.       *\n");
	printf("*             08-06-2017            *\n");
	printf("*                                   *\n");
	printf("*************************************\n");
}

/**
	@brief Procedimiento que muestra las opciones del menu principal.
*/
void mostrarMenuSeleccion()
{
	printf("\nIngrese numero de la opcion deseada: \n");
	printf("1.- Realizar Busqueda\n");
	printf("2.- Salir\n");
}

/**
	@brief Funcion que obtiene la opcion ingresada en el menu.
	@param valMin : Entero con la opcion minima de ingreso.
	@param valMax : Entero con la opcion maxima de ingreso.
	@returns un Entero con la opcion ingresada.
*/
int obtenerOpcionIngresada(int valMin, int valMax)
{
	int leerOpcion = SIN_INGRESO;
	do
	{
		fflush(stdin); // Limpiamos buffer de entrada.
		if ((scanf("%d", &leerOpcion) == 0) || (leerOpcion < valMin || leerOpcion > valMax))
		{
		    while (getchar() != '\n');
		    printf("\n- Error. Ingrese una opcion valida.\n\n");
		    mostrarMenuSeleccion();
		    fflush(stdin); // Limpiamos buffer.
		}
		
	} while (leerOpcion < valMin || leerOpcion > valMax);

	// Retorno la opcion ingresada ya validada.
	return leerOpcion;
}

/**
	@brief Funcion que obtiene la opcion ingresada en el menu.
	@returns seleccion ingresada.
*/
int obtenerSeleccionMenu()
{
	mostrarMenuSeleccion();
	int opcionIngresada = obtenerOpcionIngresada(1, 2);
	switch (opcionIngresada)
	{
		case INICIAR: return INICIAR;
		case SALIR: return SALIR;
	}
	return SALIR;
}