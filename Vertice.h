#ifndef VERTICE_H
#define VERTICE_H

#include<iostream>
#include "Arista.h"

using namespace std;



template <typename Dato>
class Arista;

template <typename Dato>
class Vertice{
private:
  Vertice<Dato> * vertice_siguiente;
  Dato dato_actual;
  Arista<Dato> * arista_adyacente;

public:
  Vertice();
  Vertice(Dato dato);
  ~Vertice();
  Vertice<Dato>* get_vertice_siguiente();
  void set_vertice_siguiente (Vertice<Dato> * nuevo_vertice);
  void set_arista_adyacente (Arista<Dato> * arista_adyacente);
  void set_nueva_arista_adyacente (Arista<Dato> * nueva_arista_adyacente);
  Dato get_dato_vertice();
  void set_dato_actual(Dato nuevo_dato);
};


template <typename Dato>
Vertice<Dato>::Vertice (){
  vertice_siguiente = 0;
  dato_actual = 0;
  arista_adyacente = 0;
}


template <typename Dato>
Vertice<Dato>::Vertice ( Dato dato ){
  vertice_siguiente = 0;
  dato_actual = dato;
  arista_adyacente = 0;
}

//VER
template <typename Dato>
Vertice<Dato>::~Vertice(){
  Arista<Dato> * arista_auxiliar = arista_adyacente; //agarra al primero
  while(arista_adyacente->get_arista_siguiente() != 0){
    arista_adyacente = arista_adyacente->get_arista_siguiente(); //el primero pasa a ser el segundo

    delete[] arista_auxiliar; //SE BORRA LA ARISTA;
  }
}


template <typename Dato>
Vertice<Dato>* Vertice<Dato>::get_vertice_siguiente(){
  return vertice_siguiente;
}


template <typename Dato>
void Vertice<Dato>::set_vertice_siguiente( Vertice<Dato> * nuevo_vertice ){
  vertice_siguiente = nuevo_vertice;
}


template <typename Dato>
void Vertice<Dato>::set_arista_adyacente (Arista<Dato> * arista_adyacente){
  this->arista_adyacente = arista_adyacente;
}


template <typename Dato>
void Vertice<Dato>::set_nueva_arista_adyacente (Arista<Dato> * nueva_arista_adyacente){
  Arista<Dato> * arista_auxiliar;
  while (arista_auxiliar->get_arista_siguiente() != 0){
    arista_auxiliar = arista_auxiliar->get_arista_siguiente();
  }
  arista_auxiliar->set_arista_siguiente(nueva_arista_adyacente);
}


template <typename Dato>
Dato Vertice<Dato>::get_dato_vertice(){
  return dato_actual;
}

template <typename Dato>
void Vertice<Dato>::set_dato_actual(Dato  nuevo_dato){
  dato_actual = nuevo_dato;
}

#endif // VERTICE_H
