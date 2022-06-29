#ifndef CAMINO_H
#define CAMINO_H

// includes
#include <iostream>

using namespace std;
template <typename Dato>

class Camino {
  private:
    Dato origen;
    Dato adyacente;
    int costo;

  public:
    /*
    Constructor
    Pre: El dato del vertice origen, el dato del vertice adyacente, el costo de la arista
    Pos: Devuelve un objeto tipo Dato con los parametros pasados
    */
    Camino(Dato Origen, Dato adyacente, int costo_arista);
    /*
    Devuelve el dato origen(atributo)
    Pre: -
    Pos: El Dato origen(atributo)
    */
    Dato get_origen();
    /*
    Devuelve el dato adyacente(atributo) 
    Pre: -
    Pos: El Dato adyacente(atributo)
    */
    Dato get_adyacente();
    /*
    Devuelve un entero, el costo del camino(atributo)
    Pre: -
    Pos: Un entero
    */
    int get_costo();
    /*
    Imprime el camino
    Pre: -
    Pos: -
    */
    void imprimir_camino();
    // Destructor
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
