#ifndef ARCHIVOS_H
#define ARCHIVOS_H

// includes
#include <iostream>
#include <fstream>
#include <string>

// includes de otros TDA
#include "Tabla_hash.h"
#include "Grafo.h"
#include "Tipo_de_lecturas.h"
#include "Escritor.h"
#include "Lectura.h"
#include "Novela_historica.h"
#include "Novela.h"
#include "Cuento.h"
#include "Poema.h"
#include "Genero.h"


using namespace std;



class Archivos {
  private:
    //atributos
    Tabla_hash * vector_hashing;
    string escritores_txt;
    Grafo<Lectura*> * grafo_completo;
    string lecturas_txt;

  public:
    /*
    Constructor con grafo
    Pre: archivo escritores, vector escritores,puntero grafo , archivo lecturas txt
    Pos: inicializa un archivo
    */
    Archivos( string escritores_txt ,Tabla_hash * vector_hashing, Grafo<Lectura*> * grafo, string lecturas_txt);
    /*

    */
    Archivos ( string archivo_escritores_txt );
    // destructor
    ~Archivos();
    /*
    Funcion que saca los parentesis de un string
    Pre: Un string que arranque y termine con parentesis
    Pos: Devuelve un string sin el primer y ultimo caracter
    */
    string sacar_parentesis ( string referencia_escritor );
    /*
    Lee el archivo escritores txt y carga el vector con los datos que haya adentro
    Pre: -
    Pos: Carga el vector_hashing con los datos dentro del archivo escritores.txt
    */
    void leer_archivo_escritores();
    /*
    Inicializa el escritor y lo guarda en el vector
    Pre: Los parametros levantados del archivo escritores.txt
    Pos: Transforma la referencia del escritor a un hash y lo almacena dentro del vector en su respectiva posiscion
    */
    void carga_vector_hashing(string referencia_escritor, string nombre, string nacionalidad, string anio_nacimiento, string anio_fallecimiento);

    /*
    Carga el grafo con las lecturas dentro de lecturas.txt
    Pre: -
    Pos: -
    */
    void cargar_grafo();
    /*
    Transforma el genero del string a un numero
    Pre: Recibe un string
    Pos: Devuelve el numero al que le corresponda el genero en el orden que esta dentro de "Tipo_de_lecturas.h"
    */
    Generos de_string_a_enumerado(string genero_string);
    /*
    Inicializa una lectura (que no sea Novela historica)
    Pre: Recibe los parametros para inicializar un objeto tipo lectura
    inicializa cuento, novela, poema y lo agrega al grafo como vertice
    Pos: -
    */
    void crear_tipo_lectura(char tipo_lectura, string titulo, string duracion_lectura, string ano_publicacion, int referencia_autor, string referencia_a_lectura);
    /*
    Inicializa una Novela historica
    Pre: Los parametros para inicializar una novela historica
    Pos: -
    */
    void crear_tipo_lectura(char tipo_lectura, string titulo, string duracion_lectura, string ano_publicacion, int referencia_autor, string referencia_a_lectura, string tema);
};



#endif // ARCHIVOS_H
