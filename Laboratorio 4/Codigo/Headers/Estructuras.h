#ifndef ESTRUCTURAS
#define ESTRUCTURAS

typedef struct ListaTelefonos
{
	char* telefonoUsuario;
	struct ListaTelefonos *siguiente;
} ListaTelefonos;

/**
	@struct lista
	@brief Estructura de Lista, contiene una lista con el camino recorrido final.
	@param dato de tipo Entero
	@param siguiente un puntero al siguiente dato.
*/
typedef struct Lista
{
	char* nombreUsuario;
	ListaTelefonos* listaTelefonos;
	struct Lista *siguiente;
} Lista;

typedef struct Arbol
{
    char* nombreUsuario;
    char* telefonoUsuario;
    struct Arbol* hijoIzquierdo;
    struct Arbol* hijoDerecho;
} Arbol;

// Como tengo los datos segmentados, puedo crear mas de una categoria, es decir
// puedp guardar el numero asociado al nombre de usuario. Para recuperar el dato
// busco el nombre de usuario que sea el que quiero, luego las coincidencias las
// reviso sus numeros (gracias a un contador de usuarios repetidos) y escribo
// los nombres.

#endif