#ifndef ESTRUCTURAS
#define ESTRUCTURAS

typedef struct Arbol
{
    char* usuario;
    struct Arbol* hijoIzquierdo;
    struct Arbol* hijoDerecho;
} Arbol;

// Como tengo los datos segmentados, puedo crear mas de una categoria, es decir
// puedp guardar el numero asociado al nombre de usuario. Para recuperar el dato
// busco el nombre de usuario que sea el que quiero, luego las coincidencias las
// reviso sus numeros (gracias a un contador de usuarios repetidos) y escribo
// los nombres.

#endif