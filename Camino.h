#ifndef CAMINO_H
#define CAMINO_H


#include <iostream>

using namespace std;
template <typename Dato>

class Camino {
private:
  Dato origen;
  Dato adyacente;
  int costo;

public:
  Camino(Dato Origen, Dato adyacente, int costo_arista);
  Dato get_origen();
  Dato get_adyacente();
  int get_costo();
  void imprimir_camino();
  ~Camino();
};

template <typename Dato>
Camino<Dato>::Camino(Dato origen, Dato adyacente, int costo_arista){
  this->origen = origen;
  this->adyacente = adyacente;
  costo = costo_arista;
}

template <typename Dato>
Camino<Dato>::~Camino(){
  origen = 0;
  adyacente = 0;
}

template <typename Dato>
Dato Camino<Dato>::get_origen(){
  return origen;
}

template <typename Dato>
Dato Camino<Dato>::get_adyacente(){
  return adyacente;
}

template <typename Dato>
int Camino<Dato>::get_costo(){
  return costo;
}


template <typename Dato>
void Camino<Dato>::imprimir_camino(){
  cout << origen->get_titulo() << "---" << costo << "--->" << adyacente->get_titulo();
}

#endif //CAMINO_H
