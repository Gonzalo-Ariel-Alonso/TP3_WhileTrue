#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

#include "Vertice.h"
#include "Arista.h"
#include "Lectura.h"
#include "Descanso_entre_lecturas.h"
#include "Tipo_de_lecturas.h"

using namespace std;

template <typename Dato>

class Grafo{
    // atributos
    private:
        Vertice<Dato> * primer_vertice;
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
        void agregar_vertice(Dato  vertice_nuevo);

        void transformar_a_grafo_completo();

        int calcular_costo_arista(Lectura * origen, Lectura * adyacente );

        Tipo_de_lecturas de_char_a_enumerado(char char_tipo_lectura);

        void conectar_nuevo_vertice_con_todos(Dato nuevo_dato);

        void conectar_todos_los_vertices_con_el_nuevo(Dato nuevo_dato);

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
        Vertice<Dato>* consulta_vertice( Dato dato );
        /*
        Consulta la cantidad de vertice
        Pre: -
        Post: Devuelve la cantidad de vertices
        */
        int get_cantidad_vertices();

        void agregar_arista(Dato  origen, Dato  adyacente, int costo_arista);

        void eliminar_vertice(Dato dato);

        void eliminar_arista (Dato  origen, Dato  adyacente);

        void imprimir_grafo();
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
Vertice<Dato>* Grafo<Dato>::consulta_vertice( Dato  dato ){
  Vertice<Dato>* vertice_auxiliar;
  if (vacia()){
    cout << "Grafo Vacio!"<< endl;
  }
  else{
    Vertice<Dato> * vertice_actual = primer_vertice;
    for (int i = 1; i <= cantidad_vertices; i++ ){
      if (vertice_actual->get_dato_vertice() == dato){
        vertice_auxiliar = vertice_actual;
        i = cantidad_vertices + 1;
      }
      vertice_actual = vertice_actual->get_vertice_siguiente();
    }
  }
  if ( !vertice_auxiliar ){
    cout << "No esta el vertice" << endl;
  }
  return vertice_auxiliar; //devuelve vacio si no esta
}

//Cambiar Vertice
template<typename Dato>
void Grafo<Dato>::agregar_vertice( Dato  nuevo_dato ){
  if (cantidad_vertices == 0){
    primer_vertice = new Vertice<Dato>(nuevo_dato);
    cantidad_vertices ++;
  }
  else{
    Vertice<Dato> * vertice_actual = primer_vertice;

    for (int i = 1; i < cantidad_vertices; i++ ){
      vertice_actual = vertice_actual->get_vertice_siguiente();
    }
    Vertice<Dato> * nuevo_vertice = new Vertice<Dato>(nuevo_dato);
    vertice_actual->set_vertice_siguiente(nuevo_vertice);
    cantidad_vertices ++;
  }
}

template <typename Dato>
void Grafo<Dato>::conectar_nuevo_vertice_con_todos(Dato nuevo_dato){
  Vertice<Dato> * vertice_origen = consulta_vertice(nuevo_dato);
  Vertice<Dato> * vertice_llegada = primer_vertice ;
  Dato * dato_vertice_origen = vertice_origen->get_dato_vertice() ;
  Dato * dato_vertice_adyacente;
  for (int i = 1; i <= cantidad_vertices; i++ ){
    dato_vertice_adyacente = vertice_llegada->get_dato_vertice();
    if ( dato_vertice_origen != dato_vertice_adyacente ){
      int costo = calcular_costo_arista(dato_vertice_origen, dato_vertice_adyacente);
      agregar_arista(dato_vertice_origen, dato_vertice_adyacente, costo );
    }
    vertice_llegada = vertice_llegada->get_vertice_siguiente();
  }
}

template <typename Dato>
void Grafo<Dato>::conectar_todos_los_vertices_con_el_nuevo(Dato nuevo_dato){
  Vertice<Dato> * vertice_llegada = consulta_vertice(nuevo_dato);
  Vertice<Dato> * vertice_origen = primer_vertice ;
  Dato * dato_vertice_origen = vertice_origen->get_dato_vertice() ;
  Dato * dato_vertice_adyacente;
  for (int i = 1; i <= cantidad_vertices; i++ ){
    dato_vertice_adyacente = vertice_llegada->get_dato_vertice();
    if ( dato_vertice_origen != dato_vertice_adyacente ){
      int costo = calcular_costo_arista(dato_vertice_origen, dato_vertice_adyacente);
      agregar_arista(dato_vertice_origen, dato_vertice_adyacente, costo );
    }
    vertice_origen = vertice_origen->get_vertice_siguiente();
  }
}



template <typename Dato>
void Grafo<Dato>::agregar_arista(Dato  origen, Dato  adyacente, int costo_arista){
  Vertice<Dato> * vertice_origen = consulta_vertice(origen);
  Vertice<Dato> * vertice_adyacente = consulta_vertice(adyacente);
  Arista<Dato> * nueva_arista = new Arista<Dato>(vertice_adyacente); //VER DONDE BORRARLA
  nueva_arista->set_peso(costo_arista);
  vertice_origen->set_nueva_arista_adyacente(nueva_arista);
  vertice_origen = 0;
  vertice_adyacente = 0;
}





//Solo hay vertices y no hay aristas
template <typename Dato>
void Grafo<Dato>::transformar_a_grafo_completo(){
  Vertice<Dato> * vertice_origen = primer_vertice; // marco el vertice origen
  Vertice<Dato> * vertice_llegada = primer_vertice; // marco el vertice adyacente
  Dato dato_vertice_origen ; // dato_origen
  Dato dato_vertice_adyacente; //dato_adyacente
  for (int i = 1; i <= cantidad_vertices; i++){ // recorro los vertices
    dato_vertice_origen = vertice_origen->get_dato_vertice(); //consigo el dato origen

    for (int j = 1; j <= cantidad_vertices; j++){ //recorro los adyacentes
      dato_vertice_adyacente = vertice_llegada->get_dato_vertice();

      if ( dato_vertice_origen != dato_vertice_adyacente ){
        int costo = calcular_costo_arista(dato_vertice_origen, dato_vertice_adyacente);
        agregar_arista(dato_vertice_origen, dato_vertice_adyacente, costo );
      }
      vertice_llegada = vertice_llegada->get_vertice_siguiente();
    }
    vertice_llegada = primer_vertice;
    vertice_origen = vertice_origen->get_vertice_siguiente();
  }
}

template <typename Dato>
int Grafo<Dato>::calcular_costo_arista(Lectura * origen, Lectura * adyacente ){
  int costo;
  Tipo_de_lecturas lectura_origen;
  Tipo_de_lecturas lectura_adyacente;
  lectura_origen = de_char_a_enumerado(origen->get_tipo_de_objeto());
  lectura_adyacente = de_char_a_enumerado(adyacente->get_tipo_de_objeto());
  Descanso_entre_lecturas costo_de_la_arista(lectura_origen , lectura_adyacente);
  costo = costo_de_la_arista.get_tiempo_de_descanso();
  return costo;
}

template <typename Dato>
Tipo_de_lecturas Grafo<Dato>::de_char_a_enumerado(char char_tipo_lectura){

  Tipo_de_lecturas Tipo_de_lecturas;
  if(char_tipo_lectura  == 'N')
    Tipo_de_lecturas = NOVELA;
  else if (char_tipo_lectura == 'C')
    Tipo_de_lecturas = CUENTO;
  else if (char_tipo_lectura  == 'P')
    Tipo_de_lecturas = POEMA;
  else if (char_tipo_lectura  == 'H')
    Tipo_de_lecturas = NOVELA_HISTORICA;

  return Tipo_de_lecturas;

}


template <typename Dato>
void Grafo<Dato>::eliminar_arista (Dato  origen, Dato  adyacente){
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
  //si no entro al while y es la primera arista adyacente
  if( i == 0 && arista_borrar->get_dato_vertice_adyacente() == adyacente ){
    cout << "era la primer arista adyacente a borrar" << endl;
    vertice_origen->set_arista_adyacente(arista_borrar->get_arista_siguiente());
    cout << "borrando arista" << endl;
    delete arista_borrar;
    cout << "borre la primer arista adyacente" << endl;
  }
  //Si encontro la arista y no es la primera
  else if (arista_borrar->get_dato_vertice_adyacente() == adyacente && i != 0){
    cout << " Encontre la arista adyacente a borrar pero no era la primera" << endl;
    arista_auxiliar->set_arista_siguiente(arista_borrar->get_arista_siguiente());
    delete arista_borrar;
    cout << "borre la arista adyacente a borrar  que no era la primera" << endl;
  }
  //no la encontro
  else{
    cout << "Arista inexistente" << endl;
  }
}

template <typename Dato>
void Grafo<Dato>::eliminar_vertice(Dato dato){
  Vertice<Dato> * actual = primer_vertice;

  //recorre por cada vertice sus adyacencias con el vertice a borrar
  for (int i = 1; i <= cantidad_vertices; i++){ //ver la condicion que no se pase
    actual->eliminar_arista(dato);
    actual = actual->get_vertice_siguiente(); // proximo vertice
  }

  Vertice<Dato> * anterior;
  actual = primer_vertice;
  //si el primer vertice es el que quiero borrar

  if (primer_vertice->get_dato_vertice() == dato ){
    primer_vertice = primer_vertice->get_vertice_siguiente();
    delete actual;
    cantidad_vertices --;
  }
  else if(cantidad_vertices == 1) {
    delete primer_vertice;
    cantidad_vertices --;
  }
  else{
    anterior = primer_vertice;
    //si coincide el dato del vertice con el que quiero eliminar no entra al while
    while(anterior->get_dato_vertice() != dato){
      anterior = actual;
      actual = actual->get_vertice_siguiente();
      if (actual->get_dato_vertice() == dato ){
          anterior->set_vertice_siguiente(actual->get_vertice_siguiente());
          delete actual;
          cantidad_vertices--;
      }
    }
  }

}

template < typename Dato >
void Grafo<Dato>::imprimir_grafo(){
  Vertice<Dato> * vertice_origen = primer_vertice; // vertice origen
  Arista<Dato> * arista_entre_vertices = vertice_origen->get_arista_adyacente();
  Dato  dato_vertice_origen ;
  Dato  dato_vertice_adyacente ;
  cout << "GRAFO COMPLETO" << endl;
  for (int i = 1; i <= cantidad_vertices; i++){
    dato_vertice_origen = vertice_origen->get_dato_vertice();
    cout << endl << endl << "VERTICE ---COSTO---> ADYACENTES" << endl;
    cout << dato_vertice_origen->get_titulo();
    while (arista_entre_vertices != 0){
      dato_vertice_adyacente = arista_entre_vertices->get_vertice_adyacente()->get_dato_vertice();
      cout << "---" << arista_entre_vertices->get_peso() << "--->" << dato_vertice_adyacente->get_titulo();
      arista_entre_vertices = arista_entre_vertices->get_arista_siguiente();
    }
    if( vertice_origen->get_vertice_siguiente() != 0 ){
      vertice_origen = vertice_origen->get_vertice_siguiente();
      arista_entre_vertices = vertice_origen->get_arista_adyacente();
    }

  }
}

//Destructor
template<typename Dato>
Grafo<Dato>::~Grafo(){
  while (!vacia()){
    eliminar_vertice(primer_vertice->get_dato_vertice());
  }
}

#endif
