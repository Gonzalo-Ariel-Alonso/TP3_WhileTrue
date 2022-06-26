#include "Grafo.h"


int main(){

    Grafo<int> *el_grafo = new Grafo<int>();

    //int * A,B,C,D,E;
    int a = 10,b = 20,c = 30, d = 40, e = 50;

    el_grafo->agregar_vertice(a);
    el_grafo->agregar_vertice(b);
    el_grafo->agregar_vertice(c);
    el_grafo->agregar_vertice(d);
    el_grafo->agregar_vertice(e);
    el_grafo->agregar_arista(a,b,9000);
    el_grafo->agregar_arista(d,e,9000);
    el_grafo->agregar_arista(c,a,9000);
    el_grafo->mostar_lista_de_adyacencia();
    el_grafo->eliminar_arista(d,e);
    el_grafo->eliminar_vertice(b);
    el_grafo->eliminar_vertice(d);
    el_grafo->eliminar_vertice(a);
    el_grafo->eliminar_vertice(b); 
    el_grafo->eliminar_grafo();
    //delete[] el_grafo;
    return 0;



}