#ifndef MENU_H
#define MENU_H

// includes
#include <iostream>
#include <string>

// includes de otros TDA
#include "Archivos.h"
#include "Lista.h"
#include "Lectura.h"
#include "Grafo.h"
#include "Vector.h"


#define TAMANIO_VECTOR 25

using namespace std;

class Menu {
private:

  Vector * vector_escritores;
  Grafo<Lectura *> grafo_completo;



public:

  //PRE: Recibe 2 strings
  //POST: carga las listas con la informacion de cada archivo
  Menu(string archivo_escritor_a_escritores, string archivo_lecturas);

  //PRE:
  //POST: Libera la memoria de lo almacenado
  ~Menu();

  //PRE: ---
  //POST:  Inicializacion de la interfaz
  void interfaz_usuario_con_ingreso();


private:

  //PRE:
  //POST: Imprime por pantalla el menu
  void mostrar_menu();

  //PRE: recibe una opcion de tipo entero
  //POST: Mediante un switch corre la opcion recibida
  void opciones_interfaz(int opcion);

  //PRE: El usuario inserta un valor
  //POST: Devuelve lo ingresado por el usuario
  int ingresar_opciones_interfaz();
  
  //PRE: ---
  ///POST: ---
  void imprimir_escritores();

};








#endif //MENU_H
