#ifndef GRAFO_H
#define GRAFO_H

// includes
#include <iostream>

// includes de otros TDA
#include "Vertice.h"
#include "Arista.h"
#include "Lectura.h"
#include "Descanso_entre_lecturas.h"
#include "Tipo_de_lecturas.h"
#include "Lista.h"
#include "Camino.h"

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
        Consulta la cantidad de vertice
        Pre: -
        Post: Devuelve la cantidad de vertices
        */
        int get_cantidad_vertices();

        /*
        Pre:-
        Post: Devuelve el primer vertice
        */
        Vertice<Dato>* get_primer_vertice();


        /*
        Agrega un vertice
        Pre: Recibe la direccion del un Dato
        Post: Lo agrega al final
        */
        void agregar_vertice(Dato  vertice_nuevo);

        /*
        Devuelve el vertice
        Pre: Recibe un objeto de tipo Dato
        Post: Devuelve el vertice
        */
        Vertice<Dato>* consulta_vertice( Dato dato );

        /*
        Agrega una arista al Grafo
        Pre:  Recibe el Dato del vertice origen ,del adyacente y el costo de la arista
        Post: Agrega el camino entre vertices con el respectivo costo
        */
        void agregar_arista(Dato  origen, Dato  adyacente, int costo_arista);


        /*
        Vuelve al grafo en completo
        Pre: Grafo creado con vertices
        Post: Conecta todos los vertices con todos
        */
        void transformar_a_grafo_completo();

        /*
        Cambia un vertice
        Pre: el vertice a cambiar
        Post: cambia el dato del vertice por el vertice_nuevo
        */
        void set_vertice(Vertice<Dato>* vertice_nuevo);

        /*
        Pre: Recibe un Dato
        Post: Lo quita del grafo junto con las aristas que lo involucran
        */
        void eliminar_vertice(Dato dato);

        /*
        Pre: Recibe el Dato origen y adyacente
        Post : borra la arista que los conecta en la respectiva direccion
        */
        void eliminar_arista (Dato  origen, Dato  adyacente);

        /*
        Pre: Recibe el vertice donde arrancar el algoritmo de prim
        Post: Imprime el arbol de expansion minima
        */
        void arbol_expansion_minima(Dato vertice_inicio);

        /*
        Pre:-
        Post: Imprime el grafo, como lista de adyacencia
        */
        void imprimir_grafo();


        //Destructor
        ~Grafo();
private:
        /*
        Pre: Recibe un dato
        Post: Borra las aristas que lo contengan
        */
        void borrar_aristas( Dato dato );
        /*
        Pre: Recibe 2 lecturas ya que usa sus metodos,
        Post: Calcula el tiempo de descanso para la arista
        */
        int calcular_costo_arista(Lectura * origen, Lectura * adyacente );

        /*
        Pre: Recibe un Dato
        Post: Conecta el Dato con el resto de vertices
        */
        void conectar_nuevo_vertice_con_todos(Dato nuevo_dato);
        /*
        Pre: Recibe un Dato
        Post: Conecta todos los vertices con el vertice que contiene al Dato
        */
        void conectar_todos_los_vertices_con_el_nuevo(Dato nuevo_dato);

        /*
        Pre: Recibe las respectivas listas a cargar
        Post: Las carga de manera que se pueda inicializar prim
        */
        void inicializar_listas_para_prim (Lista<Dato> * vertices_agregados, Lista<Dato> * vertices_a_agregar, Dato vertice_inicio);

        /*
        Pre: Recibe las listas cargadas ya por el algoritmo de prim
        Post: Carga el arbol con la informacion de las listas
        */
        int crear_arbol(Grafo<Dato> * arbol ,Lista<Dato> * vertices_agregados, Lista<Camino<Dato> *> * caminos);
        /*
        Pre: Recibe 3 listas cargadas con sus respectivos datos
        Post: Devuelve una lista con los vertices, otra vacia y una que guardo los caminos y costos
        */
        void algoritmo_prim(Lista<Dato> * vertices_agregados, Lista<Dato> * vertices_a_agrega, Lista<Camino<Dato>*> * caminos);

        /*
        NO TIENE USO MAS QUE PARA PODER BORRAR UN GRAFO SIN BORRAR LOS OBJETOS
        QUE ESTAN GUARDADOS EN EL GRAFO ORIGINAL
        SE USA ANTES DE DESTRUIR EL ARBOL DE EXPANSION MINIMA
        */
        void cambiar_datos_por_nulo();

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
Vertice<Dato>* Grafo<Dato>::get_primer_vertice(){
  return primer_vertice;
}


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
  Tipo_de_lecturas lectura_origen = origen->get_tipo_de_lectura();
  Tipo_de_lecturas lectura_adyacente = adyacente->get_tipo_de_lectura();
  Descanso_entre_lecturas costo_de_la_arista(lectura_origen , lectura_adyacente);
  costo = costo_de_la_arista.get_tiempo_de_descanso();
  return costo;
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
    vertice_origen->set_arista_adyacente(arista_borrar->get_arista_siguiente());
    delete arista_borrar;
  }
  //Si encontro la arista y no es la primera
  else if (arista_borrar->get_dato_vertice_adyacente() == adyacente && i != 0){
    arista_auxiliar->set_arista_siguiente(arista_borrar->get_arista_siguiente());
    delete arista_borrar;
  }
  //creo que este else if es al pedo
  else if (arista_borrar->get_dato_vertice_adyacente() == adyacente && arista_borrar->get_vertice_adyacente() == 0){
    arista_auxiliar->set_arista_siguiente(0);
    delete arista_borrar;
  }
  //no la encontro
  else{
    cout << "Arista inexistente" << endl;
  }
}

template <typename Dato>
void Grafo<Dato>::borrar_aristas( Dato dato ){
  Vertice<Dato> * actual = primer_vertice;
  //recorre por cada vertice sus adyacencias con el vertice a borrar
  for (int i = 1; i <= cantidad_vertices; i++){ //ver la condicion que no se pase
    //eliminar_arista(actual->get_dato_vertice(),dato);
    actual->eliminar_arista(dato);
    actual = actual->get_vertice_siguiente(); // proximo vertice
  }
}


template <typename Dato>
void Grafo<Dato>::eliminar_vertice(Dato dato){
  Vertice<Dato> * actual = primer_vertice;
  borrar_aristas(dato);
  Vertice<Dato> * anterior;
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
/*
template < typename Dato >
void Grafo<Dato>::imprimir_grafo(){
  if (cantidad_vertices > 0){
    Vertice<Dato> * vertice_origen = primer_vertice; // vertice origen
    Arista<Dato> * arista_entre_vertices = vertice_origen->get_arista_adyacente();
    Dato  dato_vertice_origen ;
    Dato  dato_vertice_adyacente ;


    cout << "\nLECTURA ---TIEMPO DE DESCANSO(min)--->LECTURAS SIGUIENTES\n\n";
    //cout << "\nVERTICE ---TIEMPO_DE_DESCANSO--->VERTICES ADYACENTES\n\n";
    for (int i = 1; i <= cantidad_vertices; i++){
      dato_vertice_origen = vertice_origen->get_dato_vertice();
      cout << dato_vertice_origen->get_titulo();
      while (arista_entre_vertices != 0){
        dato_vertice_adyacente = arista_entre_vertices->get_vertice_adyacente()->get_dato_vertice();
        cout << "---" << arista_entre_vertices->get_peso() << "--->" << dato_vertice_adyacente->get_titulo();
        arista_entre_vertices = arista_entre_vertices->get_arista_siguiente();
      }
      cout << "\n";
      if( vertice_origen->get_vertice_siguiente() != 0 ){
        vertice_origen = vertice_origen->get_vertice_siguiente();
        arista_entre_vertices = vertice_origen->get_arista_adyacente();
      }

    }
  }
}
*/

template < typename Dato >
void Grafo<Dato>::imprimir_grafo(){
  if (cantidad_vertices > 0){
    Vertice<Dato> * vertice_origen = primer_vertice; // vertice origen
    Arista<Dato> * arista_entre_vertices = vertice_origen->get_arista_adyacente();
    Dato  dato_vertice_origen ;
    Dato  dato_vertice_adyacente ;


    cout << "\nLECTURA (duracion) ------- TIEMPO DE DESCANSO(min) ------>LECTURAS SIGUIENTES (duracion)\n\n";
    //cout << "\nVERTICE ---TIEMPO_DE_DESCANSO--->VERTICES ADYACENTES\n\n";
    for (int i = 1; i <= cantidad_vertices; i++){
      dato_vertice_origen = vertice_origen->get_dato_vertice();

      while (arista_entre_vertices != 0){
        cout << dato_vertice_origen->get_titulo();
        dato_vertice_adyacente = arista_entre_vertices->get_vertice_adyacente()->get_dato_vertice();
        cout << " ( " << dato_vertice_origen->get_tiempo_lectura() << " ) ";
        cout << "------- " << arista_entre_vertices->get_peso() << " ------>" << dato_vertice_adyacente->get_titulo();
        cout << " ( " << dato_vertice_adyacente->get_tiempo_lectura() << " ) " << endl;
        arista_entre_vertices = arista_entre_vertices->get_arista_siguiente();
      }
      if (vertice_origen->get_arista_adyacente() != 0 ){
        cout << "\n";
      }
      if( vertice_origen->get_vertice_siguiente() != 0 ){
        vertice_origen = vertice_origen->get_vertice_siguiente();
        arista_entre_vertices = vertice_origen->get_arista_adyacente();
      }

    }
  }

}



//ALGORIMO PRIM
template<typename Dato>
void Grafo<Dato>::arbol_expansion_minima(Dato vertice_inicio){

  Grafo<Dato> arbol; //arbol expansion minima estatico
  Lista<Dato> vertices_agregados; //guarda los vertices YA agregados


  Lista<Dato> vertices_a_agregar; // aca van todos los vertices NO agregados

  Lista<Camino<Dato> *> caminos; // es una lista con un objeto CAMINO que guarda objeto origen y adyacente con el peso de arista

  inicializar_listas_para_prim(&vertices_agregados, &vertices_a_agregar, vertice_inicio);


  //El algoritmo de prim me llena la lista de vertices_agregados, me vacia vertices_a_agregar y me llena
  //con los caminos minimio la lista caminos
  algoritmo_prim(&vertices_agregados, &vertices_a_agregar, &caminos);
  //una vez terminado el algortimo agrego todos los vertices al arbol

  int costo_arbol_expansion_minima = crear_arbol(&arbol, &vertices_agregados, &caminos);
  arbol.imprimir_grafo();

  vertices_agregados.vaciar_datos(); //se vacia para que no borre los del grafo y del arbol
  arbol.cambiar_datos_por_nulo(); //se vacia para que no borre los del grafo
  cout << endl << endl << "Costo Arbol Expansion Minima: " << costo_arbol_expansion_minima << endl;
}


template < typename Dato>
void Grafo<Dato>::inicializar_listas_para_prim (Lista<Dato> * vertices_agregados, Lista<Dato> * vertices_a_agregar, Dato vertice_inicio){
  vertices_agregados->alta(vertice_inicio); //agrego ya su primer vertice inicio
  Vertice<Dato> * actual = primer_vertice ;
  //recorro los vertices
  for (int i = 1; i <= cantidad_vertices; i++){
    //lo agego a vertices_a_agregar si es que e vertice no esta agregado en vertices_agregados
    if ( !vertices_agregados->esta_el_dato(actual->get_dato_vertice()) ){
      vertices_a_agregar->alta(actual->get_dato_vertice());//alta
    }
    actual = actual->get_vertice_siguiente(); //Actual pasa a ser el siguiente
  }
}

template < typename Dato >
int Grafo<Dato>::crear_arbol(Grafo<Dato> * arbol ,Lista<Dato> * vertices_agregados, Lista<Camino<Dato> *> * caminos){
  for (int i = 1; i <= cantidad_vertices; i++){
    arbol->agregar_vertice(vertices_agregados->consulta(i));
  }
  //como hay N vertices, y N-1 aristas la condicion de corte tiene que ser 1
  //antes que cantidad_vertices
  Camino<Dato> * camino_minimo;
  int costo_arbol_expansion_minima = 0;
  for (int i = 1 ; i < cantidad_vertices; i++){
    camino_minimo = caminos->consulta(i);
    Dato origen = camino_minimo->get_origen();
    Dato adyacente = camino_minimo->get_adyacente();
    int costo_arista_agregar = camino_minimo->get_costo();
    costo_arbol_expansion_minima += costo_arista_agregar;
    arbol->agregar_arista(origen,adyacente,costo_arista_agregar);
  }
  return costo_arbol_expansion_minima;
}

template <typename Dato>
void Grafo<Dato>::algoritmo_prim(Lista<Dato> * vertices_agregados, Lista<Dato> * vertices_a_agregar, Lista<Camino<Dato>*> * caminos){
  Vertice<Dato> * vertice_actual;
  Arista<Dato> * arista_auxiliar;
  Camino<Dato> * camino_minimo;

 /*
 LAS LISTAS LLEGAN BIEN CARGADAS!!
 */
  int costo_arista;
  int cantidad_vertices_agregados;
  //me guardo el dato de donde sale el vertice
  Dato minima_salida;
  //me gusardo el dato del vertice_adyacente;
  Dato minima_llegada;

  //recorro un for hasta que agrego todos los vertices
  // i < cantidad_vertices, porque el primero ya esta agregado entonces faltan N-1 vertices

  for (int i = 1; i < cantidad_vertices; i++){
// N-1
    minima_salida = 0;
    minima_llegada = 0;
    //me guardo el costo de la arista, inicializa alto para saber que cualquier arista es mas chica
    costo_arista = 99999;

    //me da la cantidad de vertices ya agregados
    cantidad_vertices_agregados = vertices_agregados->obtener_cantidad();
    // recorro de los vertices ya agregados y busco la arista de menor costo;
    for (int j = 1; j <= cantidad_vertices_agregados; j++){

      //vertice_actual toma el valor de los vertices en la lista de agregados
      vertice_actual = consulta_vertice(vertices_agregados->consulta(j));
      //arista_auxiliar toma el valor de la primer adyacente a vertice_actual
      arista_auxiliar = vertice_actual->get_arista_adyacente();
      //recorro todas las adyacente buscando la arista minima

      while (arista_auxiliar != 0 ){

        // compara si es que la arista de llegada es una que pertenece a aristas a agregar
        if (vertices_a_agregar->esta_el_dato(arista_auxiliar->get_dato_vertice_adyacente())){
          int peso_arista = arista_auxiliar->get_peso();
          //entre a la arista, y comparo si es mas chica a la ya hallada(inicializada en 99999)
          //si es igual lo ignoro y me quedo con la que tenia
          if (peso_arista < costo_arista){
            costo_arista = peso_arista;
            minima_salida = vertice_actual->get_dato_vertice();
            minima_llegada = arista_auxiliar->get_dato_vertice_adyacente();
          }
        }
        arista_auxiliar = arista_auxiliar->get_arista_siguiente();
      }
    }
    camino_minimo = new Camino<Dato>(minima_salida, minima_llegada, costo_arista);
    caminos->alta(camino_minimo);
    vertices_agregados->alta(minima_llegada);
    vertices_a_agregar->baja_sin_borrar_dato(minima_llegada);
  }

}

template <typename Dato>
void Grafo<Dato>::cambiar_datos_por_nulo(){
  Arista<Dato> * arista_auxiliar;
  Vertice<Dato> * vertice_auxiliar;
  vertice_auxiliar = primer_vertice;
  for (int i = 1; i <= cantidad_vertices; i++){
    arista_auxiliar = vertice_auxiliar->get_arista_adyacente();
     while(arista_auxiliar != 0){
       arista_auxiliar->get_vertice_adyacente()->set_dato_actual(0);
       arista_auxiliar = arista_auxiliar->get_arista_siguiente();
     }
     vertice_auxiliar->set_dato_actual(0);
     vertice_auxiliar = vertice_auxiliar->get_vertice_siguiente();
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
