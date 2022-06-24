#ifndef ARISTA_H
#define ARISTA_H

//#include "Vertice.h"
//#include "Descanso_entre_lecturas.h"

template <class Dato>
class Arista
{
private:
    Arista * arsita_siguiente;
    Vertice * vertice_adyacente;
    int peso;

public:
    Arista();
    Arista(Vertice * Vertice_adyacente);
    ~Arista();
    void set_arista_siguiente(Arista * arista_nueva);
    Arista get_arista_siguiente();
    void set_vertice_adyacente(Vertice * vertice_adyacente);
    Vertice * get_vertice_adyacente();
    int get_peso();
};

template <class Dato>
Arista<Dato>::Arista(){
}


template <class Dato>
Arista<Dato>::~Arista(){
    arsita_siguiente = nullptr;
}

template <class Dato>
Arista<Dato>::Arista(Vertice * Vertice_adyacente){
    this->Vertice_adyacente = vertice_adyacente;
    /*Descanso_entre_lecturas Descanso(Vertice_adyacente->get_tipo_de_lectura,arsita_siguiente->get_vertice_adyacente()->get_tipo_de_lectura);
    peso = Descanso.get_tiempo_de_descanso();*/
}

template <class Dato>
void Arista<Dato>::set_arista_siguiente(Arista * arista_nueva){
    arsita_siguiente = arista_nueva;
}

template <class Dato>
Arista<Dato> Arista<Dato>::get_arista_siguiente(){
    return arsita_siguiente;
}

template <class Dato>
void Arista<Dato>::set_vertice_adyacente(Vertice * vertice_adyacente){
    this->vertice_adyacente = vertice_adyacente;
}
template <class Dato>
Vertice * Arista<Dato>::get_vertice_adyacente(){
    return vertice_adyacente;
}

template <class Dato>
int Arista<Dato>::get_peso(){
    return peso;
}


#endif