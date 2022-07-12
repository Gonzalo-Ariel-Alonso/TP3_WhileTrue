#ifndef LECTURAS_CUENTO_H
#define LECTURAS_CUENTO_H

// includes
#include <iostream>
#include <string>

// includes de otros TDA
#include "Lectura.h"
#include "Escritor.h"

using namespace std;

class Cuento : public Lectura {
private:
    string titulo_de_libro;
public:
  //PRE:Recibe los parametros para cargar el objeto padre e hijo
  //POST:Almacena los datos
    Cuento (char tipo_de_lectura, string titulo, int tiempo_lectura, int anio , int referencia_autor , string titulo_de_libro);
    ~Cuento()=default;
    //PRE:----
    //POST:Imprime los datos por pantalla
    void mostrar() override;

};


#endif //LECTURAS_CUENTO_H
