#ifndef VECTOR_H
#define VECTOR_H

#include "Escritor.h"
#include "Lista.h"

class Vector{
private:
  Lista<Escritor*> lista_objetos;
  int cantidad_anidados;

public:
  Vector();
  void agregar_objeto ( Escritor* nuevo_escritor );
  void eliminar_objeto ( string objeto_sacar );
  Escritor* consulta ( string referencia );
  int get_cantidad_anidados();
  void imprimir_lista();
};


#endif //VECTOR_H
