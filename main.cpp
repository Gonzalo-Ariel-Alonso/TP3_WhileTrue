#include <iostream>

#include "Grafo.h"

using namespace std;

int main(){
  int * p;
  int i = 20;
  int * t;
  int j = 10;
  Grafo<int> el_grafo;
  p = &i;
  t = &j;
  el_grafo.agregar_vertice(p);
  el_grafo.agregar_vertice(t);
  el_grafo.agregar_arista(p,t,9000);
  cout << el_grafo.consulta_vertice(p) << std::endl;


  return 0;
}
