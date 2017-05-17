#include <stdlib.h>
#include <stdio.h>
#include "Ejecucion.h"
#include "Lectura.h"
#include "Menu.h"

void mostrarMenuPrincipal()
{
	printf("*************************************\n");
	printf("*                                   *\n");
	printf("*          Laboratorio N.3          *\n");
	printf("*               Grafos              *\n");
	printf("*                                   *\n");
	printf("*        Cristobal Medrano A.       *\n");
	printf("*             18-05-2017            *\n");
	printf("*                                   *\n");
	printf("*************************************\n");
}

void mostrarMenuSeleccion()
{
	printf("\nIngrese numero de la opcion deseada: \n");
	printf("1.- Ingresar Archivo\n");
	printf("2.- Salir\n");
}

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

int obtenerSeleccionMenu()
{
	mostrarMenuSeleccion();
	int opcionIngresada = obtenerOpcionIngresada(1, 2);
	switch (opcionIngresada)
	{
		case INGRESAR: return INGRESAR;
		case SALIR: return SALIR;
	}
}