#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H

// includes de otros TDA
#include "Nodo.h"

template <typename Dato>
class Lista {
    // Atributos
private:
    Nodo<Dato> * primero;
    int cantidad;
    //Nodo<Dato> * cursor;

    // Metodos
public:
    /*
    Constructor
    PRE: -
    POS: construye una Lista vacia
    */
    Lista();


    /*
    Alta al final de la lista
    PRE: Recibe un dato
    Post: Agrega el dato al final de la lista
    */
    void alta(Dato e);

    /*
    Alta
    PRE: e es un Dato valido y 1 <= pos <= obtener_cantidad() + 1
    POS: agrega el elemento en la posicion pos (se empieza por 1)
    */
    void alta(Dato e, int pos);

    /*
    Baja
    PRE: 1 <= pos <= obtener_cantidad()
    POS: da de baja al elemento que esta en pos, se empieza por 1
    */
    void baja(int pos);

    void baja(Dato d);

    void baja_sin_borrar_dato(Dato d);

    //Pre: Recibe un dato
    //Post: Modifica el dato actual del nodo por el nuevo
    void cambiar_dato(Dato d, int pos);

    /*
    Consulta
    PRE: 1 <= pos <= obtener_cantidad()
    POS: devuelve el elemento que esta en pos, se empieza por 1
    */
    Dato consulta(int pos);


    /*
    Vacia
    PRE: -
    POS: devuelve true si la Lista esta vacia, false de lo contrario
    */
    bool vacia();


    int obtener_cantidad();

    bool esta_el_dato(Dato d);

    void vaciar_datos();

    // Destructor
    ~Lista();

private:

    Nodo<Dato> * obtener_nodo(int pos);
};

// Constructor
template <typename Dato>
Lista<Dato>::Lista() {
    primero = 0;
    cantidad = 0;
}

//Pregunta si esta vacia
template <typename Dato>
bool Lista<Dato>::vacia() {
    return (cantidad == 0);
}

//Pregunta la cantidad de nodos(Espacio)
template <typename Dato>
int Lista<Dato>::obtener_cantidad() {
    return cantidad;
}

//Destructor
template <typename Dato>
Lista<Dato>::~Lista() {
    while (! vacia()){
        baja(1);
    }
}

// Consulta
template <typename Dato>
Dato Lista<Dato>::consulta(int pos) {
    Nodo<Dato>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

//Alta al final
template <typename Dato>
void Lista<Dato>::alta(Dato e) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (cantidad == 0) {
        primero = nuevo;
    }
    else {
        Nodo<Dato>* ultimo = obtener_nodo(cantidad);
        ultimo->cambiar_siguiente(nuevo);
    }
    cantidad++;
}


// alta
template <typename Dato>
void Lista<Dato>::alta(Dato e, int pos) {
    Nodo<Dato>* nuevo = new Nodo<Dato>(e);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        nuevo->cambiar_siguiente(anterior->obtener_siguiente());
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}



// baja
template <typename Dato>
void Lista<Dato>::baja(int pos) {
    Nodo<Dato> * borrar = primero;
    if (pos == 1) {
        primero = primero->obtener_siguiente();
    }
    else {
        Nodo<Dato>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(borrar->obtener_siguiente());
    }
    cantidad--;
    delete borrar;
}

template <typename Dato>
void Lista<Dato>::baja(Dato d){
  int posicion_dato = 0;
  for (int i = 1; i <= cantidad ; i ++){
    if (consulta(i) == d){
      posicion_dato = i;
    }
  }
  if (posicion_dato != 0){
    baja(posicion_dato);
  }
}

template <typename Dato>
void Lista<Dato>::baja_sin_borrar_dato(Dato d){
  int posicion_dato = 0;
  for (int i = 1; i <= cantidad ; i ++){
    if (consulta(i) == d){
      posicion_dato = i;
    }
  }
  if (posicion_dato != 0){
    cambiar_dato(0, posicion_dato);
    baja(posicion_dato);
  }
}


//Cambia el valor actual

template <typename Dato >
void Lista<Dato>::cambiar_dato(Dato d, int pos){
    obtener_nodo(pos)->cambiar_dato(d);
}

template <typename Dato>
bool Lista<Dato>::esta_el_dato(Dato d){
  bool revisar = false;
  for (int i = 1; i <= cantidad ; i ++){
    if (consulta(i) == d){
      revisar = true;
    }
  }
  return revisar;
}

template <typename Dato>
void Lista<Dato>::vaciar_datos(){
  for (int i = 1; i <= cantidad; i++){
    cambiar_dato(0,i);
  }
}

// obtener_nodo
template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int pos) {
    Nodo<Dato>* aux = primero;
    int contador = 1;
    while (contador < pos) {
        aux = aux->obtener_siguiente();
        contador++;
    }
    return aux;
}


#endif //LISTA_LISTA_H
