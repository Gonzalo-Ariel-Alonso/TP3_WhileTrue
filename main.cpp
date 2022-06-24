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
  el_grafo.agregar_vertice(i);
  el_grafo.agregar_vertice(j);
  el_grafo.agregar_arista(i,j,9000);
  cout << el_grafo.consulta_vertice(i)->get_dato_vertice() << std::endl;


  return 0;
}
