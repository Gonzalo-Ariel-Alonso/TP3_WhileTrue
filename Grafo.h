#ifndef GRAFO_H
#define GRAFO_H

#include "Vertice.h"

template <typename Dato>

class Grafo{
    // atributos
    private:
        Vertice * primer_vertice;
        int cantidad_vertices;
    public:
        /*
        Constructor
        Pre: -
        Post: Inicializa en 0 cantidad_vertices y deja apuntando a null primer_vertice
        */
        Grafo();
        /*
        Vacia
        Pre: -
        Post: devuelve si la lista esta vacia
        */
        bool vacia();
        /*
        Agrega un vertice
        Pre: el vertice a agregar
        Post: deja apuntando el vertice al nuevo y lo devuelve
        */
        Vertice * agregar_vertice(Vertice<Dato>* vertice_nuevo);
        /*
        Cambia un vertice
        Pre: el vertice a cambiar
        Post: cambia el dato del vertice por el vertice_nuevo
        */
        void set_vertice(Vertice<Dato>* vertice_nuevo);
        /*
        Devuelve el vertice
        Pre: -
        Post: Devuelve el vertice
        */
        Vertice* get_vertice();
        /*
        Consulta la cantidad de vertice
        Pre: -
        Post: Devuelve la cantidad de vertices
        */
        int get_cantidad_vertices();
        //Destructor
        ~Grafo();
};

//Constructor   
template<typename Dato>
Grafo<Dato>::Grafo(){
    primer_vertice = 0;
    cantidad_vertices = 0;
}
//Vacia
template<typename Dato>
bool Grafo<Dato>::vacia(){
    return (cantidad_vertices == 0);
}
//Obtener cantidad vertice
template<typename Dato>
int Grafo<Dato>::get_cantidad_vertices(){
    return cantidad_vertices;
}
//Obtener Vertice
template<typename Dato>
Vertice* Grafo<Dato>::get_vertice() {
    return primer_vertice;
}
//Cambiar Vertice
template<typename Dato>
void Grafo<Dato>::set_vertice_siguiente(){
}
//Destructor
template<typename Dato>
Grafo<Dato>::~Grafo(){
}

#endif