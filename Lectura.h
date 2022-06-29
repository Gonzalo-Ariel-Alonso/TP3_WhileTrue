#ifndef LECTURAS_LECTURA_H
#define LECTURAS_LECTURA_H

// includes
#include <iostream>
#include <string>

// includes de otros TDA
#include "Escritor.h"
#include "Genero.h"
#include "Tipo_de_lecturas.h"


using namespace std;

class Lectura {
protected:
    Tipo_de_lecturas tipo_de_lectura;
    string titulo;
    int tiempo_lectura;
    int anio;
    int referencia_autor;
public:

    //PRE: Recibe los datos a almacenar
    //POST: Almacena los datos
    Lectura ( char tipo_de_lectura, string titulo, int tiempo_lectura, int anio, int referencia_autor);
    //PRE:
    //POST:
    virtual ~Lectura();
    virtual void mostrar () = 0;

    //PRE:--
    //POST: Devuelve el titulo
    string get_titulo();

    //PRE:
    //POST:Devuelve el tiempo de lectura
    int get_tiempo_lectura();

    //PRE:
    //POST:Devuelve el año
    int get_anio();

    Tipo_de_lecturas get_tipo_de_lectura();
    
    Tipo_de_lecturas de_char_a_enumerado(char char_tipo_lectura);

};


#endif //LECTURAS_LECTURA_H
