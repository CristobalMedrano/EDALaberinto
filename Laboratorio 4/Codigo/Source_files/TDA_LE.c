/**
	@file TDA_Listas_Enlazadas.c
	@brief Listas Enlazadas

	TDA de listas enlazadas mediante nodos.

	@author Cristobal Medrano
	@date 19/04/2017
  
*/

#include <stdlib.h>
#include <stdio.h>
#include <Estructuras.h>
#include <TDA_LE.h>
/**
	@brief Funcion que crea un nodo telefono.
	@param dato es el elemento a guardar en la lista.
	@returns Lista (puntero), si fue creada exitosamente.
	@returns NULL, si no fue creada.
*/
ListaTelefonos* crearNodoTelefono()
{
	ListaTelefonos *lista = (ListaTelefonos *)malloc(sizeof(ListaTelefonos));
	//Si la asignacion de memoria es exitosa, se inicializan las variables
	if(lista!=NULL){
	    lista->telefonoUsuario = NULL;
		lista->siguiente = NULL;
		return lista;
	}
	else{
		return NULL;
	}
}	
/**
	@brief Funcion que crea un nodo.
	@param dato es el elemento a guardar en la lista.
	@returns Lista (puntero), si fue creada exitosamente.
	@returns NULL, si no fue creada.
*/
Lista* crearNodo()
{
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	//Si la asignacion de memoria es exitosa, se inicializan las variables
	if(lista!=NULL){
	    lista->nombreUsuario = NULL;
		lista->siguiente = NULL;
		return lista;
	}
	else{
		return NULL;
	}
}

/**
	@brief Funcion que inserta un elemento en la lista.
	@param L es una Lista de nodos.
	@param pos es la posicion en donde se insertara el elemento.
	@param dato es el dato a guardar en la lista.
	@returns Lista (puntero), con los datos actualizados.
*/
Lista* InsertarPos(Lista* L, int pos, char* nombreUsuario)
{
	int i;
	// Si la pos ingresada es menor a 0, retorno la lista.
	if(pos < 0)
	{
		return L;
	}
	// Si la pos ingresada es igual a 0, agrego el elemento a la lista.
	if(pos == 0)
	{
		Lista* nueva = crearNodo();
		nueva->nombreUsuario = nombreUsuario;
		nueva->siguiente = L;
		return nueva;
	}
	i = 0;
	Lista *indice = crearNodo();
	indice = L;
	// Muevo el puntero a la posicion - 1 que no sea nula.
	while (indice != NULL && i < pos -1)
	{
		indice = indice->siguiente;
		i++;
	}
	// si el indice no es nulo, creo el nodo y lo agrego a la lista.
	if(indice != NULL)
	{
		Lista* nueva = crearNodo();
		nueva->nombreUsuario = nombreUsuario;
		nueva->siguiente = indice->siguiente;
		indice->siguiente = nueva;
	}
	return L; 
}
/**
	@brief Funcion que inserta un elemento al final de la lista.
	@param L es una Lista de nodos.
	@param nombreUsuario es el elemento a guardar en la lista.
	@returns Lista (puntero), con los datos actualizados.
*/
Lista* InsertarFinal(Lista* L, char* nombreUsuario)
{
	//Se crea una nueva lista
	Lista *nuevo = crearNodo();
	Lista *aux = crearNodo();
	//Se comprueba si se realiza con exito
	//Si la lista es creada con exito
	if(nuevo!=NULL){
        //Se ve si L esta vacia
        if (L==NULL){
            //En ese caso, L sera igual a la nueva lista que creamos
        	L = nuevo;
            nuevo->nombreUsuario = nombreUsuario;
            nuevo->siguiente = NULL;
            return L;
        }
        else
        { 
        	// Aux sera igual a L.
        	aux = L;
        	// Ubicamos el puntero en el ultimo nodo.
        	while(aux->siguiente != NULL)
        	{
        		aux = aux->siguiente;
        	}
        	// Asignamos la ultima posicion al nuevo nodo.
        	aux->siguiente = nuevo;
        	nuevo->nombreUsuario = nombreUsuario;
        	nuevo->siguiente = NULL;
        	// Retornamos la lista.
        	return L;
        }

	}
	//En caso que la asignacion de memoria falle, se avisa del error y se retorna la lista L
	else{
        printf("Error en la asignacion de memoria\n");
        return L;
    }
}

/**
	@brief Funcion que inserta un elemento al final de la lista.
	@param L es una Lista de nodos.
	@param telefonoUsuario es el elemento a guardar en la lista.
	@returns Lista (puntero), con los datos actualizados.
*/
ListaTelefonos* InsertarTelefono(ListaTelefonos* L, char* telefonoUsuario)
{
	//Se crea una nueva lista
	ListaTelefonos *nuevo = crearNodoTelefono();
	ListaTelefonos *aux = crearNodoTelefono();
	//Se comprueba si se realiza con exito
	//Si la lista es creada con exito
	if(nuevo!=NULL){
        //Se ve si L esta vacia
        if (L==NULL){
            //En ese caso, L sera igual a la nueva lista que creamos
        	L = nuevo;
            nuevo->telefonoUsuario = telefonoUsuario;
            nuevo->siguiente = NULL;
            return L;
        }
        else
        { 
        	// Aux sera igual a L.
        	aux = L;
        	// Ubicamos el puntero en el ultimo nodo.
        	while(aux->siguiente != NULL)
        	{
        		aux = aux->siguiente;
        	}
        	// Asignamos la ultima posicion al nuevo nodo.
        	aux->siguiente = nuevo;
        	nuevo->telefonoUsuario = telefonoUsuario;
        	nuevo->siguiente = NULL;
        	// Retornamos la lista.
        	return L;
        }

	}
	//En caso que la asignacion de memoria falle, se avisa del error y se retorna la lista L
	else{
        printf("Error en la asignacion de memoria\n");
        return L;
    }
}

/**
	@brief Funcion que obtiene un elemento de la lista, segun la posicion.
	@param L lista con los nodos.
	@param pos posicion del elemento a buscar.
	@returns elemento si la ejecucion fue correcta.
	@returns NULL si la posicion es invalida.
*/
char* obtener(Lista* L, int pos)
{
	int i;
	if(pos < 0)
	{
		return NULL;
	}
	i = 0;
	Lista* indice = L;
	while(indice != NULL && i < pos)
	{
		indice = indice->siguiente;
		i++;
	}
	if(indice == NULL)
	{
		return NULL;
	}
	return indice->nombreUsuario;
}
/**
	@brief Funcion que obtiene el largo de la lista.
	@param L lista con los nodos.
	@returns int con el largo de la lista.
*/
int largo(Lista* L)
{
	int i = 0;
	Lista* indice = L;
	while(indice != NULL)
	{
		indice = indice->siguiente;
		i++;
	}
	return i;
}

/**
	@brief Procedimiento que muestra la lista.
	@param L lista con los nodos.
*/
void mostrar(Lista * L)
{
	if(L!=NULL)
	{
        Lista *auxiliar = crearNodo();
        auxiliar=L;
        while(auxiliar!=NULL)
        {
            printf("Elemento a buscar: %s\n", auxiliar->nombreUsuario);
            auxiliar = auxiliar->siguiente;
        }
	}
}