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

  Arista<int*> * arista_aux = el_grafo.consulta_vertice(p)->get_arista_adyacente();
  cout << "vertice p = 30" << endl;
  while (arista_aux != 0){
    cout << *arista_aux->get_dato_vertice_adyacente() << endl;
    cout << arista_aux->get_peso() << endl;
    arista_aux = arista_aux->get_arista_siguiente();
  }
  el_grafo.eliminar_arista(p,t);
  arista_aux = el_grafo.consulta_vertice(p)->get_arista_adyacente();
  cout << "vertice p = 30" << endl;
  while (arista_aux != 0){
    cout << *arista_aux->get_dato_vertice_adyacente() << endl;
    cout << arista_aux->get_peso() << endl;
    arista_aux = arista_aux->get_arista_siguiente();
  }

  arista_aux = el_grafo.consulta_vertice(t)->get_arista_adyacente();
  cout << "vertice t = 20" << endl;
  while (arista_aux != 0){
    cout << *arista_aux->get_dato_vertice_adyacente() << endl;
    cout << arista_aux->get_peso() << endl;
    arista_aux = arista_aux->get_arista_siguiente();
  }

  arista_aux = el_grafo.consulta_vertice(r)->get_arista_adyacente();
  cout << "vertice r = 10" << endl;
  while (arista_aux != 0){
    cout << *arista_aux->get_dato_vertice_adyacente() << endl;
    cout << arista_aux->get_peso() << endl;
    arista_aux = arista_aux->get_arista_siguiente();
  }


  cout << "final"<< endl;

  return 0;
}
