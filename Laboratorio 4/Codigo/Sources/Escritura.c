#include <stdlib.h>
#include <stdio.h>
#include <Estructuras.h>
#include <TDA_LE.h>
#include <Escritura.h>

void escribirDatos(FILE* archivoSalida, Lista* listaBusqueda)
{
	int contador = 0;
	if(listaBusqueda != NULL)
	{
        Lista *auxiliar = crearNodo();
        ListaTelefonos *auxiliarTelefonos = crearNodoTelefono();
        auxiliar=listaBusqueda;
        while(auxiliar != NULL)
        {
        	contador = 0;
        	auxiliarTelefonos=auxiliar->listaTelefonos;
        	fprintf(archivoSalida, "%s", auxiliar->nombreUsuario);
        	while(auxiliarTelefonos != NULL)
        	{
        		if (contador >= 1)
        		{
        			fprintf(archivoSalida, " - %s", auxiliarTelefonos->telefonoUsuario);
        			contador++;
        			auxiliarTelefonos = auxiliarTelefonos->siguiente;
        		}
        		else
        		{
        			fprintf(archivoSalida, " %s", auxiliarTelefonos->telefonoUsuario);
        			contador++;
        			auxiliarTelefonos = auxiliarTelefonos->siguiente;
        		}
        		
        	}
        	fprintf(archivoSalida, "\n");
        	auxiliar = auxiliar->siguiente;
        }
	}
}

int escribirArchivo(Lista* listaBusqueda)
{
	FILE *archivoSalida;
	archivoSalida = fopen("TelefonosEncontrados.out", "w");
	if (archivoSalida != NULL)
	{
		escribirDatos(archivoSalida, listaBusqueda);
	}
	else
	{
		printf("\n- Error de Escritura. Funcion escribirArchivo: El archivo no puede ser creado.\n\n");
		return FALSE;	
	}
	fclose(archivoSalida);
	return TRUE;
}