#ifndef LISTAS_ENLAZADAS
#define LISTAS_ENLAZADAS

Lista* crearNodo();
Lista* InsertarPos(Lista* L, int pos, int dato);
Lista* InsertarFinal(Lista* L, int dato);
int obtener(Lista* L, int pos);
int largo(Lista* L);

#endif