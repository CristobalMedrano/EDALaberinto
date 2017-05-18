#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Estructuras.h"
#include "Menu.h"
#include "Lectura.h"
#include "Ejecucion.h"

int main(int argc, char const *argv[])
{
	printf("\n- Iniciando Ejecucion.\n\n");
	clock_t start = clock();
	ejecucionPrincipal();
	printf("- Ejecucion Terminada.\n\n");
	printf("Tiempo de ejecucion Total: %f(s)\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	return 0;
}