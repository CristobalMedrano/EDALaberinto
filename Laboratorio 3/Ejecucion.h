#ifndef EJECUCION

#define EJECUCION
#define TRUE 1
#define FALSE 0

Casilla* Dijkstra(Grafo* grafo, int vInicial);
Lista* obtenerRecorrido(Casilla* camino, int vInicial, int vFinal);
int ejecucionPrincipal();

#endif