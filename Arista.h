#ifndef ARISTA_H
#define ARISTA_H

// includes
#include <iostream>

// includes de otros TDA
#include "Vertice.h"

using namespace std;

template <typename Dato>
class Vertice;

template <typename Dato>
class Arista{
    private:
        //atributos
        Arista<Dato> * arista_adyacente;
        Vertice<Dato> * vertice_adyacente;
        int peso;

    public:
        /*
        Constructor
        Pre: -
        Pos: Inicializa una arista con el vertice adyacente y el arista adayacente apuntando a 0
        */
        Arista();
        /*
        Constructor
        Pre: La posicion de un vertice
        Pos: Inicializa una arista con el vertice pasado por parametro  
        */
        Arista(Vertice<Dato> * vertice_adyacente);
        /*
        Destructor
        Pre: -
        Pos: -
        */
        ~Arista();
        /*
        Cambia el arista adyacente(atributo) por el que se paso por parametro
        Pre: El puntero de una arista
        Pos: -
        */
        void set_arista_siguiente(Arista<Dato> * arista_nueva);
        /*
        Devuelve el arista siguiente(atributo)
        Pre: -
        Pos: Devuelve el (atributo) arista adyacente
        */
        Arista<Dato>* get_arista_siguiente();
        /*
        Cambia el vertice adyacente(atributo) por el que se paso por parametro
        Pre: El puntero de un vertice
        Pos: -
        */
        void set_vertice_adyacente(Vertice<Dato> * vertice_adyacente);
        /*
        Devuelve el arista siguiente(atributo)
        Pre: -
        Pos: Devuelve el (atributo) vertice adyacente
        */
        Vertice<Dato> * get_vertice_adyacente();
        /*
        Devuelve el dato del vertice
        Pre: -
        Pos: Devuelve el dato del vertice(atributo)
        */
        Dato get_dato_vertice_adyacente();
        /*
        Devuelve el (atributo) peso, que es el peso de la arista
        Pre: -
        Pos: Devuelve un entero
        */
        int get_peso();
        /*
        Cambia el peso de la arista por el pasado por parametro
        Pre: Un entero
        Pos: -
        */
        void set_peso(int peso);
};

template <typename Dato>
Arista<Dato>::Arista(){
  vertice_adyacente = 0;
  arista_adyacente = 0;
}


template <typename Dato>
Arista<Dato>::~Arista(){
    arista_adyacente = nullptr;
    vertice_adyacente = nullptr;
}

template <typename Dato>
Arista<Dato>::Arista(Vertice<Dato> * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
    this->arista_adyacente = 0;
}

template <typename Dato>
void Arista<Dato>::set_arista_siguiente(Arista<Dato> * arista_nueva){
    arista_adyacente = arista_nueva;
}

template <typename Dato>
Arista<Dato> * Arista<Dato>::get_arista_siguiente(){
    return arista_adyacente;
}

template <typename Dato>
void Arista<Dato>::set_vertice_adyacente(Vertice<Dato> * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
}

template <typename Dato>
Vertice<Dato> * Arista<Dato>::get_vertice_adyacente(){
    return vertice_adyacente;
}

template <typename Dato>
Dato Arista<Dato>::get_dato_vertice_adyacente(){
  return vertice_adyacente->get_dato_vertice();
}

template <typename Dato>
int Arista<Dato>::get_peso(){
    return peso;
}

template <typename Dato>
void Arista<Dato>::set_peso(int peso){
    this->peso = peso;
}


#endif
