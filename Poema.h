#ifndef LECTURAS_POEMA_H
#define LECTURAS_POEMA_H

// includes
#include <iostream>
#include <string>

// includes de otros TDA
#include "Lectura.h"
#include "Escritor.h"

class Poema: public Lectura {
  private:
      // atributos
      int versos;
  public:

    //PRE: Recibe por parametro los datos a almacenar
    //POST: Almacena los datos recibidos
      Poema (char tipo_de_lectura, string titulo, int tiempo_lectura, int anio , int referencia_autor , int versos);
      ~Poema()=default;

      //PRE:
      //POST: Imprime por pantalla los datos
      void mostrar()override;
};


#endif //LECTURAS_POEMA_H
