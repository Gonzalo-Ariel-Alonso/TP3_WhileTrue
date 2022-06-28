#include "Archivos.h"


Archivos::Archivos( string escritores_txt ,Vector * vector_escritores, Grafo<Lectura*> * grafo, string lecturas_txt ){
  this->escritores_txt = escritores_txt;
  this->vector_escritores = vector_escritores;
  this->grafo_completo = grafo;
  this->lecturas_txt = lecturas_txt;

}

Archivos::~Archivos(){
  vector_escritores = 0;
  grafo_completo = 0;
}


string Archivos::sacar_parentesis(string referencia_escritor){
  long unsigned int tamanio_string = referencia_escritor.length();
  string nueva_referencia;
  for (long unsigned int i = 1; i < tamanio_string-1; i++){
    nueva_referencia += referencia_escritor[i];
  }
  return nueva_referencia;
}

int Archivos::funcion_hashing(string referencia_escritor){
  int referencia = stoi(referencia_escritor);
  int posicion_hashing = referencia % TAMANIO_VECTOR;
  return posicion_hashing;
}

void Archivos::leer_archivo_escritores(){
    ifstream escritores;
    escritores.open(escritores_txt);
    string referencia_escritor;
    string nombre;
    string nacionalidad;
    string anio_nacimiento;
    string anio_fallecimiento = "/n";
    int pos;
    string vacio;
    while (!escritores.eof()){
        getline(escritores,referencia_escritor);
        getline(escritores,nombre);
        getline(escritores,nacionalidad);
        getline(escritores,anio_nacimiento);
        if (anio_nacimiento != ""){
            getline(escritores,anio_fallecimiento);
        }
        if (anio_fallecimiento != ""){
            getline(escritores,vacio);
        }
        carga_vector_escritores(referencia_escritor, nombre, nacionalidad, anio_nacimiento, anio_fallecimiento);
        pos++;
        anio_fallecimiento = ""; anio_nacimiento = "";
    }
    escritores.close();
}

void Archivos::carga_vector_escritores(string referencia_escritor,string nombre, string nacionalidad, string anio_nacimiento, string anio_fallecimiento){
  //crear objeto escritor
  referencia_escritor = sacar_parentesis(referencia_escritor);
  int pos = funcion_hashing(referencia_escritor);//la posicion dentro del vector de hash
  int referencia_escritor_entero = stoi(referencia_escritor);
  Escritor* aux = new Escritor(referencia_escritor_entero,nombre,nacionalidad,anio_nacimiento,anio_fallecimiento);
  vector_escritores[pos].agregar_objeto(aux);
  //AGREGARLO AL VECTOR
}

Generos Archivos::de_string_a_enumerado(string genero_string){
    Generos genero;
    if(genero_string  == "DRAMA")
        genero = DRAMA;
    else if (genero_string == "COMEDIA")
        genero = COMEDIA;
    else if (genero_string  == "FICCION")
        genero = FICCION;
    else if (genero_string  == "SUSPENSO")
        genero = SUSPENSO;
    else if (genero_string  == "TERROR")
        genero = TERROR;
    else if (genero_string  == "ROMANTICA")
        genero = ROMANTICA;
    else if (genero_string  == "HISTORICA")
        genero = HISTORICA;
    return genero;
}

void Archivos::cargar_grafo(){
  ifstream lecturas;
  lecturas.open(lecturas_txt);
  string tipo_lecturas, titulo, duracion_lectura, ano_publicacion, referencia_a_lectura, tema_novela_historica,referencia_a_escritor, vacio;
  while (!lecturas.eof()){
      getline(lecturas,tipo_lecturas);
      getline(lecturas,titulo);
      getline(lecturas,duracion_lectura);
      getline(lecturas,ano_publicacion);
      getline(lecturas,referencia_a_lectura);
      if (referencia_a_lectura == "HISTORICA"){
          getline(lecturas,tema_novela_historica);
      }
      getline(lecturas,referencia_a_escritor);
      getline(lecturas,vacio);

      char tipo_lectura = tipo_lecturas.at(0);
      int referencia_a_escritor = referencia_a_escritor;

      if ( tema_novela_historica != "" ){
        crear_tipo_lectura(tipo_lectura, titulo, duracion_lectura, ano_publicacion, referencia_a_escritor, referencia_a_lectura, tema_novela_historica);
      }
      else{
        crear_tipo_lectura(tipo_lectura, titulo, duracion_lectura, ano_publicacion, referencia_a_escritor, referencia_a_lectura);
      }
      tema_novela_historica = "";


  }
  lecturas.close();
}

void Archivos::crear_tipo_lectura(char tipo_lectura, string titulo, string duracion_lectura, string ano_publicacion, int referencia_autor, string referencia_a_lectura){
  if (tipo_lectura == 'C'){

    Cuento* nuevo_cuento = new Cuento(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),referencia_autor,referencia_a_lectura);
    grafo_completo->agregar_vertice(nuevo_cuento);
  }
  else if(tipo_lectura == 'N'){

    Generos genero = de_string_a_enumerado(referencia_a_lectura);
    Novela * nueva_novela = new Novela(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),referencia_autor,genero);
    grafo_completo->agregar_vertice(nueva_novela);

  }
  else if(tipo_lectura == 'P'){
    int cantidad_versos = stoi(referencia_a_lectura);
    Poema * nuevo_poema = new Poema(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),referencia_autor,cantidad_versos);
    grafo_completo->agregar_vertice(nuevo_poema);
  }
}


void Archivos::crear_tipo_lectura(char tipo_lectura, string titulo, string duracion_lectura, string ano_publicacion, int referencia_autor, string referencia_a_lectura, string tema){
  Generos genero = de_string_a_enumerado(referencia_a_lectura);
  Novela_historica* nueva_novela_historica = new Novela_historica(tipo_lectura,titulo,stoi(duracion_lectura),stoi(ano_publicacion),referencia_autor,genero,tema);
  grafo_completo->agregar_vertice(nueva_novela_historica);
}
