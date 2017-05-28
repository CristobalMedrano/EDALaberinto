#ifndef TDA_ARBOL
#define TDA_ARBOL

#define SIN_DATO -1
Arbol* crearHoja(int dato, Arbol* arbol_izquierdo, Arbol* arbol_derecho);
Arbol* borrarArbol(Arbol* arbol, int dato);
Arbol* obtenerRaiz(Arbol* arbol);
Arbol* mayorAnterior(Arbol* arbol, Arbol* actual);
Arbol* menorSiguiente(Arbol* arbol, Arbol* actual);
Arbol* obtenerPadre(Arbol* arbol, Arbol* elemento);
Arbol* obtenerMayorElemento(Arbol* arbol);
Arbol* obtenerMenorElemento(Arbol* arbol);
Arbol* buscarDato(Arbol* arbol, int dato);
int obtenerDatoArbol(Arbol* arbol);
Arbol* hijo_IZQUIERDO(Arbol* arbol);
Arbol* hijo_DERECHO(Arbol* arbol);
Arbol* insertarDato(Arbol* arbol, int dato);
void preOrden(Arbol* arbol);
void inOrden(Arbol* arbol);
void postOrden(Arbol* arbol);
void MenuArboles();

#endif