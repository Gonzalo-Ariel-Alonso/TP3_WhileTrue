#include <iostream>

#include "Grafo.h"
#include "Arista.h"
using namespace std;

int main(){
  int * p;
  int i = 30;
  int * t;
  int j = 20;
  int * r;
  int k = 10;
  r = &k;
  Grafo<int*> el_grafo;
  p = &i;
  t = &j;
  cout << "agrego p" << endl;
  el_grafo.agregar_vertice(p);
  cout << *el_grafo.consulta_vertice(p)->get_dato_vertice() << std::endl;
  cout << "agrego t" << endl;
  el_grafo.agregar_vertice(t);
  cout << *el_grafo.consulta_vertice(t)->get_dato_vertice() << std::endl;
  cout << "agrego r" << endl;
  el_grafo.agregar_vertice(r);
  cout << *el_grafo.consulta_vertice(r)->get_dato_vertice() << std::endl;
  cout << "agrego la arista p - t" << endl;
  el_grafo.agregar_arista(p,t,9000);
  cout << "1ro" << endl;

  cout << el_grafo.consulta_vertice(p)->get_arista_adyacente()->get_peso() << std::endl;
  cout << "final"<< endl;

  return 0;
}
