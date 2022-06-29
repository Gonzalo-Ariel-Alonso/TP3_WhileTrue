#ifndef VERTICE_H
#define VERTICE_H

// includes
#include<iostream>

// includes de otros TDA
#include "Arista.h"

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
  Arista<Dato>* get_arista_adyacente();
  void eliminar_arista(Dato dato);
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
  //voy a borrar solo las aristas del vertice aca

  Arista<Dato> * arista_auxiliar; //agarra al primero
  while( arista_adyacente != 0 ){
    arista_auxiliar = arista_adyacente;
    arista_adyacente = arista_adyacente->get_arista_siguiente(); //el primero pasa a ser el segundo
    delete arista_auxiliar; //SE BORRA LA ARISTA;
  }
  if (arista_adyacente != 0){
    delete arista_auxiliar;
  }
  delete dato_actual;
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
  Arista<Dato> * arista_auxiliar = arista_adyacente;
  if (arista_adyacente == 0){
    arista_adyacente = nueva_arista_adyacente;
  }
  else{
    while ( arista_auxiliar->get_arista_siguiente() != 0 ){
      arista_auxiliar = arista_auxiliar->get_arista_siguiente();
    }
    arista_auxiliar->set_arista_siguiente(nueva_arista_adyacente);
  }

}

template <typename Dato>
void Vertice<Dato>::eliminar_arista(Dato dato){
  Arista<Dato> * actual = arista_adyacente;
  Arista<Dato> * anterior;
  if ( arista_adyacente != 0){ //se que hay ayacentes
    //si es la primer arista ( arista nro 1)
    if ( arista_adyacente->get_vertice_adyacente()->get_dato_vertice() == dato ){
      arista_adyacente = actual->get_arista_siguiente();
      delete actual;
    }
    //Else si son las otras
    else{
      //mientras que no llegue al ultimo puntero nullo y en este caso no entra ya
      while (actual != 0 && actual->get_arista_siguiente() != 0){
        anterior = actual;
        actual = actual->get_arista_siguiente(); //actual = 0;
        if(actual->get_vertice_adyacente()->get_dato_vertice() == dato ){
          anterior->set_arista_siguiente(actual->get_arista_siguiente());
          delete actual;
        }
      }
    }
  }
}

template <typename Dato>
Arista<Dato>* Vertice<Dato>::get_arista_adyacente(){
  return arista_adyacente;
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
