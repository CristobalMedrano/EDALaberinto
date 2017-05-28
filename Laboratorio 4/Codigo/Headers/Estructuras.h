#ifndef ESTRUCTURAS
#define ESTRUCTURAS

typedef struct Arbol
{
        char nombre[256];
        int dato;
        struct Arbol* hijoIzquierdo;
        struct Arbol* hijoDerecho;
}Arbol;

#endif