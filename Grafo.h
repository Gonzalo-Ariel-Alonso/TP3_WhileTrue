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
        Vertice<Dato> * agregar_vertice(Vertice<Dato>* vertice_nuevo);
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
        Vertice<Dato>* consulta_vertice( Dato * nuevo_dato );
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


template<typename Dato>
Vertice<Dato>* Grafo<Dato>::consulta_vertice( Dato * nuevo_dato ){
  Vertice<Dato>* vertice_auxiliar;
  if (vacia()){
    cout << "Grafo Vacio!"<< endl;
  }
  else{
    Vertice<Dato> * vertice_actual = primer_vertice;
    for (int i = 1; i <= cantidad_vertices; i++ ){
      vertice_actual = vertice_actual->get_vertice_siguiente();
      if (vertice_actual->get_dato_vertice() == nuevo_dato){
        vertice_auxiliar = vertice_actual;
        i = cantidad_vertices++;
      }
    }
  }
  if ( !vertice_auxiliar ){
    cout << "No esta el vertice" << endl;
  }
  return vertice_auxiliar; //devuelve vacio si no esta
}

//Cambiar Vertice
template<typename Dato>
void Grafo<Dato>::agregar_vertice( Dato * nuevo_dato ){
  if (cantidad_vertices == 0){
    primer_vertice = new Vertice<Dato>(nuevo_dato);
    cantidad_vertices ++;
  }
  else{
    Vertice<Dato> * vertice_actual = primer_vertice;
    for (int i = 1; i <= cantidad_vertices; i++ ){
      vertice_actual = vertice_actual->get_vertice_siguiente();
    }
    Vertice<Dato> * nuevo_vertice = new Vertice<Dato>(nuevo_dato);
    vertice_actual->set_vertice_siguiente(nuevo_vertice);
    cantidad_vertices ++;
  }
}

template <typename Dato>
void Grafo<Dato>::agregar_arista(Dato * origen, Dato * adyacente, int costo_arista){
  Vertice<Dato> * vertice_origen = consulta_vertice(origen);
  Vertice<Dato> * vertice_adyacente = consulta_vertice(adyacente);
  Arista<Dato> * nueva_arista = new Arista<Dato>(vertice_adyacente); //VER DONDE BORRARLA
  vertice_origen->set_nueva_arista_adyacente(nueva_arista);
  vertice_origen = 0;
  vertice_adyacente = 0;
}

void Grafo<Dato>::eliminar_arista (Dato * origen, Dato * adyacente){
  Vertice<Dato> * vertice_origen = consulta_vertice(origen); //salida
  Vertice<Dato> * vertice_adyacente = consulta_vertice(adyacente); //llegada
  Arista<Dato> * arista_borrar = vertice_origen->get_arista_adyacente();
  int i = 0;
  Arista<Dato> * arista_auxiliar;
  while( arista_borrar->get_dato_vertice_adyacente() != adyacente && arista_borrar->get_arista_siguiente() != 0 ){
    arista_auxiliar = arista_borrar; //uno anterior al borrado
    arista_borrar = arista_borrar->get_arista_siguiente();
    i++;
  }

  if( i == 0 && arista_borrar->get_dato_vertice_adyacente() == adyacente ){
    vertice_origen->set_arista_adyacente(arista_borrar->get_arista_siguiente());
    delete[] arista_borrar;
  }
  else if (arista_borrar->get_dato_vertice_adyacente() == adyacente && i != 0){
    arista_auxiliar->set_arista_siguiente(arista_borrar->get_arista_siguiente());
    delete[] arista_borrar;
  }
  else{
    cout << "Arista inexistente" << endl;
  }

}

//Destructor
template<typename Dato>
Grafo<Dato>::~Grafo(){
  Vertice<Dato> * vertice_borrar;
  while (!vacio()){
    vertice_borrar = primer_vertice;
    primer_vertice = vertice_borrar->get_vertice_siguiente();
    delete[] vertice_borrar;
    cantidad_vertices --;
  }
}

#endif
